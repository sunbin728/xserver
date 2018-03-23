#include "bizz.h"
#include "dealclient.h"
#include "core.h"
#include "common/util.h"
#include "common/logger.h"
#include "net/connection.h"
#include "base/command.h"

#include <unistd.h>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
//#include <strstream>
//#include <sstream>

using namespace rapidjson;
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
            LOG_INFO("bizz::DoWork req=%s", buffer.GetString());
        }

        Document doc_resp;
        switch (msg->header->Command){
            //From Client
            case Command::COMMON_HEART_BEAT:
                {
                    HeartBeatHandler(doc_req, doc_resp);
                    break;
                }

            default:
                LOG_ERROR("bizz::DoWork unknown command: command=%d", msg->header->Command);
        }

        if (!doc_resp.IsNull()){
            bool sendStatus = Connection::SendMsg(msg->socketfd, msg->header->Command, doc_resp);
            if (sendStatus){
                StringBuffer buffer;
                Writer<StringBuffer> writer(buffer);
                doc_req.Accept(writer);
                LOG_INFO("bizz::DoWork resp=%s", buffer.GetString());
            }
        }
    }
}
