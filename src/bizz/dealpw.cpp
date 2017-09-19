#include "dealpw.h"
#include "common/logger.h"
#include "net/session_manager.h"
#include "protobuf/robot_2_mts.pb.h"
#include "protobuf/command_type.pb.h"

namespace bizz{
    //deal pw
    void PW2GSKeepAliveRespHandle(MSG* msg, gs2pw::ServerKeepAliveResp& pw2gsKeepAliveResp){
        uint32_t pwid = pw2gsKeepAliveResp.pw_id();
        const uint64_t& pwTime = pw2gsKeepAliveResp.pw_time();
        uint32_t multiple = pw2gsKeepAliveResp.multiple();

        LOG_DEBUG("Bizz::PW2GSKeepAliveRespHandle Recv pw keepalive resp: pwid=%d, pwTime=%d, multiple=%d", pwid, pwTime, multiple);

        ////////// sync pw time to mts
        NetProto::gs2mts::PwTimeSync pts;
        pts.set_pw_ts(pwTime);
        pts.set_multiple(multiple);

        SessionManager::Instance().SendMsg(MTS, GS2MTS_Pw_Time_Sync, pts);
    }
}
