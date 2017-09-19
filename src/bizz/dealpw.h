#ifndef _DEALPW_H_
#define _DEALPW_H_

#include "base/package.h"
#include "protobuf/Protocol.pb.h"
#include "protobuf/gs_2_pw.pb.h"

using namespace NetProto;

namespace bizz{
    //pw
    void PW2GSKeepAliveRespHandle(MSG* msg, gs2pw::ServerKeepAliveResp& pw2gsKeepAliveResp);
}

#endif /* _DEALPW_H_ */
