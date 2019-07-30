//
//  MultiPlatformMgr-ios.cpp
//  NiuNiu
//
//  Created by zhong on 1/4/16.
//
//

#include "MultiPlatformMgr-ios.h"
#import "AppController.h"
#import "RootViewController.h"
#import <AVFoundation/AVFoundation.h>

//iOS中获取网卡mac信息
#include <sys/socket.h> // Per msqr
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
//#include "../proj.ios_mac/ios/SystemInfo.h"
//#include "IosSysUtils.h"
//#include "Cocos2dx/Common/CCUMSocialSDK.h"
#include "tools/tools/MTNotification.h"
#include "platform/df/RoomEventIDDefine.h"
//#include "IosHelper.h"
#include "tools/StringUtility.h"

//#include "MobClickCpp.h"

/*
 *
 */
//#import <SXSdk/SXSdkApi.h>

void shareCallback(int platform, int stCode, const string& errorMsg);
void AuthorizeCallBack(int platform, int stCode, const map<string, string>& data);
void deleteAuthorizationCallBack(int platform, int stCode, const map<string, string>& data);

@interface FaceChoiceDelegate : NSObject<UINavigationControllerDelegate,UIImagePickerControllerDelegate>
{
	
}
@end

@implementation FaceChoiceDelegate

+(UIImage*)reSizeImage:(UIImage*)image toSize:(CGSize)reSize
{
	UIGraphicsBeginImageContext(CGSizeMake(reSize.width, reSize.height));
	[image drawInRect:CGRectMake(0, 0, reSize.width, reSize.height)];
	UIImage *reSizeImage = UIGraphicsGetImageFromCurrentImageContext();
	UIGraphicsEndImageContext();
	return reSizeImage;
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingImage:(UIImage *)image editingInfo:(NSDictionary *)editingInfo
{
	[picker dismissModalViewControllerAnimated:YES completion:nil];
	UIImage *pimage = [FaceChoiceDelegate reSizeImage:image toSize:CGSizeMake(48.0, 48.0)];
	NSData *imageData = UIImagePNGRepresentation(pimage);
	
	cocos2d::Image * pcimage = new cocos2d::Image();
	if (pcimage->initWithImageData((const unsigned char *)[imageData bytes], [imageData length]))
	{
		if (MultiPlatformMgr::getInstance()->getPlatformDelegate())
		{
			MultiPlatformMgr::getInstance()->getPlatformDelegate()->didPickImgFinish(pcimage);
		}
	}
	pcimage->release();
	[self release];
}

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
	[picker dismissModalViewControllerAnimated:YES completion:nil];
	[self release];
}

@end

MultiPlatformMgr_ios::MultiPlatformMgr_ios()
{
	m_nWebchatType = 0;
	m_ShareNoticeNameSuccess = "";
	m_ShareNoticeNameFail = "";
}

MultiPlatformMgr_ios::~MultiPlatformMgr_ios()
{
	
}

MultiPlatformMgr* MultiPlatformMgr::getInstance()
{
	if (nullptr == s_multiInstance)
	{
		s_multiInstance = new MultiPlatformMgr_ios();
	}
	return s_multiInstance;
}

void MultiPlatformMgr_ios::test()
{
	cocos2d::log("ios test");
}

void MultiPlatformMgr_ios::triggerPickImg()
{
	UIImagePickerController *pickerImage = [[UIImagePickerController alloc] init];
	if([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypePhotoLibrary]) {
		pickerImage.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
		pickerImage.mediaTypes = [UIImagePickerController availableMediaTypesForSourceType:pickerImage.sourceType];
		
	}
	FaceChoiceDelegate *delegate = [[FaceChoiceDelegate alloc] init];
	pickerImage.delegate = delegate;
	pickerImage.allowsEditing = YES;
	AppController * pApp = (AppController*)[[UIApplication sharedApplication] delegate];
	//[pApp.viewController presentModalViewController:pickerImage animated:YES];
	//[pApp.viewController presentViewController:((UIImagePickerController *)pickerImage) animated:YES completion:nil];
}

void MultiPlatformMgr_ios::switchVibratorState(bool bOpen)
{
	m_bOpenVibrator = bOpen;
	if (m_bOpenVibrator)
	{
		AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
	}
}

void MultiPlatformMgr_ios::vibrator()
{
	if (!m_bOpenVibrator)
	{
		return;
	}
	AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
}


void MultiPlatformMgr_ios::startSoundRecord()
{
	std::string kFileName = utility::toString(time(NULL),".wav");
	s_kRecordFileName = cocos2d::FileUtils::getInstance()->getWritablePath()+kFileName;
	//IosHelper::beginRecord(s_kRecordFileName.c_str());
}


const char* MultiPlatformMgr_ios::stopSoundRecord()
{
	//IosHelper::endRecord();
	return s_kRecordFileName.c_str();
}

void MultiPlatformMgr_ios::updateVersion()
{
	NSString *app_version = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
	if (nil != app_version)
	{
		m_strVersion = [app_version UTF8String];
	}
	else
	{
		m_strVersion = "";
	}
}

void MultiPlatformMgr_ios::OpenShare(std::vector<int>& platforms, const char* text, const char* title,const char* imgName,const char* targeturl, const char* noticeSuccess, const char* noticeFail, bool isDirectShare)
{
	
//	umeng::social::CCUMSocialSDK *sdk = umeng::social::CCUMSocialSDK::create();
//	sdk->setLogEnable(true) ;
	
	//sdk->setWeiXinAppInfo("wx94e1db9c1ae1c391","754a7e4edc6e228193569089b813ecb4");
	//sdk->setTargetUrl("http://www.dushigame.cn");
	//vector<int>* platforms1 = new vector<int>();
	//platforms1->push_back(umeng::social::WEIXIN_CIRCLE) ;
	//platforms->push_back(umeng::social::WEIXIN) ;
	//sdk->setPlatforms(platforms) ;
	//void openShare(vector<int>* platforms,const char* text, const char* title,const char* imgName,const char* targeturl,ShareEventHandler callback);
	//sdk->openShare(const char *text, const char *imgName, ShareEventHandler callback)
	//umeng::social::ShareEventHandler
	//sdk->openShare(platforms,"都市游戏-江西人自己的棋牌游戏","都市游戏-江西人自己的棋牌游戏", "https://i1.piimg.com/1949/5a3349d85bd5fd24.png","http://www.dushigame.cn", (umeng::social::ShareEventHandler)(&shareCallback));
	
	vector<int>* sharePlatforms = new vector<int>();
	for (size_t i = 0; i< platforms.size(); i++)
	{
		sharePlatforms->push_back(platforms[i]);
	}
	m_ShareNoticeNameSuccess = "";
	m_ShareNoticeNameFail = "";
	if (strlen(noticeSuccess) > 0)
	{
		m_ShareNoticeNameSuccess = noticeSuccess;
	}
	
	if (strlen(noticeFail) > 0)
	{
		m_ShareNoticeNameFail = noticeFail;
	}
	
	if (strlen(targeturl) == 0)
	{
		targeturl = NULL;
	}
	
	if (isDirectShare)
	{
		//sdk->directShare(platforms[0], text, title, imgName, targeturl, (umeng::social::ShareEventHandler)(&shareCallback));
	}
	else
	{
		//sdk->openShare(sharePlatforms, text, title, imgName, targeturl, (umeng::social::ShareEventHandler)(&shareCallback));
	}
	
}

void shareCallback(int platform, int stCode, const string& errorMsg)
{
	std::string strSuccess = (MultiPlatformMgr::getInstance())->GetShareNoticeNameSuccess();
	std::string strFail = (MultiPlatformMgr::getInstance())->GetShareNoticeNameFail();
	
	if ( stCode == 100 )
	{
		if ("" != strFail )
		{
			G_NOTIFY(strFail);
		}
	}
	else if ( stCode == 200 )
	{
		if ("" != strSuccess)
		{
			G_NOTIFY(strSuccess);
		}
		
	}
	else
	{
		if ("" != strFail )
		{
			G_NOTIFY(strFail);
		}
	}
}

int MultiPlatformMgr_ios::WechatLogin(int nType)
{
//	m_nWebchatType = nType;
//	umeng::social::CCUMSocialSDK *sdk = umeng::social::CCUMSocialSDK::create();
//	sdk->getPlatformInfo(umeng::social::WEIXIN,(umeng::social::AuthEventHandler)(&AuthorizeCallBack));
	
	return 1;
}

void AuthorizeCallBack(int platform, int stCode, const map<string, string>& data)
{
	int ntype = ((MultiPlatformMgr::getInstance()))->GetWebChatType();
	if (stCode == 100 )//开始授权
	{
		CCLOG("开始授权");
	}
	else if (stCode == 200)//授权成功
	{
		CCLOG("授权成功");
		
		std::string Result = "";
		std::string uid = data.at("uid");
		std::string openid = data.at("openid");
		std::string accessToken = data.at("accessToken");
		std::string refreshToken = data.at("refreshToken");
		std::string name = data.at("name");
		std::string iconurl = data.at("iconurl");
		std::string gender = data.at("gender");
		Result = uid + "," + refreshToken + "," + name + "," + openid + "," + iconurl + "," + "0";
		if (ntype == 0)
		{
			G_NOTIFY_D("Login_Event", MTData::create(1, 0, 0, Result));
		}
		else if (ntype == 1)
		{
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 0, 0, Result));
		}
		
	}
	else if (stCode == 0)//代表授权出错
	{
		CCLOG("授权出错");
		if (ntype == 0)
		{
			G_NOTIFY_D("Login_Event", MTData::create(1, 1));
		}else if (ntype == 1)
		{
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 1, 0, "error"));
		}
		
	}
	else if (stCode == -1)//代表取消授权
	{
		CCLOG("取消授权");
		if (ntype == 0)
		{
			G_NOTIFY_D("Login_Event", MTData::create(1, 2));
		}else if (ntype == 1)
		{
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 1, 0, "cancel"));
		}
		
	}
	
	
	
	//0代表授权出错, -1代表取消授权
}

//void AuthorizeCallBack1(int platform, int stCode, const map<string, string>& data)




//判断是否授权
bool MultiPlatformMgr_ios::isAuthorized()
{
	/*
	 umeng::social::CCUMSocialSDK *sdk = umeng::social::CCUMSocialSDK::create("57beae30e0f55a0f1f0015b4");
	 sdk->setWeiXinAppInfo("wx94e1db9c1ae1c391","754a7e4edc6e228193569089b813ecb4");
	 return sdk->isAuthorized(umeng::social::WEIXIN);*/
}

//删除授权
int MultiPlatformMgr_ios::deleteAuthorization()
{
	/*
	 umeng::social::CCUMSocialSDK *sdk = umeng::social::CCUMSocialSDK::create("57beae30e0f55a0f1f0015b4");
	 sdk->setWeiXinAppInfo("wx94e1db9c1ae1c391","754a7e4edc6e228193569089b813ecb4");
	 sdk->deleteAuthorization(umeng::social::WEIXIN, (umeng::social::AuthEventHandler)(&deleteAuthorizationCallBack));*/
	
}

void deleteAuthorizationCallBack(int platform, int stCode, const map<string, string>& data)
{
	
}

int MultiPlatformMgr_ios::GetBatteryLevel()
{
//	float fBatteryLevel = getBatteryLeve();
//	if(fBatteryLevel == 0.1f)
//	{
//		return 0;
//	}
//	
//	fBatteryLevel = fBatteryLevel * 100.0f;
//	
//	if (fBatteryLevel >= 66)
//	{
//		return 3;
//	}
//	else if (fBatteryLevel >= 33)
//	{
//		return 2;
//	}
//	else if (fBatteryLevel > 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
}

int MultiPlatformMgr_ios::GetNetType()
{
	//return getNetState();
}


int MultiPlatformMgr_ios::GetNetLevel()
{
	return NETLEVEL_STRENGTH_GREAT;
}

void MultiPlatformMgr_ios::ShowToast(const std::string & str)
{
	
}


bool MultiPlatformMgr_ios::obtainNetWorkState()
{
	//bool haveWifi = isWIFIEnabled();
	//bool have3G = is3GEnabled();
	
	//return haveWifi || have3G;
}

void MultiPlatformMgr_ios::updateMachineID()
{
	int                 mib[6];
	size_t              len;
	char                *buf;
	unsigned char       *ptr;
	struct if_msghdr    *ifm;
	struct sockaddr_dl  *sdl;
	
	mib[0] = CTL_NET;
	mib[1] = AF_ROUTE;
	mib[2] = 0;
	mib[3] = AF_LINK;
	mib[4] = NET_RT_IFLIST;
	
	if ((mib[5] = if_nametoindex("en0")) == 0)
	{
		printf("Error: if_nametoindex error/n");
		return ;
	}
	
	if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0)
	{
		printf("Error: sysctl, take 1/n");
		return ;
	}
	
	if ((buf=(char*)malloc(len)) == NULL)
	{
		printf("Could not allocate memory. error!/n");
		return ;
	}
	
	if (sysctl(mib, 6, buf, &len, NULL, 0) < 0)
	{
		printf("Error: sysctl, take 2");
		free(buf);
		return;
	}
	
	ifm = (struct if_msghdr *)buf;
	sdl = (struct sockaddr_dl *)(ifm + 1);
	ptr = (unsigned char *)LLADDR(sdl);
	
	NSString *outstring = [NSString stringWithFormat:@"%02X:%02X:%02X:%02X:%02X:%02X",*ptr, *(ptr+1), *(ptr+2), *(ptr+3), *(ptr+4), *(ptr+5)];
	free(buf);
	
	NSString *bundleIdentifier = [[NSBundle mainBundle] bundleIdentifier];
	NSString *stringToHash = [NSString stringWithFormat:@"%@%@",outstring,bundleIdentifier];
	m_strMachineID = [stringToHash UTF8String];
}

int MultiPlatformMgr_ios::Pay(float price, long userID, long gameID, std::string accounts, std::string ProductId, long appId, bool isFormal)
{
	if (userID == 0)
	{
//		AppController *appController = (AppController *)[[UIApplication sharedApplication] delegate];
//		if (isFormal)
//		{
//			[appController.viewController createPay:price:1];
//		}
//		else
//		{
//			[appController.viewController createPay:price:2];
//		}
		
	}
	else
	{
		//		UnPay();
		//		AppController *appController = (AppController *)[[UIApplication sharedApplication] delegate];
		//		[appController.viewController payAction:price :userID :gameID :accounts :ProductId: appId];
	}
	return 1;
}

int MultiPlatformMgr_ios::UMPay(float price, long userID, long gameID, std::string accounts, std::string ProductId)
{
//	AppController *appController = (AppController *)[[UIApplication sharedApplication] delegate];
//	[appController.viewController start:price:userID:gameID:accounts.c_str():ProductId.c_str()];
	return 1;
}

int MultiPlatformMgr_ios::UnPay()
{
	//	AppController *appController = (AppController *)[[UIApplication sharedApplication] delegate];
	//	[appController.viewController unPayAction];
	return 1;
}


void MultiPlatformMgr_ios::CallCustomServiceIphone(std::string iphoneNum)
{
	NSString *allString = [NSString stringWithFormat:@"tel:%s",iphoneNum.c_str()];
	[[UIApplication sharedApplication] openURL:[NSURL URLWithString:allString]];
}

void MultiPlatformMgr_ios::openLocalPhoto()
{
	AppController *app = (AppController*) [[UIApplication sharedApplication] delegate];
	[app OpenLocalPhoto];
}

//=============================手心SDK接口====================================
//登录
void MultiPlatformMgr_ios::HandLogin(){
	//AppController *appController = (AppController *)[[UIApplication sharedApplication] delegate];
	//[appController.viewController handLogin];
}

//切换帐号
void MultiPlatformMgr_ios::HandChangeAccount(){
	//退出登录
	//[SXSdkApi showSignOutView];
}

//传值充值
void MultiPlatformMgr_ios::Handpay(std::string goodsName, double money, std::string object, std::string sid, std::string sname, int tag){
	
	//	NSString * trans_goodsName = [NSString stringWithCString:goodsName.c_str() encoding:NSUTF8StringEncoding];
	//	NSString * trans_object = [NSString stringWithCString:object.c_str() encoding:NSUTF8StringEncoding];
	//	NSString * trans_sid = [NSString stringWithCString:sid.c_str() encoding:NSUTF8StringEncoding];
	//
	//	AppController *appController = (AppController *)[[UIApplication sharedApplication] delegate];
	//	[appController.viewController createPayWithProductID:trans_goodsName money:money object:trans_object sid:trans_sid formal:tag];
}

//固定充值
void MultiPlatformMgr_ios::HandFixedpay(){
	
}

//修改名字
void MultiPlatformMgr_ios::HandSubRole(std::string userId, std::string userName, int userLevel, long roleCTime, std::string zoneId, std::string zoneName){
	
}
//=============================手心SDK接口====================================
void MultiPlatformMgr_ios::umengPay(double cash, int source, double coin, const char * item, int amount)
{
	if (strlen(item) > 0)
	{
		//umeng::MobClickCpp::pay(cash, source, item, amount, coin);
	}
	else
	{
		//umeng::MobClickCpp::pay(cash, source, coin);
	}
}

void MultiPlatformMgr_ios::umengBuy(const char *item, int amount, double price)
{
	//umeng::MobClickCpp::buy(item, amount, price);
}

void MultiPlatformMgr_ios::umengUser(const char *item, int amount, double price)
{
	//umeng::MobClickCpp::use(item, amount, price);
}

void MultiPlatformMgr_ios::umengbonus(const char *item, int amount, double price, int source)
{
	if (strlen(item) > 0)
	{
		//umeng::MobClickCpp::bonus(item, amount, price, source);
	}
	else
	{
		//umeng::MobClickCpp::bonus(price, source);
	}
}
