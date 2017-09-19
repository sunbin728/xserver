#ifndef _PACKAGE_H_
#define _PACKAGE_H_

#include "protobuf/msg_head.pb.h"

const int CLIENT = NetProto::MsgSrc::CLIENT;
const int MTS = NetProto::MsgSrc::MTS;
const int PW = NetProto::MsgSrc::PW;
const int CENTER = NetProto::MsgSrc::CENTER;
const int ACC = NetProto::MsgSrc::ACC;

#define ADDUSERREQ 0
#define ADDUSERRESP 100
#define CHECKUSERREQ 1
#define CHECKUSERRESP 101
#define CHECKUNAMEREQ 2
#define CHECKUNAMERESP 102

#endif /* _PACKAGE_H_ */
