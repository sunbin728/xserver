#ifndef _PACKAGE_H_
#define _PACKAGE_H_

#include <stdint.h>

#pragma pack(push,1)

typedef struct tagHEAD
{
  uint32_t    PkgLen;
  uint32_t    CheckSum;
  uint16_t    Command;
  uint16_t	  Target;
  uint16_t	  Retcode;
}HEAD,*PHEAD;

typedef struct tagMSG
{
  HEAD*    header;
  int    size;
  int socketfd;
}MSG,*PMSG;

#pragma pack(pop)

namespace package{
    HEAD* ReadHeader(char* buf, int size);
    bool ReadMsg(char* buf, int size, MSG* msg);
}

#define ADDUSERREQ 0
#define ADDUSERRESP 100
#define CHECKUSERREQ 1
#define CHECKUSERRESP 101
#define CHECKUNAMEREQ 2
#define CHECKUNAMERESP 102

#endif /* _PACKAGE_H_ */
