#pragma once
#include <string>
#include <vector>
#include "../platform/GlobalConfig.h"
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#endif
#include "cocos2d.h"
using namespace std;
USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(1280, 720);

#define	kPlatformRevolutionWidth  1280
#define kPlatformRevolutionHeight  720

//分辨率
const float c_iphone5_ratio = 16.0f / 9.0f;
const float c_iphone4s_ratio = 3.0f / 2.0f;
const float c_ipad_ratio = 4.0f / 3.0f;

//原游戏资源分辨率
const float kOriginGameRevolutionWidth = 1420.0f;
const float kOriginGameRevolutionHeight = 800.0f;

//游戏资源分辨率
const float kGameRevolutionWidth = 1280.0f;
const float kGameRevolutionHeight = 720.0f;

//游戏资源分辨率缩放因子
#define fGameRevolutionXFactor				(kGameRevolutionWidth/kOriginGameRevolutionWidth)
#define fGameRevolutionYFactor				(kGameRevolutionHeight/kOriginGameRevolutionHeight)

#define  PLATFROM_VERSION   0x00

#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
char* jstringToChar(JNIEnv *env, jstring jstr);
#endif


bool  CheckInfo(std::string str);

void ShowExitDialog();

void OpenShare();