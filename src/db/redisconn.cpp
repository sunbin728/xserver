#include "redisconn.h"

#include "common/logger.h"

RedisConn::RedisConn(std::string addr, int port, std::string username, std::string password):
    m_addr(addr),
    m_port(port),
    m_username(username),
    m_password(password),
    m_conn(NULL){
    }

RedisConn::~RedisConn(){
    if (m_conn != NULL){
        redisFree(m_conn);
        m_conn=NULL;
    }
}

bool RedisConn::Init(){
    try {
        m_conn = redisConnect(m_addr.c_str(), m_port);
        if (m_conn == NULL || m_conn->err) {
            if (m_conn) {
                LOG_ERROR("Init fail: err=%s, addr=%s, port=%d", m_conn->errstr, m_addr.c_str(), m_port);
            } else {
                LOG_ERROR("Init fail: Can't allocate redis context, addr=%s, port=%d", m_addr.c_str(), m_port);
            }
        }else{
            LOG_INFO("Init ok: addr=%s, port=%d", m_addr.c_str(), m_port);
        }
    } catch (...) {
        LOG_ERROR("Init error: catch, m_addr=%s", m_addr.c_str());
        return false;
    }
    return true;
}

bool RedisConn::Reconnect(){
    LOG_INFO("Reconnect: addr=%s, port=%d", m_addr.c_str(), m_port);
    if (m_conn != NULL){
        redisFree(m_conn);
    }
    return Init();
}

RedisReply RedisConn::ExecCmd(string cmd){
    redisReply *reply = (redisReply*)redisCommand(m_conn, cmd.c_str());
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
