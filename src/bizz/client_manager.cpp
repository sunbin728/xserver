#include "client_manager.h"
#include "common/logger.h"
#include "base/command.h"
#include <string>


ClientManager& ClientManager::Instance(){
    static ClientManager clientManager;
    return clientManager;
}

ClientManager::~ClientManager(){
    //Connection对象由SessionManager负责销毁，此处不需要处理
    //pthread_rwlock_destroy(&m_rwlock);      //销毁读写
    //std::map<int, Connection*>::iterator iter;
    //for (iter =  m_mapConns.begin(); iter != m_mapConns.end(); ++iter){
        //delete iter->second;
    //}
}

void ClientManager::AddConn(int uid, Connection* pConn){
    pthread_rwlock_wrlock(&m_rwlock);      //写者加写锁
    m_mapConns[uid]= pConn;
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    LOG_DEBUG("ClientManager::AddConn uid=%d, pConn=%p", uid, pConn);
}

Connection* ClientManager::GetConn(int uid){
    Connection *pConn = NULL;
    pthread_rwlock_rdlock(&m_rwlock);    //读者加读锁
    std::map<int, Connection*>::iterator it = m_mapConns.find(uid);
    if (it != m_mapConns.end()){
        pConn = it->second;
    }
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    return pConn;
}

void ClientManager::RemoveConn(int uid){
    LOG_DEBUG("ClientManager::RemoveConn uid=%d", uid);
    pthread_rwlock_wrlock(&m_rwlock);      //写者加写锁
    std::map<int, Connection*>::iterator it = m_mapConns.find(uid);
    if (it != m_mapConns.end()){
        m_mapConns.erase(it);
    }
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
}
