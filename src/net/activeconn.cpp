#include "activeconn.h"
#include <memory.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>

#include "common/logger.h"
#include "common/util.h"
#include "base/package.h"
#include "base/command.h"
#include "bizz/dealpw.h"
#include "protobuf/command_type.pb.h"
#include "protobuf/gs_2_pw.pb.h"

using namespace NetProto;

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
        LOG_INFO("ActiveConn::Init ok: m_socketfd=%d, m_addr=%s, m_port=%d", m_socketfd, m_addr.c_str(), m_port);
        return true;
    }else{
        LOG_ERROR("ActiveConn::Init fail: m_socketfd=%d, m_addr=%s, m_port=%d", m_socketfd, m_addr.c_str(), m_port);
        return false;
    }
}

void ActiveConn::resetConn(){
    Connection::resetConn();
    MSG* msg=NULL;
    while(m_queue.size_approx()!=0){
        while(m_queue.try_dequeue(msg)){
            delete msg;
        }
    }
}

void ActiveConn::DoWork(){
    LOGDEBUG("Connection::DoWork");
    MSG* msg = new MSG();
    if (package::ReadMsg(m_buf, m_wPos-m_rPos, msg)){
        m_rPos += msg->size;
        memcpy(m_buf, m_buf+m_rPos, m_wPos-m_rPos);
        m_wPos = m_wPos - m_rPos;
        m_rPos = 0;

        msg->socketfd = m_socketfd;
        AddMsg(msg);
    }
}

void ActiveConn::AddMsg(MSG* msg){
    m_queue.enqueue(m_ptok, msg);
    LOG_DEBUG("ActiveConn::AddMsg conntype=%d, queuesize=%d, msg->size=%d, PkgLen=%d, Command=%d, Target=%d, Retcode=%d",
            m_conntype, m_queue.size_approx(), msg->size, msg->header->PkgLen, msg->header->Command,
            msg->header->Target, msg->header->Retcode);
}

MSG* ActiveConn::SendMsgAndRecv(uint16_t command, const ::google::protobuf::Message& msg){
    std::lock_guard<std::mutex> mtx_locker(m_mtx);
    bool ret = Connection::SendMsg(command, msg);
    MSG* recv_msg = NULL;
    if (ret){
        RecvMsg(recv_msg);
    }
    return recv_msg;
}

MSG* ActiveConn::SendMsgAndRecv(uint16_t command, const std::ostringstream& msgstream){
    std::lock_guard<std::mutex> mtx_locker(m_mtx);
    bool ret = Connection::SendMsg(command, msgstream);
    MSG* recv_msg = NULL;
    if (ret){
        RecvMsg(recv_msg);
    }
    return recv_msg;
}

MSG* ActiveConn::SendMsgAndRecv(const std::ostringstream& msgstream){
    std::lock_guard<std::mutex> mtx_locker(m_mtx);
    bool ret = Connection::SendMsg(msgstream);
    MSG* recv_msg = NULL;
    if (ret){
        RecvMsg(recv_msg);
    }
    return recv_msg;
}

void ActiveConn::RecvMsg(MSG* &msg){
    LOG_ERROR("ActiveConn::RecvMsg begin: conntype=%d", m_conntype);
    while (!m_queue.try_dequeue_from_producer(m_ptok, msg)){
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    LOG_DEBUG("ActiveConn::RecvMsg end: conntype=%d, queuesize=%d, msg->size=%d, PkgLen=%d, Command=%d, Target=%d, Retcode=%d",
            m_conntype, m_queue.size_approx(), msg->size, msg->header->PkgLen, msg->header->Command,
            msg->header->Target, msg->header->Retcode);
}

bool ActiveConn::Send(const char* buf, int data_size){
    if (!GetValid()){
        LOG_ERROR("ActiveConn::Send GetValid is false: conntype=%d", m_conntype);
        return false;
    }else{
        bool ret = Connection::Send(buf, data_size);
        if (!ret){
            SetValid(false);
        }
        return ret;
    }
}

void ActiveConn::initHeartBeatPkg(){
    uint16_t command = NetProto::GS2PW_Keep_Alive;
    HEAD header;
    //header.PkgLen = 0;
    header.CheckSum = 0;
    header.Target = m_conntype;
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
    MSG* msg = SendMsgAndRecv(m_heartBeatStream);

    if (NULL != msg){
        gs2pw::ServerKeepAliveResp pw2gsKeepAliveResp;
        pw2gsKeepAliveResp.ParseFromArray(msg->GetProtobuf(), msg->GetProtobufLen());
        bizz::PW2GSKeepAliveRespHandle(msg, pw2gsKeepAliveResp);
        delete msg;
        return true;
    }else{
        return false;
    }
}
