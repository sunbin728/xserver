#ifndef _PACKAGE_H_
#define _PACKAGE_H_

#include <stdint.h>
#include <iostream>

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
    ~tagMSG(){
        if (NULL!=header){
            free(header);
            header = NULL;
        }
    };

    char* GetProtobuf(){return ((char*)header)+14;}
    int GetProtobufLen(){return header->PkgLen-10;}
}MSG,*PMSG;

#pragma pack(pop)

std::ostream& operator<<(std::ostream& s, HEAD& head);

namespace package{
    HEAD* ReadHeader(char* buf, int size);
    bool ReadMsg(char* buf, int size, MSG* msg);
}

#endif /* _PACKAGE_H_ */
