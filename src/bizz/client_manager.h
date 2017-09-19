#ifndef _CLIENT_MANAGER_H_
#define _CLIENT_MANAGER_H_

#include <map>
#include "net/connection.h"


class ClientManager{
    private:
        ClientManager(){
            pthread_rwlock_init(&m_rwlock, NULL);
        }
        ClientManager(const ClientManager &clientManager);
        ClientManager& operator=(const ClientManager &clientManager);
        ~ClientManager();

    public:
        static ClientManager& Instance();
        void AddConn(int uid, Connection* pConn);
        Connection* GetConn(int uid);
        void RemoveConn(int uid);

    private:
        std::map<int, Connection*> m_mapConns;
        pthread_rwlock_t m_rwlock;    //声明读写锁
};
#endif /* _CLIENT_MANAGER_H_ */
