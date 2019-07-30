#ifndef _IServerItem_H_
#define _IServerItem_H_

#include "../IChatSink.h"
#include "../IStringMessageSink.h"
#include "IServerItemSink.h"


//查找桌子
class tagSearchTable : public cocos2d::Ref
{
	CC_SET_AND_GET(bool, bOneNull, OneNull);				//一个空位
	CC_SET_AND_GET(bool, bTwoNull, TwoNull);				//两个空位
	CC_SET_AND_GET(bool, bAllNull, AllNull);				//全空位置
	CC_SET_AND_GET(bool, bNotFull, NotFull);				//不全满位
	CC_SET_AND_GET(bool, bFilterPass, FilterPass);			//过滤密码
	
	CC_SET_AND_GET(word, wStartTableID, StartTableID);		//起始桌子
	CC_SET_AND_GET(word, wResultTableID, ResultTableID);	//结果桌子
	CC_SET_AND_GET(word, wResultChairID, ResultChairID);	//结果椅子
};

class CGameServerItem;

//房间
class IServerItem : public cocos2d::Ref
{
public:
	virtual ~IServerItem(){};

	//配置接口
public:
	//设置接口
	virtual bool SetServerItemSink(IServerItemSink* pIServerItemSink)=0;
	//设置接口
	virtual bool SetChatSink(IChatSink* pIChatSink)=0;
	//设置接口
	virtual bool SetStringMessageSink(IStringMessageSink* pIStringMessageSink)=0;
	
	//连接接口
public:
	//连接服务器
	virtual bool ConnectServer(CGameServerItem * pGameServerItem,WORD wAVServerPort,dword dwAVServerAddr)=0;

	//重连服务器
	virtual bool ReconnectServer(CGameServerItem * pGameServerItem,WORD wAVServerPort,dword dwAVServerAddr) = 0;

	//连接断开
	virtual bool IntermitConnect(bool force)=0;

	//强行断开链接
	virtual void TerminConnect() = 0;

	//恢复链接
	virtual void ResumeConnect() = 0;

	//属性接口
public:
	//用户属性
	virtual tagUserAttribute * GetUserAttribute() = 0;
	//房间属性
	virtual tagServerAttribute *  GetServerAttribute() = 0;
	//服务状态
	virtual enServiceStatus GetServiceStatus()=0;
	//是否服务状态
	virtual bool IsService()=0;
	//设置状态
	virtual void SetServiceStatus(enServiceStatus ServiceStatus)=0;
	//自己状态
	virtual bool IsPlayingMySelf()=0;
	//用户接口
public:
	//自己位置
	virtual IClientUserItem * GetMeUserItem()=0;
	//游戏用户
	virtual IClientUserItem * GetTableUserItem(word wChariID)=0;
	//查找用户
	virtual IClientUserItem * SearchUserByUserID(dword dwUserID)=0;
	//查找用户
	virtual IClientUserItem * SearchUserByGameID(dword dwGameID)=0;
	//查找用户
	virtual IClientUserItem * SearchUserByNickName(const char* szNickName)=0;
	
	//网络接口
public:
	//发送函数
	virtual bool SendSocketData(word wMainCmdID, word wSubCmdID)=0;

	//发送函数
	virtual bool SendSocketData(word wMainCmdID, word wSubCmdID, const char * pData, word wDataSize)=0;

	//发送函数
	virtual bool SendSocketDataLua(word wMainCmdID, word wSubCmdID, const cocos2d::Ref * data) = 0;

	//动作处理
public:
	//执行快速加入
	virtual bool PerformQuickSitDown()=0;
	virtual bool PerformAutoJoin() = 0;
	//执行旁观
	virtual bool PerformLookonAction(word wTableID, word wChairID)=0;
	//执行起立
	virtual bool PerformStandUpAction(word wTableID, word wChairID)=0;
	//执行坐下
	virtual bool PerformSitDownAction(word wTableID, word wChairID, bool bEfficacyPass, const char * psw = nullptr) = 0;
	//执行购买
	virtual bool PerformBuyProperty(byte cbRequestArea,const char* pszNickName, word wItemCount, word wPropertyIndex)=0;

	//桌子消息
public:
	//获得空桌子
	virtual WORD GetSpaceTableId(WORD tableid)=0;
	//获得对应桌子的空椅子
	virtual WORD GetSpaceChairId(WORD tableId)=0;
	//获得总桌子数
	virtual WORD GetTotalTableCount()=0;
	//////////////////////////////////////////////////////////////////////////
	// 框架消息
public:
	//游戏已准备好
	virtual void OnGFGameReady(bool bInit)=0;
	//游戏关闭
	virtual void OnGFGameClose(int iExitCode)=0;
	//放作弊场通知玩家进入新的游戏
	virtual void AvertGameEnter() = 0;

	//////////////////////////////////////////////////////////////////////////
	// Socket消息
public:
	// 发送数据
	virtual bool GFSendData(int main, int sub, const char * data, int size)=0;

public:
	static IServerItem* create();
	static void destory();
	static IServerItem* get();
};

#endif // _IServerItem_H_