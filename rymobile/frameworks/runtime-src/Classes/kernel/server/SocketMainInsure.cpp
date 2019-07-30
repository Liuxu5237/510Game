#include "CServerItem.h"

//银行消息
bool CServerItem::OnSocketMainInsure(int sub, char * data, int dataSize)
{
	//效验状态
	ASSERT(data!=0);
	if (data==0) return true;

	//游戏处理
	byte *pActivityGame = (byte*)data;
	if(*pActivityGame==TRUE)
	{
		return OnSocketMainGameFrame(MDM_GR_INSURE,sub,data,dataSize);
	}

	////消息处理
	//ASSERT(m_pDlgInsureServer!=0);
	//if (m_pDlgInsureServer==0) return true;
	//if (m_pDlgInsureServer->OnServerInsureMessage(MDM_GR_INSURE,sub,data,dataSize)==false)
	//{
	//	ASSERT(FALSE);
	//	return false;
	//}

	return false;
}
