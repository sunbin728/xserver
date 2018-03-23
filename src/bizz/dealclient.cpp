#include "dealclient.h"
#include "base/package.h"
#include "common/logger.h"
#include "common/timeutil.h"
#include "net/session_manager.h"

namespace bizz{
    //deal client
    void HeartBeatHandler(Document &req, Document &resp){
        LOG_INFO("HeartBeatHandler: now=%" PRIu64"", req["nowTime"].GetUint64());
        resp.SetObject();
        resp.AddMember("nowTime", TimeUtil::Now(), resp.GetAllocator());
    }

}
