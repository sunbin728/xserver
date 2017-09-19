#ifndef _DEALCLIENT_H_
#define _DEALCLIENT_H_

#include "base/package.h"
#include "protobuf/Protocol.pb.h"

using namespace NetProto;

namespace bizz{
    //client
    void C2GSLoginHandle(MSG* msg, C2GSLogin& c2gsLogin);
    void C2GSCreateRobotHandle(MSG* msg, C2GSCreateRobot& c2gsCreateRobot);
    void C2GSEnterSceneHandle(MSG* msg, C2GSEnterScene& c2gsEnterScene);
}

#endif /* _DEALCLIENT_H_ */
