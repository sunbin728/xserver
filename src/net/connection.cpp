#include "connection.h"
#include "base/package.h"
#include <string.h>
#include "bizz/worker_manager.h"

#include "common/logger.h"
#include "common/util.h"

Connection::~Connection(){
    if (m_socketfd != 0){
        close(m_socketfd);
        LOG_DEBUG("Connection::~Connection close m_socketfd:%d", m_socketfd);
    }
    //if (NULL != m_buf){
    //delete[] m_buf;
    //m_buf = NULL;
    //}
    //if (NULL != m_sendbuf){
    //delete[] m_sendbuf;
    //m_sendbuf = NULL;
    //}
    if (NULL != m_ringBuffer){
        delete m_ringBuffer;
        m_ringBuffer = NULL;
    }
}

//void Connection::DoWork(){
//LOG_DEBUG("Connection::DoWork");
//MSG* msg = NULL;
//// TODO:  优化buf的移动
//int dataSize =  m_wPos-m_rPos;
//while((msg = package::ReadMsg(m_buf, dataSize))!=NULL){
//m_rPos += msg->size;
//msg->socketfd = m_socketfd;
//WorkerManager::Instance().DealMsg(msg);
//dataSize =  m_wPos-m_rPos;
//}
//if (m_rPos!=0){
//memcpy(m_buf, m_buf+m_rPos, m_wPos-m_rPos);
//m_wPos = m_wPos - m_rPos;
//m_rPos = 0;
//}
//}

void Connection::DoWork(){
    LOG_DEBUG("Connection::DoWork");
    MSG* msg = NULL;
    // TODO:  优化buf的移动
    while((msg = package::ReadMsg((char*)m_ringBuffer->ReadAddress(), m_ringBuffer->CountBytes()))!=NULL){
        m_ringBuffer->ReadAdvance(msg->size);
        msg->socketfd = m_socketfd;
        WorkerManager::Instance().DealMsg(msg);
    }
}

void Connection::resetConn(){
    if (m_socketfd != 0){
        close(m_socketfd);
        LOG_DEBUG("Connection::resetConn close m_socketfd:%d", m_socketfd);
    }
    m_rPos = 0;
    m_wPos = 0;
}

bool Connection::SendMsg(uint16_t command, const std::ostringstream& msgstream){
    std::string msgstring = msgstream.str();
    HEAD header;
    header.PkgLen = msgstring.length()+10;
    header.CheckSum = 0;
    header.Target = m_conntype;
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

bool Connection::SendMsg(const std::ostringstream& msgstream){
    bool ret = Send(msgstream.str().c_str(), msgstream.str().length());
    return ret;
}


bool Connection::Send(const char* buf, int data_size){
    return Connection::Send(m_socketfd, buf, data_size);
}

bool Connection::SendMsg(int socketfd, uint16_t command, const rapidjson::Document& docMsg){
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    docMsg.Accept(writer);

    HEAD header;
    header.PkgLen = buffer.GetSize()+10;
    header.CheckSum = 0;
    header.Target = 0;
    header.Command = command;
    header.Retcode = 0;

    int msgsize = sizeof(header)+buffer.GetSize();
    char* msg = (char*)malloc(msgsize);
    memcpy(msg, &header, sizeof(header));
    memcpy(msg+sizeof(header), buffer.GetString(), buffer.GetSize());

    bool ret = Connection::Send(socketfd, msg, msgsize);
    if (ret){
        LOG_INFO("Connection::SendMsg success: fd=%d, data_size=%d, PkgLen=%d, CheckSum=%d, Target=%d, Command=%d, Retcode=%d",
                socketfd, msgsize, header.PkgLen, header.CheckSum, header.Target, header.Command, header.Retcode);
    }else{
        LOG_INFO("Connection::SendMsg success: fd=%d, data_size=%d, PkgLen=%d, CheckSum=%d, Target=%d, Command=%d, Retcode=%d",
                socketfd, msgsize, header.PkgLen, header.CheckSum, header.Target, header.Command, header.Retcode);
    }
    free(msg);
    return ret;
}

bool Connection::Send(int socketfd, const char* buf, int data_size){
    //std::string datastr_dec = util::ToDecString(buf, data_size);
    //LOG_INFO("Connection::Send begin: fd=%d, data_size=%d, data=%s", m_socketfd, data_size, datastr_dec.c_str());

    //std::string datastr_hex = util::ToHexString(buf, data_size);
    //LOG_INFO("Connection::Send begin: fd=%d, data_size=%d, data=%s", m_socketfd, data_size, datastr_hex.c_str());
    int nwrite;
    int n = data_size;
    while (n > 0) {
        nwrite = write(socketfd, buf + data_size - n, n);
        if (nwrite < n) {
            if (nwrite == -1 && errno != EAGAIN) {
                LOG_ERROR("Connection::Send write fail: fd=%d, nwrite=%d, errno=%d", socketfd, nwrite, errno);
                return false;
            }
        }
        n -= nwrite;
    }
    return true;
}
