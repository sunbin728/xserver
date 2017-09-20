#ifndef _TIMEUTIL_H_
#define _TIMEUTIL_H_

#ifndef _WIN32
#include <sys/time.h>
#endif
#include <time.h>
#include <string>
#include <string.h>
#include "base/basetype.h"

class TimeUtil
{
public:
	static const UInt32 _ONE_MINUTE = 60 ;
	static const UInt32 _HALF_HOUR  = 30 * _ONE_MINUTE;
	static const UInt32 _ONE_HOUR   = 60 * _ONE_MINUTE;
    static const UInt32 DaySec = 24 * 60 * 60;
	static const UInt32 ACESec = 5 * 60;

	//是不是前半小时
	static inline bool isFirstHalfHour(UInt32 time=Now()) 
	{
        time_t t = static_cast<time_t>(time) ;
        return localtime(&t)->tm_min < 30;
	}

	//是不是后半小时
	static inline bool isSecondHalfHour(UInt32 time=Now()) 
	{
        time_t t = static_cast<time_t>(time) ;
        return localtime(&t)->tm_min >= 30;
	}
	//是否是今天
	static inline bool isToday(UInt32 time) { return isSameDay(time, Now());}
	// t1 he t2 是不是同一天
	static inline bool isSameDay(UInt32 t1, UInt32 t2) {
		UInt32 bagTiem = std::max(t1, t2);
		UInt32 smallTiem = std::min(t1, t2);

		if (bagTiem - smallTiem > DaySec)
			return false;

		UInt8 d1 = Day(t1);
		UInt8 d2 = Day(t1);

		return d1 == d2;
	}

	static inline void Init() { tzset(); }
	static inline UInt32 Now() { return static_cast<UInt32>(time(NULL)); }
	static inline UInt8 Day(UInt32 now = Now())
	{
		time_t now2 = static_cast<time_t>(now);
		struct tm * local = localtime(&now2);
		return static_cast<UInt8>(local->tm_wday);
	}
	//@brief: 当天凌晨零点的时间
	static inline UInt32 SharpDay(int c = 0, UInt32 cur = Now())
	{
		UInt32 tmptm = (cur + timezone) / 86400 * 86400 + timezone;
		if(tmptm > cur)
			tmptm -= 86400;
		else if(tmptm + 86400 <= cur)
			tmptm += 86400;
		return tmptm + c * 86400;
	}
	static inline UInt32 SharpHour(int c, UInt32 tm = Now())
	{
		return (tm + c * 3600) / 3600 * 3600;
	}
	static inline UInt32 SharpFourtyMin(int c, UInt32 tm = Now())
	{
		return (tm + c * 2400) / 2400 * 2400;
	}
	static inline UInt32 SharpMinute(int c, UInt32 tm = Now())
	{
		return (tm + c * 60) / 60 * 60;
	}
    static inline std::string GetAscTime(UInt32 now = Now())
    {
        time_t t = static_cast<time_t>(now);
        return asctime( localtime( &t ) );
    }
	static inline UInt64 GetTick()
	{
		struct timeval tv;
		if(gettimeofday(&tv, NULL))
			return 0;
		return tv.tv_sec * 1000000 + tv.tv_usec;
	}

    static inline UInt8 GetHour(UInt32 now = Now()) 
	{
        time_t t = static_cast<time_t>(now) ;
        return static_cast<UInt8>(localtime(&t)->tm_hour);
	}
    static inline UInt8 GetWeekDay(UInt32 now = Now()) 
    {
        time_t t = static_cast<time_t>(now) ;
        return static_cast<UInt8>(localtime(&t)->tm_wday);
    }
    static inline UInt8 GetMonthDay(UInt32 now = Now())
    {
        time_t t = static_cast<time_t>(now) ;
        return static_cast<UInt8>(localtime(&t)->tm_mday);
    }
    static inline UInt8 GetYearMonth(UInt32 now = Now())
    {
        time_t t = static_cast<time_t>(now);
        return static_cast<UInt8>(localtime(&t)->tm_mon) + 1;
    }
    static inline UInt16 GetYear(UInt32 now = Now())
    {
        time_t t = static_cast<time_t>(now);
        return static_cast<UInt16>(localtime(&t)->tm_year + 1900);
    }
	static inline UInt32 MkTime( UInt16 year, UInt8 month, UInt8 day, UInt8 hour, UInt8 min, UInt8 sec )
	{
		struct tm nowTm;
		nowTm.tm_year = year - 1900;
		nowTm.tm_mon = month - 1;
		nowTm.tm_mday = day;
		nowTm.tm_hour = hour;
		nowTm.tm_min = min;
		nowTm.tm_sec = sec;
		nowTm.tm_isdst = -1;
		return static_cast<UInt32>(mktime( &nowTm ));
	}

	static inline UInt64 MkTime64( UInt16 year, UInt8 month, UInt8 day, UInt8 hour, UInt8 min, UInt8 sec )
	{
		struct tm nowTm;
		nowTm.tm_year = year - 1900;
		nowTm.tm_mon = month - 1;
		nowTm.tm_mday = day;
		nowTm.tm_hour = hour;
		nowTm.tm_min = min;
		nowTm.tm_sec = sec;
		nowTm.tm_isdst = -1;
		return static_cast<UInt64>(mktime( &nowTm ));
	}

    static inline UInt32 Tomorrow()
    {
        time_t now = time(NULL);
		struct tm * local = localtime(&now);
        ++local->tm_mday;
        local->tm_hour = 0;
        local->tm_min = 0;
        local->tm_sec = 0;
		return static_cast<UInt32>(mktime( local ));
    }


	static inline const char* getTimeStr32(UInt32 now = Now())
	{
		static char chTmp[20];
		bzero(chTmp,sizeof(chTmp));
		struct tm *p;
		time_t now_t = (time_t)now;
		p = localtime(&now_t);
		p->tm_year = p->tm_year + 1900;
		p->tm_mon = p->tm_mon + 1;
		snprintf(chTmp,sizeof(chTmp),"%04d-%02d-%02d %02d-%02d-%02d",\
				p->tm_year, p->tm_mon, p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		chTmp[19] = '\0';
		return chTmp;
	}


	static inline const char* getTimeStr(UInt64 now = Now())
	{
		static char chTmp[32];
		bzero(chTmp,sizeof(chTmp));
		struct tm *p;
		time_t now_t = (time_t)now;
		p = localtime(&now_t);
		p->tm_year = p->tm_year + 1900;
		p->tm_mon = p->tm_mon + 1;
		snprintf(chTmp,sizeof(chTmp),"%04d-%02d-%02d %02d:%02d:%02d",\
				p->tm_year, p->tm_mon, p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
		return chTmp;
	}
};

#endif // _TIMEUTIL_H_
