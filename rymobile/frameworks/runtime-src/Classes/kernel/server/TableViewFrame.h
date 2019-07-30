#ifndef _TableViewFrame_H_
#define _TableViewFrame_H_

#include <vector>
#include "ITableViewFrame.h"
#include "../user/IClientUserItem.h"
#include "platform/PlatformHeader.h"

//////////////////////////////////////////////////////////////////////////////////
//桌子视图
class CTableView : public ITableView
{
	//桌子属性
protected:
	//桌子标志
	bool							mIsLocker;							//密码标志
	bool							mIsPlaying;							//游戏标志
	bool							mIsFocusFrame;						//框架标志

	//桌子状态
	WORD							mWatchCount;						//旁观数目
	dword							mTableOwnerID;						//桌主索引

	//属性变量
	WORD							mTableID;							//桌子号码
	WORD							mChairCount;						//椅子数目
	IClientUserItem *				mIClientUserItem[MAX_CHAIR];		//用户信息

	//组件接口
protected:
	ITableViewFrame *				mITableViewFrame;					//桌子接口

	//函数定义
public:
	//构造函数
	CTableView();
	//析构函数
	virtual ~CTableView();

	//功能接口
public:
	//空椅子数
	virtual WORD GetNullChairCount(word & wNullChairID);
	//配置函数
	virtual void InitTableView(word wTableID, word wChairCount, ITableViewFrame * pITableViewFrame);

	//用户接口
public:
	//获取用户
	virtual IClientUserItem * GetClientUserItem(word wChairID);
	//设置信息
	virtual bool SetClientUserItem(word wChairID, IClientUserItem * pIClientUserItem);

	//查询接口
public:
	//游戏标志
	virtual bool GetPlayFlag() { return mIsPlaying; }
	//密码标志
	virtual bool GetLockerFlag() { return mIsLocker; }

	//状态接口
public:
	//焦点框架
	virtual void SetFocusFrame(bool bFocusFrame);
	//桌子状态 
	virtual void SetTableStatus(bool bPlaying, bool bLocker);
};

//////////////////////////////////////////////////////////////////////////////////

//数组定义
typedef std::vector<CTableView *>		CTableViewArray;					//桌子数组

//桌子框架
class CTableViewFrame 
	: public ITableViewFrame
{
	//友元定义
	friend class CTableView;

	//属性变量
protected:
	WORD							mTableCount;						//游戏桌数
	WORD							mChairCount;						//椅子数目
	dword							mServerRule;						//房间规则
	WORD							mServerType;						//房间类型

	//控制变量
public:

	//控件变量
public:
	CTableViewArray					mTableViewArray;					//桌子数组

	//比赛变量
public:
	

	//函数定义
public:
	//构造函数
	CTableViewFrame();
	//析构函数
	virtual ~CTableViewFrame();

	//配置接口
public:
	//配置桌子
	virtual bool ConfigTableFrame(WORD wTableCount, WORD wChairCount, dword dwServerRule, WORD wServerType, WORD wServerID);

	//信息接口
public:
	//桌子数目
	virtual WORD GetTableCount() { return mTableCount; }
	//椅子数目
	virtual WORD GetChairCount() { return mChairCount; }
	
	//用户接口
public:
	//获取用户
	virtual IClientUserItem * GetClientUserItem(WORD wTableID, WORD wChairID);
	//设置信息
	virtual bool SetClientUserItem(WORD wTableID, WORD wChairID, IClientUserItem * pIClientUserItem);

	//状态接口
public:
	//游戏标志
	virtual bool GetPlayFlag(WORD wTableID);
	//密码标志
	virtual bool GetLockerFlag(WORD wTableID);
	//焦点框架
	virtual void SetFocusFrame(WORD wTableID, bool bFocusFrame);
	//桌子状态 
	virtual void SetTableStatus(WORD wTableID, bool bPlaying, bool bLocker);
	//桌子状态 
	virtual void SetTableStatus(bool bWaitDistribute);

	//视图控制
public:
	//桌子可视
	virtual bool VisibleTable(WORD wTableID);
	//闪动桌子
	virtual bool FlashGameTable(WORD wTableID);
	//闪动椅子
	virtual bool FlashGameChair(WORD wTableID, WORD wChairID);

	//功能接口
public:
	//更新桌子
	virtual bool UpdateTableView(WORD wTableID);
	//获取桌子
	virtual ITableView * GetTableViewItem(WORD wTableID);
	//空椅子数
	virtual word GetNullChairCount(WORD wTableID, WORD & wNullChairID);

};

//////////////////////////////////////////////////////////////////////////////////

#endif // _TableViewFrame_H_