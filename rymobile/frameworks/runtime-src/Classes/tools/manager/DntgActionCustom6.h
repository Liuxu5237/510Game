#ifndef __Dntg_ACTION_CUSTOM_H__
#define __Dntg_ACTION_CUSTOM_H__

/////////////////////////////////////////////////////////////////////////////////////////////////
#include "Move_Point_Manager.h"
#include "cocos2d.h"
USING_NS_CC;
/////////////////////////////////////////////////////////////////////////////////////////////////
///< 鱼移动的点的基类
namespace  Dntg
{

	///////////////////////////////////////////////////////////////////////////////////////////
	///< 子弹的直线移动
	class Action_Bullet_Move6 : public cocos2d::ActionInterval
	{
	public:
		static Action_Bullet_Move6 * create(float angle, float speed);

		virtual void step(float dt);
		virtual bool isDone() { return false; }
		virtual void startWithTarget(Node *target) override;
	protected:
		Action_Bullet_Move6(){}
		bool init(float angle, float speed);
	protected:
		float angle_;
		float bullet_speed_;

		float dx_;
		float dy_;
	};

	///< 子弹的锁定移动..
	class Action_Bullet_Move_To6 : public Action_Bullet_Move6
	{
	public:
		static Action_Bullet_Move_To6 * create(const xPoint & start, const xPoint & end, float angle, float speed);

		//virtual void update(float time);
		virtual void step(float dt);

	private:
		Action_Bullet_Move_To6(){};
		bool init(const xPoint & start, const xPoint & end, float angle, float speed);
	private:
		float angle_;
		float bullet_speed_;
		xPoint start_;
		xPoint delta_;
		///<  鱼持续的时间,如果过了之后.就要使用新的子弹移动.
		float _Bduration;
		///<  总长度
		float _length;

	};

	//////////////////////////////////////////////////////////////////////////
	///< 鱼移动的基类
	class Action_Base_Bird_Move6 : public cocos2d::CCActionInterval
	{
	public:
		Action_Base_Bird_Move6(){}
	public:
		virtual xPoint BirdMoveTo(float elapsed) { return xPoint(); }

	};

	/////////////////////////////////////////////////////////////////////////////////////////////////
	///< 鱼的找点移动!!!
	class Action_Move_Point6 : public Action_Base_Bird_Move6
	{
	public:
		static Action_Move_Point6* create(float d, std::string points, std::string offse);

	public:
        
		virtual void update(float time);
		virtual xPoint BirdMoveTo(float elapsed);
	private:
		Action_Move_Point6() { /*_bird_move = 0;*/ }
		bool init(float d, std::string points, std::string offse);

	private:
		Move_Points move_points_;
		//float _bird_move;
	};


	//////////////////////////////////////////////////////////////////////////
	///< 鱼的特殊移动的基类
	class Action_Bird_Move6 : public Action_Base_Bird_Move6
	{
	public:
		Action_Bird_Move6() :m_ptLast(0, 0), m_ptCurrent(0, 0) {}

	protected:
		void move_angle();

	protected:
		xPoint m_ptLast;
		xPoint m_ptCurrent;
	public:
		virtual xPoint BirdMoveTo(float elapsed) { return xPoint(); }
	};

	//////////////////////////////////////////////////////////////////////////
	///< 鱼的圆圈移动
	class Action_Bird_Round_Move6 : public Action_Bird_Move6
	{
	public:
        static Action_Bird_Round_Move6* create(std::string center, float radius, float rotate_duration, float start_angle, float rotate_angle, float move_duration, float bird_speed, bool is_centre_bird = false);

		Action_Bird_Round_Move6() {};
	private:
		bool init(std::string center, float radius, float rotate_duration, float start_angle, float rotate_angle, float move_duration, float bird_speed, bool is_centre_bird);

	public:
		virtual void update(float time) override;

		virtual xPoint BirdMoveTo(float elapsed);

	private:
		xPoint center_;
		float radius_;
		float rotate_duration_;
		float start_angle_;
		float rotate_angle_;
		float move_duration_;
		xPoint delta_;
		float bird_speed_;
		int stage_;
		float angle_;
		bool is_centre_bird_;
	};
	//直线动作
	//------------------------------------------------------------------------
	///< 直线移动,龙王,龟丞相等等的移动...
	class Action_Bird_Move_Linear6 : public Action_Bird_Move6
	{
	public:
		static Action_Bird_Move_Linear6* create(float bird_speed, std::string start, std::string end);

		Action_Bird_Move_Linear6() {};
	private:
		bool init(float bird_speed,
			std::string start, std::string end);

		virtual void update(float time) override;

	public:
		virtual xPoint BirdMoveTo(float elapsed);
	protected:
		xPoint start_;
		xPoint end_;
		xPoint delta_;
		float bird_speed_;
	};

	//////////////////////////////////////////////////////////////////////////
	//场景鱼阵 直线 中间停顿
	class Action_Bird_Move_Pause_Linear6 : public Action_Bird_Move6
	{
	public:
		static Action_Bird_Move_Pause_Linear6* create(float bird_speed, float pause_time, std::string start, std::string pause, std::string end, float start_angle = 0.f);

		Action_Bird_Move_Pause_Linear6() {};

	private:
		bool init(float bird_speed, float pause_time, std::string start, std::string pause, std::string end, float start_angle = 0.f);

		virtual void update(float time) override;

	public:
		virtual xPoint BirdMoveTo(float elapsed) override;

	protected:
		xPoint start_;
		xPoint end_;
		xPoint pause_;				//暂停点
		xPoint front_delta_;
		xPoint back_delta_;
		float bird_speed_;
		float pause_time_;			//暂停时间
		float front_time_;			//暂停之前的动作时间
		float back_time_;			//暂停之后的动作时间
		float start_angle_;			//开始点等于暂停点时使用此角度
	};
	//////////////////////////////////////////////////////////////////////////
	class RemoveAction6 : public cocos2d::ActionInstant
	{
	public:
		//
		// Hide
		//
		static RemoveAction6 * create()
		{
			RemoveAction6 *pRet = new RemoveAction6();

			if (pRet) {
				pRet->autorelease();
			}

			return pRet;
		}

		void update(float time) {
			CC_UNUSED_PARAM(time);
			_target->removeFromParentAndCleanup(true);
		}

		cocos2d::FiniteTimeAction *reverse() {
			return 0;
		}

		// 	cocos2d::Ref* copyWithZone(cocos2d::CCZone *pZone) {
		// 		return 0;
		// 	}
	};

	//////////////////////////////////////////////////////////////////////////

	class Shake6 : public ActionInterval
	{
	public:
		Shake6();

		// Create the action with a time and a strength (same in x and y)  
		// 产生震动效果的初始化函数参数,两个方向相同  
		// @param d 震动持续的时间  
		// @param strength 震动的幅度  
		static Shake6* create(float d, float strength);
		// Create the action with a time and strengths (different in x and y)  
		// 产生震动效果的初始化函数,两个方向值不一样  
		static Shake6* create(float d, float strength_x, float strength_y);
		bool initWithDuration(float d, float strength_x, float strength_y);
		float fgRangeRand(float min, float max);
		//以下都是重写父类抽象类的函数(必须重写)  
		virtual Shake6* clone() const override;
		virtual Shake6* reverse(void) const override;
		virtual void startWithTarget(Node *target) override;
		virtual void update(float time) override;
		virtual void stop(void);

	protected:
		// Initial position of the shaked node  
		// 精灵的位置  
		float _initial_x, _initial_y;
		// Strength of the action  
		// 抖动的幅度  
		float _strength_x, _strength_y;
	};


	//////////////////////////////////////////////////////////////////////////

	class BirdDeathAction6 : public ActionInterval
	{
	public:
		BirdDeathAction6();


		///< 参数一是时间, 参数二是执行的动作数.
		static BirdDeathAction6* create(float d);
		// Create the action with a time and strengths (different in x and y)  

		bool initWithDuration(float d);

		//以下都是重写父类抽象类的函数(必须重写)  
		virtual void startWithTarget(Node *target) override;
		virtual void update(float time) override;

	protected:
		float mOldRotate;
		int mNumber;
		///< 单个角度
		float mSignDregress;
		///, 是否允许了
		bool isRun[8];
	};

}

#endif
