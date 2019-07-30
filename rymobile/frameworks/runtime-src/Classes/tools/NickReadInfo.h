#ifndef NICK_READ_INFO_H
#define NICK_READ_INFO_H

#include "cocos2d.h"

USING_NS_CC;

/********************************
随机昵称
	
注册昵称时才用到，所以注册完毕后调用Release()
********************************/
class CNickReadInfo
{
	static CNickReadInfo * m_pInfo;
	CNickReadInfo();
	~CNickReadInfo();
public:
	static CNickReadInfo * shared();
	static void Release();

	std::string RandNick();
protected:
	bool Init();
	bool Split(const std::string & str, char ch);

private:
	std::vector< std::map<size_t,std::string> > m_vString;
};

/********************************
		字符串屏蔽
********************************/
class CHarmonyString
{
	static CHarmonyString * m_pHarmony;
	CHarmonyString();
	~CHarmonyString();
public:
	static CHarmonyString * shared();
	static void Release();

	bool CheckString(const std::string & str);

protected:
	bool Init();
	bool Split(const std::string & str, char ch);

	bool IsHave(const std::string &str1, const std::string &str2);
private:
	
	std::string  m_string;
};


#endif // !NICK_READ_INFO_H


