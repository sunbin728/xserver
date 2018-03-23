#include "redisclusterconn.h"

#include <sstream>
#include "common/logger.h"

RedisClusterConn::RedisClusterConn(std::string addr, std::string username, std::string password):
    m_addr(addr),
    m_username(username),
    m_password(password),
    m_conn(NULL){
    }

RedisClusterConn::~RedisClusterConn(){
    if (m_conn != NULL){
        redisClusterFree(m_conn);
        m_conn=NULL;
    }
}

bool RedisClusterConn::Init(){
    try {
        m_conn = redisClusterContextInit();
        redisClusterSetOptionAddNodes(m_conn, m_addr.c_str());
        redisClusterConnect2(m_conn);
        if (m_conn == NULL || m_conn->err) {
            if (m_conn) {
                LOG_ERROR("Init fail: err=%s, addr=%s", m_conn->errstr, m_addr.c_str());
            } else {
                LOG_ERROR("Init fail: Can't allocate redis context, addr=%s", m_addr.c_str());
            }
        }else{
            LOG_INFO("Init ok: addr=%s", m_addr.c_str());
        }
    } catch (...) {
        LOG_ERROR("Init error: catch, m_addr=%s", m_addr.c_str());
        return false;
    }
    return true;
}

bool RedisClusterConn::Reconnect(){
    if (m_conn != NULL){
        redisClusterFree(m_conn);
    }
    return Init();
}

RedisReply RedisClusterConn::ExecCmd(string cmd){
    redisReply *reply = (redisReply*)redisClusterCommand(m_conn, cmd.c_str());
    if(reply == NULL || m_conn->err)
    {
        LOG_INFO("ExecCmd reply is null: cmd=%s, err=%d, errstr=%s", cmd.c_str(), m_conn->err, m_conn->errstr);
        int err=m_conn->err;
        string errstr=m_conn->errstr;
        Reconnect();
        return RedisReply(reply, err, errstr);
    }
    return RedisReply(reply, m_conn->err, m_conn->errstr);
}
