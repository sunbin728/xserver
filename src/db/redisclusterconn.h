#ifndef _REDISCLUSTERCONN_H_
#define _REDISCLUSTERCONN_H_

#include "redisconnbase.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include <hiredis-vip/hircluster.h>
using namespace std;

class RedisClusterConn:public RedisConnBase{
    public:
        RedisClusterConn(std::string addr, std::string username, std::string password);
        ~RedisClusterConn();
        RedisClusterConn(const RedisClusterConn &conn);
        RedisClusterConn& operator=(const RedisClusterConn &conn);

        virtual RedisReply ExecCmd(string cmd);
        virtual bool Init();
    private:
        bool Reconnect();

    private:
        std::string m_addr;
        std::string m_username;
        std::string m_password;
        redisClusterContext *m_conn;
};
#endif /* _REDISCLUSTERCONN_H_ */
