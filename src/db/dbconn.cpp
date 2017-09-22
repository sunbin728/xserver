#include "dbconn.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <sstream>

#include "common/logger.h"

DbResult::~DbResult(){
    vector<DbRow*>::iterator it;
    for(it=m_res.begin(); it!=m_res.end(); ++it){
        delete *it;
    }
}

int DbResult::GetCount(){
    return m_res.size();
}

string DbResult::ToString(){
    ostringstream ostr;
    vector<DbRow*>::iterator it;
    ostr << endl;
    for(it=m_res.begin(); it!=m_res.end(); ++it){
    }
    return ostr.str();
}

DbConn::DbConn(int id, std::string addr, int port, std::string username, std::string password,
        std::string dbname, std::string charset):
    m_id(id),
    m_addr(addr),
    m_port(port),
    m_username(username),
    m_password(password),
    m_dbname(dbname),
    m_charset(charset),
    m_conn(NULL){
    }

DbConn::~DbConn(){
    delete m_conn;
}

bool DbConn::Init(){
    try {
        sql::Driver *driver;
        sql::ConnectOptionsMap connection_properties;

        connection_properties["hostName"] = m_addr;
        connection_properties["userName"] = m_username;
        connection_properties["password"] = m_password;
        connection_properties["schema"] = m_dbname;
        connection_properties["port"] = m_port;
        connection_properties["OPT_RECONNECT"] = true;
        connection_properties["OPT_CONNECT_TIMEOUT"] = 5;
        connection_properties["OPT_CHARSET_NAME"] = "utf8mb4";

        driver = get_driver_instance();
        m_conn = driver->connect(connection_properties);
        if (m_conn->isValid()){
            LOG_DEBUG("DbConn::Init ok: id=%d, addr=%s, port=%d, username=%s, password=%s, dbname=%s, charset=%s",
                    m_id, m_addr.c_str(), m_port, m_username.c_str(), m_password.c_str(), m_dbname.c_str(), m_charset.c_str());
        }
    } catch (sql::SQLException &e) {
        LOG_ERROR("DbConn::Init Execption: err=%s, errcode=%d, sqlState=%s", e.what(), e.getErrorCode(), e.getSQLState().c_str());
        return false;
    }
    return true;
}

sql::Connection*  DbConn::GetConn(){
    return m_conn;
}


bool DbConn::Execute(std::string &sql){
    sql::Statement *stmt = m_conn->createStatement();
    bool ret = stmt->execute(sql);
    delete stmt;
    return ret;
}

std::shared_ptr<DbResult> DbConn::ExecuteQuery(std::string &sql){
    LOG_INFO("DbConn::ExecuteQuery: sql=%s", sql.c_str());
    sql::Statement *stmt = m_conn->createStatement();
    sql::ResultSet  *res = stmt->executeQuery(sql);
    sql::ResultSetMetaData *res_meta = res->getMetaData();
    int numcols = res_meta->getColumnCount();
    DbResult * dbResult = new DbResult();
    while (res->next()) {
        DbRow* row = new DbRow();
        for(int i=0; i<numcols; ++i){
            std::string fieldname = res_meta->getColumnName(i+1).asStdString();
            std::string val = res->getString(i+1).asStdString();
            row->m_fieldmap.push_back(fieldname);
            row->m_values[fieldname] = val;
            //std::cout << fieldname << " " << val << endl;
        }
        dbResult->AddRow(row);
    }
    delete res;
    delete stmt;
    return std::shared_ptr<DbResult>(dbResult);
}
