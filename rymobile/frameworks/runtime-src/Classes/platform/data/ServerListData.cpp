#include "ServerListData.h"
#include "../df/Macro.h"
//构造函数
CGameListItem::CGameListItem(enItemGenre ItemGenre)
{
	//属性数据
	m_ItemGenre=ItemGenre;
	m_pParentListItem=0;

	return;
}

//析构函数
CGameListItem::~CGameListItem()
{
}

//////////////////////////////////////////////////////////////////////////////////

//构造函数
CGameTypeItem::CGameTypeItem() : CGameListItem(ItemGenre_Type)
{
	//属性数据
	zeromemory(&m_GameType,sizeof(m_GameType));
}

//析构函数
CGameTypeItem::~CGameTypeItem()
{
}

//////////////////////////////////////////////////////////////////////////////////

//构造函数
CGameKindItem::CGameKindItem() : CGameListItem(ItemGenre_Kind)
{
	//更新变量
	m_dwUpdateTime=0;
	m_bUpdateItem=false;

	//扩展数据
	m_dwProcessVersion=0L;

	//属性数据
	zeromemory(&m_GameKind,sizeof(m_GameKind));

	return;
}

//析构函数
CGameKindItem::~CGameKindItem()
{
}

//////////////////////////////////////////////////////////////////////////////////

//构造函数
CGameNodeItem::CGameNodeItem() : CGameListItem(ItemGenre_Node)
{
	//属性数据
	zeromemory(&m_GameNode,sizeof(m_GameNode));
}

//析构函数
CGameNodeItem::~CGameNodeItem()
{
}

//////////////////////////////////////////////////////////////////////////////////

//构造函数
CGameServerItem::CGameServerItem() : CGameListItem(ItemGenre_Server)
{
	//辅助变量
	m_pGameKindItem=0;

	//扩展数据
	m_ServerStatus=ServerStatus_Normal;

	//属性数据
	zeromemory(&m_GameServer,sizeof(m_GameServer));
}

//析构函数
CGameServerItem::~CGameServerItem()
{
}

//////////////////////////////////////////////////////////////////////////////////

//构造函数
CGamePageItem::CGamePageItem() : CGameListItem(ItemGenre_Page)
{
	//属性数据
	zeromemory(&m_GamePage,sizeof(m_GamePage));
}

//析构函数
CGamePageItem::~CGamePageItem()
{
}

//////////////////////////////////////////////////////////////////////////////////

/************************************************************************/
/* 构造函数                                                             */
/************************************************************************/
CGameInsideItem::CGameInsideItem() : CGameListItem(ItemGenre_Inside)
{
}

/************************************************************************/
/* 析构函数                                                              */
/************************************************************************/
CGameInsideItem::~CGameInsideItem()
{
}

//静态变量
CServerListData * __gServerListData=0;				//列表数据

/************************************************************************/
/* 获取对象                                                              */
/************************************************************************/
CServerListData* CServerListData::shared()
{
	if (__gServerListData == 0)
		__gServerListData = new CServerListData();
	return __gServerListData;
}

/************************************************************************/
/* 消除对                                                               */
/************************************************************************/
void CServerListData::purge()
{
	if (__gServerListData)
		delete __gServerListData;
	__gServerListData = 0;
}

/************************************************************************/
/* 构造函数                                                              */
/************************************************************************/
CServerListData::CServerListData()
{
	//设置质数
	//m_GameTypeItemMap.resize(PRIME_TYPE);
	//m_GameKindItemMap.resize(PRIME_KIND);
	//m_GameNodeItemMap.resize(PRIME_NODE);
	//m_GamePageItemMap.resize(PRIME_PAGE);
	//m_GameServerItemMap.resize(PRIME_SERVER);

	//设置对象
	//ASSERT(m_pServerListData==0);
	m_dwAllOnLineCount=0;

	return;
}

/************************************************************************/
/* 析构函数                                                              */
/************************************************************************/
CServerListData::~CServerListData()
{
	//删除种类
	CGameTypeItemMap::iterator itTypeItem = m_GameTypeItemMap.begin();
	for (; itTypeItem != m_GameTypeItemMap.end(); ++itTypeItem)
	{
		SafeDelete(itTypeItem->second);
	}
	m_GameTypeItemMap.clear();

	//删除类型
	CGameKindItemMap::iterator itKindItem = m_GameKindItemMap.begin();
	for (; itKindItem != m_GameKindItemMap.end(); ++itKindItem)
	{
		SafeDelete(itKindItem->second);
	}
	m_GameKindItemMap.clear();

	//删除节点
	CGameNodeItemMap::iterator itNodeItem = m_GameNodeItemMap.begin();
	for (; itNodeItem != m_GameNodeItemMap.end(); ++itNodeItem)
	{
		SafeDelete(itNodeItem->second);
	}
	m_GameNodeItemMap.clear();

	//删除定制
	CGamePageItemMap::iterator itPageItem = m_GamePageItemMap.begin();
	for (; itPageItem != m_GamePageItemMap.end(); ++itPageItem)
	{
		SafeDelete(itPageItem->second);
	}
	m_GamePageItemMap.clear();
	
	//删除房间
	CGameServerItemMap::iterator itServerItem = m_GameServerItemMap.begin();
	for (; itServerItem != m_GameServerItemMap.end(); ++itServerItem)
	{
		SafeDelete(itServerItem->second);
	}
	m_GameServerItemMap.clear();

	//删除定制
	CGameListItemArray::iterator itListItem = m_GameListItemWait.begin();
	for (; itListItem != m_GameListItemWait.end(); ++itListItem)
	{
		SafeDelete(*itListItem);
	}
	m_GameListItemWait.clear();

	mVectorGameTypeItem.clear();
	mVectorGameKindItem.clear();
	mVectorGameNodeItem.clear();
	mVectorGamePageItem.clear();

	mVectorGameServerItem.clear();

	return;
}

/************************************************************************/
/* 比较函数                                                             */
/************************************************************************/
int cmp(const std::pair<uint16, CGameListItem*>& x, const std::pair<uint16, CGameListItem*>& y)
{
	return (CGameListItem*)(x.second)->GetSortID() < (CGameListItem*)(y.second)->GetSortID();
}

/************************************************************************/
/* 完成通知                                                             */
/************************************************************************/
void CServerListData::OnGameItemFinish()
{
	mVectorGameTypeItem.clear();
	for (CGameTypeItemMap::iterator curr = m_GameTypeItemMap.begin(); curr != m_GameTypeItemMap.end(); curr++)
	{
		mVectorGameTypeItem.push_back(std::make_pair(curr->first, curr->second));
	}
	std::sort(mVectorGameTypeItem.begin(), mVectorGameTypeItem.end(), cmp);

	mVectorGameKindItem.clear();
	for (CGameKindItemMap::iterator curr = m_GameKindItemMap.begin(); curr != m_GameKindItemMap.end(); curr++)
	{
		mVectorGameKindItem.push_back(std::make_pair(curr->first, curr->second));
	}
	std::sort(mVectorGameKindItem.begin(), mVectorGameKindItem.end(), cmp);

	mVectorGameNodeItem.clear();
	for (CGameNodeItemMap::iterator curr = m_GameNodeItemMap.begin(); curr != m_GameNodeItemMap.end(); curr++)
	{
		mVectorGameNodeItem.push_back(std::make_pair(curr->first, curr->second));
	}
	std::sort(mVectorGameNodeItem.begin(), mVectorGameNodeItem.end(), cmp);

	mVectorGamePageItem.clear();
	for (CGamePageItemMap::iterator curr = m_GamePageItemMap.begin(); curr != m_GamePageItemMap.end(); curr++)
	{
		mVectorGamePageItem.push_back(std::make_pair(curr->first, curr->second));
	}
	std::sort(mVectorGamePageItem.begin(), mVectorGamePageItem.end(), cmp);
}

/************************************************************************/
/* 完成通知                                                             */
/************************************************************************/
void CServerListData::OnGameKindFinish(uint16 wKindID)
{
	mVectorGameServerItem.clear();

	for (CGameServerItemMap::iterator curr = m_GameServerItemMap.begin(); curr != m_GameServerItemMap.end(); curr++)
	{
		CGameServerItem * item_ = curr->second;
		if (item_ && item_->m_GameServer.wKindID == wKindID)
		{
			mVectorGameServerItem.push_back(std::make_pair(curr->first, curr->second));
		}
	}
	std::sort(mVectorGameServerItem.begin(), mVectorGameServerItem.end(), cmp);
}

/************************************************************************/
/* 更新通知                                                             */
/************************************************************************/
void CServerListData::OnGameItemUpdateFinish()
{
	//暂时不做事情
}

/************************************************************************/
/* 插入通知                                                             */
/************************************************************************/
void CServerListData::OnGameItemInsert(CGameListItem * pGameListItem)
{
	//暂时不做事情
}

/************************************************************************/
/* 更新通知                                                              */
/************************************************************************/
void CServerListData::OnGameItemUpdate(CGameListItem * pGameListItem)
{
	//暂时不做事情
}

/************************************************************************/
/* 删除通知                                                               */
/************************************************************************/
void CServerListData::OnGameItemDelete(CGameListItem * pGameListItem)
{
	//暂时不做事情
}

/************************************************************************/
/* 设置人数                                                             */
/************************************************************************/
void CServerListData::SetKindOnLineCount(uint16 wKindID, uint32 dwOnLineCount)
{
	//搜索类型
	CGameKindItem * pGameKindItem = SearchGameKind(wKindID);

	//设置人数
	if (pGameKindItem!=0)
	{
		//设置变量
		pGameKindItem->m_GameKind.dwOnLineCount = dwOnLineCount;
		OnGameItemUpdate(pGameKindItem);
	}
}

/************************************************************************/
/* 设置人数                                                              */
/************************************************************************/
void CServerListData::SetServerOnLineCount(uint16 wServerID, uint32 dwOnLineCount)
{
	//搜索房间
	CGameServerItem * pGameServerItem=SearchGameServer(wServerID);

	//设置人数
	if (pGameServerItem!=0)
	{
		//设置变量
		m_dwAllOnLineCount -= pGameServerItem->m_GameServer.dwOnLineCount;
		m_dwAllOnLineCount += dwOnLineCount;

		//设置变量
		pGameServerItem->m_GameServer.dwOnLineCount=dwOnLineCount;
		OnGameItemUpdate(pGameServerItem);
		//查找类型
		CGameKindItem * pGameKindItem = SearchGameKind(pGameServerItem->m_GameServer.wKindID);
		if(pGameKindItem)
		{
			//变量定义
			uint32 dwGameKindOnline=0;
			CGameServerItemMap::iterator it = m_GameServerItemMap.end();
			do
			{
				//获取房间
				CGameServerItem * pGameServerItem2=EmunGameServerItem(it);

				//设置房间
				if((pGameServerItem2 != 0) && (pGameServerItem2->m_GameServer.wKindID == pGameServerItem->m_GameServer.wKindID))
				{
					dwGameKindOnline += pGameServerItem2->m_GameServer.dwOnLineCount;
				}

			} while (it != m_GameServerItemMap.end());

			//设置变量
			pGameKindItem->m_GameKind.dwOnLineCount = dwGameKindOnline;
			OnGameItemUpdate(pGameKindItem);
		}
	}
}

/************************************************************************/
/* 设置人数                                                              */
/************************************************************************/
void CServerListData::SetServerOnLineFinish()
{
	//事件通知
	OnGameItemUpdateFinish();
}

/************************************************************************/
/* 插入种类                                                              */
/************************************************************************/
bool CServerListData::InsertGameType(const cocos2d::Ref * pRef)
{
	const tagGameType * pGameType = (const tagGameType *)pRef;
	//变量定义
	CGameTypeItem * pGameTypeItem=0;
	bool bInsert = false;
	CGameTypeItemMap::iterator it = m_GameTypeItemMap.find(pGameType->wTypeID);
	
	if (it == m_GameTypeItemMap.end())
	{
		pGameTypeItem = new CGameTypeItem;
		bInsert = true;
	}
	else
	{
		pGameTypeItem = it->second;
	}		
	
	if (pGameTypeItem == 0) return false;

	//设置数据
	memcpy(&pGameTypeItem->m_GameType,pGameType,sizeof(tagGameType));

	//寻找父项
	if (pGameType->wJoinID != 0)
	{
		//寻找父项
		pGameTypeItem->m_pParentListItem = SearchGameType(pGameType->wJoinID);

		//待决判断
		if (pGameTypeItem->m_pParentListItem==0) 
		{
			m_GameListItemWait.push_back(pGameTypeItem);
			return true;
		}
	}

	//插入处理
	if (bInsert)
	{
		//设置索引
		m_GameTypeItemMap[pGameType->wTypeID] = pGameTypeItem;
		OnGameItemInsert(pGameTypeItem);
	}
	else
	{
		OnGameItemUpdate(pGameTypeItem);
	}
	
	return true;
}

/************************************************************************/
/* 插入类型                                                             */
/************************************************************************/
bool CServerListData::InsertGameKind(const cocos2d::Ref * pRef)
{
	const tagGameKind * pGameKind = (const tagGameKind *)pRef;
	//变量定义
	CGameKindItem * pGameKindItem=0;
	bool bInsert = false;
	CGameKindItemMap::iterator it = m_GameKindItemMap.find(pGameKind->wKindID);

	if (it == m_GameKindItemMap.end())
	{
		pGameKindItem = new CGameKindItem;
		bInsert = true;
	}
	else
	{
		pGameKindItem = it->second;
	}		

	if (pGameKindItem == 0) return false;

	//获取版本
	if (bInsert==true)
	{
		//tchar szProcessPath[MAX_PATH]={0};
		//GetProcessPathByProcessFullName(pGameKind->szProcessName, szProcessPath, MAX_PATH);
		//CWHService::GetModuleVersion(szProcessPath,pGameKindItem->m_dwProcessVersion);
	}

	//设置数据
	memcpy(&pGameKindItem->m_GameKind,pGameKind,sizeof(tagGameKind));

	//寻找父项
	if (pGameKind->wJoinID != 0)
	{
		pGameKindItem->m_pParentListItem = SearchGameKind(pGameKind->wJoinID);
	}
	else
	{
		pGameKindItem->m_pParentListItem = SearchGameType(pGameKind->wTypeID);
	}

	//待决判断
	/*if (pGameKindItem->m_pParentListItem==0) 
	{
		m_GameListItemWait.push_back(pGameKindItem);
		return true;
	}*/

	//插入处理
	if (bInsert==true)
	{
		//设置索引
		m_GameKindItemMap[pGameKind->wKindID] = pGameKindItem;
		OnGameItemInsert(pGameKindItem);
	}
	else
	{
		OnGameItemUpdate(pGameKindItem);
	}
	
	return true;
}

/************************************************************************/
/* 插入节点                                                              */
/************************************************************************/
bool CServerListData::InsertGameNode(const cocos2d::Ref * pRef)
{
	const tagGameNode * pGameNode = (const tagGameNode *)pRef;
	//变量定义
	CGameNodeItem * pGameNodeItem=0;
	bool bInsert = false;
	CGameNodeItemMap::iterator it = m_GameNodeItemMap.find(pGameNode->wNodeID);

	if (it == m_GameNodeItemMap.end())
	{
		pGameNodeItem = new CGameNodeItem;
		bInsert = true;
	}
	else
	{
		pGameNodeItem = it->second;
	}		

	if (pGameNodeItem == 0) return false;

	//设置数据
	memcpy(&pGameNodeItem->m_GameNode,&pGameNode,sizeof(tagGameNode));

	//寻找父项
	if (pGameNode->wJoinID != 0)
	{
		pGameNodeItem->m_pParentListItem = SearchGameNode(pGameNode->wJoinID);
	}
	else
	{
		pGameNodeItem->m_pParentListItem = SearchGameKind(pGameNode->wKindID);
	}

	//待决判断
	if (pGameNodeItem->m_pParentListItem==0) 
	{
		m_GameListItemWait.push_back(pGameNodeItem);
		return true;
	}

	//插入处理
	if (bInsert==true)
	{
		//设置索引
		m_GameNodeItemMap[pGameNode->wNodeID] = pGameNodeItem;
		OnGameItemInsert(pGameNodeItem);
	}
	else
	{
		OnGameItemUpdate(pGameNodeItem);
	}
	return true;
}

/************************************************************************/
/* 插入定制                                                              */
/************************************************************************/
bool CServerListData::InsertGamePage(const cocos2d::Ref * pRef)
{
	const tagGamePage * pGamePage = (const tagGamePage *)pRef;

	//变量定义
	CGamePageItem * pGamePageItem=0;
	bool bInsert = false;
	CGamePageItemMap::iterator it = m_GamePageItemMap.find(pGamePage->wPageID);

	if (it == m_GamePageItemMap.end())
	{
		pGamePageItem = new CGamePageItem;
		bInsert = true;
	}
	else
	{
		pGamePageItem = it->second;
	}		

	if (pGamePageItem == 0) return false;


	//设置数据
	memcpy(&pGamePageItem->m_GamePage,pGamePage,sizeof(tagGamePage));

	//寻找父项
	if ((pGamePage->wNodeID != 0) || (pGamePage->wKindID != 0))
	{
		//寻找父项
		if (pGamePage->wNodeID != 0) pGamePageItem->m_pParentListItem = SearchGameNode(pGamePage->wNodeID);
		else if (pGamePage->wKindID != 0) pGamePageItem->m_pParentListItem = SearchGameKind(pGamePage->wKindID);

		//待决判断
		if (pGamePageItem->m_pParentListItem==0) 
		{
			m_GameListItemWait.push_back(pGamePageItem);
			return true;
		}
	}

	//插入处理
	if (bInsert==true)
	{
		//设置索引
		m_GamePageItemMap[pGamePage->wPageID] = pGamePageItem;
		OnGameItemInsert(pGamePageItem);
	}
	else
	{
		OnGameItemUpdate(pGamePageItem);
	}
	
	return true;
}

/************************************************************************/
/* 插入房间                                                              */
/************************************************************************/
bool CServerListData::InsertGameServer(const cocos2d::Ref * pRef)
{
	const tagGameServer * pGameServer = (const tagGameServer *)pRef;
	//变量定义
	CGameServerItem * pGameServerItem=0;
	bool bInsert = false;
	CGameServerItemMap::iterator it = m_GameServerItemMap.find(pGameServer->wServerID);

	if (it == m_GameServerItemMap.end())
	{
		pGameServerItem = new CGameServerItem;
		bInsert = true;
	}
	else
	{
		pGameServerItem = it->second;
	}		

	if (pGameServerItem == 0) return false;

	//设置数据
	memcpy(&pGameServerItem->m_GameServer,pGameServer,sizeof(tagGameServer));
	m_dwAllOnLineCount += pGameServer->dwOnLineCount;

	//寻找父项
	if (pGameServer->wNodeID != 0)
	{
		pGameServerItem->m_pGameKindItem = SearchGameKind(pGameServer->wKindID);
		pGameServerItem->m_pParentListItem = SearchGameNode(pGameServer->wNodeID);
	}
	else
	{
		pGameServerItem->m_pGameKindItem = SearchGameKind(pGameServer->wKindID);
		pGameServerItem->m_pParentListItem = SearchGameKind(pGameServer->wKindID);
	}

	//查找类型
	if(bInsert==true && pGameServerItem->m_pGameKindItem)
	{
		//变量定义
		uint32 dwGameKindOnline=0;
		uint32 dwGameKindFullCount=0;
		CGameServerItemMap::iterator it = m_GameServerItemMap.end();
		do
		{
			//获取房间
			CGameServerItem * pGameServerItem2=EmunGameServerItem(it);

			//设置房间
			if((pGameServerItem2 != 0) && (pGameServerItem2->m_GameServer.wKindID == pGameServerItem->m_GameServer.wKindID))
			{
				dwGameKindOnline += pGameServerItem2->m_GameServer.dwOnLineCount;
				dwGameKindFullCount += pGameServerItem2->m_GameServer.dwFullCount;
			}

		} while (it != m_GameServerItemMap.end());

		//设置变量
		pGameServerItem->m_pGameKindItem->m_GameKind.dwOnLineCount = dwGameKindOnline;
		pGameServerItem->m_pGameKindItem->m_GameKind.dwFullCount = dwGameKindFullCount;

		OnGameItemUpdate(pGameServerItem->m_pGameKindItem);
	}

	//插入处理
	if (bInsert==true)
	{
		//设置索引
		m_GameServerItemMap[pGameServer->wServerID] = pGameServerItem;
		OnGameItemInsert(pGameServerItem);
	}
	else
	{
		OnGameItemUpdate(pGameServerItem);
	}
	return true;
}

/************************************************************************/
/* 插入房间                                                              */
/************************************************************************/
bool CServerListData::InsertGameMatch(const cocos2d::Ref * pRef)
{
	const tagGameMatch * pGameMatch = (const tagGameMatch *)pRef;
	//变量定义
	CGameServerItem * pGameServerItem = 0;
	CGameServerItemMap::iterator it = m_GameServerItemMap.find(pGameMatch->wServerID);
	bool bInsert = false;
	if (it == m_GameServerItemMap.end())
	{
		pGameServerItem = new CGameServerItem;
		bInsert = true;
	}
	else
	{
		pGameServerItem = it->second;
	}

	if (pGameServerItem == 0)
	{
		return false;
	}

	//设置数据
	memcpy(&pGameServerItem->m_GameMatch, pGameMatch, sizeof(tagGameMatch));

	//插入处理
	if (bInsert == true)
	{
		//设置索引
		m_GameServerItemMap[pGameMatch->wServerID] = pGameServerItem;
		OnGameItemInsert(pGameServerItem);
	}
	else
	{
		OnGameItemUpdate(pGameServerItem);
	}

	return true;
}

/************************************************************************/
/* 删除种类                                                             */
/************************************************************************/
bool CServerListData::DeleteGameType(uint16 wTypeID)
{
	//查找种类
	CGameTypeItemMap::iterator it = m_GameTypeItemMap.find(wTypeID);
	if (it == m_GameTypeItemMap.end())
	{
		return false;
	}

	CGameTypeItem * pGameTypeItem= it->second;
	
	//删除通知
	OnGameItemDelete(pGameTypeItem);

	//重置数据
	SafeDelete(pGameTypeItem);

	//删除数据
	m_GameTypeItemMap.erase(it);

	return true;
}

/************************************************************************/
/* 删除类型                                                              */
/************************************************************************/
bool CServerListData::DeleteGameKind(uint16 wKindID)
{
	//查找类型
	CGameKindItemMap::iterator it = m_GameKindItemMap.find(wKindID);
	if (it == m_GameKindItemMap.end())
	{
		return false;
	}

	CGameKindItem * pGameKindItem=it->second;

	//删除通知
	OnGameItemDelete(pGameKindItem);

	//删除数据
	SafeDelete(pGameKindItem);

	//删除数据
	m_GameKindItemMap.erase(it);

	return true;
}

/************************************************************************/
/* 删除节点                                                              */
/************************************************************************/
bool CServerListData::DeleteGameNode(uint16 wNodeID)
{
	//查找节点
	CGameNodeItemMap::iterator it = m_GameNodeItemMap.find(wNodeID);
	if (it == m_GameNodeItemMap.end())
	{
		return false;
	}

	CGameNodeItem * pGameNodeItem=it->second;

	//删除通知
	OnGameItemDelete(pGameNodeItem);

	//删除数据
	SafeDelete(pGameNodeItem);

	//删除数据
	m_GameNodeItemMap.erase(it);

	return false;
}

/************************************************************************/
/* 删除房间                                                              */
/************************************************************************/
bool CServerListData::DeleteGameServer(uint16 wServerID)
{
	//查找房间
	CGameServerItemMap::iterator it = m_GameServerItemMap.find(wServerID);
	if (it == m_GameServerItemMap.end())
	{
		return false;
	}

	CGameServerItem * pGameServerItem=it->second;

	//设置数据
	m_dwAllOnLineCount -= pGameServerItem->m_GameServer.dwOnLineCount;

	OnGameItemDelete(pGameServerItem);

	//删除数据
	SafeDelete(pGameServerItem);

	//删除数据
	m_GameServerItemMap.erase(it);

	return false;
}

/************************************************************************/
/* 删除定制                                                             */
/************************************************************************/
bool CServerListData::DeleteGamePage(uint16 wPageID)
{
	//查找类型
	CGamePageItemMap::iterator it = m_GamePageItemMap.find(wPageID);
	if (it == m_GamePageItemMap.end())
	{
		return false;
	}

	CGamePageItem * pGamePageItem=it->second;

	//删除通知
	//ASSERT(m_pIServerListDataSink!=0);
	OnGameItemDelete(pGamePageItem);

	//删除数据
	SafeDelete(pGamePageItem);

	//删除数据
	m_GamePageItemMap.erase(it);

	return true;
}

//清理种类
bool CServerListData::ClearGameType()
{
	m_GameTypeItemMap.clear();
	mVectorGameTypeItem.clear();
	return true;
}

//清理类型
bool CServerListData::ClearGameKind()
{
	m_GameKindItemMap.clear();
	mVectorGameKindItem.clear();
	return true;
}

//清理节点
bool CServerListData::ClearGameNode()
{
	m_GameNodeItemMap.clear();
	mVectorGameNodeItem.clear();
	return true;
}

//清理定制
bool CServerListData::ClearGamePage()
{
	m_GamePageItemMap.clear();
	mVectorGamePageItem.clear();
	return true;
}

//清理房间
bool CServerListData::ClearGameServer()
{
	m_GameServerItemMap.clear();
	mVectorGameServerItem.clear();
	return true;
}

/************************************************************************/
/* 枚举种类                                                              */
/************************************************************************/
CGameTypeItem * CServerListData::EmunGameTypeItem(CGameTypeItemMap::iterator &it)
{
	//调整参数
	if (it==m_GameTypeItemMap.end()) it=m_GameTypeItemMap.begin();
	if (it==m_GameTypeItemMap.end()) return 0;

	//查找房间
	CGameTypeItem * pGameTypeItem=it->second;
	it++;
	return pGameTypeItem;
}

/************************************************************************/
/* 枚举类型                                                              */
/************************************************************************/
CGameKindItem * CServerListData::EmunGameKindItem(CGameKindItemMap::iterator &it)
{
	//调整参数
	if (it==m_GameKindItemMap.end()) it=m_GameKindItemMap.begin();
	if (it==m_GameKindItemMap.end()) return 0;

	//查找房间
	CGameKindItem * pGameKindItem=it->second;
	it++;
	return pGameKindItem;
}

/************************************************************************/
/* 枚举节点                                                              */
/************************************************************************/
CGameNodeItem * CServerListData::EmunGameNodeItem(CGameNodeItemMap::iterator &it)
{
	//调整参数
	if (it==m_GameNodeItemMap.end()) it=m_GameNodeItemMap.begin();
	if (it==m_GameNodeItemMap.end()) return 0;

	//查找节点
	CGameNodeItem * pGameNodeItem=it->second;
	it++;
	return pGameNodeItem;
}

/************************************************************************/
/* 枚举定制                                                             */
/************************************************************************/
CGamePageItem * CServerListData::EmunGamePageItem(CGamePageItemMap::iterator &it)
{
	//调整参数
	if (it==m_GamePageItemMap.end()) return 0;

	//查找房间
	CGamePageItem * pGamePageItem=it->second;
	it++;
	return pGamePageItem;
}

/************************************************************************/
/* 枚举房间                                                              */
/************************************************************************/
CGameServerItem * CServerListData::EmunGameServerItem(CGameServerItemMap::iterator &it)
{
	//调整参数
	if (it==m_GameServerItemMap.end()) return 0;

	//查找房间
	CGameServerItem * pGameServerItem=it->second;
	it++;
	return pGameServerItem;
}

/************************************************************************/
/* 查找种类                                                              */
/************************************************************************/
CGameTypeItem * CServerListData::SearchGameTypeByIndex(uint32 nIndex)
{
	if (nIndex < mVectorGameTypeItem.size())
	{
		return mVectorGameTypeItem[nIndex].second;
	}

	return NULL;
}

/************************************************************************/
/* 查找类型                                                              */
/************************************************************************/
CGameKindItem * CServerListData::SearchGameKindByIndex(uint32 nIndex)
{
	if (nIndex < mVectorGameKindItem.size())
	{
		return mVectorGameKindItem[nIndex].second;
	}

	return NULL;
}

/************************************************************************/
/* 查找节点                                                              */
/************************************************************************/
CGameNodeItem * CServerListData::SearchGameNodeByIndex(uint32 nIndex)
{
	if (nIndex < mVectorGameNodeItem.size())
	{
		return mVectorGameNodeItem[nIndex].second;
	}

	return NULL;
}

/************************************************************************/
/* 查找定制                                                             */
/************************************************************************/
CGamePageItem * CServerListData::SearchGamePageByIndex(uint32 nIndex)
{
	if (nIndex < mVectorGamePageItem.size())
	{
		return mVectorGamePageItem[nIndex].second;
	}

	return NULL;
}

/************************************************************************/
/* 查找房间                                                              */
/************************************************************************/
CGameServerItem * CServerListData::SearchGameServerByIndex(uint32 nIndex)
{
	if (nIndex < mVectorGameServerItem.size())
	{
		return mVectorGameServerItem[nIndex].second;
	}

	return NULL;
}

/************************************************************************/
/* 查找种类                                                             */
/************************************************************************/
CGameTypeItem * CServerListData::SearchGameType(uint16 wTypeID)
{
	CGameTypeItemMap::iterator it = m_GameTypeItemMap.find(wTypeID);
	if (it == m_GameTypeItemMap.end())
		return 0;

	return it->second;
}

/************************************************************************/
/* 查找类型                                                              */
/************************************************************************/
CGameKindItem * CServerListData::SearchGameKind(uint16 wKindID)
{
	CGameKindItemMap::iterator it = m_GameKindItemMap.find(wKindID);
	if (it == m_GameKindItemMap.end())
		return 0;

	return it->second;
}

/************************************************************************/
/* 查找节点                                                              */
/************************************************************************/
CGameNodeItem * CServerListData::SearchGameNode(uint16 wNodeID)
{
	CGameNodeItemMap::iterator it = m_GameNodeItemMap.find(wNodeID);
	if (it == m_GameNodeItemMap.end())
		return 0;

	return it->second;
}

/************************************************************************/
/* 查找房间                                                             */
/************************************************************************/
CGameServerItem * CServerListData::SearchGameServer(uint16 wServerID)
{
	CGameServerItemMap::iterator it = m_GameServerItemMap.find(wServerID);
	if (it == m_GameServerItemMap.end())
		return 0;

	return it->second;
}

/************************************************************************/
/* 查找定制                                                             */
/************************************************************************/
CGamePageItem * CServerListData::SearchGamePage(uint16 wPageID)
{
	CGamePageItemMap::iterator it = m_GamePageItemMap.find(wPageID);
	if (it == m_GamePageItemMap.end())
		return 0;

	return it->second;
}

/************************************************************************/
/* 获取总在线人数                                                        */
/************************************************************************/
uint32 CServerListData::GetAllOnLineCount()
{
	//定义变量
	uint32 dwAllOnLineCount=0;
	CGameKindItemMap::iterator it = m_GameKindItemMap.end();

	//遍历
	do
	{
		CGameKindItem *pGameKindItem = EmunGameKindItem(it);
		if(pGameKindItem)
		{
			dwAllOnLineCount += pGameKindItem->m_GameKind.dwOnLineCount;
		}
	}while(it != m_GameKindItemMap.end());

	return dwAllOnLineCount;
}

//////////////////////////////////////////////////////////////////////////////////
