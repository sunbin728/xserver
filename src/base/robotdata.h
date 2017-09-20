#ifndef _ROBOTDATA_H_
#define _ROBOTDATA_H_

#include "basetype.h"
#include <string>

#pragma pack(1)
struct RobotData
{
    UInt8 robotId[32];
    UInt8 classId;
    UInt16 nameId;

    UInt32 age;
    UInt8 gender;
    UInt32 intellectual;
    UInt32 beautiful;
    UInt32 lovely;
    UInt32 skinState;
    UInt32 longPhy;
    UInt32 shortPhy;
    UInt32 energy;
    UInt32 thirsty;
    UInt32 hunger;
    UInt32 clean;
    UInt16 sufaceTemperature;
    UInt32 money;
    UInt32 registerTime; // game server ts
    //char   birthday[20];   // pw time 2017-03-29 00:00:00
    UInt64 birthday;
    UInt64 offlinePwTs;
    UInt16 locality;     // ref HouseArea.xlsx
    UInt32 sleep;
};

#pragma pack()

struct RobotConf
{
	std::string	_name;
	UInt16		_id;
	UInt16 		_name_id;
	UInt16 		_type;
	UInt16 		_age;
	UInt16 		_gender;
	UInt16 		_intellectual;
	UInt16 		_beautiful;
	UInt16 		_lovely;
	UInt16 		_skin_state;
	UInt16 		_long_physical;
	UInt16 		_short_physical;
	UInt16 		_energy;
	UInt16 		_thirsty;
	UInt16 		_hunger;
	UInt16 		_clean;
	UInt16 		_surface_temperature;
	UInt32 		_account;
    UInt16      _bornArea;
};

#endif /* _ROBOTDATA_H_ */
