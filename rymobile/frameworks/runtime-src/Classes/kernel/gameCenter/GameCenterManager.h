#ifndef _GAME_CENTER_MANAGER_H_
#define _GAME_CENTER_MANAGER_H_


#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
#pragma warning( disable : 4005) 
#endif

#include <map>
#include "cocos2d.h"
#include "../server/CServerItem.h"
#include "../server/IServerItemSink.h"
#include "../IStringMessageSink.h"
#include "platform/df/types.h"
#include "platform/data/ServerListData.h"
#include "../user/IClientUserItem.h"
#include "platform/msg/CMD_GameServer.h"
using namespace std;

class CGameCenterManager : public cocos2d::Ref
	, IServerItemSink
	, IStringMessageSink
	, IChatSink
{
protected:
	// 单体实例
	static CGameCenterManager * ms_pkInstance;
	
public:

	// 单体函数
	static CGameCenterManager * Instance()
	{
		if (ms_pkInstance == nullptr)
		{
			ms_pkInstance = new CGameCenterManager;
		}
		return ms_pkInstance;
	}

private:

	// 构造函数
	CGameCenterManager();

	// 析构函数
	virtual ~CGameCenterManager();

public:

	// 初始化方法
	bool init(CGameServerItem* pGameServerItem);

protected:

	//坐下失败
	virtual void onGRRequestFailure(const std::string& sDescribeString);

	//登陆成功
	virtual void OnGRLogonSuccess();

	//登陆失败
	virtual void OnGRLogonFailure(long lErrorCode, const std::string& sDescribeString);

	//登陆完成
	virtual void OnGRLogonFinish();

	//更新通知
	virtual void OnGRUpdateNotify(byte cbMustUpdate, const std::string& sDescribeString);

public:
	//列表配置
	virtual void OnGRConfigColumn();

	//房间配置
	virtual void OnGRConfigServer();

	//道具配置
	virtual void OnGRConfigProperty();

	//玩家权限配置
	virtual void OnGRConfigUserRight();

	//配置完成
	virtual void OnGRConfigFinish();

	//用户信息
public:

	//用户进入
	virtual void OnGRUserEnter(IClientUserItem* pIClientUserItem);

	//用户更新
	virtual void OnGRUserUpdate(IClientUserItem* pIClientUserItem);

	//用户删除
	virtual void OnGRUserDelete(IClientUserItem* pIClientUserItem);

	//表情消息
public:

	//用户表情
	virtual bool InsertExpression(const char* pszSendUser, unsigned int index);

	//用户表情
	virtual bool InsertExpression(const char* pszSendUser, unsigned int index, bool bMyselfString);

	//用户表情
	virtual bool InsertExpression(const char* pszSendUser, const char* pszRecvUser, unsigned int index);

	//聊天消息
public:
	//用户聊天
	virtual bool InsertUserChat(const char* pszSendUser, const char* pszString, unsigned int crColor);

	//用户聊天
	virtual bool InsertUserChat(const char* pszSendUser, const char* pszRecvUser, const char* pszString, unsigned int crColor);

	//用户私聊
	virtual bool InsertWhisperChat(const char* pszSendUser, const char* pszString, unsigned int crColor, bool bMyselfString);

	//用户喇叭
	virtual bool InsertUserTrumpet(const char* pszSendUser, const char* pszString, unsigned int crColor);

	//用户喇叭
	virtual bool InsertUserTyphon(const char* pszSendUser, const char* pszString, unsigned int crColor);

	//系统消息
public:

	//系统消息
	virtual bool InsertSystemChat(const char * pszString);

	//事件消息
public:
	
	//进入事件
	virtual bool InsertUserEnter(const char* pszUserName);

	//离开事件
	virtual bool InsertUserLeave(const char* pszUserName);

	//断线事件
	virtual bool InsertUserOffLine(const char* pszUserName);
	//字符消息
public:

	//普通消息(窗口输出)
	virtual bool InsertNormalString(const char* pszString);

	//系统消息(窗口输出)
	virtual bool InsertSystemString(const char* pszString);

	//提示消息(对话框方式??)
	virtual int InsertPromptString(const char* pszString, int iButtonType);

	//公告消息(窗口输出)
	virtual bool InsertAfficheString(const char* pszString);

	//定制消息
public:
	//喜报消息
	virtual bool InsertGladString(const char* pszContent, const char* pszNickName, const char* pszNum, dword colText, dword colName, dword colNum);

	//框架消息
public:

	//用户邀请
	virtual void OnGFUserInvite(const std::string& szMessage);

	//用户邀请失败
	virtual void OnGFUserInviteFailure(const std::string& szMessage);

	//房间退出
	virtual void OnGFServerClose(const std::string& szMessage);

	// 链接服务器失败
	virtual void OnConnectServerError(int errorCode);

	//创建游戏内核
	virtual bool CreateKernel();

	// 开始游戏
	virtual bool StartGame();

	// 游戏关闭通知
	virtual bool OnGameClose(int nErrorCode);

	// 放作弊场通知玩家进入新的游戏
	virtual void AvertGameEnter();


	//辅助函数
public:
	// 链接服务器
	void connectServer();

	// 链接服务器
	void connectServer(CGameServerItem* pGameServerItem);

	// 重连服务器
	void reconnectServer();

	// 载入游戏资源数据
	void loadGameBaseData();

	// 断开连接
	void disconnectServer();

public:
	// 玩家坐下
	void QuickSitdown(WORD chair_id, WORD table_id);

	CC_SET_AND_GET(bool, m_bChangDesk, ChangDesk)
	CC_SET_AND_GET(bool, m_bCanCreateTable, CanCreateTable)
	CC_SET_AND_GET(BYTE, m_iMatcState, MatcState)
public:

	CServerItem* GetServerItem(){
		return mCServerItem;
	}

	CGameServerItem * GetGameServerItem()
	{
		return mGameServerItem;
	}

private:
	// 游戏服务器信息
	CGameServerItem*	mGameServerItem;

	// 服务器链接接口
	IServerItem*		mServerItem;

	// 游戏服务器链接
	CServerItem*		mCServerItem;
};
#endif // _ServerScene_H_