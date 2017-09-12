#ifndef BIZZ_H_
#define BIZZ_H_

#include "base/package.h"
#include "protobuf/acc_checkuname.pb.h"

namespace bizz{
    void  DoWork(MSG* msg);
    void CheckUname(protocol::CheckUnameReq &checkUnameReq, protocol::CheckUnameResp &checkUnameResp);
}

#endif /* BIZZ_H_ */
