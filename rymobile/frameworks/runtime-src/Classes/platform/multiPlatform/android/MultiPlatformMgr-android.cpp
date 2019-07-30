#include "MultiPlatformMgr-android.h"
#include "../../df/Define.h"
#include "tools/tools/MTNotification.h"
#include "script/UtilityFun.h"
#include "platform/df/RoomEventIDDefine.h"
#if  CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include <map>
#include <jni.h>
#include "jni/JniHelper.h"
#include "Cocos2dx/Common/CCUMSocialSDK.h"
#include "script/UtilityFun.h"
#define JAVA_CLASS "com.foxuc.utils.WHHelper"
USING_NS_CC;

void shareCallback(int platform, int stCode, const string& errorMsg);
void authCallback(int platform, int stCode, map<string, string>& data);
void deleteAuthorizationCallBack(int platform, int stCode, const map<string, string>& data);

#ifdef __cplusplus
extern "C"
{
    JNIEXPORT void JNICALL Java_com_foxuc_utils_WHHelper_nativeDidPickImgFinish(JNIEnv * env, jobject obj, jstring jStr)
    {
        std::string path = JniHelper::jstring2string(jStr);
        
        auto scheduler = Director::getInstance()->getScheduler();
        scheduler->performFunctionInCocosThread([path](){
            cocos2d::Image * pcimage = new cocos2d::Image();
            if (pcimage->initWithImageFile(path))
            {
                cocos2d::log("path:%s",path.c_str());
                if (MultiPlatformMgr::getInstance()->getPlatformDelegate())
                {
                    MultiPlatformMgr::getInstance()->getPlatformDelegate()->didPickImgFinish(pcimage);
                }
            }
            pcimage->release();
        });
    }
	/*
    JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_AppActivity_nativeQuitApp(JNIEnv * env, jobject obj)
    {
        auto player = static_cast<ModeLayer *>(HallDataMgr::getInstance()->AddpopLayer("提示", "确定要退出008打游戏吗?", Type_Ensure_Cancel));
        player->setEnsureCallback([]
                                  {
                                      Director::getInstance()->end();
                                  });
    }
	*/
}
#endif
MultiPlatformMgr_android::MultiPlatformMgr_android()
{
	m_nWebchatType = 0;
	m_ShareNoticeNameSuccess = "";
	m_ShareNoticeNameFail = "";
	//m_nOpenType = 0;
}

MultiPlatformMgr_android::~MultiPlatformMgr_android()
{
    
}

MultiPlatformMgr* MultiPlatformMgr::getInstance()
{
    if (nullptr == s_multiInstance)
    {
        s_multiInstance = new MultiPlatformMgr_android();
    }
    return s_multiInstance;
}

void MultiPlatformMgr_android::test()
{
    
}

void MultiPlatformMgr_android::triggerPickImg()
{
    JniMethodInfo t;
    bool isHave = JniHelper::getStaticMethodInfo(t,
                                                 JAVA_CLASS,
                                                 "pickImg",
                                                 "()V");
    if (isHave)
    {
        t.env->CallStaticVoidMethod(t.classID,t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void MultiPlatformMgr_android::switchVibratorState(bool bOpen)
{
    m_bOpenVibrator = bOpen;
    JniMethodInfo t;
    bool isHave = JniHelper::getStaticMethodInfo(t,
                                                 JAVA_CLASS,
                                                 "switchVibratorState",
                                                 "(Z)V");
    if (isHave)
    {
        t.env->CallStaticVoidMethod(t.classID,t.methodID,bOpen);
        t.env->DeleteLocalRef(t.classID);
    }
}

void  MultiPlatformMgr_android::ShowToast(const std::string & str)
{
	JniMethodInfo minfo;
	
	bool ret = JniHelper::getStaticMethodInfo(minfo, "org/cocos2dx/lua/PayHelper", "ShowTogast", "(Ljava/lang/String;)V");
	if(ret)
	{
		jstring jStrAccounts = minfo.env->NewStringUTF(str.c_str());
		//log("show Toast ...............");

		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID,jStrAccounts );
	}
}

//开始录音
void MultiPlatformMgr_android::startSoundRecord()
{
	std::string kFileName = utility::toString(time(NULL),".wav");
	s_kRecordFileName = cocos2d::FileUtils::getInstance()->getWritablePath()+kFileName;

	JniMethodInfo minfo;  
	bool isHave = JniHelper::getStaticMethodInfo(minfo,"org.cocos2dx.lua.Native", "startSoundRecord", "(Ljava/lang/String;)V");
	if (isHave)  
	{  
		jstring jurl = minfo.env->NewStringUTF(kFileName.c_str());
		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID,jurl); 
		cocos2d::log("JniFun call startSoundRecord over!");

		minfo.env->DeleteLocalRef(minfo.classID);  
	}  
	else
	{
		cocos2d::log("JniFun call startSoundRecord error!");
	}
}

//结束录音
const char* MultiPlatformMgr_android::stopSoundRecord()
{
	std::string str;
	JniMethodInfo minfo;  
	bool isHave = JniHelper::getStaticMethodInfo(minfo,"org.cocos2dx.lua.Native", "stopSoundRecord", "()Ljava/lang/String;");
	if (isHave)  
	{  
		jstring jFileName = (jstring)minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID); 
		const char *newStr = minfo.env->GetStringUTFChars(jFileName, 0);
		str = newStr;
		cocos2d::log("JniFun call stopSoundRecord over :");
		cocos2d::log("%s",str.c_str());
		minfo.env->ReleaseStringUTFChars(jFileName, newStr);
		minfo.env->DeleteLocalRef(minfo.classID); 
	}  
	else
	{
		cocos2d::log("JniFun call stopSoundRecord error!");
	}
	return str.c_str();
}

//获取网络状态
bool MultiPlatformMgr_android::obtainNetWorkState()
{
	JniMethodInfo minfo;//定义Jni函数信息结构体
	int isHaveNet = 0;
	//getStaticMethodInfo 次函数返回一个bool值表示是否找到此函数
	const char * jniClass = "org.cocos2dx.lua.AppActivity";//这里写你所要调用的java代码的类名
	bool isHave = JniHelper::getStaticMethodInfo(minfo,jniClass,"haveNetWork","()I");//本人在此传递的参数是字符串
	if (!isHave) {
		//CCLog("jni->%s/callJni:此函数不存在", jniClass);
	}
	else{
		//CCLog("jni->%s/callJni:此函数存在", jniClass);
		//jstring jdata = minfo.env->NewStringUTF(data);
		//调用此函数
		isHaveNet = minfo.env->CallStaticIntMethod(minfo.classID, minfo.methodID);
	}
	//CCLog("jni-java函数执行完毕");

	return isHaveNet;
}
//面板分享
//void boardCallback(int platform) {
//
//	umeng::social::CCUMSocialSDK *sdk = umeng::social::CCUMSocialSDK::create();
//	sdk->directShare(platform,"江西人自己的棋牌游戏","都市游戏", 
//		"https://i1.piimg.com/1949/5a3349d85bd5fd24.png","http://www.dushigame.cn", (umeng::social::ShareEventHandler)(&shareCallback));
//}

//分享功能
void MultiPlatformMgr_android::OpenShare(std::vector<int>& platforms, const char* text, const char* title,const char* imgName,const char* targeturl, const char* noticeSuccess, const char* noticeFail, bool isDirectShare)
{
	//JniMethodInfo minfo;
	//bool ret = JniHelper::getStaticMethodInfo(minfo, "org/cocos2dx/lua/PayHelper", "ShareOpen", "()V");
	//if (ret)
	//{
	//	minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
	//}
	//umeng::social::CCUMSocialSDK *sdk = umeng::social::CCUMSocialSDK::create();
	//vector<int>* platforms = new vector<int>();
	//platforms->push_back(umeng::social::WEIXIN_CIRCLE) ;
	//platforms->push_back(umeng::social::WEIXIN) ;
	//sdk->openShare(platforms,"江西人自己的棋牌游戏","都市游戏", 
	//	"https://i1.piimg.com/1949/5a3349d85bd5fd24.png","http://www.dushigame.cn", (umeng::social::ShareEventHandler)(shareCallback));

	umeng::social::CCUMSocialSDK *sdk = umeng::social::CCUMSocialSDK::create();
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
	//if (isDirectShare)
	{
		//sdk->directShare(platforms[0], text, title, imgName, targeturl, (umeng::social::ShareEventHandler)(&shareCallback));
	} 
	//else
	{
		sdk->openShare(sharePlatforms, text, title, imgName, targeturl, (umeng::social::ShareEventHandler)(&shareCallback));
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
		if ("" != strFail)
		{
			G_NOTIFY(strFail);
		}
	}
}

void MultiPlatformMgr_android::vibrator()
{
    if (!m_bOpenVibrator)
    {
        return;
    }
    JniMethodInfo t;
    bool isHave = JniHelper::getStaticMethodInfo(t,
                                                 JAVA_CLASS,
                                                 "switchVibratorState",
                                                 "(Z)V");
    if (isHave)
    {
        t.env->CallStaticVoidMethod(t.classID,t.methodID,true);
        t.env->DeleteLocalRef(t.classID);
    }
}

void MultiPlatformMgr_android::updateVersion()
{
    JniMethodInfo t;
    bool isHave = JniHelper::getStaticMethodInfo(t,
                                                 JAVA_CLASS,
                                                 "clientVersion",
                                                 "()Ljava/lang/String;");
    if (isHave)
    {
        jstring jstr = (jstring)t.env->CallStaticObjectMethod(t.classID,t.methodID);
        t.env->DeleteLocalRef(t.classID);
        m_strVersion = JniHelper::jstring2string(jstr);
        t.env->DeleteLocalRef(jstr);
    }
}

void MultiPlatformMgr_android::updateMachineID()
{
    JniMethodInfo t;
    bool isHave = JniHelper::getStaticMethodInfo(t,
                                                 JAVA_CLASS,
                                                 "getAndroidMachineID",
                                                 "()Ljava/lang/String;");
    if (isHave)
    {
        jstring jstr = (jstring)t.env->CallStaticObjectMethod(t.classID,t.methodID);
        t.env->DeleteLocalRef(t.classID);
        m_strMachineID = JniHelper::jstring2string(jstr);
        t.env->DeleteLocalRef(jstr);
    }
}

int MultiPlatformMgr_android::GetBatteryLevel()
{
	//定义Jni函数信息结构体
	JniMethodInfo minfo;
	
	int nBatterylevel = 0;
	const char * jniClass = "org.cocos2dx.lua.AppActivity";
	bool isHave = JniHelper::getStaticMethodInfo(minfo, jniClass, "getBatteryLevel", "()I");
	if (!isHave) {
		
		nBatterylevel = 0;
	}
	else{
		
		nBatterylevel = minfo.env->CallStaticIntMethod(minfo.classID, minfo.methodID);
	}
	
	if (nBatterylevel >= 66)
	{
		return 3;
	}
	else if (nBatterylevel >= 33)
	{
		return 2;
	}
	else if (nBatterylevel > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//得到网络类型
int MultiPlatformMgr_android::GetNetType()
{
	JniMethodInfo minfo;

	int netType = 0;
	const char * jniClass = "org.cocos2dx.lua.AppActivity";
	bool isHave = JniHelper::getStaticMethodInfo(minfo, jniClass, "getNetInfo", "()[I");
	if (isHave) {
		jintArray msg = (jintArray)minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
		int len = minfo.env->GetArrayLength(msg);
		jint* elems = minfo.env->GetIntArrayElements(msg, 0); 
		if (2 == len)
		{
			netType = elems[0];	
		}
	}
	
	return netType;
}

//得到网络强度
int MultiPlatformMgr_android::GetNetLevel()
{
	JniMethodInfo minfo;

	int netLevel = NETLEVEL_STRENGTH_NONE_OR_UNKNOWN;
	const char * jniClass = "org.cocos2dx.lua.AppActivity";
	bool isHave = JniHelper::getStaticMethodInfo(minfo, jniClass, "getNetInfo", "()[I");
	if (isHave) {
		jintArray msg = (jintArray)minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
		int len = minfo.env->GetArrayLength(msg);
		jint* elems = minfo.env->GetIntArrayElements(msg, 0);
		if (2 == len)
		{
			netLevel = elems[1];
		}
	}

	return netLevel;
}
//得到设备id
std::string MultiPlatformMgr_android::getMachineId()
{
	char szMachineID[LEN_MACHINE_ID]={};
	//cocos2d::log("MultiPlatformMgr_android::machineID1 = %s",szMachineID);
	JniMethodInfo minfo;
	bool ret = JniHelper::getStaticMethodInfo(minfo, "org.cocos2dx.lua.PayHelper", "GetMachineID", "()Ljava/lang/String;");
	if(ret)
	{
		cocos2d::log("MultiPlatformMgr_android::GetMachineID3 succeed");
		jobject machid = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);//CallStaticObjectMethod CallStaticVoidMethod
		memcpy(szMachineID,JniHelper::jstring2string((jstring)machid).c_str(),sizeof(szMachineID));
	}else
	{
		cocos2d::log("MultiPlatformMgr_android::getMachineId call fail");
	}
	return szMachineID;
}

//支付接口
int MultiPlatformMgr_android::Pay(float price, long userID, long gameID, std::string accounts, std::string ProductId, long appId, bool isFormal) 
{
	JniMethodInfo minfo;
	bool isHave = JniHelper::getStaticMethodInfo(minfo,"org.cocos2dx.lua.PayHelper", "doPay", "(FJJLjava/lang/String;Ljava/lang/String;J)V");
	if (isHave)
	{
		jfloat jMont = price;
		jlong jUserId = userID;
		jlong jGameId = gameID;
		jstring jStrAccounts = minfo.env->NewStringUTF(accounts.c_str());
		jstring jProductID = minfo.env->NewStringUTF(ProductId.c_str());	
		jlong jAppId = appId;
		//传入类ID和方法ID，小心方法名写错，第一个字母是大写
		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, jMont, jUserId, jGameId, jStrAccounts,jProductID,jAppId);
		
	}else
	{
		cocos2d::log("MultiPlatformMgr_android::Pay call fail");
	}

	return 0;
}

//取消支付
int MultiPlatformMgr_android::UnPay() 
{
	return 0;
}


//微信登录
int MultiPlatformMgr_android::WechatLogin(int nType)
{
	m_nWebchatType = nType;
	umeng::social::CCUMSocialSDK *sdk = umeng::social::CCUMSocialSDK::create();
	sdk->getPlatformInfo(umeng::social::WEIXIN, (umeng::social::AuthEventHandler)(&authCallback));

	return 1;
}

/*
*授权回调
* @param platform 要授权的平台
* @param stCode 返回码, 200代表授权成功, 100代表开始授权, 0代表授权出错, -1代表取消授权
* @param data 授权时返回的数据
*/
void authCallback(int platform, int stCode,  std::map<string, string>& data)
{
	int ntype = ((MultiPlatformMgr::getInstance()))->GetWebChatType();
	//if (stCode == 100)//开始授权
	//{
	//	CCLOG("AuthorizeCallBack start");
	//}
	//else 
	if (stCode == 200)//授权成功
	{
		CCLOG("AuthorizeCallBack success");

		std::string result = "";
		std::string uid = "";
		std::string openid = "";
		std::string accessToken = "";
		std::string refreshToken = "";
		std::string name = "";
		std::string iconurl = "";
		std::string gender = "";

		//std::string resultFirst = "";

		std::map<string, string>::iterator it = data.begin();
		for (; it != data.end(); ++it) {
			log("authCallback data  %s -> %s.", it->first.c_str(), it->second.c_str());
		/*	result += it->first;
			result +="=";
			result += it->second;
			result += ",";*/

			if ("unionid"==it->first)
			{
				uid = it->second;
			} 
			else if ("openid"==it->first)
			{
				openid = it->second;
			}
			else if ("access_token"==it->first)
			{
				accessToken = it->second;
			}
			else if ("refresh_token"==it->first)
			{
				refreshToken = it->second;
			}
			else if ("screen_name"==it->first)
			{
				name = it->second;
			}
			else if ("profile_image_url"==it->first)
			{
				iconurl = it->second;
			}
			else if ("gender"==it->first)
			{
				gender = it->second;
			}
			else
			{
				//city
				//country
				//expires_in
			}
			
		}

		result = uid + "," + refreshToken + "," + name + "," + openid + "," + iconurl + "," + gender;
		if (ntype == 0)
		{
			G_NOTIFY_D("Login_Event", MTData::create(1, 0, 0, result));
		}
		else if (ntype == 1)
		{
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 0, 0, result));
		}

	}
	else if (stCode == 0)//代表授权出错
	{
		CCLOG("AuthorizeCallBack error");
		if (ntype == 0)
		{
			G_NOTIFY_D("Login_Event", MTData::create(1, 1));
		}
		else if (ntype == 1)
		{
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 1, 0, "error"));
		}

	}
	else //if (stCode == -1)//代表取消授权
	{
		CCLOG("取消授权");
		if (ntype == 0)
		{
			G_NOTIFY_D("Login_Event", MTData::create(1, 2));
		}
		else if (ntype == 1)
		{
			G_NOTIFY_D("room_event", MTData::create(ROOM_EVENT_ID_WEBCHATBIND, 1, 0, "cancel"));
		}

	}



	//0代表授权出错, -1代表取消授权
}

//void AuthorizeCallBack1(int platform, int stCode, const map<string, string>& data)




//判断是否授权
bool MultiPlatformMgr_android::isAuthorized()
{
	/*
	umeng::social::CCUMSocialSDK *sdk = umeng::social::CCUMSocialSDK::create("57beae30e0f55a0f1f0015b4");
	sdk->setWeiXinAppInfo("wx94e1db9c1ae1c391","754a7e4edc6e228193569089b813ecb4");
	return sdk->isAuthorized(umeng::social::WEIXIN);*/
}

//删除授权
int MultiPlatformMgr_android::deleteAuthorization()
{
	umeng::social::CCUMSocialSDK *sdk = umeng::social::CCUMSocialSDK::create();
	sdk->deleteAuthorization(umeng::social::WEIXIN, (umeng::social::AuthEventHandler)(&deleteAuthorizationCallBack));
	//CCUMSocialSDK *sdk = CCUMSocialSDK::create( );
	//log("deleteAuthorization");
	//sdk->deleteAuthorization(WEIXIN, auth_selector(authCallback));
}

void deleteAuthorizationCallBack(int platform, int stCode, const map<string, string>& data)
{

}


void MultiPlatformMgr_android::CallCustomServiceIphone(std::string strphoneNum)
{
	JniMethodInfo minfo;
	bool isHave = JniHelper::getStaticMethodInfo(minfo,"org.cocos2dx.lua.PayHelper", "CallPhone", "(Ljava/lang/String;)V");
	if (isHave)
	{
		jstring jstrphoneNum = minfo.env->NewStringUTF(strphoneNum.c_str());
		//传入类ID和方法ID，小心方法名写错，第一个字母是大写
		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, jstrphoneNum);
	}
	else
	{
		cocos2d::log("MultiPlatformMgr_android::CallCustomServiceIphone call fail");
	}
}

void MultiPlatformMgr_android::openLocalPhoto()
{
	//m_nOpenType = 0;
	JniMethodInfo minfo;
	bool isHave = JniHelper::getStaticMethodInfo(minfo,"org.cocos2dx.lua.ImagePicker", "openPhoto", "()V");
	if (isHave)
	{
		//传入类ID和方法ID，小心方法名写错，第一个字母是大写
		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
	}
	else
	{
		cocos2d::log("MultiPlatformMgr_android::openLocalPhoto call fail");
	}
}

//登录
void MultiPlatformMgr_android::HandLogin()
{
	JniMethodInfo t;
	const char * jniClass = "org.cocos2dx.lua.AppActivity";
	bool isHave = JniHelper::getStaticMethodInfo(t,
		jniClass,
		"LoginHandSDK",
		"()V");
	if (isHave)
	{
		t.env->CallStaticVoidMethod(t.classID,t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
}

void MultiPlatformMgr_android::HandChangeAccount()
{
	JniMethodInfo t;
	const char * jniClass = "org.cocos2dx.lua.AppActivity";
	bool isHave = JniHelper::getStaticMethodInfo(t,
		jniClass,
		"ChangeAccount",
		"()V");
	if (isHave)
	{
		t.env->CallStaticVoidMethod(t.classID,t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
}


void MultiPlatformMgr_android::Handpay(std::string goodsName, double money, std::string object, std::string sid, std::string sname, int tag)
{
// 	JniMethodInfo t;
// 	const char * jniClass = "org.cocos2dx.lua.AppActivity";
// 	bool isHave = JniHelper::getStaticMethodInfo(t,
// 		jniClass,
// 		"Handpay",
// 		"()V");
// 	if (isHave)
// 	{
// 		jint jmoney = money;
// 		jint jtag = tag;
// 		jstring jgoodsName = t.env->NewStringUTF(goodsName.c_str());
// 		jstring jobject = t.env->NewStringUTF(object.c_str());
// 		jstring jsid = t.env->NewStringUTF(sid.c_str());
// 		jstring jsname = t.env->NewStringUTF(sname.c_str());
// 		t.env->CallStaticVoidMethod(t.classID,t.methodID,jgoodsName);
// 		t.env->DeleteLocalRef(t.classID);
// 	}

	JniMethodInfo minfo;
	bool isHave = JniHelper::getStaticMethodInfo(minfo,"org.cocos2dx.lua.AppActivity", "Handpay", "(Ljava/lang/String;DLjava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V");
	if (isHave)
	{
		jdouble jmoney = money;
		jint jtag = tag;
		jstring jgoodsName = minfo.env->NewStringUTF(goodsName.c_str());
		jstring jobject = minfo.env->NewStringUTF(object.c_str());
		jstring jsid = minfo.env->NewStringUTF(sid.c_str());
		jstring jsname = minfo.env->NewStringUTF(sname.c_str());
		//传入类ID和方法ID，小心方法名写错，第一个字母是大写
		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, jgoodsName, jmoney, jobject,jsid,jsname,jtag);
	}
	else
	{
		cocos2d::log("MultiPlatformMgr_android::CallCustomServiceIphone call fail");
	}
}


void MultiPlatformMgr_android::HandFixedpay()
{
	JniMethodInfo t;
	const char * jniClass = "org.cocos2dx.lua.AppActivity";
	bool isHave = JniHelper::getStaticMethodInfo(t,
		jniClass,
		"HandFixedpay",
		"()V");
	if (isHave)
	{
		t.env->CallStaticVoidMethod(t.classID,t.methodID);
		t.env->DeleteLocalRef(t.classID);
	}
}


void MultiPlatformMgr_android::HandSubRole(std::string userId, std::string userName, int userLevel, long roleCTime, std::string zoneId, std::string zoneName)
{
	JniMethodInfo minfo;
	bool isHave = JniHelper::getStaticMethodInfo(minfo,"org.cocos2dx.lua.AppActivity", "HandSubRole", "()V");
	if (isHave)
	{
		jstring juserId = minfo.env->NewStringUTF(userId.c_str());
		jstring juserName = minfo.env->NewStringUTF(userName.c_str());
		jint juserLevel = userLevel;
		jlong jroleCTime = roleCTime;
		jstring jzoneId = minfo.env->NewStringUTF(zoneId.c_str());
		jstring jzoneName = minfo.env->NewStringUTF(zoneName.c_str());
		//传入类ID和方法ID，小心方法名写错，第一个字母是大写
		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, juserId, juserName, juserLevel, jroleCTime, jzoneId, jzoneName);

	}
	else
	{
		cocos2d::log("MultiPlatformMgr_android::HandSubRole call fail");
	}

}

#endif