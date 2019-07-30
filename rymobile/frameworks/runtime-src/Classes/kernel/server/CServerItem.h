#ifndef _CServerItem_H_
#define _CServerItem_H_

#include "IServerItemSink.h"
#include "IServerItem.h"
#include "TableViewFrame.h"


#include "../IRoomFrameSink.h"
#include "../IGameFrameSink.h"
#include "../IChatSink.h"
#include "../IStringMessageSink.h"

#include "../user/ClientUserManager.h"

#include "kernel/network/ISocketEngine.h"
#include "kernel/network/ISocketEngineSink.h"


class CTableViewFrame;
class CUserManager;

class CServerItem 
	: public IServerItem
	, public IUserManagerSink
	, public ISocketEngineSink
	//, public IRoomFrameSink
{

public:
	CServerItem();
	~CServerItem();
	//////////////////////////////////////////////////////////////////////////
	// IServerItem
	//////////////////////////////////////////////////////////////////////////
	//配置接口
public:
	//设置接口
	virtual bool SetServerItemSink(IServerItemSink* pIServerItemSink);

	//设置接口
	virtual bool SetChatSink(IChatSink* pIChatSink);

	//设置接口
	virtual bool SetStringMessageSink(IStringMessageSink* pIStringMessageSink);

	//配置房间
	virtual bool SetServerAttribute(CGameServerItem * pGameServerItem,word wAVServerPort,dword dwAVServerAddr);

	//连接接口
public:
	//初始化房间
	virtual bool ConnectServer(CGameServerItem * pGameServerItem,WORD wAVServerPort,dword dwAVServerAddr);

	//重连服务器
	virtual bool ReconnectServer(CGameServerItem * pGameServerItem,WORD wAVServerPort,dword dwAVServerAddr);

	//中断连接
	virtual bool IntermitConnect(bool force);
	
	//强行断开链接
	virtual void TerminConnect();

	//恢复链接
	virtual void ResumeConnect();

	//属性接口
public:
	//用户属性
	virtual tagUserAttribute* GetUserAttribute();

	//房间属性
	virtual tagServerAttribute*  GetServerAttribute();

	//服务状态
	virtual enServiceStatus GetServiceStatus();

	//是否服务状态
	virtual bool IsService();

	//设置状态
	virtual void SetServiceStatus(enServiceStatus ServiceStatus);

	//自己状态
	virtual bool IsPlayingMySelf();
	
	//用户接口
public:
	//自己位置
	virtual WORD GetMeChairID();

	//自己位置
	virtual IClientUserItem * GetMeUserItem();

	//游戏用户
	virtual IClientUserItem * GetTableUserItem(WORD wChariID);

	//查找用户
	virtual IClientUserItem * SearchUserByUserID(dword dwUserID);

	//查找用户
	virtual IClientUserItem * SearchUserByGameID(dword dwGameID);

	//查找用户
	virtual IClientUserItem * SearchUserByNickName(const char* szNickName);

	//用户数
	virtual dword GetActiveUserCount();
	
	//桌子接口
public:
	//获取对应桌子是否锁的状态
	virtual bool GetTableLockState(int tableId);

	//桌子是否游戏
	virtual bool GetTableGameState(int tableId);

	//获取桌子
	virtual CTableViewFrame*  GetTableItem();
	//网络接口
public:
	//发送函数
	virtual bool SendSocketData(WORD wMainCmdID, WORD wSubCmdID);

	//发送函数
	virtual bool SendSocketData(WORD wMainCmdID, WORD wSubCmdID, const char * data, WORD dataSize);

	//发送函数
	virtual bool SendSocketDataLua(word wMainCmdID, word wSubCmdID, const cocos2d::Ref * data);

	//网络命令
public:
	//发送登录
	virtual bool SendLogonPacket();

	//发送规则
	virtual bool SendUserRulePacket();

	//发送旁观
	virtual bool SendLookonPacket(WORD wTableID, WORD wChairID);

	//发送坐下
	virtual bool SendSitDownPacket(WORD wTableID, WORD wChairID, const char* lpszPassword=0);

	//发送起立
	virtual bool SendStandUpPacket(WORD wTableID, WORD wChairID, BYTE cbForceLeave);

	//发送表情
	virtual bool SendExpressionPacket(dword dwTargetUserID, WORD wItemIndex);

	//发送聊天
	virtual bool SendUserChatPacket(dword dwTargetUserID, const char* pszChatString, dword dwColor);

	//发送报名
	virtual bool SendFullApply(SCORE fee);

	virtual bool SendStandUp();

	//动作处理
public:
	//查找桌子
	virtual bool SearchGameTable(tagSearchTable * SearchTable);

	//执行快速加入
	virtual bool PerformQuickSitDown();
	virtual bool PerformAutoJoin();

	//执行旁观
	virtual bool PerformLookonAction(WORD wTableID, WORD wChairID);

	//执行起立
	virtual bool PerformStandUpAction(WORD wTableID, WORD wChairID);

	//执行坐下
	virtual bool PerformSitDownAction(WORD wTableID, WORD wChairID, bool bEfficacyPass, const char * psw = nullptr);

	//执行购买
	virtual bool PerformBuyProperty(BYTE cbRequestArea,const char* pszNickName, WORD wItemCount, WORD wPropertyIndex);

	//内部函数
protected:
	//聊天效验
	bool EfficacyUserChat(const char* pszChatString, WORD wExpressionIndex);

	//桌子效验
	bool EfficacyTableRule(WORD wTableID, WORD wChairID, bool bReqLookon, char strDescribe[256]);

	//获得空的桌子id
	virtual WORD GetSpaceTableId(WORD iTableid);
	//获得空的椅子
	virtual WORD GetSpaceChairId(WORD tableId);
	//获得桌子总数量
	virtual WORD GetTotalTableCount();
public:
	//是否是分组房间
	bool IsDistributionTable();

	//////////////////////////////////////////////////////////////////////////
	// IUserManagerSink
	//////////////////////////////////////////////////////////////////////////
public:
	virtual void OnUserItemAcitve(IClientUserItem* pIClientUserItem);
	virtual void OnUserItemDelete(IClientUserItem* pIClientUserItem);
	virtual void OnUserFaceUpdate(IClientUserItem* pIClientUserItem);
	virtual void OnUserItemUpdate(IClientUserItem* pIClientUserItem, const tagUserScore& LastScore);
	virtual void OnUserItemUpdate(IClientUserItem* pIClientUserItem, const tagUserStatus& LastStatus);
	virtual void OnUserItemUpdate(IClientUserItem* pIClientUserItem, const tagUserAttrib & UserAttrib);

	//////////////////////////////////////////////////////////////////////////
	// ISocketEngineSink
	//////////////////////////////////////////////////////////////////////////
protected:
	virtual void onEventTCPSocketLink();
	virtual void onEventTCPSocketShut();
	virtual void onEventTCPSocketError(int errorCode);
	virtual bool onEventTCPSocketRead(int main, int sub, char * data, int dataSize);

	//////////////////////////////////////////////////////////////////////////
	//登录消息
	bool OnSocketMainLogon(int sub, char * data, int dataSize);
	//登录成功
	bool OnSocketSubLogonSuccess(char* data, int dataSize);
	//登录失败
	bool OnSocketSubLogonFailure(char* data, int dataSize);
	//登录完成
	bool OnSocketSubLogonFinish(char* data, int dataSize);
	//更新提示
	bool OnSocketSubUpdateNotify(char* data, int dataSize);


	
	//////////////////////////////////////////////////////////////////////////
	//配置信息
	bool OnSocketMainConfig(int sub, char* data, int dataSize);
	//列表配置
	bool OnSocketSubConfigColumn(char* data, int dataSize);
	//房间配置
	bool OnSocketSubConfigServer(char* data, int dataSize);
	//道具配置
	bool OnSocketSubConfigProperty(char* data, int dataSize);
	//配置玩家权限	
	bool OnSocketSubConfigUserRight(char* data, int dataSize);
	//配置完成
	bool OnSocketSubConfigFinish(char* data, int dataSize);

	//////////////////////////////////////////////////////////////////////////
	//用户信息
	bool OnSocketMainUser(int sub, char* data, int dataSize);
	//请求失败
	bool OnSocketSubRequestFailure(char* data, int dataSize);
	//邀请玩家
	bool OnSocketSubUserInvite(char* data, int dataSize);
	//等待分配
	bool OnSocketSubWaitDistribute(char* data, int dataSize);
	//用户进入
	bool OnSocketSubUserEnter(char* data, int dataSize);
	//用户进入（完整）
	bool OnSocketSubUserEnterSimple(char* data, int dataSize);
	//用户积分
	bool OnSocketSubUserScore(char* data, int dataSize);
	//用户状态
	bool OnSocketSubUserStatus(char* data, int dataSize);
	//用户聊天
	bool OnSocketSubUserChat(char* data, int dataSize);
	//用户表情
	bool OnSocketSubExpression(char* data, int dataSize);
	//用户私聊
	bool OnSocketSubWisperUserChat(char* data, int dataSize);
	//私聊表情
	bool OnSocketSubWisperExpression(char* data, int dataSize);
	//道具成功
	bool OnSocketSubPropertySuccess(char* data, int dataSize);
	//道具失败
	bool OnSocketSubPropertyFailure(char* data, int dataSize);
	//道具效应
	bool OnSocketSubPropertyEffect(char* data, int dataSize);
	//道具消息
	bool OnSocketSubPropertyMessage(char* data, int dataSize);
	//道具喇叭
	bool OnSocketSubPropertyTrumpet(char* data, int dataSize);
	//喜报消息
	bool OnSocketSubGladMessage(char* data, int dataSize);

	//////////////////////////////////////////////////////////////////////////
	//状态信息
	bool OnSocketMainStatus(int sub, char* data, int dataSize);
	//桌子信息
	bool OnSocketSubStatusTableInfo(char* data, int dataSize);
	//桌子状态
	bool OnSocketSubStatusTableStatus(char* data, int dataSize);

	//////////////////////////////////////////////////////////////////////////
	//银行消息
	bool OnSocketMainInsure(int sub, char* data, int dataSize);

	//////////////////////////////////////////////////////////////////////////
	//管理消息
	bool OnSocketMainManager(int sub, char* data, int dataSize);

	//////////////////////////////////////////////////////////////////////////
	//系统消息
	bool OnSocketMainSystem(int sub, char* data, int dataSize);
	//系统消息
	bool OnSocketSubSystemMessage(char* data, int dataSize);
	//动作消息
	bool OnSocketSubActionMessage(char* data, int dataSize);

	//////////////////////////////////////////////////////////////////////////
	//游戏消息,框架消息
	bool OnSocketMainGameFrame(int main, int sub, char* data, int dataSize);
	
	//////////////////////////////////////////////////////////////////////////
	//比赛消息
	bool OnSocketMainMatch(int sub, char* data, int dataSize);
	
	//房卡信息
	bool OnSocketMainPrivate(int sub, char * data, int dataSize);

	//////////////////////////////////////////////////////////////////////////
	// 框架消息
public:
	//游戏已准备好
	virtual void OnGFGameReady(bool bInit);
	//游戏关闭
	virtual void OnGFGameClose(int iExitCode);
	//放作弊场通知玩家进入新的游戏
	virtual void AvertGameEnter();

	//////////////////////////////////////////////////////////////////////////
	// Socket消息
public:
	// 发送数据
	virtual bool GFSendData(int main, int sub, const char * data, int size);
	bool	mIsQuickSitDown;   //是否快速加入


	//////////////////////////////////////////////////////////////////////////
	// 数据
	//////////////////////////////////////////////////////////////////////////
	tagGameServer		mGameServer;					//房间信息
private:
	//辅助变量
	WORD	mReqTableID;						//请求桌子
	WORD	mReqChairID;						//请求位置
	WORD	mFindTableID;						//查找桌子
	bool	mIsGameReady;						//游戏是否准备好
	int     mLastJoinTableID;                        //上次快速加入桌子ID
	word    mNullchaircount;
	//用户
	IClientUserItem*	mMeUserItem;
	CPlazaUserManager*	mUserManager;

	//房间属性
	enServiceStatus		mServiceStatus;
	tagGameKind			mGameKind;						//类型信息

	tagUserAttribute	mUserAttribute;					//用户属性
	tagServerAttribute	mServerAttribute;				//房间属性

	//配置参数
	CParameterGame*		mParameterGame;					//游戏配置
	CParameterServer*	mParameterServer;				//房间配置
	
	//桌子
	CTableViewFrame		mTableViewFrame;				//桌子框架

	//接口
	IServerItemSink*	mIServerItemSink;				//房间接口
	IChatSink*			mIChatSink;						//聊天接口
	IStringMessageSink*	mIStringMessageSink;			//信息接口
	
	// 网络连接
	ISocketEngine*		mSocketEngine;
};
#endif // _CServerItem_H_