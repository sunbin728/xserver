#ifndef _CLIENTCONN_H_
#define _CLIENTCONN_H_

#include "connection.h"

class ClientConn: public Connection{
    public:
        ClientConn(int fd, int conntype):Connection(fd, conntype){}
        virtual void DealMsg(MSG* msg);
};
#endif /*_CLIENTCONN_H_*/
