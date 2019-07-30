#include "cocos2d.h"
#include "gPlatform.h"
#include "MTNotification.h"
#include "../../platform/PlatformHeader.h"
#include "../Dialog/Timer.h"

USING_NS_CC;

using namespace std;

//////////////////////////////////////////////////////////////////////////
// android
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include <Jni.h>
#include "platform/android/jni/JniHelper.h"

bool getJniMethod(jobject& jobj, JniMethodInfo &minfo, const char* sFunction, const char* sSignature)
{
	#define JNI_PACKAGE "com/io/pyds/JniCaller"
	//getStaticMethodInfo，判断Java静态函数是否存在，并且把信息保存到minfo里
	//参数1：JniMethodInfo
	//参数2：Java类包名+类名
	//参数3：Java函数名称
	//参数4：函数参数类型和返回值类型
	if (!JniHelper::getStaticMethodInfo(minfo,JNI_PACKAGE,"shared","()V")) 
	{
		return false;
	}
	//这里的调用getInstance，返回Test类的对象。

	jobj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);

	bool bvalue =  JniHelper::getMethodInfo(minfo,JNI_PACKAGE,sFunction,sSignature);
	return bvalue;
}

// 获取平台
int jniCjPlatform()
{
	JniMethodInfo minfo;
	jobject jobj;//存对象
	
	if (getJniMethod(jobj, minfo, "jniCjPlatform","()I"))
	{
		return minfo.env->CallIntMethod(jobj, minfo.methodID);
	}

	return GAME_PLATFORM_DEFAULT;
}

// 获取平台名字
std::string jniCjPlatformName()
{
	JniMethodInfo minfo;
	jobject jobj;//存对象
	log("jniCjPlatformName1");
	if (getJniMethod(jobj, minfo, "jniCjPlatformName","()Ljava/lang/String;"))
	{
		jstring result = (jstring)minfo.env->CallObjectMethod(jobj, minfo.methodID);  
		const char* str = minfo.env->GetStringUTFChars(result, 0); 
		std::string retUtf8 = str;
		minfo.env->ReleaseStringUTFChars(result, 0); 
		return retUtf8;
	}

	return "x.x.x";
}


// 获取平台版本
std::string jniCjPlatformVersion()
{
	JniMethodInfo minfo;
	jobject jobj;//存对象
	if (getJniMethod(jobj, minfo, "jniCjPlatformVersion","()Ljava/lang/String;"))
	{
		jstring result = (jstring)minfo.env->CallObjectMethod(jobj, minfo.methodID);  
		const char* str = minfo.env->GetStringUTFChars(result, 0); 
		std::string retUtf8 = str;
		minfo.env->ReleaseStringUTFChars(result, 0); 
		return retUtf8;
	}

	return "x.x.x";
}

//打开平台相关登录界面
void jniCjOpenLoginView()
{
	JniMethodInfo minfo;
	jobject jobj;//存对象
	if (getJniMethod(jobj, minfo, "jniCjOpenLoginView","()V"))
	{
		minfo.env->CallObjectMethod(jobj, minfo.methodID);
	}
}

//打开平台相关切换帐号界面
void jniCjOpenSwitchView()
{
	JniMethodInfo minfo;
	jobject jobj;//存对象
	if (getJniMethod(jobj, minfo, "jniCjOpenSwitchView","()V"))
	{
		minfo.env->CallObjectMethod(jobj, minfo.methodID);
	}
}

//打开平台相关退出界面
void jniCjOpenExitView()
{
	JniMethodInfo minfo;
	jobject jobj;//存对象
	if (getJniMethod(jobj, minfo, "jniCjOpenExitView","()V"))
	{
		minfo.env->CallObjectMethod(jobj, minfo.methodID);
	}
}

//打开平台相关支付
void jniCjOpenPayView(int item, const char* account, const char* username, const char* userid)
{
	JniMethodInfo minfo;
	jobject jobj;//存对象
	if (getJniMethod(jobj, minfo, "jniCjOpenPayView","(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)V"))
	{
		jstring sAccount	= minfo.env->NewStringUTF(account);
		jstring sUserName	= minfo.env->NewStringUTF(username);
		jstring sUserId		= minfo.env->NewStringUTF(userid);
		//调用openWebview, 参数1：Test对象   参数2：方法ID
		minfo.env->CallObjectMethod(jobj, minfo.methodID, item, sAccount, sUserName, sUserId);
		//删除字符串
		minfo.env->DeleteLocalRef (sAccount);
		minfo.env->DeleteLocalRef (sUserName);
		minfo.env->DeleteLocalRef (sUserId);
	}
}

//打开平台相关实名注册(目前360特有)
void jniCjOpenRealNameRegisterView()
{
	JniMethodInfo minfo;
	jobject jobj;//存对象
	if (getJniMethod(jobj, minfo, "jniCjOpenRealNameRegisterView","()V"))
	{
		minfo.env->CallObjectMethod(jobj, minfo.methodID);
	}
}

//打开平台相关防沉迷相关
void jniCjOpenAntiAddiction()
{
	JniMethodInfo minfo;
	jobject jobj;//存对象
	if (getJniMethod(jobj, minfo, "jniCjOpenAntiAddiction","()V"))
	{
		minfo.env->CallObjectMethod(jobj, minfo.methodID);
	}
}
/////////////////////////////////////////////////////////////////////////////
//call c
#ifdef __cplusplus
extern "C"
{
#endif
	//java 调用
	//授权成功
	JNIEXPORT void JNICALL Java_com_io_pyds_JniCaller_jniCcAuthSuccess(JNIEnv* env, jobject jobj, jstring jsPlatformName, jstring jsPlatformId, jstring jsName)
	{
		const char* sPlatformName	= env->GetStringUTFChars(jsPlatformName, 0);
		const char* sPlatformId		= env->GetStringUTFChars(jsPlatformId, 0);
		const char* sName			= env->GetStringUTFChars(jsName, 0);
		log("authSuccess............................");
		log("Platform:%s id:%s", sPlatformName, sPlatformId);

		std::string sAccount = sPlatformName;
		sAccount += "_";
		sAccount += sPlatformId;
		G_NOTIFY_D("PLATFORM_AUTH_SUCCESS", MTData::create(0, 0, 0, sAccount, sAccount, sName));

		env->ReleaseStringUTFChars(jsPlatformName, sPlatformName);
		env->ReleaseStringUTFChars(jsPlatformId, sPlatformId);
		env->ReleaseStringUTFChars(jsName, sName);
	}

	JNIEXPORT void JNICALL Java_com_io_pyds_JniCaller_jniCcAuthFail(JNIEnv* env, jobject jobj)
	{
		G_NOTIFY_D("PLATFORM_AUTH_FAILURE", 0);
	}

	JNIEXPORT void JNICALL Java_com_io_pyds_JniCaller_jniCcExit(JNIEnv* env, jobject jobj, jint type)
	{
		G_NOTIFY_D("PLATFORM_GAME_EXIT", MTData::create(type));
	}

	JNIEXPORT void JNICALL Java_com_io_pyds_JniCaller_jniCcRefreshCoins(JNIEnv* env, jobject jobj)
	{
		G_NOTIFY_D("INSURE_QUERY", MTData::create(3));
	}

#ifdef __cplusplus
}
#endif

#endif // #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)



// ios
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//#include "../proj.ios_mac/ios/IAPHelper.h"
#include "../../../proj.ios_mac/ios/thirdparty/IAP/IOSiAP.h"
#include "../../../proj.ios_mac/ios/thirdparty/IAP/IOSiAP_Bridge.h"

static int COSTS[]={
	600,1800,5000,12800
};


static std::string gen_uuid_ex(const std::string& sAccount)
{
	////生成100000内的随机数
	//int num = 10000 + rand()%90000;
	//time_t second;
	//time(&second);
	////获取当前时间
	//struct tm *p = localtime(&second);
	//char buf[100] = {0};
	////格式化时间和随机数字符串，存放在buf内
	//sprintf(buf, "%d-%d-%d-%d:%d:%d-%06d", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday, 	p->tm_hour, p->tm_min, p->tm_sec, num);  
	//return buf;
	//生成100000内的随机数

	int num = 10000 + rand()%90000;
	time_t second;
	time(&second);
	//获取当前时间
	struct tm *p = localtime(&second);
	char buf[100] = {0};
	//格式化时间和随机数字符串，存放在buf内
	sprintf(buf, "%d-%d-%d-%d:%d:%d-%s", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday, 	p->tm_hour, p->tm_min, p->tm_sec, sAccount.c_str());  
	return buf;

}


//class IAPBridge : public IAPDelegate
//{
//public:
//	IAPHelper* iap;
//	int requestState;
//	int payIndex;
//	string sAccount;
//	string sUserName;
//	string sUserId;
//	string sOrder;
//
//	IAPBridge()
//	{
//		requestState = 0;
//		payIndex = -1;
//		iap = new IAPHelper();
//		iap->delegate = this;
//	}
//	~IAPBridge()
//	{
//		delete iap;
//	}
//
//public:
//	void pay(int index, const std::string& account, const std::string& username, const std::string& userid)
//	{
//		if (!iap->canMakePayments() || index > 4)
//		{
//			G_NOTIFY_D("PAYMENT_DISABLE", 0);
//			return;
//		}
//
//		if (-1 != payIndex)
//		{
//			// paying...
//			G_NOTIFY_D("PAYMENT_PAYING", 0);
//			return;
//		}
//
//		payIndex = index;
//		sAccount = account;
//		sUserName = username;
//		sUserId = userid;
//
//		if (requestState == 2)
//		{
//			innerPay();
//		}
//		else
//		{
//			requestProducts();
//		}
//	}
//
//	void innerPay()
//	{
//		char buf[64]={0};
//		sprintf(buf, "com.io.jcby.c%02d", payIndex);
//		
//		IAPProduct* product = iap->productByIdentifier(buf);
//		if (0 == product)
//		{
//			payIndex = -1;
//			G_NOTIFY_D("PAYMENT_PRODUCT_NONE", 0);
//			log("can't find product:%s", buf);
//			return;
//		}
//		sOrder = gen_uuid_ex(sAccount);
//		//log("order:%s", sOrder.c_str());
//		iap->paymentWithProduct(product, COSTS[payIndex-1], sAccount, sUserName, sUserId, sOrder);
//	}
//
//	void requestProducts()
//	{
//		if (0 != requestState)
//			return;
//		requestState = 1;
//		vector<string> identifiers;
//		identifiers.push_back("com.io.jcby.c01");
//		identifiers.push_back("com.io.jcby.c02");
//		identifiers.push_back("com.io.jcby.c03");
//		identifiers.push_back("com.io.jcby.c04");
//		iap->requestProducts(identifiers);
//	}
//
//
//	// for requestProduct
//	virtual void onRequestProductsFinish()
//	{
//		requestState = 2;
//		innerPay();
//	}
//
//	virtual void onRequestProductsError(int code)
//	{
//		requestState = 0;
//		G_NOTIFY_D("PAYMENT_PRODUCTS_FAILED", 0);
//	}
//
//	// for payment
//	virtual void onPaymentEvent(const std::string& identifier, int quantity, IAPPaymentEvent e, const std::string& sErr)
//	{
//		switch (e)
//		{
//		case IAP_PAYMENT_PURCHASING:
//			//log("payment:IAP_PAYMENT_PURCHASING");
//			return;
//		case IAP_PAYMENT_PURCHASED:
//			//log("payment:IAP_PAYMENT_PURCHASED");
//			G_NOTIFY_D("PAYMENT_PAY_FINISH", MTData::create(payIndex));
//			break;
//		case IAP_PAYMENT_FAILED:
//			//log("payment:IAP_PAYMENT_FAILED");
//			G_NOTIFY_D("PAYMENT_PAY_FAILED", MTData::create(0, 0, 0, sErr));
//			break;
//		case IAP_PAYMENT_RESTORED:
//			//log("payment:IAP_PAYMENT_RESTORED");
//			break;
//		case IAP_PAYMENT_REMOVED:
//			//log("payment:IAP_PAYMENT_REMOVED");
//			break;
//		}
//
//		payIndex = -1;
//	}
//
//};
#endif // #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

//////////////////////////////////////////////////////////////////////////
int __iPlatform = -1;

int platformGetPlatform()
{
	if (__iPlatform != -1)
		return __iPlatform;
#if 0
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
		__iPlatform = jniCjPlatform();
	#else
		__iPlatform = GAME_PLATFORM_DEFAULT;
	#endif
#else
	__iPlatform = GAME_PLATFORM_DEFAULT;
#endif
	return __iPlatform;
}


std::string platformGetPlatformName()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	return jniCjPlatformName();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	return "ios";
#endif
	return "";
}


std::string platformGetPlatformVersion()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	jniCjPlatformName();
	return jniCjPlatformVersion();
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	//return iosPlatformVersion();
#endif
	return "x.x.x";
}


void platformOpenLoginView()
{
	static unsigned long  sLastTime = 0;

	unsigned long curTime = CoTimer::getCurrentTime();
	if (curTime < sLastTime)
		return;
	sLastTime = curTime+5000;
	
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	jniCjOpenLoginView();
#endif
}

void platformOpenExitView()
{
	static unsigned long  sLastTime = 0;

	unsigned long curTime = CoTimer::getCurrentTime();
	if (curTime < sLastTime)
		return;
	sLastTime = curTime+5000;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	jniCjOpenExitView();
#endif
}


void platformOpenPayView(int item, const char* account, const char* username, const char* userid)
{
	static unsigned long  sLastTime = 0;

	unsigned long curTime = CoTimer::getCurrentTime();
	if (curTime < sLastTime)
		return;
	sLastTime = curTime+5000;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	jniCjOpenPayView(item, account, username, userid);
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//	static IAPBridge bridge;
//	bridge.pay(item, account, username, userid);
#endif
}
