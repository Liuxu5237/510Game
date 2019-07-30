//
//  MultiPlatformMgr.cpp
//  NiuNiu
//
//  Created by zhong on 1/4/16.
//
//

#include "MultiPlatformMgr.h"

MultiPlatformMgr* MultiPlatformMgr::s_multiInstance = nullptr;

MultiPlatformMgr::MultiPlatformMgr()
{
    m_strMachineID = "";
    m_strVersion = "";

	m_nWebchatType = 0;
	m_ShareNoticeNameSuccess = "";
	m_ShareNoticeNameFail = "";
	//m_nOpenType = 0;
}

MultiPlatformMgr::~MultiPlatformMgr()
{
    
}

void MultiPlatformMgr::destroy()
{
    CC_SAFE_DELETE(s_multiInstance);
}

void MultiPlatformMgr::init()
{
    m_bOpenVibrator = true;
    m_pDelegate = nullptr;
}

void MultiPlatformMgr::test()
{
    cocos2d::log("base test");
}

void MultiPlatformMgr::triggerPickImg()
{
    cocos2d::log("base trigger");
}

void MultiPlatformMgr::switchVibratorState(bool bOpen)
{
    cocos2d::log("base switch");
}

void MultiPlatformMgr::vibrator()
{
    cocos2d::log("base vibrator");
}

std::string MultiPlatformMgr::clientVersionInfo()
{
    return m_strVersion;
}

void MultiPlatformMgr::updateVersion()
{
    cocos2d::log("base updateVersion");
}

std::string MultiPlatformMgr::getMachineId()
{
    return m_strMachineID;
}

void MultiPlatformMgr::updateMachineID()
{
    cocos2d::log("base updateMachineID");
}

// 显示提示文字
void MultiPlatformMgr::ShowToast(const std::string & str)
{
	//cocos2d::log(str.c_str());
}

// 获取当前的网络状态
bool MultiPlatformMgr::obtainNetWorkState()
{
	return false;
}

//打开分享
void MultiPlatformMgr::OpenShare(std::vector<int>& platforms, const char* text, const char* title,const char* imgName,const char* targeturl, const char* noticeSuccess, const char* noticeFail, bool isDirectShare)
{
	cocos2d::log("open share");
}

//得到电池电量
int MultiPlatformMgr::GetBatteryLevel()
{
	return 3;
}

//开始录音
void MultiPlatformMgr::startSoundRecord()
{

}

//结束录音
const char * MultiPlatformMgr::stopSoundRecord()
{
	return "";
}

typedef enum
{
	// Apple NetworkStatus Compatible Names.  
	NoNetWork = 0,
	ConnWiFi = 2,
	Conn3G = 1
} NetState;

//得到网络类型
int MultiPlatformMgr::GetNetType()
{
	return ConnWiFi;
}

//得到网络强度
int MultiPlatformMgr::GetNetLevel()
{
	return NETLEVEL_STRENGTH_GREAT;
}

//支付接口
int MultiPlatformMgr::Pay(float price, long userID, long gameID, std::string accounts, std::string ProductId, long appId, bool isFormal)
{
	return 0;
}

int MultiPlatformMgr::UMPay(float price, long userID, long gameID, std::string accounts, std::string ProductId)
{
	return 0;
}

//取消支付
int MultiPlatformMgr::UnPay()
{
	return 0;
}

int MultiPlatformMgr::WechatLogin(int nType/*=0*/)
{
	return 0;
}


bool MultiPlatformMgr::isAuthorized()
{
	return false;
}

int MultiPlatformMgr::deleteAuthorization()
{
	return 0;
}

void MultiPlatformMgr::CallCustomServiceIphone(std::string iphoneNum)
{
	cocos2d::log("call iphone");
}

void MultiPlatformMgr::openLocalPhoto()
{
	cocos2d::log("open LocalPhoto");
}
//登录
void MultiPlatformMgr::HandLogin()
{
	cocos2d::log("HandLogin");
}

void MultiPlatformMgr::HandChangeAccount()
{
	cocos2d::log("HandChangeAccount");
}


void MultiPlatformMgr::Handpay(std::string goodsName, double money, std::string object, std::string sid, std::string sname, int tag)
{
	cocos2d::log("Handpay");
}


void MultiPlatformMgr::HandFixedpay()
{
	cocos2d::log("HandFixedpay");
}


void MultiPlatformMgr::HandSubRole(std::string userId, std::string userName, int userLevel, long roleCTime, std::string zoneId, std::string zoneName)
{
	cocos2d::log("HandSubRole");
}

void MultiPlatformMgr::umengPay(double cash, int source, double coin, const char * item, int amount)
{
	cocos2d::log("umengPay");
}

void MultiPlatformMgr::umengBuy(const char *item, int amount, double price)
{
	cocos2d::log("umengBuy");
}

void MultiPlatformMgr::umengUser(const char *item, int amount, double price)
{
	cocos2d::log("umengUser");
}

void MultiPlatformMgr::umengbonus(const char *item, int amount, double price, int source)
{
	cocos2d::log("umengbonus");
}



