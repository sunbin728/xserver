#include "package.h"

#include <cstddef>
#include <stdlib.h>
#include <cstring>
#include "common/logger.h"

std::ostream& operator<<(std::ostream& s, HEAD& head){
    s << head.PkgLen << head.CheckSum << head.Command << head.Target << head.Retcode;
    return s;
}

namespace package{
    HEAD* ReadHeader(char* buf, int datasize){
        if (size_t(datasize)  < sizeof(HEAD)){
            LOG_DEBUG("package::ReadHeader datasize=%d, sizeof(HEAD)=%d", datasize, sizeof(HEAD));
            return NULL;
        }
        HEAD *pHead = (HEAD*)buf;
        return pHead;
    }

    bool ReadMsg(char* buf, int size, MSG *msg){
        HEAD* pHead = ReadHeader(buf, size);
        if (NULL==pHead){
            return false;
        }

        if (size<int(pHead->PkgLen+4)){
            return false;
        }

        msg->size = pHead->PkgLen+4;
        msg->header = (HEAD*)malloc(msg->size);
        memset(msg->header, 0, msg->size);
        memcpy(msg->header, buf, msg->size);
        LOG_DEBUG("package::ReadMsg msg->size=%d, PkgLen=%d, Command=%d, Target=%d, Retcode=%d",
                msg->size, msg->header->PkgLen, msg->header->Command, msg->header->Target, msg->header->Retcode);
        return true;
    }

}
