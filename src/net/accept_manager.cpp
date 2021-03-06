#include "accept_manager.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <thread>
#include <stdio.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "base/command.h"
#include "common/logger.h"
#include "connection.h"
#include "clientconn.h"
#include "session_manager.h"


typedef int SOCKET;
#define MESS_SIZE 1024 * 1024
#define MAX_EVENTS 100000

//设置socket连接为非阻塞模式
void setnonblocking(int sockfd)
{
    int opts;
    opts=fcntl(sockfd,F_GETFL);
    if(opts<0)
    {
        LOG_FATAL("fcntl(sockfd,GETFL) fail: socket=%d", sockfd);
    }
    opts = opts|O_NONBLOCK;
    if(fcntl(sockfd,F_SETFL,opts)<0)
    {
        LOG_FATAL("fcntl(sockfd,SETFL,opts) fail: socket=%d, opts=%d", sockfd, opts);
    }
}

AcceptManager& AcceptManager::Instance(){
    static AcceptManager acceptManager;
    return acceptManager;
}

void AcceptManager::Stop(){
    m_start= false;
    while(m_working){
        LOG_INFO("AcceptManager::Stoping");
        sleep(1);
    }
    SessionManager::Instance().Destroy();
    close(m_listenfd);
    close(m_epfd);
    LOG_INFO("AcceptManager::Stop");
}

void AcceptManager::Start(){
    std::thread thrd_accept(&AcceptManager::StartET, this);
    //std::thread thrd_accept(&AcceptManager::StartLT, this);
    thrd_accept.detach();
}

bool AcceptManager::AddEvent(int conn_sock){
    struct epoll_event ev;
    setnonblocking(conn_sock);
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = conn_sock;
    if (epoll_ctl(m_epfd, EPOLL_CTL_ADD, conn_sock,
                &ev) == -1) {
        LOG_FATAL("AcceptManager::AddEvent epoll_ctl EPOLL_CTL_ADD fail: errno=%d, conn_sock=%d", errno, conn_sock);
        return false;
    }
    return true;
}

void AcceptManager::StartET(){
    struct epoll_event ev, events[MAX_EVENTS];
    int conn_sock, nfds, fd, i, nread, n;
    char* buf=0;
    socklen_t  addrlen;
    const int trueFlag = 1;

    //IPV4 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct sockaddr_in local, remote;
    if (m_listenNet == 1 || m_listenNet==4)
    {
        //创建listen socket
        if( (m_listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            LOG_FATAL("AcceptManager::StartET socket fail");
        }
        if (setsockopt(m_listenfd, SOL_SOCKET, SO_REUSEADDR, &trueFlag, sizeof(int)) < 0){
            LOG_FATAL("AcceptManager::StartET setsockopt SO_REUSEADDR fail");
        }
        if (setsockopt(m_listenfd, SOL_SOCKET, SO_REUSEPORT, &trueFlag, sizeof(int)) < 0){
            LOG_FATAL("AcceptManager::StartET setsockopt SO_REUSEADDR fail");
        }
        setnonblocking(m_listenfd);
        bzero(&local, sizeof(local));
        local.sin_family = AF_INET;
        this->m_addr = "";
        if (this->m_addr == ""){
            local.sin_addr.s_addr = htonl(INADDR_ANY);
        }else{
            local.sin_addr.s_addr = inet_addr(this->m_addr.c_str());
        }
        local.sin_port = htons(this->m_port);
        if( bind(m_listenfd, (struct sockaddr *) &local, sizeof(local)) < 0) {
            LOG_FATAL("AcceptManager::StartET bind fail: m_listenfd=%d, errno=%d", m_listenfd, errno);
        }
        listen(m_listenfd, 100);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //IPV6 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct sockaddr_in6 local6, remote6;
    if (m_listenNet == 1 || m_listenNet==6)
    {
        //创建listen socket
        if( (m_listenfd6 = socket(AF_INET6, SOCK_STREAM, 0)) < 0) {
            LOG_FATAL("AcceptManager::StartET socket fail");
        }
        if (setsockopt(m_listenfd6, SOL_SOCKET, SO_REUSEADDR, &trueFlag, sizeof(int)) < 0){
            LOG_FATAL("AcceptManager::StartET setsockopt SO_REUSEADDR fail");
        }
        if (setsockopt(m_listenfd6, SOL_SOCKET, SO_REUSEPORT, &trueFlag, sizeof(int)) < 0){
            LOG_FATAL("AcceptManager::StartET setsockopt SO_REUSEADDR fail");
        }
        setnonblocking(m_listenfd6);
        bzero(&local6, sizeof(local6));
        local6.sin6_family = AF_INET6;
        //this->m_addr6 = "2001:0:53aa:64c:1013:76a3:c34f:69a4";
        if (this->m_addr6 == ""){
            local6.sin6_addr = in6addr_any;
        }else{
            inet_pton(AF_INET6, m_addr6.c_str(), &local6.sin6_addr);
        }
        local6.sin6_port = htons(this->m_port);
        if( bind(m_listenfd6, (struct sockaddr *) &local6, sizeof(local6)) < 0) {
            LOG_FATAL("AcceptManager::StartET bind fail: m_listenfd=%d, errno=%d", m_listenfd6, errno);
        }
        listen(m_listenfd6, 100);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////


    //EPOLL
    m_epfd = epoll_create(MAX_EVENTS);
    if (m_epfd == -1) {
        LOG_FATAL("AcceptManager::StartET epoll_create fail: errno=%d", errno);
    }

    //边缘触发, 监听IPV4
    if (m_listenNet == 1 || m_listenNet==4)
    {
        ev.events = EPOLLIN | EPOLLET;;
        ev.data.fd = m_listenfd;
        if (epoll_ctl(m_epfd, EPOLL_CTL_ADD, m_listenfd, &ev) == -1) {
            LOG_FATAL("AcceptManager::StartET epoll_ctl EPOLL_CTL_ADD fail: m_listenfd=%d, errno=%d", m_listenfd, errno);
        }
        LOG_INFO("AcceptManager::StartET Server is Online: addr=%s, port=%d", this->m_addr.c_str(), this->m_port);
    }

    //边缘触发, 监听IPV6
    if (m_listenNet == 1 || m_listenNet==6)
    {
        ev.events = EPOLLIN | EPOLLET;;
        ev.data.fd = m_listenfd6;
        if (epoll_ctl(m_epfd, EPOLL_CTL_ADD, m_listenfd6, &ev) == -1) {
            LOG_FATAL("AcceptManager::StartET epoll_ctl EPOLL_CTL_ADD fail: m_listenfd=%d, errno=%d", m_listenfd, errno);
        }
        LOG_INFO("AcceptManager::StartET Server is Online IPV6: port=%d", this->m_port);
    }


    m_start = true;
    for (;;) {
        nfds = epoll_wait(m_epfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            LOG_FATAL("AcceptManager::StartET epoll_pwait fail");
        }
        if (!m_start) {
            LOG_INFO("AcceptManager::StartET m_start is false, prepare to stop.");
            break;
        }

        m_working=true;
        for (i = 0; i < nfds; ++i) {
            fd = events[i].data.fd;

            //处理新进来的连接ipv4
            if (fd == m_listenfd) {
                while ((conn_sock = accept(m_listenfd,(sockaddr *) &remote,
                                &addrlen)) > 0) {
                    LOG_INFO("AcceptManager::StartET: %s Connect", inet_ntoa(remote.sin_addr));
                    setnonblocking(conn_sock);
                    ev.events = EPOLLIN | EPOLLET;
                    ev.data.fd = conn_sock;
                    if (epoll_ctl(m_epfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
                        LOG_FATAL("AcceptManager::StartET epoll_ctl EPOLL_CTL_ADD fail: conn_sock=%d", conn_sock);
                    }
                    //构造一个连接对象并加入session
                    Connection* pConn = new ClientConn(conn_sock, ServerType::SERVER_TYPE_GC);
                    SessionManager::Instance().AddConn(conn_sock, pConn);
                }
                if (conn_sock == -1) {
                    if (errno != EAGAIN && errno != ECONNABORTED
                            && errno != EPROTO && errno != EINTR)
                        LOG_ERROR("AcceptManager::StartET accept fail: m_listenfd=%d", m_listenfd);
                }
                continue;
            }

            //处理新进来的连接ipv6
            if (fd == m_listenfd6) {
                while ((conn_sock = accept(m_listenfd6,(sockaddr *) &remote6,
                                &addrlen)) > 0) {
                    char str[INET_ADDRSTRLEN+1];
                    LOG_INFO("AcceptManager::StartET: %s Connect", inet_ntop(AF_INET6, &remote6.sin6_addr, str, sizeof(str)));
                    setnonblocking(conn_sock);
                    ev.events = EPOLLIN | EPOLLET;
                    ev.data.fd = conn_sock;
                    if (epoll_ctl(m_epfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
                        LOG_FATAL("AcceptManager::StartET epoll_ctl EPOLL_CTL_ADD fail: conn_sock=%d", conn_sock);
                    }
                    //构造一个连接对象并加入session
                    Connection* pConn = new ClientConn(conn_sock, ServerType::SERVER_TYPE_GC);
                    SessionManager::Instance().AddConn(conn_sock, pConn);
                }
                if (conn_sock == -1) {
                    if (errno != EAGAIN && errno != ECONNABORTED
                            && errno != EPROTO && errno != EINTR)
                        LOG_ERROR("AcceptManager::StartET accept fail: m_listenfd=%d", m_listenfd);
                }
                continue;
            }


            if (events[i].events & EPOLLIN) {
                LOG_INFO("AcceptManager::StartET EPOLLIN: fd=%d", fd);
                //获取对应连接对象的专属buf
                Connection* pConn = SessionManager::Instance().GetConn(fd);
                if (NULL==pConn){
                    LOG_ERROR("AcceptManager::StartET GetConn fail: fd=%d", fd);
                    close(fd);
                    continue;
                }
READFLAG:
                buf = pConn->GetWriteBuffer();
                int writesize = pConn->GetWriteSize();
                n = 0;
                //TODO: 当nread< writesize-n时，是否还需要继续read?
                while ((nread = read(fd, buf + n, writesize-n)) > 0) {
                    n += nread;
                    //待接收缓存已满，先处理消息再重新接收
                    if (writesize-n ==0){
                        pConn->WriteAdvance(n);
                        LOG_INFO("AcceptManager::StartET read ok: fd=%d, data_size=%d", fd, n);
                        pConn->DoWork();
                        goto READFLAG;
                    }
                }
                //设置下次可写的位置
                pConn->WriteAdvance(n);

                if (n==0 || (nread == -1 && errno != EAGAIN)) {
                    LOG_ERROR("AcceptManager::StartET read fail: fd=%d, data_size=%d, nread=%d, errno=%d", fd, n, nread, errno);
                    //TODO:此处是否需要移除对fd的监听
                    //if (epoll_ctl(m_epfd, EPOLL_CTL_DEL, fd, NULL) == -1) {
                    //LOG_ERROR("AcceptManager::StartET epoll_ctl EPOLL_CTL_DEL fail: fd=%d, errno=%d", fd, errno);
                    //}
                    SessionManager::Instance().RemoveConn(fd);
                    events[i].data.fd = -1;
                    continue;
                }else{
                    //LOG_INFO("AcceptManager::StartET read ok: fd=%d, data_size=%d", fd, n);
                    LOG_INFO("AcceptManager::StartET read ok: fd=%d, data_size=%d, nread=%d, errno=%d", fd, n, nread, errno);
                    //DoWork
                    pConn->DoWork();
                    //有读取到数据，nread=0表示到连接断开
                    //先处理数据再断开连接
                    if (nread==0){
                        SessionManager::Instance().RemoveConn(fd);
                        events[i].data.fd = -1;
                        continue;
                    }

                    //ev.data.fd = fd;
                    //ev.events=EPOLLOUT|EPOLLET;
                    //if (epoll_ctl(m_epfd, EPOLL_CTL_MOD, fd, &ev) == -1) {
                    //LOG_ERROR("AcceptManager::StartET epoll_ctl EPOLL_CTL_MOD fail: fd=%d", fd);
                    //close(fd);
                    //events[i].data.fd = -1;
                    //continue;
                    //}
                }
            }
            if (events[i].events & EPOLLOUT) {
                LOG_INFO("AcceptManager::zzzzzzzzzzzzzzzz");
                //LOG_INFO("AcceptManager::StartET EPOLLOUT: fd=%d", fd);
                //int nwrite, data_size = strlen(buf);
                //n = data_size;
                //while (n > 0) {
                //nwrite = write(fd, buf + data_size - n, n);
                //if (nwrite < n) {
                //if (nwrite == -1 && errno != EAGAIN) {
                //LOG_ERROR("AcceptManager::StartET write fail: fd=%d, nwrite=%d, errno=%d", fd, nwrite, errno);
                //}
                //break;
                //}
                //n -= nwrite;
                //}
                //LOG_INFO("AcceptManager::StartET write ok: fd=%d, data_size=%d, buf=%s", fd, data_size, buf);

                //ev.data.fd = fd;
                //ev.events=EPOLLIN|EPOLLET;
                //if (epoll_ctl(m_epfd, EPOLL_CTL_MOD, fd, &ev) == -1) {
                //LOG_ERROR("AcceptManager::StartET epoll_ctl EPOLL_CTL_MOD fail: fd=%d", fd);
                //close(fd);
                //events[i].data.fd = -1;
                //continue;
                //}
            }
        }
        m_working=false;
    }
    close(m_listenfd);
    close(m_epfd);
}

void AcceptManager::StartLT(){
    //1.创建监听套接字
    SOCKET listenSock = socket(AF_INET,SOCK_STREAM,0);
    //2.定义服务器IP地址
    sockaddr_in svrAddr;
    memset(&svrAddr,0,sizeof(svrAddr));
    svrAddr.sin_family = AF_INET;
    if (this->m_addr == ""){
        svrAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    }else{
        svrAddr.sin_addr.s_addr = inet_addr(this->m_addr.c_str());
    }
    svrAddr.sin_port = htons(this->m_port);
    //3.创建epoll_event变量
    struct epoll_event *events =(epoll_event *) malloc(sizeof(epoll_event)*MAX_EVENTS);//发生事件缓冲区
    struct epoll_event event;//定义单个事件
    int epollHandle;//返回的文件描述符
    int numOfEvent;//实际发生事件的个数
    //4.绑定
    if(bind(listenSock,(sockaddr*)&svrAddr,sizeof(svrAddr))==-1)
    {
        LOG_FATAL("AcceptManager::StartLT Bind Failed: addr=%s, port=%d", this->m_addr.c_str(), this->m_port);
    }
    //5.监听
    if(listen(listenSock,100)==-1)
    {
        LOG_FATAL("AcceptManager::StartLT Listen Failed: addr=%s, port=%d, listenSocket=%d", this->m_addr.c_str(), this->m_port, listenSock);
    }
    //6.向内存申请一块区域
    epollHandle = epoll_create(MAX_EVENTS);
    event.events = EPOLLIN;//监听可读事件
    event.data.fd = listenSock;//监听的套接字
    //7.将监听的事件加入
    epoll_ctl(epollHandle, EPOLL_CTL_ADD, listenSock, &event);

    sockaddr_in  clientAddr;
    socklen_t  addrLen;
    char messBuf[MESS_SIZE];
    int sockfd;
    int numOfCh = 0;
    LOG_INFO("AcceptManager::StartLT Server is Online: addr=%s, port=%d", this->m_addr.c_str(), this->m_port);
    while(true)
    {
        //8.等待
        numOfEvent = epoll_wait(epollHandle, events, MAX_EVENTS, -1);
        if(numOfEvent ==-1)
        {
            LOG_WARN("AcceptManager::StartLT Epoll_wait Failed");
            break;
        }

        //9.处理发生的事件
        for(int i=0; i<numOfEvent; ++i)
        {
            if(events[i].data.fd==listenSock)  //判断是否是监听套接字发生事件
            {
                SOCKET  clientSock = accept(listenSock,(sockaddr*)&clientAddr,&addrLen);
                if(clientSock<0){
                    LOG_FATAL("AcceptManager::StartLT accept fail: clientSock=%d", clientSock);
                }
                LOG_INFO("AcceptManager::StartLT: %s Connect", inet_ntoa(clientAddr.sin_addr));

                //设置非阻塞
                setnonblocking(clientSock);
                //设置用于注测的读操作事件
                event.events=EPOLLIN|EPOLLET;
                //event.events=EPOLLIN;
                event.data.fd = clientSock;
                //将客户端套接字加入监听队列
                epoll_ctl(epollHandle,EPOLL_CTL_ADD,clientSock,&event);
            }
            else if(events[i].events&EPOLLIN)//如果是已经连接的用户，并且收到数据，那么进行读入。
            {
                //不是服务器套接字，则说明是客户端发送数据
                if ( (sockfd = events[i].data.fd) < 0)
                    continue;
                //读取数据
                memset(messBuf,0,MESS_SIZE);
                if ( (numOfCh = read(sockfd, messBuf, MESS_SIZE)) < 0) {
                    if (errno == ECONNRESET) {
                        LOG_WARN("AcceptManager::StartLT read fail: fd=%d, numOfCh=%d, errno=ECONNRESET", sockfd, numOfCh);
                        close(sockfd);
                        events[i].data.fd = -1;
                    } else{
                        LOG_WARN("AcceptManager::StartLT read fail: fd=%d, numOfCh=%d, errno=%d", sockfd, numOfCh, errno);
                    }
                } else if (numOfCh == 0) {
                    LOG_WARN("AcceptManager::StartLT read fail: fd=%d, numOfCh=%d, errno=%d", sockfd, numOfCh, errno);
                    close(sockfd);
                    events[i].data.fd = -1;
                }else{
                    messBuf[numOfCh] = '\0';
                    LOG_INFO("AcceptManager::StartLT read ok: fd=%d, numOfCh=%d, messBuf=%s", sockfd, numOfCh, messBuf);
                    //设置用于写操作的文件描述符
                    event.data.fd=sockfd;
                    //设置用于注测的写操作事件
                    event.events=EPOLLOUT|EPOLLET;
                    //修改sockfd上要处理的事件为EPOLLOUT
                    epoll_ctl(epollHandle,EPOLL_CTL_MOD,sockfd,&event);
                }
            }
            else if(events[i].events&EPOLLOUT) // 如果有数据发送
            {
                sockfd = events[i].data.fd;
                write(sockfd, messBuf, numOfCh);
                LOG_INFO("AcceptManager::StartLT write ok: fd=%d, numOfCh=%d, messBuf=%s", sockfd, numOfCh, messBuf);
                //设置用于读操作的文件描述符
                event.data.fd=sockfd;
                //设置用于注测的读操作事件
                event.events=EPOLLIN|EPOLLET;
                //修改sockfd上要处理的事件为EPOLIN
                epoll_ctl(epollHandle,EPOLL_CTL_MOD,sockfd,&event);
            }
        }
    }
    close(listenSock);
    close(epollHandle);
}

