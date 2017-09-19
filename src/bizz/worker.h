#ifndef _WORKER_H_
#define _WORKER_H_

//#include "common/cache.h"
#include "base/package.h"
#include "queue/atomicops.h"
#include "queue/readerwriterqueue.h"

using namespace moodycamel;

class Worker{
    public:
        Worker(int workid):
            m_workid(workid),
            m_queue(){
        }
        Worker(const Worker &worker);
        Worker& operator=(const Worker &worker);
        ~Worker(){
        };

        void Start();
        void doWork();
        void AddMsg(MSG* msg);
    private:
        int m_workid;
        BlockingReaderWriterQueue<MSG*> m_queue;
};
#endif /* _WORKER_H_ */
