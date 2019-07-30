#ifndef _CClientKernel_H_
#define _CClientKernel_H_

#include "IClientKernel.h"

#include "kernel/network/ISocketEngine.h"
#include "../user/ClientUserManager.h"
#include "../IRoomFrameSink.h"
#include "../IGameFrameSink.h"


class CGameClientKernel 
	: public IClientKernel
	, public IUserManagerSink
	//, public IGameFrameSink
{

public:
	CGameClientKernel();
	virtual ~CGameClientKernel();

	//////////////////////////////////////////////////////////////////////////
	// IClientKernel
	//配置接口
public:
	//设置接口
	virtual bool SetChatSink(IChatSink* pIChatSink);
	//设置接口
	virtual bool SetStringMessageSink(IStringMessageSink* pIStringMessageSink);
	//内核配置
	virtual bool Init();
	//关闭游戏
	virtual bool Intermit(int iExitCode);

	//关闭连接
	virtual bool IntermitConnect(int iExitCode);

	//属性接口
public:
	//用户属性
	virtual tagUserAttribute * GetUserAttribute();
	//游戏属性
	virtual tagGameAttribute * GetGameAttribute();
	//房间属性
	virtual tagServerAttribute * GetServerAttribute();
		
	//模式接口
public:
	//单机模式
	virtual bool IsSingleMode();
	//旁观状态
	virtual bool IsLookonMode();
	//允许状态
	virtual bool IsAllowLookon();

public:
	// 是否比赛房间
	virtual bool IsMatchRoom();

	//状态接口
public:
	//获取状态
	virtual byte GetGameStatus();
	//设置状态
	virtual void SetGameStatus(byte cbGameStatus);

	//用户接口
public:
	//自己位置
	virtual word GetMeChairID();
	//自己位置
	virtual IClientUserItem * GetMeUserItem();
	//游戏用户
	virtual IClientUserItem * GetTableUserItem(word wChariID);
	//查找用户
	virtual IClientUserItem * SearchUserByUserID(dword dwUserID);
	//查找用户
	virtual IClientUserItem * SearchUserByGameID(dword dwGameID);
	//查找用户
	virtual IClientUserItem * SearchUserByNickName(const char* szNickName);
	//旁观用户
	virtual IClientUserItem * EnumLookonUserItem(word wEnumIndex);

	//网络接口
public:
	//发送函数
	virtual bool SendSocketData(word wMainCmdID, word wSubCmdID);
	//发送函数
	virtual bool SendSocketData(word wMainCmdID, word wSubCmdID, const char * data, word dataSize);
	//发送函数
	virtual bool SendSocketDataLua(word wMainCmdID, word wSubCmdID, const cocos2d::Ref * data, word dataSize);
	//功能接口
public:
	//发送进入场景
	virtual bool SendGameOption();
	//发送准备
	virtual bool SendUserReady();
	//旁观控制
	virtual bool SendUserLookon(dword dwUserID, bool bAllowLookon);
	//发送表情
	virtual bool SendUserExpression(dword dwTargetUserID, word wItemIndex);
	//发送聊天
	virtual bool SendUserChatMessage(dword dwTargetUserID, const char* pszChatString, dword crColor);

	//辅助接口
public:
	//激活框架
	virtual void ActiveGameFrame();
	//切换椅子
	virtual word SwitchViewChairID(word wChairID);

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
	//IGameFrameSink
	
	//配置接口
public:
	//房间配置
	virtual void OnGFConfigServer(const tagUserAttribute * UserAttribute, const tagServerAttribute * ServerAttribute);
	//配置完成
	virtual void OnGFConfigFinish();

	//Socket接口
public:
	virtual bool OnGFEventSocket(int main, int sub, void* data, int dataSize);

	//用户聊天
	bool OnSocketSubUserChat(void* data, int dataSize);
	//游戏消息
	bool OnSocketSubUserTalk(void* data, int dataSize);
	//用户表情
	bool OnSocketSubExpression(void* data, int dataSize);
	//游戏状态
	bool OnSocketSubGameStatus(void* data, int dataSize);
	//游戏场景
	bool OnSocketSubGameScene(void* data, int dataSize);
	//旁观状态
	bool OnSocketSubLookonStatus(void* data, int dataSize);
	//系统消息
	bool OnSocketSubSystemMessage(void* data, int dataSize);
	//动作消息
	bool OnSocketSubActionMessage(void* data, int dataSize);

	//用户接口
public:
	//用户进入
	virtual void OnGFUserEnter(IClientUserItem* pIClientUserItem);
	//用户积分
	virtual void OnGFUserScore(dword dwUserID, const tagUserScore& UserScore);
	//用户状态
	virtual void OnGFUserStatus(dword dwUserID, const tagUserStatus& UserStatus);
	//用户属性
	virtual void OnGFUserAttrib(dword dwUserID, const tagUserAttrib& UserAttrib);
	//用户自定义头像
	virtual void OnGFUserCustomFace(dword dwUserID,  dword dwCustomID, const tagCustomFaceInfo& CustomFaceInfo);


//////////////////////////////////////////////////////////////////////////
	// 捕鱼前控交互

	bool onOperateStock(uint8_t code_, int range_);

	bool onOperateRBL(uint8_t code_, uint8_t rbl_, dword game_id, uint64_t limit_score);

	bool onGiveFish(dword game_id_, uint8_t bird_type_[], int type_count_, int catch_count_, float catch_probability_);

	bool onSetDifficulty(int difficulty_, dword game_id_, uint8_t operate_code_);

	//////////////////////////////////////////////////////////////////////////
	// 数据
	//////////////////////////////////////////////////////////////////////////
private:
	bool mAllowLookon;									//是否允许旁观
	byte mGameStatus;									//游戏状态
	bool m_bInit;
	IClientUserItem*	mMeClientUserItem;					//自身数据
	CGameUserManager*	mUserManager;					//用户管理

	tagUserAttribute	mUserAttribute;					//用户属性
	tagGameAttribute	mGameAttribute;					//游戏属性
	tagServerAttribute	mServerAttribute;				//房间属性
	
	//接口
	IChatSink*			mIChatSink;						//聊天接口
	IStringMessageSink*	mIStringMessageSink;			//信息接口

};
#endif // _CClientKernel_H_