#ifndef _PACKAGE_H_
#define _PACKAGE_H_

#include <stdint.h>
#include <iostream>
#include <cstring>

#pragma pack(push,1)

typedef struct tagHEAD
{
    uint32_t    PkgLen;
    uint32_t    CheckSum;
    uint16_t    Command;
    uint16_t    Target;
    uint16_t    Retcode;
}HEAD,*PHEAD;


typedef struct tagMSG
{
    HEAD*    header;
    int    size;
    int socketfd;
    int connType;
    void* pConn;
    tagMSG(int _size){
        header = (HEAD*)malloc(_size);
        memset(header, 0, _size);
        size = _size;
        socketfd = 0;
        connType = 0;
        pConn=nullptr;
    }
    tagMSG(){
        size = 0;
        socketfd = 0;
        connType = 0;
        pConn=nullptr;
    }
    ~tagMSG(){
        if (NULL!=header){
            free(header);
            header = NULL;
            pConn=nullptr;
        }
    };

    char* GetDataPtr(){return ((char*)header)+14;}
    int GetDataLen(){return header->PkgLen-10;}
}MSG,*PMSG;

#pragma pack(pop)

std::ostream& operator<<(std::ostream& s, HEAD& head);

namespace package{
    HEAD* ReadHeader(char* buf, int size);
    MSG* ReadMsg(char* buf, int size);
}

#endif /* _PACKAGE_H_ */
