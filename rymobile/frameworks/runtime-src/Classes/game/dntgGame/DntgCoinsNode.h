#ifndef _Dntg_CoinsNode_H_
#define _Dntg_CoinsNode_H_

#include "cocos2d.h"
namespace  Dntg
{
#define MAX_COIN		30

	class CoinsNode : public cocos2d::Node
	{
	public:
		static CoinsNode* create();

	private:
		CoinsNode();
		~CoinsNode();
		bool init();

	public:
		void show_coin(int count, int score, int  chair_id_);

	private:
		void func_show(cocos2d::Node* node);
	public:
		cocos2d::Label *label_coin_;
		cocos2d::Label *label_coinSwitch_;        //对的你是给我切换用的 成不成功别怪我 我尽力了
		cocos2d::Sprite *spr_coin_[MAX_COIN];
		bool			m_bShowNodt;				//默认显示
		cocos2d::SpriteBatchNode* mBatchNode;
		int				m_mCharID;
		static bool m_bShow;
	};
}
#endif // _CoinsNode_H_