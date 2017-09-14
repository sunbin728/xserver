#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include <unistd.h>
#include <sstream>

class Connection{
    static const int MAXBUF = 100 * 1024;
    public:
    Connection(int fd, int conntype):
        m_conntype(conntype),
        m_socketfd(fd),
        m_buf(NULL),
        m_rPos(0),
        m_wPos(0){
            m_buf = new char[MAXBUF];
        }
    ~Connection(){
        close(m_socketfd);
        if (NULL != m_buf){
            delete[] m_buf;
            m_buf = NULL;
        }
    }
    Connection(const Connection &conn);
    Connection& operator=(const Connection &conn);

    int GetConnType(){return m_conntype;}
    int GetSocketfd(){return m_socketfd;}
    char* GetWriteBuffer(){ return m_buf + m_wPos;}
    void SetWPos(int wPos){m_wPos += wPos;}


    bool SendMsg(uint16_t command, const std::ostringstream& msgstream);
    bool Send(const char* buf, int size);
    void DoWork();

    private:
    int m_conntype;
    int m_socketfd;
    char* m_buf;
    int m_rPos;
    int m_wPos;
};
#endif /* _CONNECTION_H_ */
