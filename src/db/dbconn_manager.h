#ifndef _DBCONN_MANAGER_H_
#define _DBCONN_MANAGER_H_

#include "dbconn.h"
#include "common/cache.h"
#include <string>


class DbConnManager{
    private:
        DbConnManager();
        DbConnManager(const DbConnManager &DbConnManager);
        DbConnManager& operator=(const DbConnManager &dbConnManager);
        ~DbConnManager();

    public:
        static DbConnManager& Instance();
        bool Init();
        DbConn* GetDbConn();
        void PutDbConn(DbConn* dbConn);

        bool Execute(std::string &sql);
        std::shared_ptr<DbResult> ExecuteQuery(std::string &sql);

    private:
        int m_maxConnSize;
        Queue<DbConn*> m_dbConnPool;
};

class SmartDbConnPtr{
    public:
        SmartDbConnPtr(DbConn* pdbConn, DbConnManager* pdbConnManager):
            m_pdbConn(pdbConn),
            m_pdbConnManager(pdbConnManager){
            }
        ~SmartDbConnPtr(){
            m_pdbConnManager->PutDbConn(m_pdbConn);
        }

        DbConn& operator*(){
            return *m_pdbConn;
        }

        DbConn* operator->(){
            return m_pdbConn;
        }

        DbConn* m_pdbConn;
        DbConnManager* m_pdbConnManager;
};
#endif /* _DBCONN_MANAGER_H_ */
