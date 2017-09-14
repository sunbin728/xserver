#ifndef _ACTIVECONN_H_
#define _ACTIVECONN_H_

#include "connection.h"
#include <string>

class ActiveConn: public Connection{
    public:
        ActiveConn(int conntype, std::string addr, int port):Connection(0, conntype),
        m_addr(addr),
        m_port(port),
        m_valid(false){
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

        void SetValid(bool valid){
            pthread_rwlock_wrlock(&m_rwlock);      //写者加写锁
            m_valid = valid;
            pthread_rwlock_unlock(&m_rwlock);      //释放写锁
        }

        bool Init();
        virtual bool SendMsg(uint16_t command, const std::ostringstream& msgstream);

    private:
        std::string m_addr;
        int m_port;
        bool m_valid;
        pthread_rwlock_t m_rwlock;    //声明读写锁
};
#endif /* _ACTIVECONN_H_ */
