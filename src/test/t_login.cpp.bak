#include <string>
#include "../common/logger.h"
#include "../common/util.h"
#include "../base/package.h"

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>

#include <google/protobuf/message.h>


using namespace std;

class Client{
    public:
        Client(string addr, int port):
            m_addr(addr),
            m_port(port){}

        ~Client(){
            if (0!=m_socketfd){
                close(m_socketfd);
            }
        }
        bool InitConn(){
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
                LOG_INFO("connect ok");
                return true;
            }else{
                LOG_FATAL("connect fail: errno=%d, m_addr=%s, m_port=%d", errno, m_addr.c_str(), m_port);
                return false;
            }
        }

        bool SendMsg(uint16_t command, const ::google::protobuf::Message& msg){
            std::ostringstream data;
            msg.SerializeToOstream(&data);
            return SendMsg(command, data);
        }

        bool SendMsg(uint16_t command, const std::ostringstream& msgstream){
            std::string msgstring = msgstream.str();
            HEAD header;
            header.PkgLen = msgstring.length()+10;
            header.CheckSum = 0;
            header.Target = 4;
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

        bool SendMsg(const std::ostringstream& msgstream){
            bool ret = Send(msgstream.str().c_str(), msgstream.str().length());
            return ret;
        }

        bool Send(const char* buf, int data_size){
            std::string datastr_dec = util::ToDecString(buf, data_size);
            LOG_INFO("Connection::Send begin: fd=%d, data_size=%d, data=%s", m_socketfd, data_size, datastr_dec.c_str());

            std::string datastr_hex = util::ToHexString(buf, data_size);
            LOG_INFO("Connection::Send begin: fd=%d, data_size=%d, data=%s", m_socketfd, data_size, datastr_hex.c_str());
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

        std::shared_ptr<MSG> RecvMsg(){
            std::shared_ptr<MSG> msg = std::shared_ptr<MSG>(new MSG());
            HEAD head;
            int sizehead = sizeof(head);
            char* buf = (char*)(&head);
            RecvFull(buf, sizehead);
            msg->header=(HEAD*)malloc(sizehead+head.PkgLen-10);
            memcpy(msg->header, &head, sizehead);
            RecvFull((char*)msg->header+sizehead, head.PkgLen-10);
            return msg;
        }

        void RecvFull(char* buf, int size){
            int readed = 0;
            int nread = 0;
            while (readed < size){
                nread = read(m_socketfd, buf + readed, size-readed);
                readed+=nread;
            }
            assert(readed == size);
        }

    public:
        string m_addr;
        int m_port;
        int m_socketfd;
};

int main(){
    Client c("172.16.3.17", 11234);
    c.InitConn();
    C2GSLogin c2gsLogin;
    c2gsLogin.set_accountid(100001);
    c.SendMsg(C2GS_LOGIN,c2gsLogin);
    std::shared_ptr<MSG> sp_recvmsg = c.RecvMsg();

    GS2CLogin gs2cLogin;
    gs2cLogin.ParseFromArray(sp_recvmsg->GetProtobuf(), sp_recvmsg->GetProtobufLen());
    LOG_INFO("gs2cLogin=%s", gs2cLogin.DebugString().c_str());
    sleep(100000);
    return 0;
}
