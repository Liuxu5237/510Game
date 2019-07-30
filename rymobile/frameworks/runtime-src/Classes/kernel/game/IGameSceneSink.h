#ifndef I_GAME_SCENE_SINK_H__
#define I_GAME_SCENE_SINK_H__

#include "cocos2d.h"
#include "platform/df/types.h"
USING_NS_CC;

class CGameScene;
class IClientUserItem;

class IGameSceneSink
{
public:
	IGameSceneSink()
	{
		m_pGameScene = NULL;
        CCLOG("--1-- IGameSceneSink() p=%p",this);
	}
	virtual ~IGameSceneSink(){};

public:
	// ��ʼ������
	virtual bool init(CGameScene * pGameScene)
	{
		m_pGameScene = pGameScene;
        CCLOG("--1-- init(CGameScene * pGameScene)=%p",m_pGameScene);
		return true;
	}

public:

	//������Ϸ
	virtual bool SetupGameClient() = 0;

	//������Ϸ
	virtual void ResetGameClient() = 0;

	//�ر���Ϸ
	virtual void CloseGameClient() = 0;

public:

	// ������ʼ
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){ return true; }

	// �����ƶ�
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){}

	// ��������
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){}


public:
	// ��������Ϣ
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void* data, int dataSize)
	{
		return true;
	}

	//��Ϸ��Ϣ
	virtual bool OnEventGameMessage(int sub, void* data, int dataSize)
	{
		return true;
	}

public:

	//������Ϸ����
	virtual void onEnterTransitionDidFinish() {}

	//��������
	virtual void update(float delta){}
public:

	// ��Ϸ��ͣ
	virtual void OnGameEnterBackground() = 0;

	// ��Ϸ�ָ�
	virtual void OnGameEnterForeground() = 0;

	// ��������ӿ�
	virtual void OnReconnectResumeGame() = 0;

	// ��⵽����Ͽ�
	virtual void OnDetectNetDown() = 0;

	// �����Ѿ����ã����뵽��������״̬
	virtual void OnEnterReconnectState() = 0;

public:

	//�û�����
	virtual void OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser) = 0;

	//�û��뿪
	virtual void OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser) = 0;

	//�û��뿪
	virtual void OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser) = 0;

	//�û�����
	virtual void OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser) = 0;

	//�û�����
	virtual void OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser) = 0;

public:

	//�ȴ�����
	virtual void OnSubWaitBack() = 0;


protected:

	CGameScene * m_pGameScene;
};

#endif
