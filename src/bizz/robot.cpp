#include "robot.h"
#include "common/logger.h"
#include "common/timeutil.h"
#include "data_manager.h"
#include "global_manager.h"

Robot* Robot::cloneNew(uint32_t robotPrototypeId)
{
    RobotConf* conf(NULL);
    conf = DataMgr::Instance().GetRobotConf(robotPrototypeId);
    if (NULL == conf){
        LOG_FATAL("Robot::cloneNew DataMgr::Instance().GetRobotConf is NULL: robotPrototypeId=%d", robotPrototypeId);
    }

    Robot* r = new Robot();

    RobotData& data = r->getRobotData();

    data.classId = conf->_type;
    data.nameId = conf->_name_id;
    data.age = conf->_age;
    data.gender = conf->_gender;
    data.intellectual = conf->_intellectual;
    data.beautiful = conf->_beautiful;
    data.lovely = conf->_lovely;
    data.skinState = conf->_skin_state;
    data.longPhy = conf->_long_physical;
    data.shortPhy = conf->_short_physical;
    data.energy = conf->_energy;
    data.thirsty = conf->_thirsty;
    data.hunger = conf->_hunger;
    data.clean = conf->_clean;
    data.sufaceTemperature = conf->_surface_temperature;
    data.money = conf->_account;
    if(conf->_bornArea)
        data.locality = conf->_bornArea;
    else
        data.locality = 1; //todo
    data.registerTime = TimeUtil::Now();
    data.birthday = GlobalManager::Instance().getPwTime();

    return r;
}

RobotData& Robot::getRobotData(){
    return m_robotdata;
}
