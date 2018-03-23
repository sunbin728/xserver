#ifndef _WORKER_H_
#define _WORKER_H_

//#include "common/cache.h"
#include "base/package.h"
#include "queue/atomicops.h"
#include "queue/readerwriterqueue.h"
#include "queue/concurrentqueue.h"
#include "queue/blockingconcurrentqueue.h"

using namespace moodycamel;

class Worker{
    public:
        Worker(int workid):
            m_workid(workid),
            m_queue(),
            m_concurrentQueue(),
            m_ptoken(m_concurrentQueue),
            m_ctoken(m_concurrentQueue),
            m_start(true),
            m_working(false){
            }
        Worker(const Worker &worker);
        Worker& operator=(const Worker &worker);
        ~Worker();

        void Start();
        void Stop();
        void doWork();
        void AddMsg(MSG* msg);
    private:
        int m_workid;
        BlockingReaderWriterQueue<MSG*> m_queue;
        BlockingConcurrentQueue<MSG*> m_concurrentQueue;
        moodycamel::ProducerToken m_ptoken;
        moodycamel::ConsumerToken m_ctoken;
        bool m_start;
        bool m_working;
};
#endif /* _WORKER_H_ */
