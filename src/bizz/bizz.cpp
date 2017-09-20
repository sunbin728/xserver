#include "bizz.h"
#include "dealclient.h"
#include "dealpw.h"
#include "dealmts.h"
#include "core.h"
#include "common/util.h"
#include "common/logger.h"
//#include "base/command.h"
#include <string>
//#include <strstream>
//#include <sstream>
//#include "protobuf/robot_2_mts.pb.h"
//#include "protobuf/gs_2_pw.pb.h"

namespace bizz{
    void  DoWork(MSG* msg){
        std::string data_hex = util::ToHexString(((char*)msg->header)+14, msg->header->PkgLen-10);
        LOG_INFO("bizz::DoWork PkgLen=%d, CheckSum=%d, Command=%d, Target=%d, Retcode=%d, data=%s",
                msg->header->PkgLen, msg->header->CheckSum, msg->header->Command, msg->header->Target, msg->header->Retcode,
                data_hex.c_str());

        std::string data_dec = util::ToDecString(((char*)msg->header)+14, msg->header->PkgLen-10);
        LOG_INFO("bizz::DoWork PkgLen=%d, CheckSum=%d, Command=%d, Target=%d, Retcode=%d, data=%s",
                msg->header->PkgLen, msg->header->CheckSum, msg->header->Command, msg->header->Target, msg->header->Retcode,
                data_dec.c_str());
        char* protobufData = msg->GetProtobuf();
        int protobufLen = msg->GetProtobufLen();

        switch (msg->header->Command){
            //From Client
            case NetProto::C2GS_LOGIN:
                {
                    C2GSLogin c2gsLogin;
                    c2gsLogin.ParseFromArray(protobufData, protobufLen);
                    C2GSLoginHandle(msg, c2gsLogin);
                    break;
                }
            case NetProto::C2GS_CREATE_ROBOT:
                {
                    C2GSCreateRobot c2gsCreateRobot;
                    c2gsCreateRobot.ParseFromArray(protobufData, protobufLen);
                    C2GSCreateRobotHandle(msg, c2gsCreateRobot);
                    break;
                }
            case C2GS_ENTER_SCENE:
                {
                    C2GSEnterScene c2gsEnterScene;
                    c2gsEnterScene.ParseFromArray(protobufData, protobufLen);
                    C2GSEnterSceneHandle(msg, c2gsEnterScene);
                    break;
                }

                //From MTS
                //case MTS2GS_GET_ROBOT_LIST:
                //{
                //MTS2GSGetRobotList mts2gsGetRobotList;
                //mts2gsGetRobotList.ParseFromArray(protobufData, protobufLen);
                //MTS2GSGetRobotListHandle(msg, mts2gsGetRobotList);
                //break;
                //}
                //case MTS2GS_CREATE_ROBOT:
                //{
                //MTS2GSCreateRobot mts2gsCreateRobot;
                //mts2gsCreateRobot.ParseFromArray(protobufData, protobufLen);
                //MTS2GSCreateRobotHandle(msg, mts2gsCreateRobot);
                //break;
                //}
                //case MTS2GS_GET_SCENE_ITEM:
                //{
                //MTS2GSGetSceneItem mts2gsGetSceneItem;
                //mts2gsGetSceneItem.ParseFromArray(protobufData, protobufLen);
                //MTS2GSGetSceneItemHandle(msg, mts2gsGetSceneItem);
                //break;
                //}

                //From PW
                //case GS2PW_Keep_Alive:
                //{
                //gs2pw::ServerKeepAliveResp pw2gsKeepAliveResp;
                //pw2gsKeepAliveResp.ParseFromArray(protobufData, protobufLen);
                //PW2GSKeepAliveRespHandle(msg, pw2gsKeepAliveResp);
                //break;
                //}
            default:
                LOG_ERROR("bizz::DoWork unknown command: command=%d", msg->header->Command);
        }

    }


}
