#ifndef _WORKER_MANAGER_H_
#define _WORKER_MANAGER_H_

#include <vector>
#include "worker.h"
#include "base/package.h"

class WorkerManager{
    private:
        WorkerManager(){
        }
        WorkerManager(const WorkerManager &workerManager);
        WorkerManager& operator=(const WorkerManager &workerManager);
        ~WorkerManager();

    public:
        static WorkerManager& Instance();
        void Start(int threadcount);
        void DealMsg(MSG* msg);

    private:
        std::vector<Worker*> m_vecWorkers;
        int m_threadcount;
};
#endif /* _WORKER_MANAGER_H_ */
