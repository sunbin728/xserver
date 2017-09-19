#include "worker.h"

#include <thread>
#include <unistd.h>
#include "common/logger.h"
#include "bizz.h"

void Worker::Start(){
    std::thread thrd_worker(&Worker::doWork, this);
    thrd_worker.detach();
}

void Worker::doWork(){
    LOG_INFO("Worker::doWork start: workid=%d", m_workid);
    while (true){
        MSG* pmsg = NULL;
        m_queue.wait_dequeue(pmsg);
        LOG_DEBUG("Worker::doWork m_queue.wait_dequeue: workid=%d, pmsg=%p", m_workid, pmsg);
        if (pmsg != NULL){
            bizz::DoWork(pmsg);
            delete pmsg;
        }else{
            usleep(1000*10);
        }
    }
}

void Worker::AddMsg(MSG* msg){
    m_queue.enqueue(msg);
    LOG_DEBUG("Worker::AddMsg workid=%d, queuesize=%d, msg->size=%d, PkgLen=%d, Command=%d, Target=%d, Retcode=%d",
            m_workid, m_queue.size_approx(), msg->size, msg->header->PkgLen, msg->header->Command,
            msg->header->Target, msg->header->Retcode);
}
