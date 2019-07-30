#ifndef _gPlatform_H_
#define _gPlatform_H_
//////////////////////////////////////////////////////////////////////////
// 游戏平台
#define GAME_PLATFORM_DEFAULT	0
#define GAME_PLATFORM_360		360

int  platformGetPlatform();
std::string platformGetPlatformName();
std::string platformGetPlatformVersion();
void platformOpenLoginView();
void platformOpenExitView();
void platformOpenPayView(int item, const char* account, const char* username, const char* userid);

#endif // _gPlatform_H_