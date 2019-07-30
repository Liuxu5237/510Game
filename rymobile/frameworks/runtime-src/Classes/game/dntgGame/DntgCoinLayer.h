#ifndef _Dntg_CoinLayer_H_
#define _Dntg_CoinLayer_H_

#include "cocos2d.h"
#include "tools/manager/Move_Point_Manager.h"
#include "widget/CCRichText.h"
USING_NS_CC;
class TailorView;
namespace  Dntg
{

	class CoinLayer
		: public cocos2d::Layer
	{
	public:
		CREATE_FUNC(CoinLayer);

	private:
		CoinLayer();
		~CoinLayer();
		bool init();

	public:
		// 金币出现动画
		void coin_move(int chair_id, int bird_type, const xPoint& pt_src, const xPoint& pt_dst);
		// 金币数字动画
		void coin_label(const xPoint& pt_src, int font_index, int price , bool bmeChairID);
		// 奖牌动画
		void big_fish_flash(const xPoint& pt, int price);
		void add_award(int chair_id, const xPoint& pt_src, int award_type, int award_count);

		// 动画特效播放
		void effect_play(const xPoint& pt, int index, float time = 1.0, float delay = 0.0f, float scale = 1.0);
		//粒子渐变小展示
		void ParSma_paly(const xPoint& pt, const std::string ParName, int count, int Opacity = 255);
		//炉子粒子展示
		void Particle_paly(const xPoint& pt, float time, const std::string ParName);
		//爆炸粒子展示
		void Explosion_paly(const xPoint& pt, const std::string ParName, int count, float time, int randColor);
		//定粒子展示
		void Ding_paly(const xPoint& pt, float time, const std::string ParName);

	private:
		void func_coin_label_end(cocos2d::Node *target, void* data);
		void func_coin_move_end(cocos2d::Node *target, void* data);
		void func_award_move_end(cocos2d::Node *target, void* data);
		void func_award_label_end(cocos2d::Node *target, void* data);
		void func_effect_end(cocos2d::Node *target, void* data);
		void clearParticleSprite(cocos2d::Node* node, void* data);
		void func_alarm_tips_end(cocos2d::Node *target, void* data);
		void func_big_fish_flash_end(cocos2d::Node *target, void* data);

		void func_msg_show(cocos2d::Node* target, void* data);
		void func_msg_start_next(cocos2d::Node* target, void* data);
		void msg_start_next(bool bRemoveFront);

		//////////////////////////////////////////////////////////////////////////
		// Notifcation
		void onGladMessage(cocos2d::Ref* obj);
		void func_msg_show_n(cocos2d::Node* target, void* data);
		void func_msg_start_next_n(cocos2d::Node* target, void* data);
		void msg_start_next_n(bool bRemoveFront);
		void add_msg(const std::string& msg);

	private:
		cocos2d::Sprite*	mSptAlarm;
		cocos2d::Sprite*	mSptAlarmTips0;
		cocos2d::SpriteBatchNode* batch_node_;

	private:
		typedef std::list<std::string>	MSG_LIST;
		typedef MSG_LIST::iterator		MSG_LIST_ITER;
		MSG_LIST				mMessageList;

		cocos2d::Sprite*		mMsgBackground;
		TailorView*				mTailor;
		cocos2d::Label *	mMsgContents[2];
		int						mMsgContentIndex;

		typedef std::list<CCRichText*>		MSG_N_LIST;
		typedef MSG_N_LIST::iterator		MSG_N_LIST_ITER;
		MSG_N_LIST							mMsgNodeList;


		cocos2d::Sprite*		mAwardBg;
		cocos2d::Label *	mAwardNum;
	};

}

#endif // _CoinLayer_H_