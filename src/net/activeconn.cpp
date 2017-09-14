#include "activeconn.h"
#include <memory.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>

#include "common/logger.h"

bool ActiveConn::Init(){
    resetConn();
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
        return true;
    }else{
        return false;
    }
}

bool ActiveConn::SendMsg(uint16_t command, const std::ostringstream& msgstream){
    bool ret = Connection::SendMsg(command, msgstream);
    if (!ret){
        SetValid(false);
    }
    return ret;
}
