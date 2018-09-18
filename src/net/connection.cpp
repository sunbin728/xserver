#include "connection.h"
#include <string.h>
#include "bizz/worker_manager.h"

#include "common/logger.h"
#include "common/util.h"
#include "common/common.h"

#include <arpa/inet.h>

Connection::Connection(int fd, int conntype):
    m_conntype(conntype),
    m_socketfd(fd),
    m_ringBuffer(NULL){
        m_ringBuffer = new RingBuffer(17);
        m_remoteAddr = GetAddressBySocket(m_socketfd);
    }

Connection::~Connection(){
    if (m_socketfd != 0){
        close(m_socketfd);
        LOG_DEBUG("Connection::~Connection close m_socketfd:%d", m_socketfd);
    }
    if (NULL != m_ringBuffer){
        delete m_ringBuffer;
        m_ringBuffer = NULL;
    }
}

void Connection::DoWork(){
    //LOG_DEBUG("Connection::DoWork");
    MSG* msg = NULL;
    // TODO:  优化buf的移动
    while((msg = package::ReadMsg((char*)m_ringBuffer->ReadAddress(), m_ringBuffer->CountBytes()))!=NULL){
        m_ringBuffer->ReadAdvance(msg->size);
        msg->socketfd = m_socketfd;
        msg->connType = m_conntype;
        msg->pConn = this;
        DealMsg(msg);
    }
}

void Connection::ResetConn(){
    if (m_socketfd != 0){
        close(m_socketfd);
        LOG_DEBUG("Connection::resetConn close m_socketfd:%d", m_socketfd);
    }
}

bool Connection::SendMsg(uint16_t command, const rapidjson::Document& docMsg){
    bool ret = Connection::SendMsg(m_socketfd, command, docMsg);
    if (ret){
        LOG_INFO("Connection::SendMsg success: fd=%d, remoteAddr=%s", m_socketfd, m_remoteAddr.c_str());
    }else{
        LOG_ERROR("Connection::SendMsg fail: fd=%d, remoteAddr=%s", m_socketfd, m_remoteAddr.c_str());
    }
    return ret;
}

/////////////static member//////////////////////////
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
        LOG_DEBUG("Connection::SendMsg success: fd=%d, data_size=%d, PkgLen=%d, CheckSum=%d, Target=%d, Command=%d, Retcode=%d",
                socketfd, msgsize, header.PkgLen, header.CheckSum, header.Target, header.Command, header.Retcode);
    }else{
        LOG_ERROR("Connection::SendMsg fail: fd=%d, data_size=%d, PkgLen=%d, CheckSum=%d, Target=%d, Command=%d, Retcode=%d",
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

//通过套接字获取IP、Port等地址信息
string Connection::GetAddressBySocket(int socketfd)
{
    struct sockaddr_in rsa;
    socklen_t  rsa_len = sizeof(struct sockaddr_in);
    if(getpeername(socketfd, (struct sockaddr *)&rsa, &rsa_len) == 0){
        char ip[20];//保存点分十进制的地址
        memset(ip, 0, 20);
        inet_ntop(AF_INET, &rsa.sin_addr, ip, sizeof(ip));
        int port = ntohs(rsa.sin_port);
        std::ostringstream buffer;
        buffer<<ip<<":"<<port;
        return buffer.str();
    }
    return "";
}
///////////////////////////////////////

