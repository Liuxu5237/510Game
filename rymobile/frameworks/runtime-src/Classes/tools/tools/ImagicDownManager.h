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
	std::string						kUrl;	//传过来的url
	std::string						kImagicName;//本地生成路径
	float							fActTime;
	bool							bSameSize;	//暂时无用
	int                             iType;	//类型
	int								iUserId;	//用户id
	int								iChairId;	//chair id
};

typedef std::vector<ImagicDownInfo> ImagicDownInfoList;
enum eDownType{
  eDownType_Game  ,//  (0)       //游戏
  eDownType_HALL,//  (1)		//大厅
  eDownType_USER,// (2)       //个人中心
  eDownType_CHAIR_ID,// (3)   //有chairid的游戏内头像下载
};
class ImagicDownManager : public cocos2d::Ref
{
protected:
	static ImagicDownManager *	m_ImagicDownManager;

public:
	//获取对象
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
	/*下载文件接口
	存在返回文件路径
	不存在返回空
	nType:下载类型
	kurl:下载路径
	iUserID:用户id
	bsamesize:是否是相同的大小
	chairid:用户id
	*/
	std::string addDown(int nType, std::string kUrl, int iUserID, bool bSameSize = true,int chairId = 0);
	/*是否有此文件
	返回值：空
	或者文件路径
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
	//得到下载文件名
	std::string GetDownFileName(int nUserId, int nIndex);
	//得到下载文件全名
	std::string GetDownFullFileName(int nUserId, int nIndex);
	//得到下载文件夹名
	std::string GetDownFilePath();
	//得到url的唯一标识符
	int GetUrlId(std::string url);

protected:
	int												m_iIdexCout;
	ImagicDownInfoList								m_pDownList;
	std::vector<cocos2d::network::HttpResponse*>	m_pGetList;
	std::string										m_strSavePath;	//文件保存路径
};
