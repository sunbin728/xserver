#include "bizz.h"
#include "core.h"
#include "common/util.h"
#include "common/logger.h"
#include "net/session_manager.h"
#include <string>
#include <strstream>
#include <sstream>


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
        char* protobufData = ((char*)msg->header)+14;
        int protobufLen = msg->header->PkgLen-10;

        switch (msg->header->Command){
            //from Client
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

                //from MTS
            case MTS2GS_GET_ROBOT_LIST:
                {
                    MTS2GSGetRobotList mts2gsGetRobotList;
                    mts2gsGetRobotList.ParseFromArray(protobufData, protobufLen);
                    MTS2GSGetRobotListHandle(msg, mts2gsGetRobotList);
                    break;
                }
            case MTS2GS_CREATE_ROBOT:
                {
                    MTS2GSCreateRobot mts2gsCreateRobot;
                    mts2gsCreateRobot.ParseFromArray(protobufData, protobufLen);
                    MTS2GSCreateRobotHandle(msg, mts2gsCreateRobot);
                    break;
                }
            case MTS2GS_GET_SCENE_ITEM:
                {
                    MTS2GSGetSceneItem mts2gsGetSceneItem;
                    mts2gsGetSceneItem.ParseFromArray(protobufData, protobufLen);
                    MTS2GSGetSceneItemHandle(msg, mts2gsGetSceneItem);
                    break;
                }
                //case CHECKUNAMEREQ:
                //protocol::CheckUnameReq checkUnameReq;
                //checkUnameReq.ParseFromArray(((char*)msg->header)+14, msg->header->PkgLen-10);
                //protocol::CheckUnameResp checkUnameResp;
                //CheckUname(checkUnameReq, checkUnameResp);

                //std::ostringstream resp_ostream;
                //checkUnameResp.SerializeToOstream(&resp_ostream);
                //SessionManager::Instance().GetConn(msg->socketfd)->SendMsg(CHECKUSERRESP, resp_ostream);
                //break;
            default:
                LOG_ERROR("bizz::DoWork unknown command: command=%d", msg->header->Command);
        }

        free(msg->header);
        msg->header = NULL;
    }

    void C2GSLoginHandle(MSG* msg, C2GSLogin& c2gsLogin){
        //uint32_t uid = c2gsLogin.accountid();
        //LOG_DEBUG("C2GSLoginHandle: uid=%u", uid);

        //GameClient * ogc = static_cast<GameClient *>( gOnline.getUidClient( uid ) );

        //CHECK_SWITCH_CONN( hdr, gc, server );


        //if ( ogc != NULL && ogc != gc )
        //{
            ////if ogc == gc, the client send the two login msg from one connection
            ////WARN_LOG( "Relogin[%u]", ogc->getOwnerId() );
            //DEBUG_LOG( "Relogin[%u]", ogc->getOwnerId() );
            //INFO_LOG( "Relogin[%u]", ogc->getOwnerId() );
            //Stream st( C2S_CHECK_LOGIN );
            //st.error( CO_Repeated_Login );
            //st << Stream::eos;
            //ogc->sendMsg( st );
            //gOnline.closeClient( ogc );
        //}
        //else if( ogc == gc)
        //{
            //DEBUG_LOG("player have logining...,do nothing!!!");
            //return false;
        //}
        ////check session
        //{
            ////TODO
            //DEBUG_LOG("OnPlayerLoginReq successful!,---user[%u]",uid);
            ////sessionStr
        //}

        ////gc->setOwnerSession((UInt8 *) sessionStr);

        //gc->setOwnerId( uid );

        //Player * player = gc->getOwner();

        //gc->setOwnerStatus( P_Online );
        /////////////new player
        //Player * nPlayer = new Player( gc );
        //player = nPlayer;
        //gc->setOwner( nPlayer );
        //StaticPlayer* sp = gSPlayerMg.get(uid);
        //if(sp == NULL)
        //{
            //sp = new StaticPlayer();
            //gSPlayerMg.add(uid,sp);
        //}
        //nPlayer->setID(uid);
        //sp->setID(uid);
        //sp->setOwner(uid);
        //nPlayer->init(sp);
        //gOnline.addUidClient( uid, gc );

        //// GS2MTS GetRobotList
        //[>
           //message GS2MTSGetRobotList
           //{
           //MsgHead msgHead     = 1; // 消息头 -- 做消息路由用
           //uint32 accountID    = 2; // 玩家id
           //}
           //*/
        //NetProto::GS2MTSGetRobotList getRobotList;
        //MsgHead* msgHead = getRobotList.mutable_msghead();
        //char accid[32] = { 0 };
        //sprintf(accid, "%d", message.accountid());
        //msgHead->set_robot_id(accid);
        //msgHead->set_msg_src(NetProto::CENTER);
        //getRobotList.set_accountid(message.accountid());

        //Stream st;
        //st.initPbHead(NetProto::GS2MTS_GET_ROBOT_LIST);
        //st.appendPbMsg(getRobotList);
        //st << Stream::eos;

        //gOnline.sendMsgToMts(st);
        //[>
           //Stream st( ONLINE2SWITCH_CMD, SS_Check_Session );
           //st << uid << gOnline.getOnlineId();
           //st.append((UInt8*) sessionStr, 16 );
           //st << Stream::eos;
           //server->sendMsg( st );
           //gc->setOwnerStatus( P_CheckSession );
           //DEBUG_LOG("Player[%u] Send SS_Check_Session Msg To Switch", uid);
           //*/
        //return true;


    }

    void C2GSCreateRobotHandle(MSG* msg, C2GSCreateRobot& c2gsCreateRobot){

    }

    void C2GSEnterSceneHandle(MSG* msg, C2GSEnterScene& c2gsEnterScene){

    }

    void MTS2GSGetRobotListHandle(MSG* msg, MTS2GSGetRobotList& mts2gsGetRobotList){

    }

    void MTS2GSCreateRobotHandle(MSG* msg, MTS2GSCreateRobot& mts2gsCreateRobot){

    }

    void MTS2GSGetSceneItemHandle(MSG* msg, MTS2GSGetSceneItem& mts2gsGetSceneItem){

    }

    //void CheckUname(protocol::CheckUnameReq &checkUnameReq, protocol::CheckUnameResp &checkUnameResp){
    //LOG_INFO("bizz::CheckUname CHECKUNAMEREQ req=\n%s", checkUnameReq.DebugString().c_str());
    //std::string uname = checkUnameReq.uname();
    //core::GetUserByUname(uname);

    //checkUnameResp.set_uname(checkUnameReq.uname());
    //checkUnameResp.set_msg("ok");
    //checkUnameResp.set_result(1);
    //LOG_INFO("bizz::CheckUname CHECKUNAMERESP resp=\n%s", checkUnameResp.DebugString().c_str());

    //}
}
