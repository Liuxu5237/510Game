#pragma once

#include "cocos2d.h"
#include "network/HttpRequest.h"
#include "network/HttpClient.h"
#include "cocos/ui/UIImageView.h"


struct ImagicDownInfo
{
	ImagicDownInfo()
	{
		pSprite = NULL;
		pRequest = NULL;
		fActTime = 0;
	}
	cocos2d::ui::ImageView*			pSprite;
	cocos2d::network::HttpRequest*	pRequest;
	std::string						kUrl;	//��������url
	std::string						kImagicName;//��������·��
	float							fActTime;
	bool							bSameSize;	//��ʱ����
	int                             iType;	//����
	int								iUserId;	//�û�id
	int								iChairId;	//chair id
};

typedef std::vector<ImagicDownInfo> ImagicDownInfoList;
enum eDownType{
  eDownType_Game  ,//  (0)       //��Ϸ
  eDownType_HALL,//  (1)		//����
  eDownType_USER,// (2)       //��������
  eDownType_CHAIR_ID,// (3)   //��chairid����Ϸ��ͷ������
};
class ImagicDownManager : public cocos2d::Ref
{
protected:
	static ImagicDownManager *	m_ImagicDownManager;

public:
	//��ȡ����
	static ImagicDownManager * GetInstance() {

		if (m_ImagicDownManager == NULL)
		{
			m_ImagicDownManager = new ImagicDownManager();
		}

		return m_ImagicDownManager;
	}
private:
	ImagicDownManager();
	~ImagicDownManager();

public:
	/*�����ļ��ӿ�
	���ڷ����ļ�·��
	�����ڷ��ؿ�
	nType:��������
	kurl:����·��
	iUserID:�û�id
	bsamesize:�Ƿ�����ͬ�Ĵ�С
	chairid:�û�id
	*/
	std::string addDown(int nType, std::string kUrl, int iUserID, bool bSameSize = true,int chairId = 0);
	/*�Ƿ��д��ļ�
	����ֵ����
	�����ļ�·��
	*/
	std::string ExistDownFile(eDownType nType, std::string kUrl, int iUserID);
protected:
	void OnImagic();
	void GetImagic(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response);

private:

	cocos2d::Texture2D* getDownTexture(std::string kFile);
	//void addDown(int Type, std::string kUrl, std::string kFileName, int iUserID);
	void upTime(float fTime);
	//void setImagic( std::string kImagic, int bSameSize);
	cocos2d::network::HttpRequest* getFile(std::string kUrl, const cocos2d::network::ccHttpRequestCallback &callback);
	//void  addDownCallBack(cocos2d::Ref * obj);
	//�õ������ļ���
	std::string GetDownFileName(int nUserId, int nIndex);
	//�õ������ļ�ȫ��
	std::string GetDownFullFileName(int nUserId, int nIndex);
	//�õ������ļ�����
	std::string GetDownFilePath();
	//�õ�url��Ψһ��ʶ��
	int GetUrlId(std::string url);

protected:
	int												m_iIdexCout;
	ImagicDownInfoList								m_pDownList;
	std::vector<cocos2d::network::HttpResponse*>	m_pGetList;
	std::string										m_strSavePath;	//�ļ�����·��
};
