#ifndef I_GAME_FRAME_ENGINE_SINK_H__
#define I_GAME_FRAME_ENGINE_SINK_H__

#include "IClientKernelSink.h"
#include "IGameSceneSink.h"

class IGameFrameEngineSink
{
public:
	IGameFrameEngineSink()
	{
		m_gameSceneSink = NULL;
        CCLOG("--1-- IGameFrameEngineSink()=%p",this);
	}
	virtual ~IGameFrameEngineSink(){
		
		if (m_gameSceneSink)
		{
			delete m_gameSceneSink;
			m_gameSceneSink = NULL;
		}
	};

public:
	void SetGameSceneSink(IGameSceneSink * pGameSceneSink){
        CCLOG("--1-- SetGameSceneSink last=%p currr=%p",m_gameSceneSink, pGameSceneSink);
		m_gameSceneSink = pGameSceneSink;
	}

	IGameSceneSink * GetGameSceneSink()
	{
		return m_gameSceneSink;
	}
	//���ƽӿ�
public:

	//������Ϸ
	virtual bool SetupGameClient() = 0;

	//������Ϸ
	virtual void ResetGameClient() = 0;

	//�ر���Ϸ
	virtual void CloseGameClient() = 0;

	//��Ϸ�¼�
public:

	//�Թ���Ϣ
	virtual bool OnEventLookonMode(void* data, int dataSize) = 0;

	//������Ϣ
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void * data, int dataSize) = 0;

	//������Ϣ
	virtual bool OnEventGameMessage(int sub, void* data, int dataSize) = 0;

	//����¼�
public:

	//ϵͳ������Ϣ
	virtual bool OnGFTableMessage(const char* szMessage){ return true; }

	//�ȴ���ʾ
	virtual bool OnGFWaitTips(bool bWait){ return true; }

	//�û��¼�
public:

	//�û�����
	virtual void OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser){}

	//�û��뿪
	virtual void OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser){}

	//�û�����
	virtual void OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser){}

	//�û�״̬
	virtual void OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser){}

	//�û�����
	virtual void OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser){}

	//�û�ͷ��
	virtual void OnEventCustomFace(IClientUserItem * pIClientUserItem, bool bLookonUser){}

protected:

	IGameSceneSink * m_gameSceneSink;
};

#endif
