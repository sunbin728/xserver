#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include <unistd.h>
#include <sstream>

#include "ringbuffer.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

class Connection{
    static const int MAXBUF = 1 * 1024;
    public:
    static bool Send(int socketfd, const char* buf, int size);
    static bool SendMsg(int socketfd, uint16_t command, const rapidjson::Document& docMsg);

    public:
    Connection(int fd, int conntype):
        m_conntype(conntype),
        m_socketfd(fd),
        //m_buf(NULL),
        //m_sendbuf(NULL),
        m_rPos(0),
        m_wPos(0),
        m_ringBuffer(NULL){
            //m_buf = new char[MAXBUF];
            //m_sendbuf = new char[MAXBUF];
            m_ringBuffer = new RingBuffer(17);
        }
    virtual ~Connection();
    Connection(const Connection &conn);
    Connection& operator=(const Connection &conn);

    int GetConnType(){return m_conntype;}
    int GetSocketfd(){return m_socketfd;}

    //char* GetWriteBuffer(){ return m_buf + m_wPos;}
    //int GetWriteSize(){ return MAXBUF-m_wPos;}
    //void WriteAdvance(int wPos){m_wPos += wPos;}

    char* GetWriteBuffer(){ return (char*)m_ringBuffer->WriteAddress();}
    int GetWriteSize(){ return m_ringBuffer->CountFreeBytes();}
    void WriteAdvance(int wPos){m_ringBuffer->WriteAdvance(wPos);}

    bool SendMsg(uint16_t command, const std::ostringstream& msgstream);
    bool SendMsg(const std::ostringstream& msgstream);
    virtual bool Send(const char* buf, int size);
    virtual void DoWork();

    protected:
    virtual void resetConn();

    protected:
    int m_conntype;
    int m_socketfd;
    //char* m_buf;
    //char* m_sendbuf;
    int m_rPos;
    int m_wPos;
    RingBuffer* m_ringBuffer;
};
#endif /* _CONNECTION_H_ */
