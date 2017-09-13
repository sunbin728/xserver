#include "core.h"

#include <string>
#include <iostream>
#include "db/dbconn_manager.h"
#include "db/dbconn.h"
#include "common/logger.h"
using namespace std;

namespace core{
    //User  GetUserByUname(std::string uname){
        //LOG_DEBUG("GetUserByUname: uname=%s", uname.c_str());
        //char sql[1000] = {0};
        //sprintf(sql, "SELECT `uid`, `uname`, `password`, `channelNo`, `activityNo`, `createTime`, `modifyTime`, `blocked`, `blockedTimeout`, `appid`, `uc` FROM `userdb`.`t_user` WHERE `uname`='%s'", uname.c_str());
        //string strsql(sql);
        //DbConnManager::Instance().ExecuteQuery(strsql);
        //DbResult* pdbResult = DbConnManager::Instance().ExecuteQuery(strsql);
        //LOG_DEBUG("GetUserByUname dbResult=%s",pdbResult->ToString().c_str());
        //User user;
        //if (pdbResult != NULL && pdbResult->GetCount()!=0){
            //user.uname = (*pdbResult)[0]->at("uname");

        //}
        //delete pdbResult;
        //return user;
    //}
}
