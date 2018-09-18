#include <string>
#include "../common/util.h"
#include "../base/package.h"

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <memory>
#include <sstream>
#include <thread>

#include <openssl/ssl.h>
#include <openssl/err.h>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;
using namespace std;

class Client{
    public:
        Client(string addr, int port):
            m_addr(addr),
            m_port(port),
            m_ctx(nullptr),
            m_ssl(nullptr){}

        ~Client(){
            if (m_ssl!=nullptr){
                /* 关闭连接 */
                SSL_shutdown(m_ssl);
                SSL_free(m_ssl);
            }
            if (0!=m_socketfd){
                close(m_socketfd);
            }
            if (m_ctx!=nullptr){
                SSL_CTX_free(m_ctx);

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
                printf("connect ok\n");
                StartWorker();
                return true;
            }else{
                printf("connect fail: errno=%d, m_addr=%s, m_port=%d", errno, m_addr.c_str(), m_port);
                return false;
            }
        }

        void ShowCerts(SSL * ssl)
        {
            X509 *cert;
            char *line;

            cert = SSL_get_peer_certificate(ssl);
            if (cert != NULL) {
                printf("Digital certificate information:\n");
                line = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);
                printf("Certificate: %s\n", line);
                free(line);
                line = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0);
                printf("Issuer: %s\n", line);
                free(line);
                X509_free(cert);
            }
            else
                printf("No certificate information！\n");
        }

        bool InitConn_TLS(){
            /* SSL 库初始化 */
            SSL_library_init();
            OpenSSL_add_all_algorithms();
            SSL_load_error_strings();
            m_ctx = SSL_CTX_new(SSLv23_client_method());
            if (m_ctx == NULL)
            {
                ERR_print_errors_fp(stdout);
                exit(1);
            }

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
                /* 基于 ctx 产生一个新的 SSL */
                m_ssl = SSL_new(m_ctx);
                SSL_set_fd(m_ssl, m_socketfd);
                /* 建立 SSL 连接 */
                if (SSL_connect(m_ssl) == -1)
                    ERR_print_errors_fp(stderr);
                else
                {
                    printf("Connected with %s encryption\n", SSL_get_cipher(m_ssl));
                    ShowCerts(m_ssl);
                }

                StartWorker();
                return true;
            }else{
                printf("connect fail: errno=%d, m_addr=%s, m_port=%d", errno, m_addr.c_str(), m_port);
                return false;
            }
        }

        void StartWorker(){
            thread recvWorker(&Client::RecvWorker,this);
            recvWorker.detach();

            thread sendWorker(&Client::SendWorker,this);
            sendWorker.detach();
        }


        bool SendMsg(uint16_t command, const rapidjson::Document& msg){
            StringBuffer buffer;
            Writer<StringBuffer> writer(buffer);
            msg.Accept(writer);
            return SendMsg(command, string(buffer.GetString(), buffer.GetSize()));
        }

        bool SendMsg(uint16_t command, const string& msgstring){
            printf("SendMsg: msg=%s\n", msgstring.c_str());
            HEAD header;
            header.PkgLen = msgstring.length()+10;
            header.CheckSum = 0;
            header.Target = 4;
            header.Command = command;
            header.Retcode = 0;

            int msgsize = sizeof(header)+msgstring.length();
            char* msg = (char*)malloc(msgsize);
            memcpy(msg, &header, sizeof(header));
            memcpy(msg+sizeof(header), msgstring.c_str(), msgstring.length());

            printf("Connection::SendMsg: fd=%d, data_size=%d, PkgLen=%d, CheckSum=%d, Target=%d, Command=%d, Retcode=%d\n",
                    m_socketfd, msgsize, header.PkgLen, header.CheckSum, header.Target, header.Command, header.Retcode);
            bool ret = Send(msg, msgsize);
            free(msg);
            return ret;
        }

        bool Send(const char* buf, int data_size){
            printf("send data_size=%d\n", data_size);
            int nwrite;
            int n = data_size;
            while (n > 0) {
                if (m_ssl != nullptr){
                    nwrite = SSL_write(m_ssl, buf + data_size - n, n);
                }else{
                    nwrite = write(m_socketfd, buf + data_size - n, n);
                }
                if (nwrite < n) {
                    if (nwrite == -1 && errno != EAGAIN) {
                        printf("Connection::Send write fail: fd=%d, nwrite=%d, errno=%d\n", m_socketfd, nwrite, errno);
                        return false;
                    }
                }
                n -= nwrite;
            }
            printf("Connection::Send ok: fd=%d, data_size=%d\n", m_socketfd, data_size);
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
                if (m_ssl != nullptr){
                    nread = SSL_read(m_ssl, buf + readed, size-readed);
                }else{
                    nread = read(m_socketfd, buf + readed, size-readed);
                }
                readed+=nread;
            }
            assert(readed == size);
        }

        void SendWorker(){
            printf("SendWorker\n");
            while(true){
                Document req;
                req.SetObject();
                req.AddMember("nowTime", 5555, req.GetAllocator());
                SendMsg(9999, req);
                sleep(5);
            }
        }

        void RecvWorker(){
            printf("RecvWorker\n");
            while(true){
                auto msg = RecvMsg();
                printf("Recv:%s\n", string(msg->GetDataPtr(), msg->GetDataLen()).c_str());
            }
        }

    public:
        string m_addr;
        int m_port;
        int m_socketfd;
        SSL_CTX *m_ctx;
        SSL *m_ssl;
};

int main(){
    //TCP
    //Client c("172.16.0.19", 1234);
    //c.InitConn();

    //TLS
    Client c("172.16.0.19", 11234);
    c.InitConn_TLS();

    sleep(100000);
    return 0;
}
