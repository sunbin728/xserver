#ifndef _SESSION_MANAGER_H_
#define _SESSION_MANAGER_H_

#include <map>
#include "connection.h"
#include "activeconn.h"

class SessionManager{
    private:
        SessionManager(){
            pthread_rwlock_init(&m_rwlock, NULL);
        }
        SessionManager(const SessionManager &sessionManager);
        SessionManager& operator=(const SessionManager &sessionManager);
        ~SessionManager();

        void initActiveConnect(int conntype, std::string addr, int port);
        void reInitActiveConnect(ActiveConn* activeConn);
        void watchWork();
    public:
        static SessionManager& Instance();
        //初始化需主动连接的部分
        void Init();
        void Destroy();

        void AddConn(int socketfd, Connection* pConn);
        Connection* GetConn(int socketfd);
        void RemoveConn(int socketfd);

        void AddActiveConn(int conntype, ActiveConn* pConn);
        ActiveConn* GetActiveConn(int conntype);

        bool SendMsg(int conntype,uint16_t command, const std::ostringstream& msgstream);

        std::shared_ptr<MSG> SendMsgAndRecv(int conntype,uint16_t command, const std::ostringstream& msgstream);

    private:
        std::map<int, Connection*> m_mapConns;
        std::map<int, ActiveConn*> m_mapActiveConns;
        pthread_rwlock_t m_rwlock;    //声明读写锁
};
#endif /* _SESSION_MANAGER_H_ */
