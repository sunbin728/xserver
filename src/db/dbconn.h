#ifndef DBCONN_H_
#define DBCONN_H_

#include <string>
#include <vector>
#include <map>

#include <cppconn/connection.h>

using namespace std;

class DbResult{
    public:
        typedef map<string, string> Row;
        DbResult(){}
        ~DbResult();
        Row* operator[](int i){
            return m_res[i];
        }
        int GetCount();
        string ToString();
        void AddRow(Row* row){
            m_res.push_back(row);
        }

    private:
        vector<Row*> m_res;
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
        DbResult* ExecuteQuery(std::string &sql);

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
#endif /* DBCONN_H_ */
