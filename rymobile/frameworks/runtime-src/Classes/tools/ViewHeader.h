#ifndef _Views_H_
#define _Views_H_

#include "cocos2d.h"
//打开连接
void open_url(const char* url);

// 格式化货币
std::string FormatMoneyFrom(const std::string& sIn);

// 格式化货币
template<typename T>
std::string FormatMoney(const T& val)
{
	std::ostringstream ost;
	ost.str("");
	ost << val;
	return FormatMoneyFrom(ost.str());
}

const char* FormatTime(int time);

#endif // _Views_H_