#include "session_manager.h"
#include "accept_manager.h"
#include "common/logger.h"
#include <string>



SessionManager& SessionManager::Instance(){
    static SessionManager sessionManager;
    return sessionManager;
}

SessionManager::~SessionManager(){
    pthread_rwlock_destroy(&m_rwlock);      //销毁读写
    std::map<int, Connection*>::iterator iter;
    for (iter =  m_mapConns.begin(); iter != m_mapConns.end(); ++iter){
        delete iter->second;
    }
}

void SessionManager::Init(){
    //init conn to MTS
    int conntype = MTS;
    std::string addr = "172.16.3.17";
    int port = 1234;
    initConnect(conntype, addr, port);

    //init conn to PW
    conntype = PW;
    addr = "172.16.3.17";
    port = 1234;
    initConnect(conntype, addr, port);
}

void SessionManager::initConnect(int conntype, std::string addr, int port){
    ActiveConn* activeConn = new ActiveConn(conntype, addr, port);
    bool ret = activeConn->Init();
    if (ret){
        this->AddActiveConn(conntype, activeConn);
        bool addret = AcceptManager::Instance().AddEvent(activeConn->GetSocketfd());
        if (!addret){
            LOG_FATAL("SessionManager::Init AcceptManager::Instance().AddEvent faild: conntype=%d, ip=%s, port=%p, socketfd=%d",
                    conntype, addr.c_str(), port, activeConn->GetSocketfd());
        }
    }else{
        LOG_FATAL("SessionManager::Init activeConn_MTS->Init faild: conntype=%d, ip=%s, port=%p", conntype, addr.c_str(), port);
    }
}

void SessionManager::AddActiveConn(int conntype, ActiveConn* pConn){
    pthread_rwlock_wrlock(&m_rwlock);      //写者加写锁
    m_mapActiveConns[conntype]= pConn;
    m_mapConns[pConn->GetSocketfd()]= pConn;
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    LOG_DEBUG("SessionManager::AddActiveConn conntype=%d, pConn=%p", conntype, pConn);

}

ActiveConn* SessionManager::GetActiveConn(int conntype){
    ActiveConn *pConn = NULL;
    pthread_rwlock_rdlock(&m_rwlock);    //读者加读锁
    std::map<int, ActiveConn*>::iterator it = m_mapActiveConns.find(conntype);
    if (it != m_mapActiveConns.end()){
        pConn = it->second;
    }
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    return pConn;
}

void SessionManager::AddConn(int socketfd, Connection* pConn){
    pthread_rwlock_wrlock(&m_rwlock);      //写者加写锁
    m_mapConns[socketfd]= pConn;
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    LOG_DEBUG("SessionManager::AddConn socketfd=%d, pConn=%p", socketfd, pConn);
}

Connection* SessionManager::GetConn(int socketfd){
    Connection *pConn = NULL;
    pthread_rwlock_rdlock(&m_rwlock);    //读者加读锁
    std::map<int, Connection*>::iterator it = m_mapConns.find(socketfd);
    if (it != m_mapConns.end()){
        pConn = it->second;
    }
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    return pConn;
}

void SessionManager::RemoveConn(int socketfd){
    Connection *pConn = NULL;
    pthread_rwlock_rdlock(&m_rwlock);    //读者加读锁
    std::map<int, Connection*>::iterator it = m_mapConns.find(socketfd);
    if (it != m_mapConns.end()){
        pConn = it->second;
        m_mapConns.erase(it);
        if (pConn->GetConnType() != CLIENT){
            //如果被断开的时非客户端连接，则需要重新连接
            std::map<int, ActiveConn*>::iterator it_active = m_mapActiveConns.find(pConn->GetConnType());
            m_mapActiveConns.erase(it_active);
            ActiveConn *activeConn = it_active->second;
            this->initConnect(activeConn->GetConnType(), activeConn->GetAddr(), activeConn->GetPort());
        }
    }
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    if (pConn != NULL){
        delete pConn;
    }
}

bool SessionManager::SendMsg(int conntype,uint16_t command, const std::ostringstream& msgstream){
    ActiveConn *pConn = NULL;
    pthread_rwlock_rdlock(&m_rwlock);    //读者加读锁
    std::map<int, ActiveConn*>::iterator it = m_mapActiveConns.find(conntype);
    if (it != m_mapActiveConns.end()){
        pConn = it->second;
    }
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    return pConn->SendMsg(command, msgstream);
}
