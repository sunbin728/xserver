#include "unistd.h"

#include <signal.h>
#include <execinfo.h>

#include "common/logger.h"
#include "net/accept_manager.h"
#include "bizz/worker_manager.h"
#include "bizz/scene_manager.h"
#include "db/dbconn_manager.h"
#include "net/session_manager.h"

void PrintTrace(int signum){
    void *pTrace[256];
    char **ppszMsg = NULL;
    size_t uTraceSize = 0;
    do {
        if (0 == (uTraceSize = backtrace(pTrace, sizeof(pTrace) / sizeof(void *)))) {
            break;
        }
        if (NULL == (ppszMsg = backtrace_symbols(pTrace, uTraceSize))) {
            break;
        }
        LOG_INFO("signum=%d. call stack:\n", signum);
        for (size_t i = 0; i < uTraceSize; ++i) {
            LOG_INFO("%s\n", ppszMsg[i]);
        }
    } while (0);
    if (NULL != ppszMsg) {
        free(ppszMsg);
        ppszMsg = NULL;
    }
}

void signalHandler(int signum) {
    switch (signum) {
        case SIGHUP: {
                         PrintTrace(signum);
                         exit(0);
                     }
        case SIGINT:{
                        PrintTrace(signum);
                        AcceptManager::Instance().Stop();
                        exit(0);
                    }
        case SIGPIPE:{
                         PrintTrace(signum);
                         //ServiceManager::instance().Stop();
                         exit(0);
                     }
        case SIGSEGV:{
                         PrintTrace(signum);
                         //ServiceManager::instance().Stop();
                         exit(0);
                     }
        case SIGFPE:{
                        PrintTrace(signum);
                        //ServiceManager::instance().Stop();
                        exit(0);
                    }
        case SIGABRT:{
                         PrintTrace(signum);
                         //ServiceManager::instance().Stop();
                         exit(0);
                     }
        default:
                     break;
    }
}


int main()
{
    Logger::Instance().Init("switch", DEBUG);
    LOG_DEBUG("begin main %s", "OK");

    SceneMgr::Instance().Init();
    DbConnManager::Instance().Init();
    WorkerManager::Instance().Start(3);
    AcceptManager::Instance().Start();
    SessionManager::Instance().Init(); 
    sigset_t signals;
    sigdelset(&signals, SIGHUP);
    sigdelset(&signals, SIGINT);
    sigdelset(&signals, SIGPIPE);
    //sigdelset(&signals, SIGSEGV);
    sigdelset(&signals, SIGFPE);
    sigdelset(&signals, SIGABRT);


    signal(SIGPIPE, signalHandler);    // SIGPIPE，管道破裂。
    //signal(SIGSEGV, signalHandler);    // SIGSEGV，非法内存访问
    signal(SIGFPE, signalHandler);       // SIGFPE，数学相关的异常，如被0除，浮点溢出，等等
    signal(SIGABRT, signalHandler);     // SIGABRT，由调用abort函数产生，进程非正常退出

    signal(SIGHUP, signalHandler);
    signal(SIGINT, signalHandler);

    sigprocmask(SIG_BLOCK, &signals, NULL);


    while(true){
        sleep(1000);
    }
    return 0;
}
