#ifndef _ITableViewFrame_H_
#define _ITableViewFrame_H_

#include "platform/PlatformHeader.h"
#include "../user/IClientUserItem.h"

class ITableViewFrame;

//桌子视图
class ITableView
{
public:
	virtual ~ITableView(){};

	//功能接口
public:
	//空椅子数
	virtual word GetNullChairCount(WORD & wNullChairID)=0;
	//配置函数
	virtual void InitTableView(WORD wTableID, WORD wChairCount, ITableViewFrame * pITableFrameView)=0;

	//用户接口
public:
	//获取用户
	virtual IClientUserItem * GetClientUserItem(WORD wChairID)=0;
	//设置信息
	virtual bool SetClientUserItem(WORD wChairID, IClientUserItem * pIClientUserItem)=0;

	//设置接口
public:
	//焦点框架
	virtual void SetFocusFrame(bool bFocusFrame)=0;
	//桌子状态 
	virtual void SetTableStatus(bool bPlaying, bool bLocker)=0;

	//查询接口
public:
	//游戏标志
	virtual bool GetPlayFlag()=0;
	//密码标志
	virtual bool GetLockerFlag()=0;
};

//桌子框架
class ITableViewFrame
{
public:
	virtual ~ITableViewFrame(){};

	//配置接口
public:
	//配置桌子
	virtual bool ConfigTableFrame(WORD wTableCount, WORD wChairCount, dword dwServerRule, WORD wServerType, WORD wServerID)=0;

	//信息接口
public:
	//桌子数目
	virtual word GetTableCount()=0;
	//椅子数目
	virtual word GetChairCount()=0;

	//用户接口
public:
	//获取用户
	virtual IClientUserItem * GetClientUserItem(WORD wTableID, WORD wChairID)=0;
	//设置信息
	virtual bool SetClientUserItem(WORD wTableID, WORD wChairID, IClientUserItem * pIClientUserItem)=0;

	//状态接口
public:
	//游戏标志
	virtual bool GetPlayFlag(WORD wTableID)=0;
	//密码标志
	virtual bool GetLockerFlag(WORD wTableID)=0;
	//焦点框架
	virtual void SetFocusFrame(WORD wTableID, bool bFocusFrame)=0;
	//桌子状态 
	virtual void SetTableStatus(WORD wTableID, bool bPlaying, bool bLocker)=0;

	//视图控制
public:
	//闪动桌子
	virtual bool FlashGameTable(WORD wTableID)=0;
	//闪动椅子
	virtual bool FlashGameChair(WORD wTableID, WORD wChairID)=0;

	//功能接口
public:
	//更新桌子
	virtual bool UpdateTableView(WORD wTableID)=0;
	//获取桌子
	virtual ITableView * GetTableViewItem(WORD wTableID)=0;
	//空椅子数
	virtual word GetNullChairCount(WORD wTableID, WORD & wNullChairID)=0;
};

#endif // _ITableViewFrame_H_