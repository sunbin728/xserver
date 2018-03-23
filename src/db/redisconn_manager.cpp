#include "redisconn_manager.h"

#include <sstream>

#include "redisconn.h"
#include "redisclusterconn.h"
#include "common/logger.h"

RedisConnManager::RedisConnManager():
    m_pRedisConnBase(NULL)
{
}

RedisConnManager::~RedisConnManager(){
    if (m_pRedisConnBase != NULL){
        delete m_pRedisConnBase;
    }
}

RedisConnManager& RedisConnManager::Instance(){
    static RedisConnManager redisConnManager;
    return redisConnManager;
}

bool RedisConnManager::Init(){
    //bool ret = InitRedis();
    bool ret = InitRedisCluster();
    return ret;
}

bool RedisConnManager::InitRedis(){
    LOG_INFO(".................................RedisConnManager::InitRedis begin.................................");
    std::string addr = "172.16.0.3";
    int port = 6379;
    std::string username = "";
    std::string password = "";
    m_pRedisConnBase = new RedisConn(addr, port, username, password);
    if (!m_pRedisConnBase->Init()){
        LOG_FATAL("RedisConnManager::InitRedis fail: addr=%s, port=%d, username=%s, password=%s",
                addr.c_str(), port, username.c_str(), password.c_str());
    }else{
        LOG_INFO("RedisConnManager::InitRedis ok: addr=%s, port=%d, username=%s, password=%s",
                addr.c_str(), port, username.c_str(), password.c_str());
    }
    LOG_INFO(".................................RedisConnManager::InitRedis end.................................");
    return true;
}

bool RedisConnManager::InitRedisCluster(){
    LOG_INFO(".................................RedisConnManager::InitRedisCluster begin.................................");
    std::string addr = "172.16.0.3:7000, 172.16.0.3:7001, 172.16.0.3:7002, 172.16.0.3:7003, 172.16.0.3:7004, 172.16.0.3:7005";
    //std::string addr = "172.16.0.7:7000, 172.16.0.7:7001, 172.16.0.7:7002, 172.16.0.7:7003, 172.16.0.7:7004, 172.16.0.7:7005";
    int port = 6379;
    std::string username = "";
    std::string password = "";
    m_pRedisConnBase = new RedisClusterConn(addr, username, password);
    if (!m_pRedisConnBase->Init()){
        LOG_FATAL("RedisConnManager::InitRedisCluster fail: addr=%s, port=%d, username=%s, password=%s",
                addr.c_str(), port, username.c_str(), password.c_str());
    }else{
        LOG_INFO("RedisConnManager::InitRedisCluster ok: addr=%s, port=%d, username=%s, password=%s",
                addr.c_str(), port, username.c_str(), password.c_str());
    }
    LOG_INFO(".................................RedisConnManager::InitRedisCluster end.................................");
    return true;
}

 RedisReply RedisConnManager::ExecCmd(string cmd){
    return m_pRedisConnBase->ExecCmd(cmd);
}
