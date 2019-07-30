#ifndef _CSocketMission_H_
#define _CSocketMission_H_

#include "ISocketEngine.h"
#include "ISocketEngineSink.h"
#include "fv/FvSingleton.h"
#include "cocos2d.h"
class CSocketMission : public cocos2d::Ref , public ISocketEngineSink
{
protected:
	// ���캯��
	CSocketMission();

	// ��������
	virtual ~CSocketMission();

//protected:

	// ����ʵ��
	//static CSocketMission *ms_pkInstance;

public:

	// ���庯��
	static CSocketMission * Instance()
	{
		CSocketMission* ms_pkInstance = new CSocketMission;
		//ms_pkInstance->autorelease();
		return ms_pkInstance;
	}

	static void Destroy(CSocketMission* intsance)
	{
		if (intsance != nullptr)
		{
			CC_SAFE_RELEASE_NULL(intsance);
			//intsance->release();
		}
	}

public:

	// ��������url
	void setUrl(const std::string & url, int port);

	// ��������������
	void start();

	// ֹͣ����������
	void stop();

	// �жϷ�����������״̬
	bool isAlive() const;

	// ����������Ϣ
	bool send(int main, int sub);

	// ����������Ϣ
	bool send(int main, int sub, const cocos2d::Ref * data, int size);

public:

	// ���÷��������ӳɹ�lua�ص�
	void setLinkSuccLuaCallBack(const std::string & strLinkSuccLuaCallBack);

	// ���÷��������ӹر�lua�ص�
	void setLinkDownLuaCallBack(const std::string & strLinkDownLuaCallBack);

	// ���÷��������Ӵ���lua�ص�
	void setLinkErrorLuaCallBack(const std::string & strLinkErrorLuaCallBack);

	// ���÷��������ݷ���lua�ص�
	void setLinkDataLuaCallBack(const std::string & strLinkDataLuaCallBack);

protected:

	// ���������ӳɹ�
	virtual void onEventTCPSocketLink();

	// ���������ӹر�
	virtual void onEventTCPSocketShut();

	// ����������ʧ��
	virtual void onEventTCPSocketError(int errorCode);

	// ���������ݷ���
	virtual bool onEventTCPSocketRead(int main, int sub, char * data, int dataSize);

private:

	// �����׽���
	ISocketEngine * mSocketEngine;

	// ���ӵ�ַ
	std::string		mUrl;

	// ���Ӷ˿�
	int				mPort;

private:
	// ���������ӳɹ�lua�ص�
	std::string		m_strLinkSuccLuaCallBack;

	// ���������ӹر�lua�ص�
	std::string		m_strLinkDownLuaCallBack;

	// ���������Ӵ���lua�ص�
	std::string		m_strLinkErrorLuaCallBack;
	
	// ���������ݷ���lua�ص�
	std::string		m_strLinkDataLuaCallBack;
}; // CSocketMission

#endif // _CSocketMission_H_