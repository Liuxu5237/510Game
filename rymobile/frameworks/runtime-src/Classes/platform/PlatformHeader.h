#ifndef PLATFORMHEADER_H_
#define PLATFORMHEADER_H_


// 
#include "data/GlobalUnits.h"
#include "data/GlobalUserInfo.h"
#include "data/OptionParameter.h"
#include "data/ServerListData.h"

#include "df/Define.h"
#include "df/DF.h"
#include "df/Macro.h"
#include "df/Module.h"
#include "df/Packet.h"
#include "df/Platform.h"
#include "df/Property.h"
#include "df/RightDefine.h"
#include "df/ServerRule.h"
#include "df/ServerRule.h"
#include "df/Struct.h"
#include "df/types.h"

#include "cocos2d.h"

#include <ctime>
#include <iostream>

#define PLAZZ_PRINTF cocos2d::log
/*
#define PLAZZ_PRINTF 
time_t t = time(NULL); \
struct tm*  stime = localtime(&t);\
char strTime[1024] = {};\
std::sprintf(strTime,"%04d-%02d-%02d %02d:%02d:%02d ", 1900 + stime->tm_year, 1 + stime->tm_mon,\
stime->tm_mday, stime->tm_hour,	stime->tm_min, stime->tm_sec);\
cocos2d::log(strTime); \
cocos2d::log
*/

#include "msg/CMD_Commom.h"
#include "msg/CMD_GameServer.h"
#include "msg/CMD_LogonServer.h"

#endif
