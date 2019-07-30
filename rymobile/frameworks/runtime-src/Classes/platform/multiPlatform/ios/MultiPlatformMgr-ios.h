//
//  MultiPlatformMgr-ios.hpp
//  NiuNiu
//
//  Created by zhong on 1/4/16.
//
//

#ifndef MultiPlatformMgr_ios_hpp
#define MultiPlatformMgr_ios_hpp

#include "cocos2d.h"
#if  CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#import <UIKit/UIKit.h>
#include <stdio.h>
#include "../MultiPlatformMgr.h"
class MultiPlatformMgr_ios : public MultiPlatformMgr
{
public:
	MultiPlatformMgr_ios();
	~MultiPlatformMgr_ios();
	
	virtual void test() override;
	
	//选择图片
	virtual void triggerPickImg() override;
	
	//震动设置 nOpen:1开；0:关
	virtual void switchVibratorState(bool bOpen) override;
	
	//设备震动
	virtual void vibrator() override;
	
	//程序版本号
	virtual void updateVersion() override;
	
	//设备id
	virtual void updateMachineID() override;
	
	//显示错误信息
	virtual void ShowToast(const std::string & str) override;
	
	//获取网络状态
	virtual bool obtainNetWorkState() override;
	
	//打开分享
	virtual void OpenShare(std::vector<int>& platforms, const char* text, const char* title,const char* imgName,const char* targeturl, const char* noticeSuccess, const char* noticeFail, bool isDirectShare) override;
	
	//分享回调
	//void shareCallback(int platform, int stCode, std::string& errorMsg);
	
	//得到电池量的强度
	virtual int GetBatteryLevel() override;
	
	//得到网络类型
	virtual int GetNetType() override;
	
	//得到网络强度
	virtual int GetNetLevel() override;
	
	//支付接口
	virtual int Pay(float price, long userID, long gameID, std::string accounts, std::string ProductId, long appId, bool isFormal) override;
	
	virtual int UMPay(float price, long userID, long gameID, std::string accounts, std::string ProductId) override;
	
	
	//取消支付
	virtual int UnPay() override;
	
	//微信登录
	virtual int WechatLogin(int nType) override;
	
	//判断是否授权
	virtual bool isAuthorized() override;
	
	//删除授权
	virtual int deleteAuthorization() override;
	
	//开始录音
	virtual void startSoundRecord() override;
	
	//停止录音
	virtual const char* stopSoundRecord() override;
	
	//调用电话，打客服电话
	virtual void CallCustomServiceIphone(std::string iphoneNum) override;
	
	//打开本地相册，选取里面的图片
	virtual void openLocalPhoto() override;
	
	//=================================================================
	//手心SDK接口
	
	//登录
	virtual void HandLogin() override;
	
	//切换帐号
	virtual void HandChangeAccount() override;
	
	//传值充值
	/**
	 * 支付接口(选接)参数说明 !!! 注意必传参数,不能为空，推荐所有参数都传值 !!!
	 *
	 * @param context
	 *            上下文 (*必传)
	 * @param goodsName
	 *            CP商品名(*必传)
	 * @param money
	 *            CP金额(定额) (*必传)（单位是人民币：元）
	 * @param object
	 *            CP扩展回调参数 (*必传)
	 * @param sid
	 *            服务器ID
	 * @param sname
	 *            服务器名称
	 * @param sdkResultCallBack
	 *            充值回调 (*必传)
	 * @param tag
	 *            标记位,暂时传0 (*必传)
	 */
	virtual void Handpay(std::string goodsName, double money, std::string object, std::string sid, std::string sname, int tag) override;
	
	//固定充值
	virtual void HandFixedpay() override;
	
	//修改名字
	virtual void HandSubRole(std::string userId, std::string userName, int userLevel, long roleCTime, std::string zoneId, std::string zoneName) override;
	//=================================================================
	//友盟充值统计
	virtual void umengPay(double cash, int source, double coin, const char * item, int amount);
	
	//友盟购买统计
	virtual void umengBuy(const char *item, int amount, double price);
	
	//友盟使用消耗
	virtual void umengUser(const char *item, int amount, double price);
	
	virtual void umengbonus(const char *item, int amount, double price, int source);
public:
	
};
#endif

#endif /* MultiPlatformMgr_ios_hpp */

