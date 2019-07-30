#ifndef __VIEWS_H__
#define __VIEWS_H__

#include "cocos2d.h"

#include "../platform/PlatformHeader.h"
#include "ViewHeader.h"
USING_NS_CC;


void open_url(const char* url)
{
#if (CC_TARGET_PLATFORM==CC_PLATFORM_WIN32)
	ShellExecuteA(NULL, NULL, url, NULL, NULL, SW_SHOWNORMAL);
#elif (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
	//NSString* ns_str = [NSString stringWithUTF8String:url];
	//[[NSWorkspace sharedWorkspace] openURL: [NSURL URLWithString:ns_str]]
#elif (CC_TARGET_PLATFORM==CC_PLATFORM_ANDROID)

#else
#endif
}

// 格式化货币
std::string FormatMoneyFrom(const std::string& sIn)
{
	if (sIn.empty())
		return "";

	std::string sRet;
	int iflag = sIn.find_last_of('.');

	std::string s1 = iflag == -1 ? sIn : sIn.substr(0, iflag);
	std::string s2 = iflag == -1 ? "" : sIn.substr(iflag);
	int len = s1.size();

	int iFlag = 0;
	if (s1[0] == '-')
		iFlag = 1;

	int c = 0;

	for (int i = len - 1; i >= iFlag; --i)
	{
		sRet.push_back(s1[i]);
		++c;

		if (c >= 3 && i != iFlag)
		{
			sRet.push_back(',');
			c = 0;
		}
	}

	if (sRet.empty() && !s2.empty())
		sRet.push_back('0');

	if (iFlag == 1)
		sRet.push_back('-');

	//反转
	std::reverse(sRet.begin(), sRet.end());

	//只有一个点
	if (s2.size() == 1)
		s2.clear();

	return sRet + s2;
}


const char* FormatTime(int time)
{
	static std::string str;

	int iDay = time / 86400;
	time -= iDay * 86400;
	int iHour = time / 3600;
	time -= iHour * 3600;
	int iMin = time / 60;
	time -= iMin * 60;

	str.resize(128, '\0');
	sprintf(&str[0], "%02d:%02d:%02d", iHour, iMin, time);
	return str.c_str();
}


#endif /* __APPMACROS_H__ */
