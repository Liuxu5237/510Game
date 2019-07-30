#include "CServerItem.h"
#include "../game/IClientKernel.h"

//游戏消息
//框架消息
bool CServerItem::OnSocketMainGameFrame(int main, int sub, char * data, int dataSize)
{
	//效验数据
	ASSERT(dataSize<=SOCKET_TCP_PACKET);
	if (dataSize>SOCKET_TCP_PACKET) return false;


	if (!IClientKernel::get() || !mIsGameReady)
		return true;
		
	return IClientKernel::get()->OnGFEventSocket(main, sub, data, dataSize);
}
