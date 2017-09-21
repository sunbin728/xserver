#ifndef _DBCONN_H_
#define _DBCONN_H_

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include <cppconn/connection.h>

using namespace std;

class DbRow{
    public:
        DbRow(){}
        ~DbRow(){};
        string operator[](string fieldname){
            //std::cout << fieldname <<"  " << m_values[fieldname] << std::endl;
            return m_values[fieldname];
        }

        string operator[](int i){
            return m_values[m_fieldmap[i]];
        }

        map<string, string> m_values;
        map<int, string> m_fieldmap;
};

class DbResult{
    public:
        DbResult(){}
        ~DbResult();
        DbRow* operator[](int i){
            return m_res[i];
        }
        int GetCount();
        string ToString();
        void AddRow(DbRow* row){
            m_res.push_back(row);
        }

    private:
        vector<DbRow*> m_res;
};

class DbConn{
    public:
        DbConn(int id, std::string addr, int port, std::string username, std::string password,
                std::string dbname, std::string charset);
        ~DbConn();
        DbConn(const DbConn &conn);
        DbConn& operator=(const DbConn &conn);

        bool Init();
        sql::Connection* GetConn();
        bool Execute(std::string &sql);
        std::shared_ptr<DbResult> ExecuteQuery(std::string &sql);

    private:
        int m_id;
        std::string m_addr;
        int m_port;
        std::string m_username;
        std::string m_password;
        std::string m_dbname;
        std::string m_charset;
        sql::Connection *m_conn;
};
#endif /* _DBCONN_H_ */
