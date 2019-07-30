#include "GameCenterManager.h"

#include "tools/global.h"
#include "tools/tools/StringData.h"
#include "tools/tools/MTNotification.h"
#include "tools/tools/MyConfigureData.h"

#include "platform/data/PlatformGameConfig.h"
#include "platform/df/RoomEventIDDefine.h"
#include "platform/df/GameEventIDDefine.h"

#include "../game/IClientKernel.h"
#include "../game/CGameFrameEngine.h"
#include "CCLuaEngine.h"
#include "lua/LuaStackEx.h"
/************************************************************************/
/* 构造函数                                                             */
/************************************************************************/

CGameCenterManager * CGameCenterManager::ms_pkInstance = NULL;
CGameCenterManager::CGameCenterManager()
{
	mServerItem = 0;
	m_bCanCreateTable = true;
	m_iMatcState = 0;
	m_bChangDesk = false;
	mCServerItem = NULL;
	mGameServerItem = NULL;
}

/************************************************************************/
/* 析构函数                                                             */
/************************************************************************/
CGameCenterManager::~CGameCenterManager()
{
	if (IServerItem::get())
	{
		mServerItem->SetServerItemSink(0);
		mServerItem->SetChatSink(0);
		mServerItem->SetStringMessageSink(0);
	}

	if (IServerItem::get())
	{
		IServerItem::get()->IntermitConnect(true);
	}

	IServerItem::destory();

	mServerItem = 0;
}

/************************************************************************/
/* 初始化方法                                                           */
/************************************************************************/
bool CGameCenterManager::init(CGameServerItem* pGameServerItem)
{
	do
	{
		mGameServerItem = pGameServerItem;
		connectServer();	
		return true;
	} while (0);
	
	return false;
}

/************************************************************************/
/* 请求失败                                                             */
/************************************************************************/
void CGameCenterManager::onGRRequestFailure(const std::string & szDescribeString)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_REQUEST_FAILURE, 0, 0, szDescribeString));
}

/************************************************************************/
/* 登陆成功                                                             */
/************************************************************************/
void CGameCenterManager::OnGRLogonSuccess()
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_LOGON_SUCCESS));
}

/************************************************************************/
/* 登陆失败                                                             */
/************************************************************************/
void CGameCenterManager::OnGRLogonFailure(long lErrorCode, const std::string& sDescribeString)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_LOGON_FAILURE, 0, 0, sDescribeString));
}

/************************************************************************/
/* 登陆完成                                                             */
/************************************************************************/
void CGameCenterManager::OnGRLogonFinish()
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_LOGON_FINISH));
}

/************************************************************************/
/* 更新通知                                                             */
/************************************************************************/
void CGameCenterManager::OnGRUpdateNotify(byte cbMustUpdate, const std::string& szDescribeString)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_UPDATE_NOTIFY, cbMustUpdate, 0, szDescribeString));
}

/************************************************************************/
/* 列表配置                                                             */
/************************************************************************/
void CGameCenterManager::OnGRConfigColumn()
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_CONFIG_COLUMN));
}

/************************************************************************/
/* 房间配置                                                             */
/************************************************************************/
void CGameCenterManager::OnGRConfigServer()
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_CONFIG_SERVER));
}

/************************************************************************/
/* 道具配置                                                             */
/************************************************************************/
void CGameCenterManager::OnGRConfigProperty()
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_CONFIG_PROPERTY));
}

/************************************************************************/
/* 玩家权限配置                                                         */
/************************************************************************/
void CGameCenterManager::OnGRConfigUserRight()
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_CONFIG_USER_RIGHT));
}

/************************************************************************/
/* 配置完成                                                             */
/************************************************************************/
void CGameCenterManager::OnGRConfigFinish()
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_CONFIG_FINISH));
}

/************************************************************************/
/* 用户进入                                                             */
/************************************************************************/
void CGameCenterManager::OnGRUserEnter(IClientUserItem * pIClientUserItem)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_USER_ENTER, 0, 0, pIClientUserItem->GetNickName()));
}

/************************************************************************/
/* 用户更新                                                             */
/************************************************************************/
void CGameCenterManager::OnGRUserUpdate(IClientUserItem * pIClientUserItem)
{
	if (pIClientUserItem == IServerItem::get()->GetMeUserItem())
	{
		G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_USER_ME_UPDATE, pIClientUserItem->GetUserID(), 0, pIClientUserItem->GetNickName()));
	}
	else
	{
		G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_USER_OTHER_UPDATE, pIClientUserItem->GetUserID(), 0, pIClientUserItem->GetNickName()));
	}
}

/************************************************************************/
/* 用户删除                                                             */
/************************************************************************/
void CGameCenterManager::OnGRUserDelete(IClientUserItem* pIClientUserItem)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_USER_DELETE, pIClientUserItem->GetUserID()));
}

/************************************************************************/
/* 用户邀请                                                             */
/************************************************************************/
void CGameCenterManager::OnGFUserInvite(const std::string& szMessage)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_USER_INVITE, 0, 0, szMessage));
}

/************************************************************************/
/* 用户邀请失败                                                         */
/************************************************************************/
void CGameCenterManager::OnGFUserInviteFailure(const std::string& szMessage)
{	
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_USER_INVITE_FAILURE, 0, 0, szMessage));
}

/************************************************************************/
/* 房间退出                                                             */
/************************************************************************/
void CGameCenterManager::OnGFServerClose(const std::string& szMessage)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_SERVER_CLOSE, 0, 0, szMessage));
}

/************************************************************************/
/* 链接服务器失败                                                      */
/************************************************************************/
void CGameCenterManager::OnConnectServerError(int errorCode)
{
	if (!IClientKernel::get())
	{
		G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_CONNECT_SERVER_ERROR, errorCode));
	}
	else
	{
		G_NOTIFY_D("RECONNECT_ON_LOSS", MTData::create());
	}
}

/************************************************************************/
/*用户表情                                                               */
/************************************************************************/
bool CGameCenterManager::InsertExpression(const char* pszSendUser, unsigned int index)
{
	return true;
}

/************************************************************************/
/* 用户表情                                                              */
/************************************************************************/
bool CGameCenterManager::InsertExpression(const char* pszSendUser, unsigned int index, bool bMyselfString)
{
	return true;
}

/************************************************************************/
/* 用户表情                                                              */
/************************************************************************/
bool CGameCenterManager::InsertExpression(const char* pszSendUser, const char* pszRecvUser, unsigned int index)
{
	return true;
}

/************************************************************************/
/* 用户聊天                                                             */
/************************************************************************/
bool CGameCenterManager::InsertUserChat(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 说:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/* 用户聊天                                                             */
/************************************************************************/
bool CGameCenterManager::InsertUserChat(const char* pszSendUser, const char* pszRecvUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 对 %s 说:%s\n"), pszSendUser, pszRecvUser, pszString);
	return true;
}

/************************************************************************/
/* 用户私聊                                                              */
/************************************************************************/
bool CGameCenterManager::InsertWhisperChat(const char* pszSendUser, const char* pszString, unsigned int crColor, bool bMyselfString)
{
	//PLAZZ_PRINTF(t8("%s 对你说:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/* 用户喇叭                                                              */
/************************************************************************/
bool CGameCenterManager::InsertUserTrumpet(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 发送Trumpet喇叭:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/* 用户喇叭                                                             */
/************************************************************************/
bool CGameCenterManager::InsertUserTyphon(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 发送Typhon喇叭:%s\n"), pszSendUser, pszString);
	return true;
}

/************************************************************************/
/*系统消息                                                               */
/************************************************************************/
bool CGameCenterManager::InsertSystemChat(const char* pszString)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_INSERT_SYSTEM_STR, 0, 0, pszString));
	return true;
}

/************************************************************************/
/* 玩家进入事件                                                         */
/************************************************************************/
bool CGameCenterManager::InsertUserEnter(const char* pszUserName)
{
	return true;
}

/************************************************************************/
/* 玩家离开事件                                                         */
/************************************************************************/
bool CGameCenterManager::InsertUserLeave(const char* pszUserName)
{
	return true;
}

/************************************************************************/
/* 断线事件                                                            */
/************************************************************************/
bool CGameCenterManager::InsertUserOffLine(const char* pszUserName)
{
	return true;
}

/************************************************************************/
/* 普通消息(窗口输出)                                                   */
/************************************************************************/
bool CGameCenterManager::InsertNormalString(const char* pszString)
{
	return true;
}

/************************************************************************/
/* 系统消息(窗口输出)                                                   */
/************************************************************************/
bool CGameCenterManager::InsertSystemString(const char* pszString)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_INSERT_SYSTEM_STR,0,0,pszString));
	return true;
}

/************************************************************************/
/* 提示消息(对话框方式??)                                               */
/************************************************************************/
int CGameCenterManager::InsertPromptString(const char* pszString, int iButtonType)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_PROMPT_STR, iButtonType, 0, pszString));
	return 0;
}

/************************************************************************/
/* 公告消息(窗口输出)                                                   */
/************************************************************************/
bool CGameCenterManager::InsertAfficheString(const char* pszString)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_PROMPT_STR, 0, 0, pszString));
	return true;
}

/************************************************************************/
/* 喜报消息                                                             */
/************************************************************************/
bool CGameCenterManager::InsertGladString(const char * pszContent, const char * pszNickName, const char * pszNum, dword colText, dword colName, dword colNum)
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_GLAD_STRING, colText, colName, pszContent, pszNickName, pszNum));
	return true;
}

/************************************************************************/
/* 创建游戏内核                                                         */
/************************************************************************/
bool CGameCenterManager::CreateKernel()
{
	IClientKernel* kernel = IClientKernel::get();
	if (kernel == NULL)
	{
		kernel = IClientKernel::create();
		if (kernel == 0)
			return false;

		std::string luaModuleName = CPlatformGameConfig::shared()->getValue(mGameServerItem->m_GameServer.wKindID, "game_lua_module");
		if (luaModuleName == "")
		{
			LuaEngine * pEngine = LuaEngine::defaultEngine();
			if (pEngine){

				LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
				luaStack->call_script_fun("game.createGameInstance", (int)mGameServerItem->m_GameServer.wKindID);
			}
		}
		else
		{
			LuaEngine * pEngine = LuaEngine::defaultEngine();
			if (pEngine){

				LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
				luaStack->call_script_fun(luaModuleName + ".createGameInstance");
			}

			CGameFrameEngine::Get()->SetGameFrameEngineSink(NULL);
		}
	}
	else
	{
		CGameFrameEngine::Get()->OnReEnterGame();
	}
	

	kernel->setGameServerItem(mGameServerItem);

	if (kernel->Init())
	{
		G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_GAME_INIT_SUCC));
		return true;
	}
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_GAME_INIT_FAILURE));

	IClientKernel::destory();
	return false;
}

/************************************************************************/
/* 开始游戏                                                             */
/************************************************************************/
bool CGameCenterManager::StartGame()
{
	//if (CheckInfo(SSTRING("Sys_con_My")))
	//	return false;

	m_bCanCreateTable = false;

	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_START_GAME));
	return true;
}

/************************************************************************/
/* 游戏关闭通知                                                          */
/************************************************************************/
bool CGameCenterManager::OnGameClose(int exitCode)
{
	m_bCanCreateTable = true;
	G_NOTIFY_D("game_event", MTData::create(GAME_EVENT_ID_GAME_CLOSE, exitCode));

	return true;
}

/************************************************************************/
/* 防作弊场进入游戏                                                      */
/************************************************************************/
void CGameCenterManager::AvertGameEnter()
{
	IClientUserItem * item = mServerItem->GetMeUserItem();
	WORD chair_id = item->GetChairID();
	WORD table_id = item->GetTableID();
	BYTE user_status = item->GetUserStatus();

	if (item->GetChairID() != INVALID_CHAIR && item->GetTableID() != INVALID_TABLE)
	{
		if ((item->GetUserStatus() == US_READY || item->GetUserStatus() == US_PLAYING))
		{
			this->StartGame();
		}
	}
}



/************************************************************************/
/* 链接服务器                                                           */
/************************************************************************/
void CGameCenterManager::connectServer()
{
	G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_ON_CONNECT_SERVER));

	disconnectServer();

	if (mServerItem == 0)
	{
		mServerItem = IServerItem::create();

		mCServerItem = dynamic_cast<CServerItem *>(mServerItem);
		mServerItem->SetServerItemSink(this);
		mCServerItem->SetStringMessageSink(this);
		mCServerItem->SetChatSink(this);
		loadGameBaseData();
		//mServerItem->ConnectServer(mGameServerItem, 0, 0);
	}
}

/************************************************************************/
/* 链接服务器                                                           */
/************************************************************************/
void CGameCenterManager::connectServer(CGameServerItem* pGameServerItem)
{
	mGameServerItem = pGameServerItem;
	connectServer();
}

/************************************************************************/
/* 重连服务器                                                           */
/************************************************************************/
void CGameCenterManager::reconnectServer()
{
	if (mServerItem)
	{
		mServerItem->ReconnectServer(mGameServerItem, 0, 0);
	}
}

/************************************************************************/
/* 载入游戏资源数据                                                     */
/************************************************************************/
void CGameCenterManager::loadGameBaseData()
{
	std::string luaModuleName = CPlatformGameConfig::shared()->getValue(mGameServerItem->m_GameServer.wKindID, "game_lua_module");
	if (luaModuleName == "")
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun("game.setGameBaseData", (int)(mGameServerItem->m_GameServer.wKindID));
		}
	}
	else
	{
		LuaEngine * pEngine = LuaEngine::defaultEngine();
		if (pEngine ){

			LuaStackEx * luaStack = static_cast<LuaStackEx*>(pEngine->getLuaStack());
			luaStack->call_script_fun(luaModuleName + ".setGameBaseData");
		}
	}
}

/************************************************************************/
/* 断开服务器                                                           */
/************************************************************************/
void CGameCenterManager::disconnectServer()
{
	if (mServerItem){

		if (IServerItem::get())
		{
			mServerItem->SetServerItemSink(0);
			mServerItem->SetChatSink(0);
			mServerItem->SetStringMessageSink(0);
		}

		if (IServerItem::get())
		{
			IServerItem::get()->IntermitConnect(true);
		}

		IServerItem::destory();
		mServerItem = 0;
	}
}

/************************************************************************/
/* 快速坐下椅子处理                                                     */
/************************************************************************/
void CGameCenterManager::QuickSitdown(WORD table_id, WORD chair_id)
{
	if (!this->m_bChangDesk)
	{
		G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_QUICK_SIT_DOWN));
	}

	WORD meTableID = table_id;
	WORD meChairID = chair_id;

	CTableViewFrame* tableview = mCServerItem->GetTableItem();
	ITableView * tableItem = tableview->GetTableViewItem(table_id);
	if (table_id != INVALID_TABLE &&
		chair_id != INVALID_CHAIR &&
		table_id < mServerItem->GetTotalTableCount())
	{
		bool isHave = true;
		isHave = mServerItem->PerformSitDownAction(table_id, chair_id, false);
	}
}