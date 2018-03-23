#include "unistd.h"

#include <signal.h>
#include <execinfo.h>
#include <iostream>

#include "common/logger.h"
#include "common/util.h"
#include "net/accept_manager.h"
#include "bizz/worker_manager.h"
#include "db/dbconn_manager.h"
#include "db/redisconn_manager.h"
#include "net/session_manager.h"

#include "queue/readerwriterqueue.h"
#include "queue/concurrentqueue.h"
#include "queue/blockingconcurrentqueue.h"

using namespace std;

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
        LOG_INFO("PrintTrace signum=%d. call stack:\n", signum);
        for (size_t i = 0; i < uTraceSize; ++i) {
            LOG_INFO("PrintTrace %s\n", ppszMsg[i]);
        }
    } while (0);
    if (NULL != ppszMsg) {
        free(ppszMsg);
        ppszMsg = NULL;
    }
}

void signalHandler(int signum) {
    switch (signum) {
        case SIGHUP:
        case SIGINT:
        case SIGSEGV:
        case SIGFPE:
        case SIGABRT:
        case SIGTERM:{
                         PrintTrace(signum);
                         LOG_INFO("recv signum=%d, prepear to exit.", signum);
                         AcceptManager::Instance().Stop();
                         LOG_INFO("signum=%d, bye!", signum);
                         exit(1);
                         break;
                     }
        case SIGPIPE:{
                         LOG_INFO("recv signum=%d, ignore.", signum);
                         break;
                     }
        default:
                     break;
    }
}

void test(){
    std::string str = "你好";
    const char* cstr = str.c_str();
    LOG_INFO(util::ToHexString_Simple(str.c_str(), str.length()).c_str());
    LOG_INFO(util::ToHexString_Simple(cstr, strlen(cstr)).c_str());
    char* cgbk = new char[10]();
    util::u2g(const_cast<char*>(cstr), strlen(cstr), cgbk, 10);
    LOG_INFO(util::ToHexString_Simple(cgbk, strlen(cgbk)).c_str());

    LOG_INFO(cstr);
    LOG_INFO(cgbk);
    exit(0);
}

void test1(){
    string key = "abc";
    std::ostringstream buffer;
    buffer << "get " << key;
    string cmd = buffer.str();
    RedisReply rr = RedisConnManager::Instance().ExecCmd(cmd);
    if (!rr.Err()){
        LOG_DEBUG("RedisReply: err=%d, errstr=%s, reply=%s", rr.Err(), rr.ErrStr().c_str(), rr->str);
        std::cout << "len=" << rr->len << ",type=" << rr->type << ", str=" << rr->str << ", integer="<< rr->integer << ", elements=" << rr->elements << ", element=" << rr->element << std::endl;
    }
}

void test2(){
    int a, b, c;
    int *pa, *pb, *pc;
    a=10;
    b=11;
    c=12;
    pa=pb=pc=nullptr;
    BlockingReaderWriterQueue<int*> m_queue;
    LOG_DEBUG("sizeof(m_queue) %d", m_queue.size_approx());
    while(true){
        while(true){
            bool ret= m_queue.try_enqueue(&a);
            if (ret){
                break;
            }
        }
        LOG_DEBUG("sizeof(m_queue) %d", m_queue.size_approx());
    }
    m_queue.enqueue(&b);
    LOG_DEBUG("sizeof(m_queue) %d", m_queue.size_approx());
    m_queue.enqueue(&c);
    LOG_DEBUG("sizeof(m_queue) %d", m_queue.size_approx());
    m_queue.wait_dequeue(pa);
    LOG_DEBUG("sizeof(m_queue) %d", m_queue.size_approx());
    m_queue.wait_dequeue(pb);
    LOG_DEBUG("sizeof(m_queue) %d", m_queue.size_approx());
    m_queue.wait_dequeue(pc);
    LOG_DEBUG("sizeof(m_queue) %d", m_queue.size_approx());
    LOG_DEBUG("*pa=%d, *pb=%d, *pc=%d", *pa, *pb, *pc);
}

#include <vector>
#include <list>
#include <deque>
#include<algorithm>

void f3(int value){
    cout << value << " ";
}

void test3(){
    vector<int> v1;
    int tt[] = {1, 3, 5, 5, 4 , 9, 2, 10, 12, 8};
    for(int i=0; i<10; i++){
        v1.push_back(tt[i]);
    }
    cout << "before sort" << endl;
    for_each(v1.begin(), v1.end(), [](int value){cout << value << " ";});
    cout << endl;
    cout << "after sort" << endl;
    //sort(v1.begin(), v1.end());
    sort(v1.begin(), v1.end(), [](int v1, int v2)->bool {
            if(v1>v2){
            return true;
            }else{
            return false;
            }
            });
    for_each(v1.begin(), v1.end(), [](int value){cout << value << " ";});
    cout << endl;
    cout << "end sort" << endl;
    std::reverse(v1.begin(), v1.begin()+5);
    for_each(v1.begin(), v1.end(), f3);

    LOG_DEBUG("test3: size=%d, capacity=%d", v1.size(), v1.capacity());
    v1.resize(5);
    LOG_DEBUG("test3: size=%d, capacity=%d", v1.size(), v1.capacity());
    v1.shrink_to_fit();
    LOG_DEBUG("test3: size=%d, capacity=%d", v1.size(), v1.capacity());

    list<int> l1;
    for(int i=0; i<10; i++){
        l1.push_back(i);
    }
    LOG_DEBUG("test3: l1_size=%ld, l1_capacity=%ld", l1.size(), l1.max_size());
    l1.resize(5);
    LOG_DEBUG("test3: l1_size=%ld, l1_capacity=%ld", l1.size(), l1.max_size());

    deque<int> d1;
    for(int i=0; i<10; i++){
        d1.push_back(i);
    }
    LOG_DEBUG("test3: d1_size=%ld, d1_capacity=%ld", d1.size(), d1.max_size());
    d1.resize(5);
    LOG_DEBUG("test3: d1_size=%ld, d1_capacity=%ld", d1.size(), d1.max_size());
}

int main()
{
    Logger::Instance().Init("xserver", DEBUG);
    LOG_DEBUG("begin main %s", "OK");
    //test3();
    //return 1;

    //DbConnManager::Instance().Init();
    RedisConnManager::Instance().Init();
    //SceneMgr::Instance().Init();
    //DataMgr::Instance().Init();
    WorkerManager::Instance().Start(10);
    AcceptManager::Instance().Start();
    SessionManager::Instance().Init();

    sigset_t signals;
    sigdelset(&signals, SIGHUP);
    sigdelset(&signals, SIGINT);
    sigdelset(&signals, SIGSEGV);
    sigdelset(&signals, SIGFPE);
    sigdelset(&signals, SIGABRT);
    sigdelset(&signals, SIGPIPE);
    sigdelset(&signals, SIGTERM);


    signal(SIGHUP, signalHandler);
    signal(SIGINT, signalHandler);
    signal(SIGSEGV, signalHandler);    // SIGSEGV，非法内存访问
    signal(SIGFPE, signalHandler);       // SIGFPE，数学相关的异常，如被0除，浮点溢出，等等
    signal(SIGABRT, signalHandler);     // SIGABRT，由调用abort函数产生，进程非正常退出
    signal(SIGPIPE, signalHandler);
    signal(SIGTERM, signalHandler);     // SIGTERM


    sigprocmask(SIG_BLOCK, &signals, NULL);


    while(true){
        sleep(3);
    }
    return 0;
}
