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
        MSG** ppmsg = m_queue.pop();
        LOG_DEBUG("Worker::doWork m_queue.pop: workid=%d, ppmsg=%p", m_workid, ppmsg);
        if (ppmsg != NULL){
            bizz::DoWork(*ppmsg);
            delete *ppmsg;
        }else{
            usleep(1000*10);
        }
    }
}

void Worker::AddMsg(MSG* msg){
    m_queue.push(msg);
    LOG_DEBUG("Worker::AddMsg workid=%d, msg->size=%d, PkgLen=%d, Command=%d, Target=%d, Retcode=%d",
            m_workid, msg->size, msg->header->PkgLen, msg->header->Command,
            msg->header->Target, msg->header->Retcode);
}
