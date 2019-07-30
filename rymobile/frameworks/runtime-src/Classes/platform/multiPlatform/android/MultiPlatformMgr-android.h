//
//  MultiPlatformMgr-android.hpp
//  NiuNiu
//
//  Created by zhong on 1/4/16.
//
//

#ifndef MultiPlatformMgr_android_hpp
#define MultiPlatformMgr_android_hpp

#include "cocos2d.h"

#include <stdio.h>
#if  CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "../MultiPlatformMgr.h"

class MultiPlatformMgr_android : public MultiPlatformMgr
{
    friend class MultiPlatformMgr;
public:
    MultiPlatformMgr_android();
    ~MultiPlatformMgr_android();
    
    virtual void test() override;
    
    //选择图片
    virtual void triggerPickImg() override;
    
    //震动设置 nOpen:1开；0:关
    virtual void switchVibratorState(bool bOpen) override;
    
    //设备震动
    virtual void vibrator() override;
    
    //程序版本号
    virtual void updateVersion() override;
    
	//得到设备id
	virtual std::string getMachineId() override;

    //设备id
    virtual void updateMachineID() override;

	//显示错误信息
	virtual void ShowToast(const std::string & str) override;

	//获取网络状态
	virtual bool obtainNetWorkState() override;

	//打开分享
	virtual void OpenShare(std::vector<int>& platforms, const char* text, const char* title,const char* imgName,const char* targeturl, const char* noticeSuccess, const char* noticeFail, bool isDirectShare=false) override;

	//得到电池量的强度
	virtual int GetBatteryLevel() override;

	//得到网络类型
	virtual int GetNetType() override;

	//得到网络强度
	virtual int GetNetLevel() override;

	//支付接口
	virtual int Pay(float price, long userID, long gameID, std::string accounts, std::string ProductId, long appId, bool isFormal) override;

	//取消支付
	virtual int UnPay() override;

	//微信登录
	virtual int WechatLogin(int nType = 0) override;

	//判断是否授权
	virtual bool isAuthorized();

	//删除授权
	virtual int deleteAuthorization();

	//开始录音
	virtual void startSoundRecord();

	//结束录音
	virtual const char* stopSoundRecord();

	//调用电话，打客服电话
	virtual void CallCustomServiceIphone(std::string strphoneNum);

	//打开本地相册，选取里面的图片
	virtual void openLocalPhoto();

	//=================================================================
	//手心SDK接口

	//登录
	virtual void HandLogin();

	//切换帐号
	virtual void HandChangeAccount();

	//传值充值
	virtual void Handpay(std::string goodsName, double money, std::string object, std::string sid, std::string sname, int tag);

	//固定充值
	virtual void HandFixedpay();

	//修改名字
	virtual void HandSubRole(std::string userId, std::string userName, int userLevel, long roleCTime, std::string zoneId, std::string zoneName);
	//=================================================================

public:


};
#endif

#endif /* MultiPlatformMgr_android_hpp */
