#include "CServerItem.h"
#include "tools/tools/Convert.h"

//管理消息
bool CServerItem::OnSocketMainManager(int sub, char * data, int dataSize)
{
	switch (sub)
	{
	case SUB_GR_OPTION_CURRENT:	//当前配置
		{
			////效验参数
			//ASSERT(dataSize==sizeof(CMD_GR_OptionCurrent));
			//if (dataSize!=sizeof(CMD_GR_OptionCurrent)) return false;

			PLAZZ_PRINTF("TODO:CServerItem::OnSocketMainManager unprocess\n");
			////消息处理
			//if (m_pDlgServerManager!=0)
			//{
			//	CMD_GR_OptionCurrent * pOptionCurrent=(CMD_GR_OptionCurrent *)data;
			//	m_pDlgServerManager->SetServerType(m_wServerType);
			//	m_pDlgServerManager->SetServerOptionInfo(pOptionCurrent->ServerOptionInfo,pOptionCurrent->dwRuleMask);
			//}

			return true;
		}
	}
	return false;
}
