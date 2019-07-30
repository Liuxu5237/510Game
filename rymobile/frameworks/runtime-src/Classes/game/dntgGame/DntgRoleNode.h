#ifndef _Dntg_RoleNode_H_
#define _Dntg_RoleNode_H_

#include "cocos2d.h"
#include "DntgCoinsNodeX.h"
#include "cocos-ext.h"
#include "DntgBirdNode.h"
#include "platform/PlatformHeader.h"
#include "tools/manager/Move_Point_Manager.h"

namespace  Dntg
{
	class RoleNode : public cocos2d::Node
	{
	public:
		static RoleNode* create(int char_id);

	private:
		RoleNode();
		~RoleNode();
		bool init(int char_id);

	public:
		void show(bool bShow,bool bGame);

		void show_coin(int count, int score, int chair_id_);

		std::string stringIntercept(std::string input, int signlen);

		void set_bow_angle(float angle);
		float get_bow_angle() const;
		bool can_fire();
		void fire(bool isSelf,bool bNoter = true);
		//你要卡我就初始化的时候让你打一炮 OK?
		void DaPaofire(bool isSelf);

		void set_nickname(const std::string& nickname);
		uint16 get_chair_id() const { return chair_id_; }

		int64 get_gold() const { return gold_; }
		void set_gold(int64 gold);

		uint16 get_cannon() const { return cannon_type_; }
		void set_cannon(uint16 cannon);

		uint16 get_level() const { return level_; }
		void set_level(uint16 level);

		int get_fire_mode() const { return fire_mode_; }

		bool is_warning_fire_show() const;
		void show_warning_fire(bool isShow);
		void set_warning_time(int time);
		void show_buttons(bool bShow);

		void set_net_state(uint32 difference);
		void set_fire_mode(int mode);

		void net_skill(int skill, int cast);
		void net_effect(int effect, int bird_id, const xPoint &pt_brid);

		//bool handle_click(const cocos2d::Vec2& pt);

		uint32 get_cannon_mulriple() const { return cannon_mulriple_; }
		void set_cannon_mulriple(uint32 cannon_mulriple);
		float get_cannon_speed() const { return cannon_speed_; }
		void set_cannon_speed(float cannon_speed) { cannon_speed_ = cannon_speed; }

		///< 自动更新
		void update(float delta);
		///< 矫正锁定线
		void correctLockLine(const cocos2d::Vec2 & bird_pos);
		///< 获取炮台位置
		cocos2d::Vec2 getPaoTaiPos();
		///< 显示能量炮聚集完毕效果
		void showPowerRoleCompleteEffect();
		///< 显示被击中的四海龙王的小头像
		void showDeadDragonKingSmallHead(int bird_id);
		///< 清理四海龙王的显示
		void clearDragonKingShow();
		///< 检测四海龙王是否聚齐
		void checkDragonKingComplete();
		///< 关闭财神显示
		void func_money_gold_callBack();
	private:
		void add_buff(int buff, const xPoint &pt_brid);
		void remove_buff(int buff);

	public:
		int get_sound_index() const;
		int get_sound_index_by(int level) const;
		int get_cannon_index_by(int level) const;
		int get_net_index_by(int level) const;
		int get_bullet_index_by(int level) const;

	private:
		void func_mark_end(cocos2d::Node* node);
		void func_born_end(cocos2d::Node* node);
		int time;
	private:
		float rotation_;
		int fire_mode_;
		int chair_id_;
		int64 gold_;
		uint16 cannon_type_;
		uint16 level_;
		uint32 buy_bird_gold_;
		uint32 buy_jinbi_gold_;
		bool is_buttons_;


		uint32 cannon_mulriple_;	//倍率
		float cannon_speed_;			//子弹速度

		typedef std::list<cocos2d::Node*> BUFF_LIST;
		typedef BUFF_LIST::iterator			BUFF_LIST_ITER;
		BUFF_LIST buff_list_;

		//炮台
		cocos2d::Sprite* mSptPaoTai;
		//弓
		cocos2d::Sprite* mSptTrack;
		//箭头指示器
		cocos2d::Sprite* mSptMark;
		//记分牌
		cocos2d::Sprite* mSptJiFenPai;
		//网络信号
		cocos2d::Sprite* mSptNetState;
		//弓
		cocos2d::Sprite* mSptBow;
		//炮台底座
		cocos2d::Sprite* mSptPaoTaiOver;
		cocos2d::Sprite* mSptPaoTaiEffect;
		//玩家分数
		cocos2d::Label* mLbJiFen;
		//大炮级别
		cocos2d::Label* mLbBow;
		cocos2d::Label* mLbName;
		cocos2d::Label* mLbTrad;

		///< 财神动画
		cocos2d::Sprite* mMoneyGoldAnimation;
		///< 龙王图片
		std::vector<cocos2d::Sprite *> mSmallDargonKing;
		cocos2d::Sprite* mSptCannonType;
		cocos2d::Sprite* mSptLuckyAni;
		///< 锁定的图标
		cocos2d::Sprite* mLockIcon;
		///< 锁定线的容器,初步定义为15个
		std::vector<cocos2d::Sprite *> mLockLine;
		///< 上面的容器的存储地方
		cocos2d::Sprite * mLockLineLayout;
		///< 炮台上面显示的锁定的图标
		cocos2d::Sprite * mLockIconStatic;

		//cocos2d::Sprite* mSptCannonAdd;
		//cocos2d::Sprite* mSptCannonSub;

		cocos2d::Sprite* mSptWarningFire;
		cocos2d::LabelAtlas* mLbWarningFire;

		cocos2d::SpriteBatchNode* batch_node_;

		cocos2d::ui::Button * mAddLevel;
		cocos2d::ui::Button * mSubLevel;

		CoinsNodeX*			mCoinsShow;

	protected:
		//< 锁定的鱼
		BirdNode * _mLockBird;
		///< 锁定鱼的动画
		BirdNode * mLockBirdAnimate;
		///< 锁定鱼的特效
		cocos2d::Sprite * mLockBirdEffect;
	public:
		///< 下面是陈淼写的方法
		//< 取消鱼的锁定
		void cancelBirdLock(cocos2d::Ref * obj);
		//< 获取被锁定的鱼
		cocos2d::Vec2 getLockBirdPos()const;
		///< 是否锁定鱼
		bool isLockBird();
		///< 获取我的炮台方向
		float getMyRoloRoration();
		///< 获取炮台的世界位置
		cocos2d::Vec2 getMyRoloWorldPostion();
		///< 获取鱼目标点的下个位置
		xPoint getFishNextPosition(float elapsed);
		///< 获取锁定的鱼
		BirdNode * getLockBird() { return _mLockBird; }
		///< 锁定的鱼
		void setLockBird(BirdNode * lockBird);
		///< 开启锁定旋转
		void openCircularLockIcon();
		///< 关闭锁定旋转
		void closeCircularLockIcon();
		///< 获取锁定鱼的动画并且执行
		void getLockBirdAnimationAndRun();

	};
}
#endif // _RoleNode_H_