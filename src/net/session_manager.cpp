#include "session_manager.h"
#include "common/logger.h"
#include <string>



SessionManager& SessionManager::Instance(){
    static SessionManager sessionManager;
    return sessionManager;
}

void SessionManager::Init(){
    //init conn to MTS
    int conntype = MTS;
    std::string addr = "172.16.3.17";
    int port = 1234;
    ActiveConn* activeConn_MTS = new ActiveConn(MTS, addr, port);
    bool ret = activeConn_MTS->Init();
    if (ret){
        this->AddActiveConn(conntype, activeConn_MTS);
    }else{
        LOG_FATAL("SessionManager::Init activeConn_MTS->Init faild: conntype=%d, ip=%s, port=%p", conntype, addr.c_str(), port);
    }

    //init conn to PW
    conntype = PW;
    addr = "172.16.3.17";
    port = 1234;
    ActiveConn* activeConn_PW = new ActiveConn(PW, addr, port);
    ret = activeConn_PW->Init();
    if (ret){
        this->AddActiveConn(conntype, activeConn_PW);
    }else{
        LOG_FATAL("SessionManager::Init activeConn_PW->Init faild: conntype=%d, ip=%s, port=%p", conntype, addr.c_str(), port);
    }
}

void SessionManager::AddActiveConn(int conntype, ActiveConn* pConn){
    pthread_rwlock_wrlock(&m_rwlock);      //写者加写锁
    m_mapActiveConns[conntype]= pConn;
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
    }
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    if (pConn != NULL){
        delete pConn;
    }
}
