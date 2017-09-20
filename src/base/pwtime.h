#ifndef _PWTIME_H_
#define _PWTIME_H_

#include "common/timeutil.h"

struct PwTime
{
    PwTime():_now(TimeUtil::Now()),_multiple(1),_lastSetTs(TimeUtil::Now())
    {
    }

    PwTime(UInt64 ts,UInt32 multiple):_now(ts),_multiple(multiple)
    {
        _lastSetTs = TimeUtil::Now();
    }

    ~PwTime()
    {
    }


    inline void setPwTime(UInt64 ts,UInt32 multiple)
    {
        _now = ts;
        _multiple = multiple;
        _lastSetTs = TimeUtil::Now();
    }

    inline UInt64 pwNowTs()
    {
        UInt64 now = (TimeUtil::Now() - _lastSetTs) * _multiple + _now;
        return now;
    }

    UInt64 _now;
    UInt32 _multiple;
    UInt32 _lastSetTs;
};
#endif /* _PWTIME_H_ */
