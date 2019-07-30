#include "global.h"

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "jni/JniHelper.h"
#include <android/log.h>

#if 1
#define  LOG_TAG    "JniHelper"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#else
#define  LOGD(...)
#endif

#endif


#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
char* jstringToChar(JNIEnv *env, jstring jstr)
{
	char * rtn = NULL;
	jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("UTF-8");
	jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr,mid,strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte * ba = env->GetByteArrayElements(barr,JNI_FALSE);
	if(alen > 0)
	{
		rtn = (char*)malloc(alen+1); //new char[alen+1];
		memcpy(rtn,ba,alen);
		rtn[alen]=0;
	}
	env->ReleaseByteArrayElements(barr,ba,0);

	return rtn;
}
#endif



bool CheckInfo( std::string str )
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo minfo;
	//getStaticMethodInfo�ж�java����ľ�̬�����Ƿ���ڣ�����bool
	bool ret = JniHelper::getStaticMethodInfo(minfo, "org/cocos2dx/lua/PayHelper", "cb", "(Ljava/lang/String;)Z");
	if(ret)
	{
		jstring strv = minfo.env->NewStringUTF(str.c_str());
		//������ID�ͷ���ID��С�ķ�����д�?��һ����ĸ�Ǵ�д
		jboolean b = minfo.env->CallStaticBooleanMethod(minfo.classID, minfo.methodID,strv );
		return b;
	}
#endif
	return false;
}

void ShowExitDialog()
{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	JniMethodInfo minfo;
	//getStaticMethodInfo�ж�java����ľ�̬�����Ƿ���ڣ�����bool
	bool ret = JniHelper::getStaticMethodInfo(minfo, "org/cocos2dx/lua/PayHelper", "ShowDialog", "()V");
	if (ret)
	{
		minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
	}
#endif
}


