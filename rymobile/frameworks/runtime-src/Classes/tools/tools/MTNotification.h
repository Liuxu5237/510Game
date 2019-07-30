#ifndef _MTNotification_H_
#define _MTNotification_H_

#include "cocos2d.h"
#include "../../platform/df/types.h"
#include "CCLuaValue.h"
USING_NS_CC;


class MTData : public cocos2d::Ref
{
public:
	static MTData* create(unsigned int data1 = 0, unsigned int data2 = 0, unsigned int data3 = 0, 
		const std::string& str1 = "", const std::string& str2 = "", const std::string& str3 = "", cocos2d::Ref * pdata = nullptr)
	{
		MTData* dat = new MTData();
		if (dat && dat->init(data1, data2, data3, str1, str2, str3, pdata))
		{
			dat->autorelease();
			return dat;
		}
		delete dat;
		return 0;
	}

	CC_SET_AND_GET(unsigned int, mData1, Data1)
	CC_SET_AND_GET(unsigned int, mData2, Data2)
	CC_SET_AND_GET(unsigned int, mData3, Data3)
	
	CC_SET_AND_GET_REF(std::string, mStr1, Str1)
	CC_SET_AND_GET_REF(std::string, mStr2, Str2)
	CC_SET_AND_GET_REF(std::string, mStr3, Str3)

	CC_SET_AND_GET(cocos2d::Ref *, mPData, PData)
private:
	MTData(){}
	~MTData(){}
	bool init(unsigned int data1, unsigned int data2, unsigned int data3, 
		const std::string& str1, const std::string& str2, const std::string& str3, cocos2d::Ref * pdata)
	{
		mData1 = data1;
		mData2 = data2;
		mData3 = data3;
		mStr1  = str1;
		mStr2  = str2;
		mStr3  = str3;
		mPData = pdata;
		return true;
	}
};



class MyNotification : public cocos2d::Ref
{
protected:
	// 构造函数
	MyNotification();

	// 析构函数
	virtual ~MyNotification();

public:
	
	// 得到通知管理器实例
	static MyNotification * getInstance();

protected:

	//创建MTNotificationImp
	void initMTNotificationImp();

public:
	
	//注册通知
	bool registerEvent(const std::string &name_, const std::function<void(EventCustom*)>& callback);

	//注册lua回调
	bool registerLuaEventCallBack(const std::string &name_, LUA_FUNCTION handler);

	//注销通知
	bool unRegisterEventListener(const std::string& customEventName);

	//分发事件
	void dispatchEvent(const std::string &name, MTData * data = nullptr);

public:

	//提取网络消息
	void post(float dt);

private:
	// 通知管理器实例
	static MyNotification* g_instance;
};


#define  G_NOTIFY_REG(name, callfunc)		 MyNotification::getInstance()->registerEvent( name, CC_CALLBACK_1( callfunc, this ) );
#define  G_NOTIFY_D(name, data )			 MyNotification::getInstance()->dispatchEvent( name, data );
#define  G_NOTIFY(name)						 MyNotification::getInstance()->dispatchEvent( name );
#define  G_NOTIFY_UNREG(customEventName)	 MyNotification::getInstance()->unRegisterEventListener(customEventName)




#endif // _MTNotification_H_
