#include "bizz.h"
#include "dealclient.h"
#include "core.h"
#include "common/util.h"
#include "common/logger.h"
#include "net/connection.h"
#include "base/command.h"

#include <unistd.h>
#include <string>
//#include <strstream>
//#include <sstream>

using namespace std;

namespace bizz{
    void  DoWork(MSG* msg){
        char* dataPtr = msg->GetDataPtr();
        int dataLen = msg->GetDataLen();
        //十六进制打印
        //std::string data_hex = util::ToHexString(dataPtr, dataLen);
        //LOG_INFO("bizz::DoWork PkgLen=%d, CheckSum=%d, Command=%d, Target=%d, Retcode=%d, data=%s",
        //msg->header->PkgLen, msg->header->CheckSum, msg->header->Command, msg->header->Target, msg->header->Retcode,
        //data_hex.c_str());

        //十进制打印
        //std::string data_dec = util::ToDecString(dataPtr, dataLen);
        //LOG_INFO("bizz::DoWork PkgLen=%d, CheckSum=%d, Command=%d, Target=%d, Retcode=%d, data=%s",
        //msg->header->PkgLen, msg->header->CheckSum, msg->header->Command, msg->header->Target, msg->header->Retcode,
        //data_dec.c_str());
        Document doc_req;
        if (doc_req.Parse(dataPtr, dataLen).HasParseError()){
            LOG_ERROR("bizz::DoWork json parse error: err=%s", doc_req.GetParseError());
            return;
        }else{
            //打印json消息
            StringBuffer buffer;
            Writer<StringBuffer> writer(buffer);
            doc_req.Accept(writer);
            LOG_INFO("bizz::DoWork req=%s, connType=%d", buffer.GetString(), msg->connType);
        }

        Document doc_resp;
        if (msg->connType == ServerType::SERVER_TYPE_GC){
            DealClientMsg(msg, doc_req, doc_resp);
        }else{
            DealServerMsg(msg, doc_req, doc_resp);
        }
        if (!doc_resp.IsNull() && msg->pConn != nullptr){
            bool sendStatus = static_cast<Connection*>(msg->pConn)->SendMsg(msg->header->Command, doc_resp);
            if (sendStatus){
                StringBuffer buffer;
                Writer<StringBuffer> writer(buffer);
                doc_req.Accept(writer);
                LOG_INFO("bizz::DoWork resp=%s", buffer.GetString());
            }
        }
    }

    void DealClientMsg(MSG* msg, Document &req, Document &resp){
        switch (msg->header->Command){
            //From Client
            case Command::COMMON_HEART_BEAT:
                {
                    HeartBeatHandler(req, resp);
                    break;
                }
            case Command::COMMON_SERVER_REG_REQ:
                {
                    ServerRegHandler(req, resp);
                    break;
                }

            default:
                LOG_ERROR("bizz::DoWork unknown command: command=%d", msg->header->Command);
        }
    }

    void DealServerMsg(MSG* msg, Document &req, Document &resp){

    }
}
