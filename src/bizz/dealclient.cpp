#include "dealclient.h"
#include "base/package.h"
#include "common/logger.h"
#include "net/session_manager.h"
#include "scene_manager.h"
#include "scene.h"
#include "protobuf/command_type.pb.h"

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
        LOG_DEBUG("C2GSCreateRobotHandle: c2gsCreateRobot=%s",c2gsCreateRobot.DebugString().c_str());

        NetProto::GS2MTSCreateRobot createRobot;
        MsgHead* msgHead = createRobot.mutable_msghead();
        char accid[32] = { 0 };
        sprintf(accid, "%d", c2gsCreateRobot.accountid());
        msgHead->set_robot_id(accid);
        msgHead->set_msg_src(NetProto::CENTER);
        createRobot.set_accountid(c2gsCreateRobot.accountid());
        createRobot.set_robotprototypeid(c2gsCreateRobot.robottype());

        std::shared_ptr<MSG> sp_recvmsg = SessionManager::Instance().SendMsgAndRecv(MTS, NetProto::GS2MTS_CREATE_ROBOT, createRobot);


        NetProto::MTS2GSCreateRobot mts2gsCreateRobot;

        mts2gsCreateRobot.ParseFromArray(sp_recvmsg->GetProtobuf(), sp_recvmsg->GetProtobufLen());
        LOG_DEBUG("C2GSCreateRobotHandle recv Mts response: mts2gsCreateRobot=%s", mts2gsCreateRobot.DebugString().c_str());
        mts2gsCreateRobot.accountid();
        uint32_t uid = mts2gsCreateRobot.accountid();

        const CreateRobotInfo& robotList = mts2gsCreateRobot.robotlist(0);

        LOG_DEBUG("C2GSCreateRobotHandle: robotlist_size=%d", mts2gsCreateRobot.robotlist_size());

        const std::string& robotId = robotList.robotid();
        uint32_t robotPrototypeId = robotList.robotprototypeid();
        LOG_DEBUG("C2GSCreateRobotHandle: robotid=%s, robotPrototypeId=%d", robotId.c_str(), robotPrototypeId);

        //Robot* robot = player->createNewRobot(robotId.c_str(),robotPrototypeId);
        //if(robot != NULL)
        //{
            //player->awakenRobot(robot);
            //////////////first new robot,should save corresponding data to db
            ////1.robot info
            //RobotBaseProp& data = robot->getRobotData();

            //NetProto::GS2CCreateRobot createRobot;

            //NetProto::RobotInfo msg;
            //msg.set_uuid(robotId);


            //msg.set_class_id(data.classId);
            //msg.set_name_id(data.nameId);
            //msg.set_age(data.age);
            //msg.set_gender(data.gender);
            //msg.set_intellectual(data.intellectual);
            //msg.set_beautiful(data.beautiful);
            //msg.set_lovely(data.lovely);
            //msg.set_skin_state(data.skinState);
            //msg.set_long_phy(data.longPhy);
            //msg.set_short_phy(data.shortPhy);
            //msg.set_energy(data.energy);
            //msg.set_thirsty(data.thirsty);
            //msg.set_hunger(data.hunger);
            //msg.set_clean(data.clean);
            //msg.set_suface_temperature(data.sufaceTemperature);
            //msg.set_money(data.money);
            //msg.set_locality(data.locality);
            //msg.set_birthday(data.registerTime);
            //msg.set_sleep(data.sleep);
            //msg.set_pw_birthday(data.birthday);
            //msg.set_offline_pw_time(data.offlinePwTs);

            //createRobot.set_issuccess(true);
            //createRobot.set_ret("success");
            //createRobot.mutable_robotinfo()->CopyFrom(msg);


            //Stream st;
            //st.initPbHead(NetProto::GS2C_CREATE_ROBOT);
            //st.appendPbMsg(createRobot);
            //st << Stream::eos;

            //ogc->sendMsg(st);
        //}
        //else
        //{
            //DEBUG_LOG("create robot failed");
        //}
        //return true;


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

        LOG_DEBUG("C2GSEnterSceneHandle: getSceneItem=%s", getSceneItem.DebugString().c_str());
        std::shared_ptr<MSG> sp_recvmsg = SessionManager::Instance().SendMsgAndRecv(MTS, NetProto::GS2MTS_GET_SCENE_ITEM, getSceneItem);

        MTS2GSGetSceneItem mts2gsGetSceneItem;
        mts2gsGetSceneItem.ParseFromArray(sp_recvmsg->GetProtobuf(), sp_recvmsg->GetProtobufLen());
        LOG_DEBUG("C2GSLoginHandle: mts2gsGetSceneItem=%s", mts2gsGetSceneItem.DebugString().c_str());

        LOG_DEBUG("C2GSLoginHandle: mts2gsGetSceneItem.itemlist_size=%d", mts2gsGetSceneItem.itemlist_size());


        ///////////////根据Map 构造 一个SceneMap
        Scene* configHomeScene = SceneMgr::Instance().DefaultScene();
        if(configHomeScene == NULL)
        {
            LOGERROR("C2GSLoginHandle not found robot home map!!");
            return;
        }

        Scene robotScene = configHomeScene->Clone();
        GS2CEnterScene gs2cEnterScene = robotScene.ToGS2CEnterScene();

        SessionManager::Instance().GetConn(msg->socketfd)->SendMsg(GS2C_ENTER_SCENE, gs2cEnterScene);
        LOG_DEBUG("C2GSLoginHandle to client: gs2cEnterScene=%s", gs2cEnterScene.DebugString().c_str());


        SessionManager::Instance().SendMsg(MTS, NetProto::GS2PW_Notify_Robot_All_World_Data, gs2cEnterScene);
        LOG_DEBUG("C2GSLoginHandle to pw: gs2cEnterScene=%s", gs2cEnterScene.DebugString().c_str());
    }
}
