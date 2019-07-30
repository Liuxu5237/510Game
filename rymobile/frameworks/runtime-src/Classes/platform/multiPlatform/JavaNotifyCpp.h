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


//android ���صĽ��
enum{
	//֧������
	PAY_SUCCESS,// 0 //֧���ɹ�
	PAY_FAIL,// 1 //֧��ʧ��
	PAY_CANCLE,//2 //֧��ȡ��

	//������
	GAME_EXIT,//  100000
	SHARE_SUCCESS,//  100001
	SHARE_FAIL,//  100002
	SHARE_CANCLE,// 100003
	
	JNI_GET_PICTURE,//��ȡ��������ͼƬ

	LINK_CALLBACK_SUCCESS,//���Ӵ�Ӧ�óɹ�

	GET_DECIVE_TOKEN,//��ȡ�豸��token
	
	HAND_LOGIN,	//����SDK��¼�ɹ�
	//΢�ŵ�¼
	//PAY_WEBCHATLOGIN_SUCCESS,//��¼�ɹ�
	//PAY_WEBCHATLOGIN_FAIL,//��¼ʧ��

	////΢�Ű�
	//PAY_WEBCHATBIND_SUCCESS,//΢�ŵ�¼�ɹ�
	//PAY_WEBCHATBIND_FAIL,	//΢�ŵ�¼ʧ��
};
/*֧���ص�
	���ⲿƽ̨�ص�ʹ�õĽӿ�
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
			//G_NOTIFY("PAY_SUCCESS");//֧��ͳһ���ô��¼�
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
		case PAY_WEBCHATLOGIN_SUCCESS:	//��¼�ɹ�
		{
			//��һλ���� 1 ��΢�ŵ�¼ �ڶ�λ0 �ǳɹ�  1��ʧ��
			G_NOTIFY_D("Login_Event", MTData::create(1, 0, 0, strResult));
		}break;
		case PAY_WEBCHATLOGIN_FAIL://��¼ʧ��
		{
			//��һλ���� 1 ��΢�ŵ�¼ �ڶ�λ0 �ǳɹ�  1��ʧ��
			G_NOTIFY_D("Login_Event", MTData::create(1, 1, 0, strResult));
		}break;
		case PAY_WEBCHATBIND_SUCCESS:	//�󶨳ɹ�
		{
			//MultiPlatformMgr::getInstance()->ShowToast(strResult);
			//��һλ���� 1 ��΢�ŵ�¼ �ڶ�λ0 �ǳɹ�  1��ʧ��
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 0, 0, strResult));
		}break;
		case PAY_WEBCHATBIND_FAIL://��ʧ��
		{
			//MultiPlatformMgr::getInstance()->ShowToast("bind fail");
			//��һλ���� 1 ��΢�ŵ�¼ �ڶ�λ0 �ǳɹ�  1��ʧ��
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 1, 0, strResult));
		}break;
		*/
		default:
		{
			bResult = false;//û�ҵ�����ʧ����
			break;
		}
	}	
	std::string str = std::string("PayResult code: ") + StringConvert::IntToString(resultCode);
	str += std::string(" str: ") + strResult;
	str += std::string(" bResult: ") + StringConvert::IntToString(bResult);
	//cocos2d::log(str.c_str());
	return bResult;
}