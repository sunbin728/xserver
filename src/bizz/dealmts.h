#ifndef _DEALMTS_H_
#define _DEALMTS_H_

#include "base/package.h"
#include "protobuf/Protocol.pb.h"

using namespace NetProto;

namespace bizz{
    //mts
    void MTS2GSGetRobotListHandle(MSG* msg, MTS2GSGetRobotList& mts2gsGetRobotList);
    void MTS2GSCreateRobotHandle(MSG* msg, MTS2GSCreateRobot& mts2gsCreateRobot);
    void MTS2GSGetSceneItemHandle(MSG* msg, MTS2GSGetSceneItem& mts2gsGetSceneItem);
}

#endif /* _DEALMTS_H_ */
