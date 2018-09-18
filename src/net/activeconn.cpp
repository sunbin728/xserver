#include "activeconn.h"
#include <memory.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>

#include "bizz/worker_manager.h"
#include "common/logger.h"
#include "base/command.h"


bool ActiveConn::Init(){
    ResetConn();
    //创建套接字
    m_socketfd = socket(AF_INET, SOCK_STREAM, 0);
    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr(m_addr.c_str());  //具体的IP地址
    serv_addr.sin_port = htons(m_port);  //端口
    int ret = connect(m_socketfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    if (0 == ret){
        SetValid(true);
        m_remoteAddr = GetAddressBySocket(m_socketfd);
        LOG_INFO("ActiveConn::Init ok: m_socketfd=%d, m_addr=%s, m_port=%d", m_socketfd, m_addr.c_str(), m_port);
        return true;
    }else{
        LOG_ERROR("ActiveConn::Init fail: errno=%d, m_socketfd=%d, m_addr=%s, m_port=%d",
                errno, m_socketfd, m_addr.c_str(), m_port);
        return false;
    }
}

void ActiveConn::DealMsg(MSG* msg){
    WorkerManager::Instance().DealServerMsg(msg);
}

