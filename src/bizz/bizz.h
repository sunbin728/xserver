#ifndef _BIZZ_H_
#define _BIZZ_H_

#include "base/package.h"
#include "protobuf/Protocol.pb.h"

using namespace NetProto;

namespace bizz{
    void  DoWork(MSG* msg);
    //client
    void C2GSLoginHandle(MSG* msg, C2GSLogin& c2gsLogin);
    void C2GSCreateRobotHandle(MSG* msg, C2GSCreateRobot& c2gsCreateRobot);
    void C2GSEnterSceneHandle(MSG* msg, C2GSEnterScene& c2gsEnterScene);
    //mts
    void MTS2GSGetRobotListHandle(MSG* msg, MTS2GSGetRobotList& mts2gsGetRobotList);
    void MTS2GSCreateRobotHandle(MSG* msg, MTS2GSCreateRobot& mts2gsCreateRobot);
    void MTS2GSGetSceneItemHandle(MSG* msg, MTS2GSGetSceneItem& mts2gsGetSceneItem);

    //void CheckUname(protocol::CheckUnameReq &checkUnameReq, protocol::CheckUnameResp &checkUnameResp);
}

#endif /* _BIZZ_H_ */
