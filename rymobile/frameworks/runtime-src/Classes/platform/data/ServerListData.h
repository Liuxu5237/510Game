#ifndef SERVER_LIST_DATA_HEAD_FILE
#define SERVER_LIST_DATA_HEAD_FILE

#pragma once

#include <vector>
#include <map>
#include "../df/Struct.h"
#include "../df/types.h"
#include "cocos2d.h"
//////////////////////////////////////////////////////////////////////////////////
//枚举定义

//子项类型
enum enItemGenre
{
	ItemGenre_Type,					//游戏种类
	ItemGenre_Kind,					//游戏类型
	ItemGenre_Node,					//游戏节点
	ItemGenre_Page,					//游戏页面
	ItemGenre_Server,				//游戏房间
	ItemGenre_Inside,				//游戏内部
};

//房间状态
enum enServerStatus
{
	ServerStatus_Normal,			//正常状态
	ServerStatus_Entrance,			//正在使用
	ServerStatus_EverEntrance,		//曾经进入
};

//////////////////////////////////////////////////////////////////////////////////

//类说明
class CGameListItem;
class CGameTypeItem;
class CGameKindItem;
class CGameNodeItem;
class CGamePageItem;
class CGameServerItem;
class CGameInsideItem;

//数组说明
typedef std::vector<CGameListItem *> CGameListItemArray;

//索引说明
 

typedef std::map<uint16, CGameTypeItem* > CGameTypeItemMap;
typedef std::map<uint16, CGameKindItem* > CGameKindItemMap;
typedef std::map<uint16, CGameNodeItem* > CGameNodeItemMap;
typedef std::map<uint16, CGamePageItem* > CGamePageItemMap;
typedef std::map<uint16, CGameServerItem* > CGameServerItemMap;

//typedef CMap<uint16,uint16,CGameTypeItem *,CGameTypeItem * &> CGameTypeItemMap;
//typedef CMap<uint16,uint16,CGameKindItem *,CGameKindItem * &> CGameKindItemMap;
//typedef CMap<uint16,uint16,CGameNodeItem *,CGameNodeItem * &> CGameNodeItemMap;
//typedef CMap<uint16,uint16,CGamePageItem *,CGamePageItem * &> CGamePageItemMap;
//typedef CMap<uint16,uint16,CGameServerItem *,CGameServerItem * &> CGameServerItemMap;

//////////////////////////////////////////////////////////////////////////////////

//列表接口
struct IServerListDataSink
{
	//状态通知
public:
	//完成通知
	virtual void OnGameItemFinish()=0;
	//完成通知
	virtual void OnGameKindFinish(uint16 wKindID)=0;
	//更新通知
	virtual void OnGameItemUpdateFinish()=0;

	//更新通知
public:
	//插入通知
	virtual void OnGameItemInsert(CGameListItem * pGameListItem)=0;
	//更新通知
	virtual void OnGameItemUpdate(CGameListItem * pGameListItem)=0;
	//删除通知
	virtual void OnGameItemDelete(CGameListItem * pGameListItem)=0;
};

//////////////////////////////////////////////////////////////////////////////////

//列表子项
class CGameListItem : public cocos2d::Ref
{
	//友元定义
	friend class CServerListData;

	//属性数据
protected:
	enItemGenre						m_ItemGenre;						//子项类型
	CGameListItem *					m_pParentListItem;					//父项子项

	//函数定义
protected:
	//构造函数
	CGameListItem(enItemGenre ItemGenre);
	//析构函数
	virtual ~CGameListItem();

	//功能函数
public:
	//获取类型
	enItemGenre GetItemGenre() { return m_ItemGenre; }
	//获取父项
	CGameListItem * GetParentListItem() { return m_pParentListItem; }

	//重载函数
public:
	//排列索引
	virtual uint16 GetSortID()=0;
};

//////////////////////////////////////////////////////////////////////////////////

//种类结构
class CGameTypeItem : public CGameListItem
{
	//属性数据
public:
	tagGameType						m_GameType;							//种类信息

	//函数定义
public:
	//构造函数
	CGameTypeItem();
	//析构函数
	virtual ~CGameTypeItem();

	virtual tagGameType* GetGameType(){ return &m_GameType; }

	//重载函数
public:
	//排列索引
	virtual uint16 GetSortID() { return m_GameType.wSortID; }
};

//////////////////////////////////////////////////////////////////////////////////

//类型结构
class CGameKindItem : public CGameListItem
{
	//属性数据
public:
	tagGameKind						m_GameKind;							//类型信息

	//更新变量
public:
	bool							m_bUpdateItem;						//更新标志
	uint32							m_dwUpdateTime;						//更新时间

	//扩展数据
public:
	uint32							m_dwProcessVersion;					//游戏版本

	//函数定义
public:
	//构造函数
	CGameKindItem();
	//析构函数
	virtual ~CGameKindItem();
	virtual tagGameKind* GetGameKind(){ return &m_GameKind; }

	//重载函数
public:
	//排列索引
	virtual uint16 GetSortID() { return m_GameKind.wSortID; }


};

//////////////////////////////////////////////////////////////////////////////////

//节点结构
class CGameNodeItem : public CGameListItem
{
	//属性数据
public:
	tagGameNode						m_GameNode;							//节点信息

	//函数定义
public:
	//构造函数
	CGameNodeItem();
	//析构函数
	virtual ~CGameNodeItem();

	virtual tagGameNode* GetGameNode(){ return &m_GameNode; }

	//重载函数
public:
	//排列索引
	virtual uint16 GetSortID() { return m_GameNode.wSortID; }
};

//////////////////////////////////////////////////////////////////////////////////

//房间结构
class CGameServerItem : public CGameListItem
{
	//属性数据
public:
	tagGameServer					m_GameServer;						//房间信息
	tagGameMatch					m_GameMatch;						//比赛信息
	//扩展数据
public:
	enServerStatus					m_ServerStatus;						//房间状态

	//辅助变量
public:
	CGameKindItem *					m_pGameKindItem;					//游戏类型

	//函数定义
public:
	//构造函数
	CGameServerItem();
	//析构函数
	virtual ~CGameServerItem();

	virtual tagGameServer* GetGameServer(){ return &m_GameServer; }

	virtual tagGameMatch * GetGameMatch() { return &m_GameMatch; }
	//重载函数
public:
	//排列索引
	virtual uint16 GetSortID() { return m_GameServer.wSortID; }
};

//////////////////////////////////////////////////////////////////////////////////

//定制结构
class CGamePageItem : public CGameListItem
{
	//属性数据
public:
	tagGamePage						m_GamePage;							//定制信息

	//函数定义
public:
	//构造函数
	CGamePageItem();
	//析构函数
	virtual ~CGamePageItem();

	virtual tagGamePage* GetGamePage(){ return &m_GamePage; }

	//重载函数
public:
	//排列索引
	virtual uint16 GetSortID() { return m_GamePage.wSortID; }
};

//////////////////////////////////////////////////////////////////////////////////

//内部结构
class CGameInsideItem : public CGameListItem
{
	//属性数据
public:
	uint32							m_dwInsideID;						//内部 ID

	//函数定义
public:
	//构造函数
	CGameInsideItem();
	//析构函数
	virtual ~CGameInsideItem();

	//重载函数
public:
	//排列索引
	virtual uint16 GetSortID() { return 0L; }
};

//////////////////////////////////////////////////////////////////////////////////

//列表服务
class CServerListData : public cocos2d::Ref, IServerListDataSink
{
	//静态函数
public:
	//获取对象
	static CServerListData* shared();

	//销毁对象
	static void purge();

	//索引变量
protected:

	CGameTypeItemMap				m_GameTypeItemMap;					//种类索引
	std::vector<std::pair<uint16, CGameTypeItem*>> mVectorGameTypeItem;
	
	CGameKindItemMap				m_GameKindItemMap;					//类型索引
	std::vector<std::pair<uint16, CGameKindItem*>> mVectorGameKindItem;

	CGameNodeItemMap				m_GameNodeItemMap;					//节点索引
	std::vector<std::pair<uint16, CGameNodeItem*>> mVectorGameNodeItem;

	CGamePageItemMap				m_GamePageItemMap;					//页面索引
	std::vector<std::pair<uint16, CGamePageItem*>> mVectorGamePageItem;

	CGameServerItemMap				m_GameServerItemMap;				//房间索引
	std::vector<std::pair<uint16, CGameServerItem*>>  mVectorGameServerItem;

	//内核变量
protected:
	CGameListItemArray				m_GameListItemWait;					//等待子项
	
public:
	uint32                           m_dwAllOnLineCount;                 //总在线人数

	//函数定义
private:
	//构造函数
	CServerListData();

	//析构函数
	virtual ~CServerListData();

public:
	//完成通知
	virtual void OnGameItemFinish();

	//完成通知
	virtual void OnGameKindFinish(uint16 wKindID);

	//更新通知
	virtual void OnGameItemUpdateFinish();

public:
	//插入通知
	virtual void OnGameItemInsert(CGameListItem * pGameListItem);

	//更新通知
	virtual void OnGameItemUpdate(CGameListItem * pGameListItem);

	//删除通知
	virtual void OnGameItemDelete(CGameListItem * pGameListItem);

	//人数函数
public:
	//设置人数
	void SetKindOnLineCount(uint16 wKindID, uint32 dwOnLineCount);

	//设置人数
	void SetServerOnLineCount(uint16 wServerID, uint32 dwOnLineCount);

	//设置人数
	void SetServerOnLineFinish();

	//插入函数
public:
	//插入种类
	bool InsertGameType(const cocos2d::Ref * pGameType);

	//插入类型
	bool InsertGameKind(const cocos2d::Ref * pGameKind);

	//插入节点
	bool InsertGameNode(const cocos2d::Ref * pGameNode);

	//插入定制
	bool InsertGamePage(const cocos2d::Ref * pGamePage);

	//插入房间
	bool InsertGameServer(const cocos2d::Ref * pGameServer);

	//插入房间
	bool InsertGameMatch(const cocos2d::Ref * pGameMatch);

	//删除函数
public:
	//删除种类
	bool DeleteGameType(uint16 wTypeID);

	//删除类型
	bool DeleteGameKind(uint16 wKindID);

	//删除节点
	bool DeleteGameNode(uint16 wNodeID);

	//删除定制
	bool DeleteGamePage(uint16 wPageID);

	//删除房间
	bool DeleteGameServer(uint16 wServerID);
	//清理种类
public:
	//清理种类
	bool ClearGameType();
	
	//清理类型
	bool ClearGameKind();
	
	//清理节点
	bool ClearGameNode();
	
	//清理定制
	bool ClearGamePage();
	
	//清理房间
	bool ClearGameServer();

	//查找函数
public:
	//查找种类
	CGameTypeItem * SearchGameTypeByIndex(uint32 nIndex);

	//查找类型
	CGameKindItem * SearchGameKindByIndex(uint32 nIndex);

	//查找节点
	CGameNodeItem * SearchGameNodeByIndex(uint32 nIndex);

	//查找定制
	CGamePageItem * SearchGamePageByIndex(uint32 nIndex);

	//查找房间
	CGameServerItem * SearchGameServerByIndex(uint32 nIndex);

public:
	//查找种类
	CGameTypeItem * SearchGameType(uint16 wTypeID);

	//查找类型
	CGameKindItem * SearchGameKind(uint16 wKindID);

	//查找节点
	CGameNodeItem * SearchGameNode(uint16 wNodeID);

	//查找定制
	CGamePageItem * SearchGamePage(uint16 wPageID);

	//查找房间
	CGameServerItem * SearchGameServer(uint16 wServerID);

	//数目函数
public:
	//种类数目
	uint32 GetGameTypeCount() { return (uint32)m_GameTypeItemMap.size(); }

	//类型数目
	uint32 GetGameKindCount() { return (uint32)m_GameKindItemMap.size(); }

	//节点数目
	uint32 GetGameNodeCount() { return (uint32)m_GameNodeItemMap.size(); }

	//定制数目
	uint32 GetGamePageCount() { return (uint32)m_GamePageItemMap.size(); }

	//房间数目 --by wh:取出的每个游戏房间Item的数量，而不是所有的游戏Item的数量
	uint32 GetGameServerCount() { return (uint32)mVectorGameServerItem.size(); }

public:
	//获取总在线人数
	uint32 GetAllOnLineCount();//{return m_dwAllOnLineCount;}

protected:

	//枚举种类
	CGameTypeItemMap::iterator GetTypeItemMapBegin() 
	{ 
		return m_GameTypeItemMap.begin(); 
	}
	CGameTypeItem * EmunGameTypeItem(CGameTypeItemMap::iterator &it);

	//枚举类型
	CGameKindItemMap::iterator GetKindItemMapBegin() 
	{ 
		return m_GameKindItemMap.begin(); 
	}
	CGameKindItemMap GetKindItemMap() 
	{ 
		return m_GameKindItemMap; 
	}
	CGameKindItem * EmunGameKindItem(CGameKindItemMap::iterator &it);

	//枚举节点
	CGameNodeItem * EmunGameNodeItem(CGameNodeItemMap::iterator &it);

	//枚举定制
	CGamePageItem * EmunGamePageItem(CGamePageItemMap::iterator &it);
	CGamePageItemMap GetGamePageMap() 
	{ 
		return m_GamePageItemMap; 
	}
	CGamePageItemMap::iterator GetPageItemMapBegin() 
	{ 
		return m_GamePageItemMap.begin(); 
	}

	//枚举房间
	CGameServerItemMap::iterator GetServerItemMapBegin()
	{ 
		return m_GameServerItemMap.begin(); 
	}
	CGameServerItem * EmunGameServerItem(CGameServerItemMap::iterator &it);
};

//////////////////////////////////////////////////////////////////////////////////

#endif
