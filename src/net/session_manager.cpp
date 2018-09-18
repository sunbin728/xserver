#include "session_manager.h"
#include "accept_manager.h"
#include "common/logger.h"
#include "base/command.h"
#include "common/timeutil.h"
#include <string>
#include <thread>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;


SessionManager& SessionManager::Instance(){
    static SessionManager sessionManager;
    return sessionManager;
}

SessionManager::~SessionManager(){
    Destroy();
}

void SessionManager::watchWork(){
    ActiveConn* pConn;
    sleep(2);
    while(true){
        pthread_rwlock_rdlock(&m_rwlock);    //读者加读锁
        LOG_INFO("SessionManager::watchWork m_mapConns.size=%d", m_mapConns.size());
        pthread_rwlock_unlock(&m_rwlock);      //释放写锁
        std::map<int, ActiveConn*>::iterator iter;
        for (iter =  m_mapActiveConns.begin(); iter != m_mapActiveConns.end(); ++iter){
            pConn = iter->second;
            if (!pConn->GetValid()){
                this->reInitActiveConnect(pConn);
            }else{
                SendHeartBeat(pConn);
            }
        }

        sleep(15);
    }
}

void SessionManager::Init(){
    while (!AcceptManager::Instance().IsStarted()){
    sleep(1);
    }
    int conntype = ServerType::SERVER_TYPE_ACC;
    std::string addr = "172.16.0.11";
    int port = 1234;
    //initActiveConnect(conntype, addr, port);

    conntype = ServerType::SERVER_TYPE_MTS;
    addr = "172.16.0.11";
    port = 3128;
    //initActiveConnect(conntype, addr, port);

    //开启监控线程，用于主动链接的重连
    std::thread thread_watchWork(&SessionManager::watchWork, this);
    thread_watchWork.detach();
}

void SessionManager::Destroy(){
    pthread_rwlock_destroy(&m_rwlock);      //销毁读写
    std::map<int, Connection*>::iterator iter;
    LOG_INFO("SessionManager::Destroy m_mapConns.size=%d", m_mapConns.size());
    for (iter =  m_mapConns.begin(); iter != m_mapConns.end();){
        delete iter->second;
        m_mapConns.erase(iter++);
    }
    LOG_INFO("SessionManager::Destroy m_mapConns.size=%d", m_mapConns.size());
}

void SessionManager::initActiveConnect(int conntype, std::string addr, int port){
    ActiveConn* activeConn = new ActiveConn(conntype, addr, port);
    bool ret = activeConn->Init();
    if (ret){
        LOG_INFO("SessionManager::initActiveConnect OK: conntype=%d, socketfd=%d, addr=%s, port=%d",
                conntype, activeConn->GetSocketfd(), addr.c_str(), port);
        this->AddActiveConn(conntype, activeConn);
        bool addret = AcceptManager::Instance().AddEvent(activeConn->GetSocketfd());
        if (!addret){
            LOG_FATAL("SessionManager::Init AcceptManager::Instance().AddEvent faild: conntype=%d, ip=%s, port=%p, socketfd=%d",
                    conntype, addr.c_str(), port, activeConn->GetSocketfd());
        }
    }else{
        LOG_FATAL("SessionManager::Init activeConn_MTS->Init faild: conntype=%d, ip=%s, port=%d", conntype, addr.c_str(), port);
    }
}

void SessionManager::reInitActiveConnect(ActiveConn* activeConn){
    LOG_INFO("SessionManager::reInitActiveConnect begin: conntype=%d", activeConn->GetConnType());
    bool ret = activeConn->Init();
    if (ret){
        bool addret = AcceptManager::Instance().AddEvent(activeConn->GetSocketfd());
        if (!addret){
            LOG_ERROR("SessionManager::Init AcceptManager::Instance().AddEvent faild: conntype=%d, ip=%s, port=%p, socketfd=%d",
                    activeConn->GetConnType(), activeConn->GetAddr().c_str(), activeConn->GetPort(), activeConn->GetSocketfd());
        }else{
            AddConn(activeConn->GetSocketfd(), activeConn);
        }
    }else{
        LOG_ERROR("SessionManager::Init AcceptManager::Instance().AddEvent faild: conntype=%d, ip=%s, port=%p, socketfd=%d",
                activeConn->GetConnType(), activeConn->GetAddr().c_str(), activeConn->GetPort(), activeConn->GetSocketfd());
    }
    LOG_INFO("SessionManager::reInitActiveConnect end: conntype=%d", activeConn->GetConnType());
}

bool SessionManager::SendHeartBeat(ActiveConn* pConn){
    rapidjson::Document heartBeat;
    heartBeat.SetObject();
    heartBeat.AddMember("nowTime", TimeUtil::Now(), heartBeat.GetAllocator());

    bool ret = pConn->SendMsg(COMMON_HEART_BEAT, heartBeat);
    if (ret){
        LOG_INFO("SendHeartBeat ok: socketfd=%d", pConn->GetSocketfd());
    }else{
        LOG_ERROR("SendHeartBeat fail: socketfd=%d", pConn->GetSocketfd());
    }
    return ret;
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
    LOG_DEBUG("SessionManager::RemoveConn socketfd=%d", socketfd);
    Connection *pConn = NULL;
    pthread_rwlock_wrlock(&m_rwlock);      //写者加写锁
    std::map<int, Connection*>::iterator it = m_mapConns.find(socketfd);
    if (it != m_mapConns.end()){
        pConn = it->second;
        m_mapConns.erase(it);
        if (pConn->GetConnType() != ServerType::SERVER_TYPE_GC){
            //如果被断开的时非客户端连接，则需要重新连接
            std::map<int, ActiveConn*>::iterator it_active = m_mapActiveConns.find(pConn->GetConnType());
            if (it_active != m_mapActiveConns.end()){
                ActiveConn *activeConn = it_active->second;
                activeConn->SetValid(false);
                LOG_DEBUG("SessionManager::RemoveConn socketfd=%d, activeConn->GetValid()=%d, this=%p",
                        socketfd, activeConn->GetValid(), this);
            }
        }else{
            if (pConn != NULL){
                delete pConn;
            }
        }
    }else{
        LOG_WARN("SessionManager::RemoveConn can not find socketfd=%d", socketfd);
    }
    pthread_rwlock_unlock(&m_rwlock);      //释放写锁
}
