#ifndef _Dntg_UIRankList_H_
#define _Dntg_UIRankList_H_

#include "cocos2d.h"
#include "cocos-ext.h"
namespace  Dntg
{
	class UIRankList
		: public cocos2d::Node
	{
	public:
		static UIRankList* create();
		static UIRankList* shared();
	private:
		UIRankList();
		~UIRankList();
		bool init();
	private:
		void updateRankList();
		void updateRankInfo();
		void onRankListNotify(cocos2d::Ref* obj);
		void onRankInfoNotify(cocos2d::Ref* obj);

	private:
		cocos2d::Label*		mLbNames[10];
		cocos2d::Label*		mLbScores[10];
		cocos2d::Label*		mLbDescs[10];

		cocos2d::Label*		mLbTime;

		cocos2d::Label*		mLbCurRank;
		cocos2d::Label*		mLbCurScore;

	};
}
#endif // _UIRankList_H_