#ifndef _SESSION_MANAGER_H_
#define _SESSION_MANAGER_H_

#include <map>
#include "connection.h"
#include "activeconn.h"

#include "protobuf/msg_head.pb.h"

class SessionManager{
    public:
        static const int CLIENT = NetProto::MsgSrc::CLIENT;
        static const int MTS = NetProto::MsgSrc::MTS;
        static const int PW = NetProto::MsgSrc::PW;
        static const int CENTER = NetProto::MsgSrc::CENTER;
        static const int ACC = NetProto::MsgSrc::ACC;
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

            std::map<int, ActiveConn*>::iterator iter_active;
            for (iter_active =  m_mapActiveConns.begin(); iter_active != m_mapActiveConns.end(); ++iter_active){
                delete iter_active->second;
            }
        };

    public:
        static SessionManager& Instance();
        void Init();
        void AddConn(int socketfd, Connection* pConn);
        Connection* GetConn(int socketfd);

        void AddActiveConn(int conntype, ActiveConn* pConn);
        ActiveConn* GetActiveConn(int conntype);
        void RemoveConn(int socketfd);

    private:
        std::map<int, Connection*> m_mapConns;
        std::map<int, ActiveConn*> m_mapActiveConns;
        pthread_rwlock_t m_rwlock;    //声明读写锁
};
#endif /* _SESSION_MANAGER_H_ */
