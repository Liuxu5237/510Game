//
//  MultiPlatformMgr.hpp
//  NiuNiu
//
//  Created by zhong on 1/4/16.
//
//

#ifndef MultiPlatformMgr_hpp
#define MultiPlatformMgr_hpp

#include <stdio.h>
#include "cocos2d.h"

class MultiPlatformMgrDelegate
{
public:
    virtual void didPickImgFinish(cocos2d::Image *pickimg){};
};


typedef enum
{
	NETLEVEL_STRENGTH_NONE_OR_UNKNOWN = 0,
	NETLEVEL_STRENGTH_POOR = 1,
	NETLEVEL_STRENGTH_MODERATE = 2,
	NETLEVEL_STRENGTH_GOOD = 3,
	NETLEVEL_STRENGTH_GREAT = 4
}NetLevel;



class MultiPlatformMgr
{
protected:
    MultiPlatformMgr();
public:
    virtual ~MultiPlatformMgr();
    
    static MultiPlatformMgr* getInstance();
    static void destroy();
    virtual void init();
    CC_SYNTHESIZE(MultiPlatformMgrDelegate*, m_pDelegate, PlatformDelegate);
public:
    virtual void test();
    
    //选择图片
    virtual void triggerPickImg();
    
    //震动设置 nOpen:1开；0:关
    virtual void switchVibratorState(bool bOpen);
    
    //设备震动
    virtual void vibrator();
    
    //程序版本号
    virtual std::string clientVersionInfo();
    
    //更新版本信息
    virtual void updateVersion();

    //得到设备id
    virtual std::string getMachineId();
    
    //更新设备id
    virtual void updateMachineID();

	// 显示提示文字
	virtual void ShowToast(const std::string & str);

	// 获取当前的网络状态
	virtual bool obtainNetWorkState();

	//打开分享
	virtual void OpenShare(std::vector<int>& platforms, const char* text, const char* title,const char* imgName,const char* targeturl, const char* noticeSuccess, const char* noticeFail, bool isDirectShare = false);

	//得到电池量的强度
	virtual int GetBatteryLevel();

	//得到网络类型
	virtual int GetNetType();

	//得到网络强度
	virtual int GetNetLevel();

	//支付接口
	virtual int Pay(float price, long userID, long gameID, std::string accounts, std::string ProductId, long appId, bool isFormal);
	
	virtual int UMPay(float price, long userID, long gameID, std::string accounts, std::string ProductId);

	//取消支付
	virtual int UnPay();

	/*微信登录
	0:登录
	1:绑定
	*/
	virtual int WechatLogin(int nType=0);


	//判断是否授权
	virtual bool isAuthorized();

	//删除授权
	virtual int deleteAuthorization();

	//开始录音
	virtual void startSoundRecord();

	//停止录音
	virtual const char* stopSoundRecord();
	
	//调用电话，打客服电话
	virtual void CallCustomServiceIphone(std::string iphoneNum);
	
	//打开本地相册，选取里面的图片
	virtual void openLocalPhoto();

	//=================================================================
	//手心SDK接口

	//登录
	virtual void HandLogin();

	//切换帐号
	virtual void HandChangeAccount();

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
	virtual void Handpay(std::string goodsName, double money, std::string object, std::string sid, std::string sname, int tag);

	//固定充值
	virtual void HandFixedpay();

	//修改名字
	virtual void HandSubRole(std::string userId, std::string userName, int userLevel, long roleCTime, std::string zoneId, std::string zoneName);
	//=================================================================
	
	//友盟充值统计
	virtual void umengPay(double cash, int source, double coin, const char * item, int amount);
	
	//友盟购买统计
	virtual void umengBuy(const char *item, int amount, double price);
	
	//友盟使用消耗
	virtual void umengUser(const char *item, int amount, double price);

	virtual void umengbonus(const char *item, int amount, double price, int source);
	
public:
	/*微信请求类型
	0:微信登录
	1:微信绑定
	*/
	int GetWebChatType(){ return m_nWebchatType; }

	//分享成功与失败的事件
	std::string GetShareNoticeNameSuccess(){ return m_ShareNoticeNameSuccess; }
	std::string GetShareNoticeNameFail(){ return m_ShareNoticeNameFail; }

	/*得到打开图片的类型
	0:从登录打开
	1:从大厅打开
	*/
	//int GetOpenType(){ return m_nOpenType; }
protected:
    static MultiPlatformMgr* s_multiInstance;
    //是否开启震动
    bool m_bOpenVibrator;
    //版本号
    std::string m_strVersion;
    //设备id(未进行md5加密)
    std::string m_strMachineID;

	//微信请求类型
	int m_nWebchatType;

	//分享中成功与失败的事件名字
	std::string m_ShareNoticeNameSuccess;
	std::string m_ShareNoticeNameFail;

	//语音纪录
	std::string s_kRecordFileName;

	//请求打开图片的类型
	//int m_nOpenType;

};
#endif /* MultiPlatformMgr_hpp */
