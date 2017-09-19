#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "net/connection.h"

class Client{
    public:
        Client(int uid, Connection* pConn):
            m_uid(uid),
            m_pConn(pConn){
        }
        Client(const Client &client);
        Client& operator=(const Client &client);
        ~Client(){
        };

    private:
        int m_uid;
        Connection* m_pConn;
};
#endif /* _CLIENT_H_ */
