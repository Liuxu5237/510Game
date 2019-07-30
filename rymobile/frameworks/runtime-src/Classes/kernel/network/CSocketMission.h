#ifndef _CSocketMission_H_
#define _CSocketMission_H_

#include "ISocketEngine.h"
#include "ISocketEngineSink.h"
#include "fv/FvSingleton.h"
#include "cocos2d.h"
class CSocketMission : public cocos2d::Ref , public ISocketEngineSink
{
protected:
	// 构造函数
	CSocketMission();

	// 析构函数
	virtual ~CSocketMission();

//protected:

	// 单体实例
	//static CSocketMission *ms_pkInstance;

public:

	// 单体函数
	static CSocketMission * Instance()
	{
		CSocketMission* ms_pkInstance = new CSocketMission;
		//ms_pkInstance->autorelease();
		return ms_pkInstance;
	}

	static void Destroy(CSocketMission* intsance)
	{
		if (intsance != nullptr)
		{
			CC_SAFE_RELEASE_NULL(intsance);
			//intsance->release();
		}
	}

public:

	// 设置链接url
	void setUrl(const std::string & url, int port);

	// 开启服务器请求
	void start();

	// 停止服务器请求
	void stop();

	// 判断服务器的链接状态
	bool isAlive() const;

	// 发送网络消息
	bool send(int main, int sub);

	// 发送网络消息
	bool send(int main, int sub, const cocos2d::Ref * data, int size);

public:

	// 设置服务器链接成功lua回调
	void setLinkSuccLuaCallBack(const std::string & strLinkSuccLuaCallBack);

	// 设置服务器链接关闭lua回调
	void setLinkDownLuaCallBack(const std::string & strLinkDownLuaCallBack);

	// 设置服务器链接错误lua回调
	void setLinkErrorLuaCallBack(const std::string & strLinkErrorLuaCallBack);

	// 设置服务器数据返回lua回调
	void setLinkDataLuaCallBack(const std::string & strLinkDataLuaCallBack);

protected:

	// 服务器链接成功
	virtual void onEventTCPSocketLink();

	// 服务器链接关闭
	virtual void onEventTCPSocketShut();

	// 服务器链接失败
	virtual void onEventTCPSocketError(int errorCode);

	// 服务器数据返回
	virtual bool onEventTCPSocketRead(int main, int sub, char * data, int dataSize);

private:

	// 链接套接字
	ISocketEngine * mSocketEngine;

	// 链接地址
	std::string		mUrl;

	// 链接端口
	int				mPort;

private:
	// 服务器链接成功lua回调
	std::string		m_strLinkSuccLuaCallBack;

	// 服务器链接关闭lua回调
	std::string		m_strLinkDownLuaCallBack;

	// 服务器链接错误lua回调
	std::string		m_strLinkErrorLuaCallBack;
	
	// 服务器数据返回lua回调
	std::string		m_strLinkDataLuaCallBack;
}; // CSocketMission

#endif // _CSocketMission_H_