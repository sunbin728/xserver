#ifndef _REDISCONN_MANAGER_H_
#define _REDISCONN_MANAGER_H_

#include "redisconnbase.h"
#include <string>

using namespace std;

class RedisConnManager{
    private:
        RedisConnManager();
        RedisConnManager(const RedisConnManager &redisConnManager);
        RedisConnManager& operator=(const RedisConnManager &redisConnManager);
        ~RedisConnManager();

    public:
        static RedisConnManager& Instance();
        bool Init();
        RedisReply ExecCmd(string cmd);

    private:
        bool InitRedis();
        bool InitRedisCluster();

    private:
        RedisConnBase *m_pRedisConnBase;
};

#endif /* _REDISCONN_MANAGER_H_ */
