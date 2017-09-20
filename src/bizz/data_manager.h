#ifndef _DATA_MANAGER_H_
#define _DATA_MANAGER_H_

#include "scene.h"
#include "base/robotdata.h"

typedef std::map<int, RobotConf*> RobotConfMap;

class DataMgr
{
    private:
        DataMgr();
        ~DataMgr();
        DataMgr(const DataMgr &DataMgr);
        DataMgr& operator=(const DataMgr &DataMgr);

    public:
        static DataMgr& Instance();

        bool Init();
        bool loadRobotConf();
        RobotConf* GetRobotConf(int prototypeId);

    private:
        RobotConfMap m_robotConfMap;
};
#endif /* _DATA_MANAGER_H_ */
