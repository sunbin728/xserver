#include "activeconn.h"
#include <memory.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>

#include "common/logger.h"
#include "base/package.h"
#include "base/command.h"
#include "protobuf/command_type.pb.h"
#include "protobuf/gs_2_pw.pb.h"
#include "common/logger.h"

bool ActiveConn::Init(){
    initHeartBeatPkg();
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

bool ActiveConn::Send(const char* buf, int size){
    bool ret = Connection::Send(buf, size);
    if (!ret){
        SetValid(false);
    }
    return ret;
}

void ActiveConn::initHeartBeatPkg(){
    uint16_t command = NetProto::GS2PW_Keep_Alive;
    HEAD header;
    //header.PkgLen = 0;
    header.CheckSum = 0;
    header.Target = 1;
    header.Command = command;
    header.Retcode = 0;

    std::stringstream heartBeatStream_body;
    NetProto::gs2pw::ServerKeepAliveReq msg;
    msg.set_gs_id(1);
    msg.SerializeToOstream(&heartBeatStream_body);

    header.PkgLen = heartBeatStream_body.str().length()+10;
    m_heartBeatStream << header << heartBeatStream_body.rdbuf();
}

bool ActiveConn::SendHeartBeat(){
    if (m_conntype != PW ){
        return true;
    }
    LOG_DEBUG("ActiveConn::SendHeartBeat: conntype=%d", m_conntype);
    return SendMsg(m_heartBeatStream);
}
