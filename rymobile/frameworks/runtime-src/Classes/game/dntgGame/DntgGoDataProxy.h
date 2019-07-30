#ifndef _Dntg_GoDataProxy_H_
#define _Dntg_GoDataProxy_H_

#include "platform/PlatformHeader.h"

namespace  Dntg
{
	class GoDataProxy
	{
	public:
		static GoDataProxy* shared();
	public:
		GoDataProxy();
		~GoDataProxy();
		//重置数据
		void reset();

		//设置获取财富
		void  setTreasure(int64 lTreasure);
		int64 getTreasure() const;

		//设置抓鱼排行榜信息
		void setRankInfo(int64 lRankScore, int64 lRankScoreCatch);
		int64 getRankScore() const;
		//设置排行榜列表
		int getSelfRank() const;
		dword getRankRefresh() const;
		void setRankList(dword dwRefreshTime, int iRanks, tagRankItem RankItems[10], SCORE lRankScores[10]);
		int getRankListCount() const;
		const tagRankItem& getRankListItem(int index) const;
		SCORE getRankScores(int index) const;
	private:
		int64		mTreasure;

		int64		mRankScore;
		int64		mRankScoreCatch;
		dword		mRefreshTime;
		int			mRanks;
		tagRankItem mRankItems[10];
		SCORE		mRankScores[10];
	}; // GoDataProxy

}
#endif // _GoDataProxy_H_