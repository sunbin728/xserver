#ifndef _SESSION_MANAGER_H_
#define _SESSION_MANAGER_H_

#include <map>

#include "connection.h"

class SessionManager{
    private:
        SessionManager(){
            pthread_rwlock_init(&m_rwlock, NULL);
        }
        SessionManager(const SessionManager &sessionManager);
        SessionManager& operator=(const SessionManager &sessionManager);
        ~SessionManager(){
            pthread_rwlock_destroy(&m_rwlock);      //销毁读写
            std::map<int, Connection*>::iterator iter;
            for (iter =  m_mapConns.begin(); iter != m_mapConns.end(); ++iter){
                delete iter->second;
            }
        };

    public:
        static SessionManager& Instance();
        void AddConn(int socketfd, Connection* pConn);
        Connection* GetConn(int socketfd);
        void RemoveConn(int socketfd);

    private:
        std::map<int, Connection*> m_mapConns;
        pthread_rwlock_t m_rwlock;    //声明读写锁
};
#endif /* _SESSION_MANAGER_H_ */
