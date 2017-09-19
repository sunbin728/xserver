#ifndef _ACTIVECONN_H_
#define _ACTIVECONN_H_

#include "connection.h"
#include <string>
#include "common/logger.h"
//#include "common/cache.h"
#include "base/package.h"
#include "queue/concurrentqueue.h"


class ActiveConn: public Connection{
    const static int MaxHeartBeatLen = 100;
    public:
    ActiveConn(int conntype, std::string addr, int port):Connection(0, conntype),
    m_addr(addr),
    m_port(port),
    m_valid(false),
    m_queue(),
    m_ptok(m_queue){
        pthread_rwlock_init(&m_rwlock, NULL);
    }
    virtual ~ActiveConn(){
        pthread_rwlock_destroy(&m_rwlock);      //销毁读写
    }
    ActiveConn(const ActiveConn &conn);
    ActiveConn& operator=(const ActiveConn &conn);
    std::string GetAddr(){return m_addr;}
    int GetPort(){
        return m_port;
    }
    bool GetValid(){
        pthread_rwlock_rdlock(&m_rwlock);    //读者加读锁
        return m_valid;
        pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    }

    bool SendHeartBeat();

    void SetValid(bool valid){
        LOG_DEBUG("ActiveConn::SetValid: valid=%d, m_addr=%s, m_port=%d", valid, m_addr.c_str(), m_port);
        pthread_rwlock_wrlock(&m_rwlock);      //写者加写锁
        m_valid = valid;
        pthread_rwlock_unlock(&m_rwlock);      //释放写锁
    }

    virtual void DoWork();
    void AddMsg(MSG* msg);
    bool Init();
    void initHeartBeatPkg();
    virtual void resetConn();
    virtual bool Send(const char* buf, int data_size);
    MSG* SendMsgAndRecv(uint16_t command, const ::google::protobuf::Message& msg);
    MSG* SendMsgAndRecv(uint16_t command, const std::ostringstream& msgstream);
    MSG* SendMsgAndRecv(const std::ostringstream& msgstream);
    void RecvMsg(MSG* msg);

    private:
    std::string m_addr;
    int m_port;
    bool m_valid;
    pthread_rwlock_t m_rwlock;    //声明读写锁
    std::ostringstream m_heartBeatStream;
    moodycamel::ConcurrentQueue<MSG*> m_queue;
    moodycamel::ProducerToken m_ptok;
    std::mutex m_mtx;
};
#endif /* _ACTIVECONN_H_ */
