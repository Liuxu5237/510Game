#include "DntgGoDataProxy.h"
#include "tools/tools/MTNotification.h"
#include "platform/data/GlobalUserInfo.h"
#include "kernel/game/IClientKernel.h"
#include "kernel/user/IClientUserItem.h"

USING_NS_CC;
using namespace Dntg;
GoDataProxy* __DntgGoDataProxyShared = 0;

GoDataProxy* GoDataProxy::shared()
{
	return __DntgGoDataProxyShared;
}

GoDataProxy::GoDataProxy()
{
	__DntgGoDataProxyShared = this;
}

GoDataProxy::~GoDataProxy()
{
	__DntgGoDataProxyShared = 0;
}

//重置数据
void GoDataProxy::reset()
{
	mTreasure = 0;
	mRankScore = 0;
	mRankScoreCatch = 0;
	mRanks = 0;
}

void GoDataProxy::setTreasure(int64 lTreasure)
{
	if (lTreasure != mTreasure)
	{
		mTreasure = lTreasure;
		IClientKernel* kernel = IClientKernel::get();

		if ((kernel->GetServerAttribute()->wServerType&GAME_GENRE_GOLD) == 0)
		{
			//变量定义
			CGlobalUserInfo * pGlobalUserInfo = CGlobalUserInfo::GetInstance();
			//设置变量
			pGlobalUserInfo->lUserScore = mTreasure;
		}

		G_NOTIFY_D("DATA_TREASURE_CHANGED", 0);
	}
}

int64 GoDataProxy::getTreasure() const
{
	return mTreasure;
}

//设置抓鱼排行榜信息
void GoDataProxy::setRankInfo(int64 lRankScore, int64 lRankScoreCatch)
{

	if (lRankScore != mRankScore ||
		lRankScoreCatch != mRankScoreCatch)
	{
		mRankScore = lRankScore;
		mRankScoreCatch = lRankScoreCatch;
		G_NOTIFY_D("RANK_INFO", 0);
	}
}

int64 GoDataProxy::getRankScore() const
{
	return mRankScoreCatch + mRankScore;
}

bool Dntg_scoreSort(const SCORE& l, const SCORE& r)
{
	return l > r;
}

bool Dntg_sortItem(const tagRankItem& l, const tagRankItem& r)
{
	return l.lScore > r.lScore;
}

//设置排行榜列表
void GoDataProxy::setRankList(dword dwRefreshTime, int iRanks, tagRankItem RankItems[10], SCORE lRankScores[10])
{
	mRefreshTime = dwRefreshTime;
	mRanks = iRanks;
	memcpy(mRankItems, RankItems, sizeof(mRankItems));
	memcpy(mRankScores, lRankScores, sizeof(mRankScores));

	std::sort(&mRankItems[0], &mRankItems[mRanks], Dntg_sortItem);
	std::sort(&mRankScores[0], &mRankScores[10], Dntg_scoreSort);
	G_NOTIFY_D("RANK_LIST", 0);
}

dword GoDataProxy::getRankRefresh() const
{
	return mRefreshTime;
}

int GoDataProxy::getSelfRank() const
{
	IClientKernel* kernel = IClientKernel::get();

	if (kernel == 0 || kernel->GetMeUserItem() == 0)
		return -1;

	for (int i = 0; i < mRanks; ++i)
	{
		if (mRankItems[i].dwUserID == IClientKernel::get()->GetMeUserItem()->GetUserID())
			return i;
	}

	return -1;
}

int GoDataProxy::getRankListCount() const
{
	return mRanks;
}

const tagRankItem& GoDataProxy::getRankListItem(int index) const
{
	return mRankItems[index];
}

SCORE GoDataProxy::getRankScores(int index) const
{
	return mRankScores[index];
}