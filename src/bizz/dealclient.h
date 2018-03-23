#ifndef _DEALCLIENT_H_
#define _DEALCLIENT_H_

#include "base/package.h"
#include "rapidjson/document.h"

using namespace rapidjson;

namespace bizz{
    //client
    void HeartBeatHandler(Document &req, Document &resp);
}

#endif /* _DEALCLIENT_H_ */
