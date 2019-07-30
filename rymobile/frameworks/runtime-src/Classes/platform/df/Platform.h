#ifndef PLATFORM_HEAD_FILE
#define PLATFORM_HEAD_FILE

//////////////////////////////////////////////////////////////////////////////////
//包含文件

//定义文件
#include "Macro.h"
#include "../df/Define.h"

//结构文件
#include "../df/Struct.h"
#include "../df/Packet.h"
#include "../df/Property.h"

//模板文件
//#include "Array.h"
#include "../df/Module.h"
//#include "PacketAide.h"
#include "../df/ServerRule.h"
#include "../df/RightDefine.h"

//////////////////////////////////////////////////////////////////////////////////

//程序版本
#define VERSION_FRAME				PROCESS_VERSION(8,0,0)				//框架版本
#define VERSION_PLAZA				PROCESS_VERSION(8,0,0)				//大厅版本
#define VERSION_MOBILE_ANDROID		PROCESS_VERSION(7,0,1)				//手机版本
#define VERSION_MOBILE_IOS			PROCESS_VERSION(7,0,1)				//手机版本

//版本定义
#define VERSION_EFFICACY			0									//效验版本
#define VERSION_FRAME_SDK			INTERFACE_VERSION(7,1)				//框架版本

#endif