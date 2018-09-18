#ifndef _BIZZ_H_
#define _BIZZ_H_

#include "base/package.h"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

namespace bizz{
    void  DoWork(MSG* msg);
    void DealClientMsg(MSG* msg, Document &req, Document &resp);
    void DealServerMsg(MSG* msg, Document &req, Document &resp);
}

#endif /* _BIZZ_H_ */
