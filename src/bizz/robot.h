#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <string>
#include "base/robotdata.h"

class Robot{
    public:
        Robot():m_robotdata(){}
        Robot(Robot &robot);
        Robot& operator=(Robot &robot);
        ~Robot(){
        };

        static Robot* cloneNew(uint32_t robotPrototypeId);
        RobotData& getRobotData();

    private:
        RobotData m_robotdata;

};
#endif /* _ROBOT_H_ */
