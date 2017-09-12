#include "worker_manager.h"

#include "common/logger.h"

WorkerManager::~WorkerManager(){
    std::vector<Worker*>::iterator iter;
    for( iter = m_vecWorkers.begin(); iter != m_vecWorkers.end(); iter++ ){
        delete *iter;
    }
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


void WorkerManager::DealMsg(MSG* msg){
    LOG_DEBUG("WorkerManager::DealMsg msg->size=%d, PkgLen=%d, Command=%d, Target=%d, Retcode=%d",
            msg->size, msg->header->PkgLen, msg->header->Command, msg->header->Target, msg->header->Retcode);
    m_vecWorkers[msg->socketfd % m_threadcount]->AddMsg(msg);
}
