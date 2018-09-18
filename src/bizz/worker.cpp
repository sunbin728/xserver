#include "worker.h"

#include <thread>
#include <unistd.h>
#include "common/logger.h"
#include "bizz.h"

Worker::~Worker(){
    Stop();
}

void Worker::Stop(){
    m_start = false;
    while(m_working){
        LOG_INFO("Worker::Stoping");
        sleep(1);
    }
    LOG_INFO("Worker::Stoped, workerid=%d", m_workid);
}

void Worker::Start(){
    std::thread thrd_worker(&Worker::doWork, this);
    thrd_worker.detach();
}

void Worker::doWork(){
    LOG_INFO("Worker::doWork start: workerid=%d", m_workid);
    MSG* pmsg = nullptr;
    while (m_start){
        //m_queue.wait_dequeue(pmsg);
        m_concurrentQueue.wait_dequeue(m_ctoken, pmsg);
        m_working = true;
        //LOG_DEBUG("Worker::doWork m_queue.wait_dequeue: workid=%d, pmsg=%p", m_workid, pmsg);
        if (pmsg != nullptr){
            bizz::DoWork(pmsg);
            delete pmsg;
            pmsg = nullptr;
        }else{
            usleep(1000*10);
        }
        m_working = false;
    }
    LOG_INFO("Worker::doWor m_start is false, prepare to stop. workerid=%d", m_workid);
}

void Worker::AddMsg(MSG* msg){
    //m_queue.enqueue(msg);
    m_concurrentQueue.enqueue(m_ptoken, msg);
    //LOG_DEBUG("Worker::AddMsg workid=%d, queuesize=%d, socketfd=%d, msg->size=%d, PkgLen=%d, Command=%d, Target=%d, Retcode=%d",
    //m_workid, m_queue.size_approx(),msg->socketfd, msg->size, msg->header->PkgLen, msg->header->Command,
    //msg->header->Target, msg->header->Retcode);
}
