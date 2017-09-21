#include "data_manager.h"
#include "common/logger.h"
#include "db/dbconn_manager.h"
#include <string>
#include "common/util.h"
using namespace util;


DataMgr::DataMgr()
{
}

DataMgr::~DataMgr()
{
}

DataMgr& DataMgr::Instance(){
    static DataMgr dataMgr;
    return dataMgr;
}

bool DataMgr::Init(){
    return loadRobotConf();
}

bool DataMgr::loadRobotConf()
{
    LOGINFO(".................DataMgr::loadRobotConf begin ............................");
    std::string sql ="select name,id,name_id,type,age,gender, intellectual,beautiful,lovely,skin_state, \
                      long_physical,short_physical,energy,thirsty, \
                      hunger,clean,surface_temperature,account \
                      FROM robot_basic_prop";

    std::shared_ptr<DbResult> dbres =   DbConnManager::Instance().ExecuteQuery(sql);
    int rowcount = dbres->GetCount();
    if (rowcount <= 0){
        LOG_FATAL("DataMgr::loadRobotConf fail: rowcount=%d", rowcount);
    }
    DbRow *row;
    for(int i=0; i<rowcount; ++i){
        row = (*dbres)[i];

        RobotConf* robotInfo = new RobotConf();
        assert(robotInfo);
        robotInfo->_name = (*row)["name"];
        robotInfo->_id = Atoi<UInt16>((*row)["id"]);
        robotInfo->_name_id = Atoi<UInt16>((*row)["name_id"]);
        robotInfo->_type = Atoi<UInt16>((*row)["type"]);
        robotInfo->_age = Atoi<UInt16>((*row)["age"]);
        robotInfo->_gender = Atoi<UInt16>((*row)["gender"]);
        robotInfo->_intellectual = Atoi<UInt16>((*row)["intellectual"]);
        robotInfo->_beautiful = Atoi<UInt16>((*row)["beautiful"]);
        robotInfo->_lovely = Atoi<UInt16>((*row)["lovely"]);
        robotInfo->_skin_state = Atoi<UInt16>((*row)["skin_state"]);
        robotInfo->_long_physical = Atoi<UInt16>((*row)["long_physical"]);
        robotInfo->_short_physical = Atoi<UInt16>((*row)["short_physical"]);
        robotInfo->_energy = Atoi<UInt16>((*row)["energy"]);
        robotInfo->_thirsty = Atoi<UInt16>((*row)["thirsty"]);
        robotInfo->_hunger = Atoi<UInt16>((*row)["hunger"]);
        robotInfo->_clean = Atoi<UInt16>((*row)["clean"]);
        robotInfo->_surface_temperature = Atoi<UInt16>((*row)["surface_temperature"]);
        robotInfo->_account = Atoi<UInt32>((*row)["account"]);

        LOG_DEBUG("DataMgr::loadRobotConf: name=%s, name_id=%d", robotInfo->_name.c_str(),robotInfo->_name_id);

        m_robotConfMap.insert(std::pair<UInt16,RobotConf*>(robotInfo->_id,robotInfo));
    }
    LOGINFO(".................DataMgr::loadRobotConf end ............................");
    return true;
}

RobotConf* DataMgr::GetRobotConf(int prototypeId){
    RobotConfMap::iterator it = m_robotConfMap.find(prototypeId);
    if (it!=m_robotConfMap.end()){
        return it->second;
    }else{
        return NULL;
    }
}
