#include "dealclient.h"
#include "base/package.h"
#include "common/logger.h"
#include "net/session_manager.h"

namespace bizz{
    //deal client
    void C2GSLoginHandle(MSG* msg, C2GSLogin& c2gsLogin){
        uint32_t uid = c2gsLogin.accountid();
        LOG_DEBUG("C2GSLoginHandle: uid=%u", uid);

        NetProto::GS2MTSGetRobotList getRobotList;
        MsgHead* msgHead = getRobotList.mutable_msghead();
        char accid[32] = { 0 };
        sprintf(accid, "%d", uid);
        msgHead->set_robot_id(accid);
        msgHead->set_msg_src(CENTER);
        getRobotList.set_accountid(uid);

        std::shared_ptr<MSG> sp_recvmsg = SessionManager::Instance().SendMsgAndRecv(MTS, NetProto::GS2MTS_GET_ROBOT_LIST, getRobotList);

        MTS2GSGetRobotList mts2gsGetRobotList;
        mts2gsGetRobotList.ParseFromArray(sp_recvmsg->GetProtobuf(), sp_recvmsg->GetProtobufLen());
        LOG_DEBUG("C2GSLoginHandle: mts2gsGetRobotList=%s", mts2gsGetRobotList.DebugString().c_str());

        NetProto::GS2CLogin gs2cLogin;
        gs2cLogin.set_issuccess(true);
        gs2cLogin.set_ret("success");
        gs2cLogin.set_robotflag(mts2gsGetRobotList.robotflag());
        gs2cLogin.mutable_robotlist()->CopyFrom(*(mts2gsGetRobotList.mutable_robotlist()));
        SessionManager::Instance().GetConn(msg->socketfd)->SendMsg(NetProto::GS2C_LOGIN, gs2cLogin);
        LOG_DEBUG("C2GSLoginHandle: mts2gsGetRobotList=%s", mts2gsGetRobotList.DebugString().c_str());
    }

    void C2GSCreateRobotHandle(MSG* msg, C2GSCreateRobot& c2gsCreateRobot){

    }

    void C2GSEnterSceneHandle(MSG* msg, C2GSEnterScene& c2gsEnterScene){
        int uid = c2gsEnterScene.accountid();
        LOG_DEBUG("C2GSEnterSceneHandle c2gsEnterScene=%s", c2gsEnterScene.DebugString().c_str());
        MsgHead* head = c2gsEnterScene.mutable_msghead();
        LOG_DEBUG("C2GSEnterSceneHandle msgHead robot id [%s]", head->robot_id().c_str());


        NetProto::GS2MTSGetSceneItem getSceneItem;
        MsgHead* msgHead = getSceneItem.mutable_msghead();
        char accid[32] = { 0 };
        sprintf(accid, "%d", uid);
        msgHead->set_robot_id(head->robot_id());
        msgHead->set_msg_src(NetProto::CENTER);
        getSceneItem.set_accountid(uid);
        getSceneItem.set_scenetype(1);
        getSceneItem.set_sceneid("170411145427534441978f51SI133678");

        LOG_DEBUG("accountid : %d, scene type : %d, scene id : %s", uid, getSceneItem.scenetype(), getSceneItem.sceneid().c_str());

        std::shared_ptr<MSG> sp_recvmsg = SessionManager::Instance().SendMsgAndRecv(MTS, NetProto::GS2MTS_GET_SCENE_ITEM, getSceneItem);


    }
}
