#ifndef _REDISCONN_H_
#define _REDISCONN_H_

#include "redisconnbase.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include <hiredis/hiredis.h>
using namespace std;

class RedisConn:public RedisConnBase{
    public:
        RedisConn(std::string addr, int port, std::string username, std::string password);
        ~RedisConn();
        RedisConn(const RedisConn &conn);
        RedisConn& operator=(const RedisConn &conn);

        virtual RedisReply ExecCmd(string cmd);
        virtual bool Init();
    private:
        bool Reconnect();

    private:
        std::string m_addr;
        int m_port;
        std::string m_username;
        std::string m_password;
        redisContext *m_conn;
};

#endif /* _REDISCONN_H_ */
