#include "clientconn.h"
#include "bizz/worker_manager.h"
#include "base/command.h"

void ClientConn::DealMsg(MSG* msg){
    WorkerManager::Instance().DealClientMsg(msg);
}


