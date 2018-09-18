#include "worker_manager.h"

#include "common/logger.h"

WorkerManager::~WorkerManager(){
    LOG_INFO("WorkerManager::~WorkerManager m_vecWorkers.size=%d", m_vecWorkers.size());
    std::vector<Worker*>::iterator iter;
    for( iter = m_vecWorkers.begin(); iter != m_vecWorkers.end(); ){
        delete *iter;
        iter = m_vecWorkers.erase(iter);
    }
    LOG_INFO("WorkerManager::~WorkerManager m_vecWorkers.size=%d", m_vecWorkers.size());
}

WorkerManager& WorkerManager::Instance(){
    static WorkerManager workerManager;
    return workerManager;
}

void WorkerManager::Start(int threadcount){
    LOG_INFO("WorkerManager::Start threadcount=%d", threadcount);
    m_threadcount = threadcount;
    for( int i=0; i<threadcount; ++i){
        Worker *worker = new Worker(i);
        m_vecWorkers.push_back(worker);
        worker->Start();
    }
}


void WorkerManager::DealClientMsg(MSG* msg){
    //std::string strbody(msg->GetDataPtr(), msg->GetDataLen());
    //LOG_DEBUG("WorkerManager::DealMsg msg->size=%d, PkgLen=%d, Command=%d, Target=%d, Retcode=%d, body=%s",
    //msg->size, msg->header->PkgLen, msg->header->Command, msg->header->Target, msg->header->Retcode, strbody.c_str());
    m_vecWorkers[msg->socketfd % (m_threadcount/2)]->AddMsg(msg);
}

void WorkerManager::DealServerMsg(MSG* msg){
    //std::string strbody(msg->GetDataPtr(), msg->GetDataLen());
    //LOG_DEBUG("WorkerManager::DealMsg msg->size=%d, PkgLen=%d, Command=%d, Target=%d, Retcode=%d, body=%s",
    //msg->size, msg->header->PkgLen, msg->header->Command, msg->header->Target, msg->header->Retcode, strbody.c_str());
    m_vecWorkers[msg->socketfd %(m_threadcount-m_threadcount/2)+m_threadcount/2]->AddMsg(msg);
}

