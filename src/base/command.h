#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "protobuf/msg_head.pb.h"

#define CLIENT NetProto::MsgSrc::CLIENT
#define MTS NetProto::MsgSrc::MTS
#define PW NetProto::MsgSrc::PW
#define CENTER NetProto::MsgSrc::CENTER
#define ACC NetProto::MsgSrc::ACC

#define ADDUSERREQ 0
#define ADDUSERRESP 100
#define CHECKUSERREQ 1
#define CHECKUSERRESP 101
#define CHECKUNAMEREQ 2
#define CHECKUNAMERESP 102

#endif /* _COMMAND_H_ */
