#include "GlobalUserInfo.h"


//////////////////////////////////////////////////////////////////////////////////

//静态变量
CGlobalUserInfo * CGlobalUserInfo::m_pGlobalUserInfo=0;				//用户信息

//////////////////////////////////////////////////////////////////////////////////

//构造函数
CGlobalUserInfo::CGlobalUserInfo()
{
	//设置对象
	ASSERT(m_pGlobalUserInfo==0);
	if (m_pGlobalUserInfo==0) m_pGlobalUserInfo=this;

	//设置变量


	return;
}

//析构函数
CGlobalUserInfo::~CGlobalUserInfo()
{
	//释放对象
	ASSERT(m_pGlobalUserInfo==this);
	if (m_pGlobalUserInfo==this) m_pGlobalUserInfo=0;

	return;
}

//重置资料
void CGlobalUserInfo::ResetUserInfoData()
{
	//设置变量
	

	return;
}

//////////////////////////////////////////////////////////////////////////////////
