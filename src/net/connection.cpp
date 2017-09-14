#include "connection.h"
#include "base/package.h"
#include <string.h>
#include "bizz/worker_manager.h"

#include "common/logger.h"


void Connection::DoWork(){
    LOGDEBUG("Connection::DoWork");
    MSG* msg = new MSG();
    if (package::ReadMsg(m_buf, m_wPos-m_rPos, msg)){
        m_rPos += msg->size;
        memcpy(m_buf, m_buf+m_rPos, m_wPos-m_rPos);
        m_wPos = m_wPos - m_rPos;
        m_rPos = 0;

        msg->socketfd = m_socketfd;
        WorkerManager::Instance().DealMsg(msg);
    }
}

void Connection::resetConn(){
    if (m_socketfd != 0){
        close(m_socketfd);
    }
    m_rPos = 0;
    m_wPos = 0;
}

bool Connection::SendMsg(uint16_t command, const std::ostringstream& msgstream){
    std::string msgstring = msgstream.str();
    HEAD header;
    header.PkgLen = msgstring.length()+10;
    header.CheckSum = 0;
    header.Target = 1;
    header.Command = command;
    header.Retcode = 0;

    int msgsize = sizeof(header)+msgstream.str().length();
    char* msg = (char*)malloc(msgsize);
    memcpy(msg, &header, sizeof(header));
    memcpy(msg+sizeof(header), msgstring.c_str(), msgstring.length());

    LOG_INFO("Connection::SendMsg: fd=%d, data_size=%d, PkgLen=%d, CheckSum=%d, Target=%d, Command=%d, Retcode=%d",
            m_socketfd, msgsize, header.PkgLen, header.CheckSum, header.Target, header.Command, header.Retcode);
    bool ret = Send(msg, msgsize);
    free(msg);
    return ret;
}


bool Connection::Send(const char* buf, int data_size){
    LOG_INFO("Connection::Send begin: fd=%d, data_size=%d", m_socketfd, data_size);
    int nwrite;
    int n = data_size;
    while (n > 0) {
        nwrite = write(m_socketfd, buf + data_size - n, n);
        if (nwrite < n) {
            if (nwrite == -1 && errno != EAGAIN) {
                LOG_ERROR("Connection::Send write fail: fd=%d, nwrite=%d, errno=%d", m_socketfd, nwrite, errno);
                return false;
            }
        }
        n -= nwrite;
    }
    LOG_INFO("Connection::Send ok: fd=%d, data_size=%d", m_socketfd, data_size);
    return true;
}

