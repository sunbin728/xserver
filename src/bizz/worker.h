#ifndef WORKER_H_
#define WORKER_H_

#include "common/cache.h"
#include "base/package.h"

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
        Queue<MSG*> m_queue;
};
#endif /* WORKER_H_ */
