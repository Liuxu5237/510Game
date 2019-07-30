#include "CServerItem.h"

#include "tools/tools/StringData.h"
#include "tools/tools/PacketReadAide.h"
#include "tools/tools/PacketWriteAide.h"
#include "CCLuaEngine.h"
#include "lua/LuaStackEx.h"
#include "tools/tools/PacketWriteAide.h"
#include "tools/tools/PacketReadAide.h"

USING_NS_CC;

/************************************************************************/
/*  比赛消息处理                                                        */
/************************************************************************/
bool CServerItem::OnSocketMainPrivate(int sub, char * data, int dataSize)
{
	LuaEngine * pEngine = LuaEngine::defaultEngine();
	if (pEngine){

		LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());

		PACKET_AIDE_DATA(data);
		return luaStack->call_script_fun("privateInterface.OnSocketMainPrivate", sub, (cocos2d::Ref *)&packet, dataSize) > 0 ? true : false;
	}
	
	return true;
}

