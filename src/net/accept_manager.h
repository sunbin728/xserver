#ifndef _ACCEPT_MANAGER_H_
#define _ACCEPT_MANAGER_H_

#include <string>

class AcceptManager{
    private:
        AcceptManager():
            m_port(11234),
            m_addr("0.0.0.0"),
            m_start(false),
            m_working(false){}
        AcceptManager(AcceptManager &acceptManager);
        AcceptManager& operator=(AcceptManager &acceptManager);
        ~AcceptManager(){
        };

    public:
        static AcceptManager& Instance();
        void Start();
        void Stop();
        bool AddEvent(int conn_sock);
        bool IsStarted(){return m_start;}

    private:
        void StartLT();
        void StartET();

    private:
        int m_port;
        std::string m_addr;
        int m_listenfd;
        int m_epfd;
        bool m_start;
        bool m_working;

};
#endif /* _ACCEPT_MANAGER_H_ */
