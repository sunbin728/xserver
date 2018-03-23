#include "package.h"

#include <cstddef>
#include <stdlib.h>
#include <cstring>
#include "common/logger.h"

std::ostream& operator<<(std::ostream& s, HEAD& head){
    //s << head.PkgLen << head.CheckSum << head.Command << head.Target << head.Retcode;
    //s << (char*)(&head);
    s.write((char*)(&head), sizeof(head));
    return s;
}

namespace package{
    HEAD* ReadHeader(char* buf, int datasize){
        if (size_t(datasize)  < sizeof(HEAD)){
            //LOG_DEBUG("package::ReadHeader datasize=%d, sizeof(HEAD)=%d", datasize, sizeof(HEAD));
            return NULL;
        }
        HEAD *pHead = (HEAD*)buf;
        return pHead;
    }

    MSG* ReadMsg(char* buf, int size){
        HEAD* pHead = ReadHeader(buf, size);
        if (NULL==pHead){
            return NULL;
        }

        if (size<int(pHead->PkgLen+4)){
            return NULL;
        }
        MSG* msg = new MSG(pHead->PkgLen+4);
        memcpy(msg->header, buf, msg->size);
        //LOG_DEBUG("package::ReadMsg msg->size=%d, PkgLen=%d, Command=%d, Target=%d, Retcode=%d",
                //msg->size, msg->header->PkgLen, msg->header->Command, msg->header->Target, msg->header->Retcode);
        return msg;
    }

}
