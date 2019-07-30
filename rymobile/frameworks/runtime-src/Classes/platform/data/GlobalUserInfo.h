#ifndef GLOBAL_USER_INFO_HEAD_FILE
#define GLOBAL_USER_INFO_HEAD_FILE

#pragma once

#include "../df/Define.h"
#include "../df/types.h"
#include "../df/Struct.h"
#include "../msg/CMD_LogonServer.h"
#include "cocos2d.h"
using namespace cocos2d;
//////////////////////////////////////////////////////////////////////////////////
//结构定义

//用户信息
class tagGlobalUserData : public cocos2d::Ref
{
	//基本资料
	CC_SET_AND_GET(dword, dwUserID,UserID)									//用户 I D
	CC_SET_AND_GET(dword, dwGameID,GameID)									//游戏 I D
	CC_SET_AND_GET(dword, dwUserMedal, UserMedal)							//用户奖牌
	CC_SET_AND_GET(dword, dwExperience, Experience)							//用户经验
	CC_SET_AND_GET(dword, dwLoveLiness, LoveLiness)							//用户魅力
	
	CC_SET_AND_GET_CHAR_ARRAY(LEN_ACCOUNTS, szAccounts, Accounts)			//登录帐号
	CC_SET_AND_GET_CHAR_ARRAY(LEN_NICKNAME, szNickName, NickName)			//用户昵称
	CC_SET_AND_GET_CHAR_ARRAY(LEN_PASSWORD, szPassword, Password)			//登录密码
	CC_SET_AND_GET_CHAR_ARRAY(LEN_PASSWORD, szDynamicPass, DynamicPass)	//动态密码
	CC_SET_AND_GET_CHAR_ARRAY(LEN_MOBILE_PHONE, szRegisterMobile, RegisterMobile)	//绑定手机
	CC_SET_AND_GET_CHAR_ARRAY(LEN_WEBCHAT_PROFILEURL, szProfileUrl, ProfileUrl)	//头像url
	//用户成绩
public:
	CC_SET_AND_GET(SCORE, lUserScore, UserScore)							//用户游戏币
	CC_SET_AND_GET(SCORE, lUserInsure, UserInsure)							//银行游戏币
	CC_SET_AND_GET(SCORE, lUserIngot, UserIngot)							//用户元宝
	CC_SET_AND_GET(SCORE, dUserBeans, UserBeans)							//用户游戏豆
	CC_SET_AND_GET(SCORE, dUserTickets, UserTickets)						//用户参数券
	CC_SET_AND_GET(SCORE, lHouseCard, HouseCard)							//用户房卡

	//扩展资料
	CC_SET_AND_GET(BYTE, cbGender, Gender)									//用户性别
	CC_SET_AND_GET(BYTE, cbMoorMachine, MoorMachine)						//锁定机器
	CC_SET_AND_GET_CHAR_ARRAY(LEN_UNDER_WRITE, szUnderWrite, UnderWrite)	//个性签名

	//社团资料
	CC_SET_AND_GET(dword, dwGroupID, GroupID)								//社团索引
	CC_SET_AND_GET_CHAR_ARRAY(LEN_GROUP_NAME, szGroupName, GroupName)		//社团名字

	//会员资料
	CC_SET_AND_GET(BYTE, cbMemberOrder, MemberOrder)						//会员等级
	systemtime						MemberOverDate;							//到期时间

	//头像信息
	CC_SET_AND_GET(WORD, wFaceID, FaceID)									//头像索引
	CC_SET_AND_GET(dword, dwCustomID, CustomID)								//自定标识
	tagCustomFaceInfo				CustomFaceInfo;							//自定头像

	//配置信息
	CC_SET_AND_GET(BYTE, cbInsureEnabled, InsureEnabled)					//银行使能
};

//扩展资料
class tagIndividualUserData : public tagGlobalUserData
{
	//用户信息
	CC_SET_AND_GET_CHAR_ARRAY(LEN_USER_NOTE, szUserNote, UserNote)					//用户说明
	CC_SET_AND_GET_CHAR_ARRAY(LEN_COMPELLATION, szCompellation, Compellation)		//真实名字

	//电话号码
	CC_SET_AND_GET_CHAR_ARRAY(LEN_SEAT_PHONE, szSeatPhone, SeatPhone)				//固定电话
	CC_SET_AND_GET_CHAR_ARRAY(LEN_MOBILE_PHONE, szMobilePhone, MobilePhone)		//移动电话

	//联系资料
	CC_SET_AND_GET_CHAR_ARRAY(LEN_QQ, szQQ, QQ)									//Q Q 号码
	CC_SET_AND_GET_CHAR_ARRAY(LEN_EMAIL, szEMail, EMail)							//电子邮件
	CC_SET_AND_GET_CHAR_ARRAY(LEN_DWELLING_PLACE, szDwellingPlace, DwellingPlace)	//联系地址
};


//银行信息
class tagUserInsureInfo : public tagIndividualUserData
{
	CC_SET_AND_GET(BYTE, cbEnjoinTransfer, EnjoinTransfer)							//转帐开关

	CC_SET_AND_GET(WORD, wRevenueTake, RevenueTake)									//税收比例
	CC_SET_AND_GET(WORD, wRevenueTransfer, RevenueTransfer)							//税收比例
	CC_SET_AND_GET(WORD, wRevenueTransferMember, RevenueTransferMember)				//税收比例
	CC_SET_AND_GET(WORD, wServerID, ServerID)										//房间标识

	CC_SET_AND_GET(SCORE, lUserScore, UserScore)									//用户游戏币
	CC_SET_AND_GET(SCORE, lUserInsure, UserInsure)									//银行游戏币
	CC_SET_AND_GET(SCORE, lTransferPrerequisite, TransferPrerequisite)				//转帐条件
};

//等级参数
class tagGrowLevelParameter : public tagUserInsureInfo
{
	CC_SET_AND_GET(WORD, wCurrLevelID, CurrLevelID)									//当前等级

	CC_SET_AND_GET(dword, dwExperience, Experience)									//当前经验
	CC_SET_AND_GET(dword, dwUpgradeExperience, UpgradeExperience)					//下级经验

	CC_SET_AND_GET(SCORE, lUpgradeRewardGold, UpgradeRewardGold)					//升级奖励
	CC_SET_AND_GET(SCORE, lUpgradeRewardIngot, UpgradeRewardIngot)					//升级奖励
};



//////////////////////////////////////////////////////////////////////////////////

//用户信息
class CGlobalUserInfo : public tagGrowLevelParameter
{
	//静态变量
protected:
	static CGlobalUserInfo *		m_pGlobalUserInfo;						//用户信息

	//函数定义
protected:
	//构造函数
	CGlobalUserInfo();
	//析构函数
	virtual ~CGlobalUserInfo();

	//CC_SYNTHESIZE(int, roomKindw, RoomKindw);

	//功能函数
public:
	//重置资料
	void ResetUserInfoData();
	
	//静态函数
public:
	//获取对象
	static CGlobalUserInfo * GetInstance() { 
		
		if (m_pGlobalUserInfo == NULL)
		{
			m_pGlobalUserInfo = new CGlobalUserInfo();
		}

		return m_pGlobalUserInfo;
	}
};

//////////////////////////////////////////////////////////////////////////////////

#endif