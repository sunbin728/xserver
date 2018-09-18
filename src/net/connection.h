#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include <unistd.h>
#include <sstream>
#include <string>

#include "base/package.h"
#include "ringbuffer.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;
using namespace std;

class Connection{
    public:
        static bool Send(int socketfd, const char* buf, int size);
        static bool SendMsg(int socketfd, uint16_t command, const rapidjson::Document& docMsg);
        static string GetAddressBySocket(int socketfd);

    public:
        Connection(int fd, int conntype);
        virtual ~Connection();
        Connection(const Connection &conn);
        Connection& operator=(const Connection &conn);

        int GetConnType(){return m_conntype;}
        void SetConnType(int conntype){ m_conntype=conntype;}
        int GetSocketfd(){return m_socketfd;}

        char* GetWriteBuffer(){ return (char*)m_ringBuffer->WriteAddress();}
        int GetWriteSize(){ return m_ringBuffer->CountFreeBytes();}
        void WriteAdvance(int wPos){m_ringBuffer->WriteAdvance(wPos);}

        void DoWork();
        bool SendMsg(uint16_t command, const rapidjson::Document& docMsg);

        virtual void DealMsg(MSG* msg)=0;

    protected:
        virtual void ResetConn();

    protected:
        int m_conntype;
        int m_socketfd;
        std::string m_remoteAddr;
        RingBuffer* m_ringBuffer;
};
#endif /* _CONNECTION_H_ */
