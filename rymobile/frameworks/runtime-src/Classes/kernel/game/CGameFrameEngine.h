#ifndef _I_GAME_FRAME_ENGINE_H_
#define	_I_GAME_FRAME_ENGINE_H_

#include "IClientKernelSink.h"


class CGameScene;
class IGameFrameEngineSink;

class  CGameFrameEngine : public IClientKernelSink
{
protected:
	// ����ʵ��
	static CGameFrameEngine * ms_pkInstance;

public:
	// ���庯��
	static CGameFrameEngine * Get()
	{
		if (ms_pkInstance == nullptr)
		{
			ms_pkInstance = new CGameFrameEngine;
		}
		return ms_pkInstance;
	}

	static void Destroy()
	{
		if (ms_pkInstance)
		{
			delete ms_pkInstance;
			ms_pkInstance = NULL;
		}
	}

protected:
	// ���캯��
	CGameFrameEngine();

	// ��������
	virtual ~CGameFrameEngine();

public:
	// ����c++��Ϸ�������ӿ�
	void SetGameFrameEngineSink(IGameFrameEngineSink * pGameFrameEngineSink)
	{ 
		m_gameFrameEngineSink = pGameFrameEngineSink; 
	}

	IGameFrameEngineSink * GetGameFrameEngineSink()
	{
		return m_gameFrameEngineSink;
	}

	void Clear();
	

	
public:

	//������Ϸ
	virtual bool SetupGameClient();

	//������Ϸ
	virtual void ResetGameClient();

	//�ر���Ϸ
	virtual void CloseGameClient();

	//��Ϸ�¼�
public:

	//�Թ���Ϣ
	virtual bool OnEventLookonMode(void* data, int dataSize);

	//������Ϣ
	virtual bool OnEventSceneMessage(BYTE cbGameStatus, bool bLookonUser, void* data, int dataSize);

	//������Ϣ
	virtual bool OnEventGameMessage(int sub, void * data, int dataSize);

	//����¼�
public:
	//ϵͳ������Ϣ
	virtual bool OnGFTableMessage(const char* szMessage);

	//�ȴ���ʾ
	virtual bool OnGFWaitTips(bool bWait);

	//�û��¼�
public:

	//�û�����
	virtual void OnEventUserEnter(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//�û��뿪
	virtual void OnEventUserLeave(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//�û�����
	virtual void OnEventUserScore(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//�û�״̬
	virtual void OnEventUserStatus(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//�û�����
	virtual void OnEventUserAttrib(IClientUserItem * pIClientUserItem, bool bLookonUser);

	//�û�ͷ��
	virtual void OnEventCustomFace(IClientUserItem * pIClientUserItem, bool bLookonUser);

public:

	// ������������
	bool RecvTalk(void* data,int dataSize);

public:

	// ���½�����Ϸ
	virtual void OnReEnterGame();

protected:

	// ��Ϸ������Ⱦ���
	CGameScene *	m_gameScene;

protected:
	// c++��Ϸ�������ӿ�
	IGameFrameEngineSink * m_gameFrameEngineSink;
};


#endif // !_GAME_FRAME_ENGINE_H_
