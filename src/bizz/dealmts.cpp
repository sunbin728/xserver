#include "dealmts.h"
#include "common/logger.h"
#include "net/session_manager.h"

namespace bizz{
    //deal mts
    void MTS2GSGetRobotListHandle(MSG* msg, MTS2GSGetRobotList& mts2gsGetRobotList){
        LOG_DEBUG("MTS2GSGetRobotListHandle: mts2gsGetRobotList=%s", mts2gsGetRobotList.DebugString().c_str());
        NetProto::GS2CLogin login;
        login.set_issuccess(true);
        login.set_ret("success");
        login.set_robotflag(mts2gsGetRobotList.robotflag());
        login.mutable_robotlist()->CopyFrom(*(mts2gsGetRobotList.mutable_robotlist()));




        //GameClient * ogc = static_cast<GameClient *>(gOnline.getUidClient(message.accountid()));

        //// SendMsgToClient
        //Stream st;
        //st.initPbHead(NetProto::GS2C_LOGIN);
        //st.appendPbMsg(login);

        //st << Stream::eos;
        //ogc->sendMsg(st);
        //return true;

    }

    void MTS2GSCreateRobotHandle(MSG* msg, MTS2GSCreateRobot& mts2gsCreateRobot){

    }

    void MTS2GSGetSceneItemHandle(MSG* msg, MTS2GSGetSceneItem& mts2gsGetSceneItem){

    }
}
