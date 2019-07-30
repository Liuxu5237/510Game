#ifndef		_GAME_SCENE_H
#define		_GAME_SCENE_H

#include "cocos2d.h"
#include "IGameTouchSink.h"
#include "platform/df/types.h"
#include "../IChatSink.h"
#include "../IStringMessageSink.h"

class CGameFrameEngine;
class IClientUserItem;
class IGameSceneSink;

class CGameScene :
	public cocos2d::Layer,
	public IGameTouchSink, public IChatSink, public IStringMessageSink
{
public:
	// 构造函数
	CGameScene();

	// 析构函数
	virtual ~CGameScene();

public:
	
	// 初始化函数
	virtual bool init();

public:

	//启动游戏
	bool SetupGameClient();

	//重置游戏
	void ResetGameClient();

	//关闭游戏
	void CloseGameClient();

public:

	// 进入游戏场景完成
	virtual void onEnterTransitionDidFinish();

	// 心跳函数
	virtual void update(float delta);

public:

	//用户进入
	virtual void OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//用户离开
	virtual void OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//用户离开
	virtual void OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//用户积分
	virtual void OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//用户属性
	virtual void OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser);

public:

	//处理断线重连进入游戏场景消息
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void* data, int dataSize);
	
	//处理游戏消息
	virtual bool OnEventGameMessage(int sub, void* data, int dataSize);

public:

	//在断网的情况下检测到网络
	void OnNetDetectedInNetLossState();

protected:

	// 游戏暂停
	void OnGameEnterBackground(cocos2d::Ref* obj);

	// 游戏恢复
	void OnGameEnterForeground(cocos2d::Ref* obj);

	// 重连进入接口
	void OnReconnectResumeGame(cocos2d::Ref * obj);

public:
	
	// 触摸开始
	virtual bool onTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	// 触摸移动
	virtual void onTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	// 触摸结束
	virtual void onTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

public:

	//接收聊天数据
	void RecvTalk(void* data, int dataSize);

public:
	
	// 切换椅子
	WORD SwitchViewChairID(WORD wChairID);

protected:
	// 底层通知网络链接断开
	void OnDetectNetDown(cocos2d::Ref * obj);

	// 检测网络的链接状况
	void reconnect_on_loss(float dt);

public:
	// 断线重连重新进入游戏
	void OnReEnterGame();

protected:

	//等待分组
	void OnSubWaitBack(cocos2d::Ref * obj);

public:
	
	// 设置游戏引擎指针
	void SetGameFrameEngine(CGameFrameEngine * pGameFrameEngine)
	{
		m_GameFrameEngine = pGameFrameEngine;
	}

	// 得到游戏引擎指针
	CGameFrameEngine * GetGameFrameEngine()
	{
		return m_GameFrameEngine;
	}

	// 设置游戏场景接口
	void SetGameSceneSink(IGameSceneSink * pGameSceneSink)
	{
        CCLOG("--1-- SetGameSceneSink last=%p  curr=%p",m_gameSceneSink,pGameSceneSink);
		m_gameSceneSink = pGameSceneSink;
        
	}

public:
	// 发送语音文件
	void sendTalkFile(int iChair, std::string kFile);

	// 发送文字 
	void sendTalkString(int iChair, std::string strString);

	//发送常用语
	void sendTalkDefine(int iChair, std::string strSoundPath);

	//发送表情
	void sendTalkBiaoQing(int iChair, std::string strFilePath);

protected:

	//接收聊天文件
	bool RevTalk_File(tagUserTalk* pNetInfo);

	bool RevTalk_String(tagUserTalk* pNetInfo);

	bool RevTalk_TalkIdex(tagUserTalk* pNetInfo);

	bool RevTalk_BiaoQing(tagUserTalk* pNetInfo);

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

protected:

	// 游戏场景引擎接口
	IGameSceneSink *	m_gameSceneSink;

	// 游戏框架
	CGameFrameEngine *	m_GameFrameEngine;

	// 网络出现问题，在有网的情况已经通知玩家
	bool				m_haveNotifyUserOnHaveNet;

	// 网络出现问题，在没网的情况已经通知玩家
	bool				m_haveNotifyUserOnNoNet;

	// 已经重连
	bool				m_nReconnetFlag;

	cocos2d::EventListenerTouchOneByOne* _touchListener;
};

#endif
