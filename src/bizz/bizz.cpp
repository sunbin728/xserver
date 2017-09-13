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

        switch (msg->header->Command){
            case ADDUSERREQ:
                break;
            case CHECKUSERREQ:
                break;
            case CHECKUNAMEREQ:
                //protocol::CheckUnameReq checkUnameReq;
                //checkUnameReq.ParseFromArray(((char*)msg->header)+14, msg->header->PkgLen-10);
                //protocol::CheckUnameResp checkUnameResp;
                //CheckUname(checkUnameReq, checkUnameResp);

                //std::ostringstream resp_ostream;
                //checkUnameResp.SerializeToOstream(&resp_ostream);
                //SessionManager::Instance().GetConn(msg->socketfd)->SendMsg(CHECKUSERRESP, resp_ostream);
                break;
        }

        free(msg->header);
        msg->header = NULL;
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
