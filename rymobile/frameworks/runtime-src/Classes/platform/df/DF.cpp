#include "DF.h"
#include "cocos2d.h"

#include "../../tools/core/MD5.h"
#include "../../tools/tools/StaticData.h"
#include "../../tools/StringUtility.h"
#include "../../tools/tools/gPlatform.h"
#include "../../tools/global.h"
//#include "../../../proj.ios_mac/ios/SystemInfo.h"

USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
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

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)

struct tagAstatInfo
{
	ADAPTER_STATUS          AdapterStatus;            //网卡状态
	NAME_BUFFER           NameBuff[16];           //名字缓冲
};

bool GetMACAddress(char szMACAddress[LEN_NETWORK_ID])
{
	//变量定义
	HINSTANCE hInstance = NULL;

	//执行逻辑
	__try
	{
		//加载 DLL
		hInstance = LoadLibrary(TEXT("NetApi32.dll"));
		if (hInstance == NULL)
		{
			__leave;
		}

		//获取函数
		typedef BYTE __stdcall NetBiosProc(NCB * Ncb);
		NetBiosProc * pNetBiosProc = (NetBiosProc *)GetProcAddress(hInstance, "Netbios");
		if (pNetBiosProc == NULL)
		{
			__leave;
		}

		//变量定义
		NCB Ncb;
		LANA_ENUM LanaEnum;
		ZeroMemory(&Ncb, sizeof(Ncb));
		ZeroMemory(&LanaEnum, sizeof(LanaEnum));

		//枚举网卡
		Ncb.ncb_command = NCBENUM;
		Ncb.ncb_length = sizeof(LanaEnum);
		Ncb.ncb_buffer = (BYTE *)&LanaEnum;
		if ((pNetBiosProc(&Ncb) != NRC_GOODRET) || (LanaEnum.length == 0))
		{
			__leave;
		}

		//获取地址
		if (LanaEnum.length > 0)
		{
			//变量定义
			tagAstatInfo Adapter;
			ZeroMemory(&Adapter, sizeof(Adapter));

			//重置网卡
			Ncb.ncb_command = NCBRESET;
			Ncb.ncb_lana_num = LanaEnum.lana[0];
			if (pNetBiosProc(&Ncb) != NRC_GOODRET)
			{
				__leave;
			}

			//获取状态
			Ncb.ncb_command = NCBASTAT;
			Ncb.ncb_length = sizeof(Adapter);
			Ncb.ncb_buffer = (BYTE *)&Adapter;
			Ncb.ncb_lana_num = LanaEnum.lana[0];
			strcpy((char *)Ncb.ncb_callname, "*");
			if (pNetBiosProc(&Ncb) != NRC_GOODRET)
			{
				__leave;
			}

			//获取地址
			for (int i = 0; i < 6; i++)
			{
				ASSERT((i * 2) < LEN_NETWORK_ID);
				sprintf(&szMACAddress[i * 2], "%02X", Adapter.AdapterStatus.adapter_address[i]);
			}
		}
	}

	//结束清理
	__finally
	{
		//释放资源
		if (hInstance != NULL)
		{
			FreeLibrary(hInstance);
			hInstance = NULL;
		}

		//错误断言
		if (AbnormalTermination() == TRUE)
		{
			ASSERT(FALSE);
		}
	}

	return true;
}
#endif



//////////////////////////////////////////////////////////////////////////

uint32 VerStringToInt( const char *strVer )
{
	string strVersion = strVer;
	vector<int> versionCodes;
	string_util::split_int(strVersion,".",versionCodes);
	if ( versionCodes.size() >= 3 )
	{
		return PROCESS_VERSION(versionCodes[0],versionCodes[1],versionCodes[2]);
	}
	else
	{
		log("Version config error!");
		return 0;
	}
}

dword CheStringToInt( const char *strVer )
{
	string strVersion = strVer;
	vector<int> versionCodes;
	string_util::split_int(strVersion,".",versionCodes);
	if ( versionCodes.size() >= 3 )
	{

		//return versionCodes[0]*256*256*256+versionCodes[1]*256*256+versionCodes[2]*256+versionCodes[3];
		return PROCESS_VERSION(versionCodes[0],versionCodes[1],versionCodes[2]);
	}
	else
	{
		log("Version config error!");
		return 0;
	}
}



DF* DF::shared() 
{
	static DF sInstance;
	return &sInstance;
}

const char* DF::MD5Encrypt(const char* pszSourceData)
{
	static std::string sPassword;
	sPassword = md5(pszSourceData);
	return sPassword.c_str();
}
//////////////////////////////////////////////////////////////////////////

DF::DF()
{
	//初始版本
	mInitVersion = "15.15.0";
}

DF::~DF()
{
}

void DF::init(int iKindID, int iPlayers, const char* sGameVersion, const char* sGameName)
{
	mKindID = iKindID;
	mGamePlayers = iPlayers;
	mClientVersion = CheStringToInt(sGameVersion);
	mGameName = sGameName;
	mPlatformID = platformGetPlatform();
}

byte DF::GetDeviceType()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	return DEVICE_TYPE_IPHONE;
#elif(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	return DEVICE_TYPE_ANDROID;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	return DEVICE_TYPE_PC_MOBILE;
#endif	
}

const char* DF::GetMachineID()
{
	static bool bFirst = true;
	static char szMachineID[LEN_MACHINE_ID]={0};

	if (bFirst)
	{
		//bFirst=false;
		//log("device Type=%d"+GetDeviceType());
		switch (GetDeviceType())
		{
		case DEVICE_TYPE_PC_MOBILE:
			{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
				GetMACAddress(szMachineID);
#endif
			}
			break;
		case DEVICE_TYPE_ANDROID:
			{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
				JniMethodInfo minfo;
				//getStaticMethodInfo�ж�java����ľ�̬�����Ƿ���ڣ�����bool
				bool ret = JniHelper::getStaticMethodInfo(minfo, "org/cocos2dx/lua/PayHelper", "GetMachineID", "()Ljava/lang/String;");
				if(ret)
				{
					log("call void func1() succeed");
					//������ID�ͷ���ID��С�ķ�����д����һ����ĸ�Ǵ�д
					jobject machid = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);//CallStaticObjectMethod CallStaticVoidMethod
					sprintf(szMachineID,"%s",jstringToChar(minfo.env,(jstring)machid));
				}
				log("machineID = %s",szMachineID);
#endif
			}
			break;
		case DEVICE_TYPE_IPHONE:
			{
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
				const char* pUUID = "adfe"/*GetUUID()*/;
				if (pUUID)
				{
					strcpy(szMachineID, MD5Encrypt(pUUID));
				}
#endif
			}
			break;
		}

	}

	return szMachineID;
}

const char* DF::GetMobilePhone()
{
	static bool bFirst = true;
	static char szPhone[LEN_MOBILE_PHONE] = { 0 };

	if (bFirst)
	{
		bFirst=false;

		switch (GetDeviceType())
		{
		case DEVICE_TYPE_PC_MOBILE:
			{
				break;
			}
		case DEVICE_TYPE_ANDROID:
			{
				break;
			}
		}
	}

	return szPhone;
}



uint32 DF::GetPlazaVersion()
{
	switch (GetDeviceType())
	{
	case DEVICE_TYPE_ANDROID:
		return VerStringToInt(mInitVersion.c_str());
		break;
	case DEVICE_TYPE_IPAD:
	case DEVICE_TYPE_IPHONE:
	case DEVICE_TYPE_ITOUCH:
		return VerStringToInt(mInitVersion.c_str());
		break;
	default:
		return VerStringToInt(mInitVersion.c_str());
	}
}

std::string DF::GetPlazaStringVersion()
{
	switch (GetDeviceType())
	{
	case DEVICE_TYPE_ANDROID:
		return mInitVersion;
	case DEVICE_TYPE_IPAD:
	case DEVICE_TYPE_IPHONE:
	case DEVICE_TYPE_ITOUCH:
		return mInitVersion;
	default:
		return mInitVersion;
	}
}

uint32 DF::GetFrameVersion()
{
	return VerStringToInt(STATIC_DATA_STRING("frameVersion"));
}

uint16 DF::GetPlazzKindID()
{
	//if (GetDeviceType() == DEVICE_TYPE_PC)
	//	return INVALID_WORD;

	return GetGameKindID();
}


uint16 DF::GetPlatformID()
{
	return mPlatformID;
}

uint32 DF::GetGameVersion()
{
	return mClientVersion;
	//switch (GetDeviceType())
	//{
	//case DEVICE_TYPE_ANDROID:
	//	return PROCESS_VERSION(6,0,3);
	//case DEVICE_TYPE_IPAD:
	//case DEVICE_TYPE_IPHONE:
	//case DEVICE_TYPE_ITOUCH:
	//	return PROCESS_VERSION(6,0,3);
	//}

	//return PROCESS_VERSION(6,0,3);
}

uint16 DF::GetGameKindID()
{
	return mKindID;
}
uint32 DF::GetGamePlayer()
{
	return mGamePlayers;
}

const char* DF::GetGameName(char szGameName[LEN_KIND])
{
	const char* sGameName = mGameName.c_str();
	strncpy(szGameName, sGameName, LEN_KIND);
	return sGameName;
}

