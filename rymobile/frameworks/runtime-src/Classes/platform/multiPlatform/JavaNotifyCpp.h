#pragma once
#include "cocos2d.h"
#include "tools/tools/MTNotification.h"
#include "platform/PlatformHeader.h"
#include "CCLuaEngine.h"
#include "tools/tools/Convert.h"
#include "platform/df/RoomEventIDDefine.h"
#include "platform/multiPlatform/MultiPlatformMgr.h"
#include "tools/tools/uploadFile.h"
#include <string>
USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "../../../cocos2d-x/cocos/platform/android/jni/JniHelper.h"

#include <android/log.h>

#if 1
#define  LOG_TAG    "JniHelper"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#else
#define  LOGD(...)
#endif



#endif


//android 返回的结果
enum{
	//支付功能
	PAY_SUCCESS,// 0 //支付成功
	PAY_FAIL,// 1 //支付失败
	PAY_CANCLE,//2 //支付取消

	//分享功能
	GAME_EXIT,//  100000
	SHARE_SUCCESS,//  100001
	SHARE_FAIL,//  100002
	SHARE_CANCLE,// 100003
	
	JNI_GET_PICTURE,//获取相册里面的图片

	LINK_CALLBACK_SUCCESS,//链接打开应用成功

	GET_DECIVE_TOKEN,//获取设备的token
	
	HAND_LOGIN,	//手心SDK登录成功
	//微信登录
	//PAY_WEBCHATLOGIN_SUCCESS,//登录成功
	//PAY_WEBCHATLOGIN_FAIL,//登录失败

	////微信绑定
	//PAY_WEBCHATBIND_SUCCESS,//微信登录成功
	//PAY_WEBCHATBIND_FAIL,	//微信登录失败
};
/*支付回调
	给外部平台回调使用的接口
*/
bool JavaNotifyCpp(int resultCode, std::string strResult)
{
	bool bResult = true;
	
	switch (resultCode)
	{
		case GAME_EXIT :
		{
			Director::sharedDirector()->end();
		}break;
		case SHARE_SUCCESS :
		{
			G_NOTIFY("SHARE_SUCCESS");
		}break;
		case SHARE_FAIL :
		{
			G_NOTIFY("SHARE_FAIL");
		}break;
		case SHARE_CANCLE :
		{
			G_NOTIFY("SHARE_CANCLE");
		}break;
		case PAY_SUCCESS: 
		case PAY_FAIL: 
		case PAY_CANCLE :
		{
			//G_NOTIFY("PAY_SUCCESS");//支付统一调用此事件
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_PAY_RESULT, resultCode));
		}break;
		
		case JNI_GET_PICTURE:
		{
			cocos2d::log(strResult.c_str());
			//MultiPlatformMgr::getInstance()->ShowToast(strResult);	
			bResult = uploadFile::GetInst()->GetUpLoadFileSuccess(strResult);
		}break;
		case LINK_CALLBACK_SUCCESS:
		{
			UserDefault::getInstance()->setStringForKey("LinkCallBackInfo", strResult);
			G_NOTIFY_D("LinkCallBack_Event", MTData::create(0, 0, 0, strResult));
		}break;
		case GET_DECIVE_TOKEN:
		{
			UserDefault::getInstance()->setStringForKey("DeviceToken", strResult);
		}break;
		case HAND_LOGIN:
		{
			G_NOTIFY_D("Login_Event", MTData::create(3,0,0, strResult));
		}break;
		
		/*
		case PAY_WEBCHATLOGIN_SUCCESS:	//登录成功
		{
			//第一位数字 1 是微信登录 第二位0 是成功  1是失败
			G_NOTIFY_D("Login_Event", MTData::create(1, 0, 0, strResult));
		}break;
		case PAY_WEBCHATLOGIN_FAIL://登录失败
		{
			//第一位数字 1 是微信登录 第二位0 是成功  1是失败
			G_NOTIFY_D("Login_Event", MTData::create(1, 1, 0, strResult));
		}break;
		case PAY_WEBCHATBIND_SUCCESS:	//绑定成功
		{
			//MultiPlatformMgr::getInstance()->ShowToast(strResult);
			//第一位数字 1 是微信登录 第二位0 是成功  1是失败
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 0, 0, strResult));
		}break;
		case PAY_WEBCHATBIND_FAIL://绑定失败
		{
			//MultiPlatformMgr::getInstance()->ShowToast("bind fail");
			//第一位数字 1 是微信登录 第二位0 是成功  1是失败
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 1, 0, strResult));
		}break;
		*/
		default:
		{
			bResult = false;//没找到就是失败了
			break;
		}
	}	
	std::string str = std::string("PayResult code: ") + StringConvert::IntToString(resultCode);
	str += std::string(" str: ") + strResult;
	str += std::string(" bResult: ") + StringConvert::IntToString(bResult);
	//cocos2d::log(str.c_str());
	return bResult;
}