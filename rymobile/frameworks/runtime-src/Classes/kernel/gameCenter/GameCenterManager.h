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
	// ����ʵ��
	static CGameCenterManager * ms_pkInstance;
	
public:

	// ���庯��
	static CGameCenterManager * Instance()
	{
		if (ms_pkInstance == nullptr)
		{
			ms_pkInstance = new CGameCenterManager;
		}
		return ms_pkInstance;
	}

private:

	// ���캯��
	CGameCenterManager();

	// ��������
	virtual ~CGameCenterManager();

public:

	// ��ʼ������
	bool init(CGameServerItem* pGameServerItem);

protected:

	//����ʧ��
	virtual void onGRRequestFailure(const std::string& sDescribeString);

	//��½�ɹ�
	virtual void OnGRLogonSuccess();

	//��½ʧ��
	virtual void OnGRLogonFailure(long lErrorCode, const std::string& sDescribeString);

	//��½���
	virtual void OnGRLogonFinish();

	//����֪ͨ
	virtual void OnGRUpdateNotify(byte cbMustUpdate, const std::string& sDescribeString);

public:
	//�б�����
	virtual void OnGRConfigColumn();

	//��������
	virtual void OnGRConfigServer();

	//��������
	virtual void OnGRConfigProperty();

	//���Ȩ������
	virtual void OnGRConfigUserRight();

	//�������
	virtual void OnGRConfigFinish();

	//�û���Ϣ
public:

	//�û�����
	virtual void OnGRUserEnter(IClientUserItem* pIClientUserItem);

	//�û�����
	virtual void OnGRUserUpdate(IClientUserItem* pIClientUserItem);

	//�û�ɾ��
	virtual void OnGRUserDelete(IClientUserItem* pIClientUserItem);

	//������Ϣ
public:

	//�û�����
	virtual bool InsertExpression(const char* pszSendUser, unsigned int index);

	//�û�����
	virtual bool InsertExpression(const char* pszSendUser, unsigned int index, bool bMyselfString);

	//�û�����
	virtual bool InsertExpression(const char* pszSendUser, const char* pszRecvUser, unsigned int index);

	//������Ϣ
public:
	//�û�����
	virtual bool InsertUserChat(const char* pszSendUser, const char* pszString, unsigned int crColor);

	//�û�����
	virtual bool InsertUserChat(const char* pszSendUser, const char* pszRecvUser, const char* pszString, unsigned int crColor);

	//�û�˽��
	virtual bool InsertWhisperChat(const char* pszSendUser, const char* pszString, unsigned int crColor, bool bMyselfString);

	//�û�����
	virtual bool InsertUserTrumpet(const char* pszSendUser, const char* pszString, unsigned int crColor);

	//�û�����
	virtual bool InsertUserTyphon(const char* pszSendUser, const char* pszString, unsigned int crColor);

	//ϵͳ��Ϣ
public:

	//ϵͳ��Ϣ
	virtual bool InsertSystemChat(const char * pszString);

	//�¼���Ϣ
public:
	
	//�����¼�
	virtual bool InsertUserEnter(const char* pszUserName);

	//�뿪�¼�
	virtual bool InsertUserLeave(const char* pszUserName);

	//�����¼�
	virtual bool InsertUserOffLine(const char* pszUserName);
	//�ַ���Ϣ
public:

	//��ͨ��Ϣ(�������)
	virtual bool InsertNormalString(const char* pszString);

	//ϵͳ��Ϣ(�������)
	virtual bool InsertSystemString(const char* pszString);

	//��ʾ��Ϣ(�Ի���ʽ??)
	virtual int InsertPromptString(const char* pszString, int iButtonType);

	//������Ϣ(�������)
	virtual bool InsertAfficheString(const char* pszString);

	//������Ϣ
public:
	//ϲ����Ϣ
	virtual bool InsertGladString(const char* pszContent, const char* pszNickName, const char* pszNum, dword colText, dword colName, dword colNum);

	//�����Ϣ
public:

	//�û�����
	virtual void OnGFUserInvite(const std::string& szMessage);

	//�û�����ʧ��
	virtual void OnGFUserInviteFailure(const std::string& szMessage);

	//�����˳�
	virtual void OnGFServerClose(const std::string& szMessage);

	// ���ӷ�����ʧ��
	virtual void OnConnectServerError(int errorCode);

	//������Ϸ�ں�
	virtual bool CreateKernel();

	// ��ʼ��Ϸ
	virtual bool StartGame();

	// ��Ϸ�ر�֪ͨ
	virtual bool OnGameClose(int nErrorCode);

	// �����׳�֪ͨ��ҽ����µ���Ϸ
	virtual void AvertGameEnter();


	//��������
public:
	// ���ӷ�����
	void connectServer();

	// ���ӷ�����
	void connectServer(CGameServerItem* pGameServerItem);

	// ����������
	void reconnectServer();

	// ������Ϸ��Դ����
	void loadGameBaseData();

	// �Ͽ�����
	void disconnectServer();

public:
	// �������
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
	// ��Ϸ��������Ϣ
	CGameServerItem*	mGameServerItem;

	// ���������ӽӿ�
	IServerItem*		mServerItem;

	// ��Ϸ����������
	CServerItem*		mCServerItem;
};
#endif // _ServerScene_H_