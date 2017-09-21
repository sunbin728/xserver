#include "dbconn_manager.h"
#include "common/logger.h"

DbConnManager::DbConnManager():
    m_maxConnSize(20),
    m_dbConnPool(m_maxConnSize, true){
    }

DbConnManager::~DbConnManager(){
}

DbConnManager& DbConnManager::Instance(){
    static DbConnManager dbConnManager;
    return dbConnManager;
}

bool DbConnManager::Init(){
    LOGINFO(".................................DbConnManager::Init begin.................................");
    for(int i=0; i<m_maxConnSize; ++i){
        std::string addr = "172.16.0.4";
        int port = 3306;
        std::string username = "nico";
        std::string password = "nico";
        std::string dbname = "NICO_CONF";
        std::string charset = "utf8";
        DbConn *pdbConn = new DbConn(i, addr, port, username, password, dbname, charset);
        if (!pdbConn->Init()){
            LOG_FATAL("DbConnManager::Init fail: addr=%s, port=%d, username=%s, password=%s, dbname=%s, charset=%s",
                    addr.c_str(), port, username.c_str(), password.c_str(), dbname.c_str(), charset.c_str());
        }else{
            m_dbConnPool.push(pdbConn);
        }
    }
    LOGINFO(".................................DbConnManager::Init end.................................");
    return true;
}

DbConn* DbConnManager::GetDbConn(){
    DbConn** ppdbConn = m_dbConnPool.pop();
    if (ppdbConn != NULL){
        return *ppdbConn;
    }else{
        return NULL;
    }
}

void DbConnManager::PutDbConn(DbConn* pdbConn){
    m_dbConnPool.push(pdbConn);
}


bool DbConnManager::Execute(std::string &sql){
    SmartDbConnPtr smartDbConnPtr(GetDbConn(), this);
    bool ret = smartDbConnPtr->Execute(sql);
    return ret;
}

std::shared_ptr<DbResult> DbConnManager::ExecuteQuery(std::string &sql){
    SmartDbConnPtr smartDbConnPtr(GetDbConn(), this);
    return smartDbConnPtr->ExecuteQuery(sql);
}
