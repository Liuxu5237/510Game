#ifndef _Dntg_BirdNode_H_
#define _Dntg_BirdNode_H_

#include "cocos2d.h"
namespace  Dntg
{
	class Bird;
	class BirdNode
		: public cocos2d::Sprite
	{
	public:
		static BirdNode* create(int type);
	public:
		BirdNode();
		virtual ~BirdNode();
		bool init(int type);
		virtual void born(bool isShadow);
		bool	m_bClickFish;
		cocos2d::Color3B	m_CurColor;
		//击中我了 然后哥哥我一会要变红了
		virtual void SetBitStatus();
		///< 死亡特效
		virtual void death();
		virtual const cocos2d::Size getSize() const;
		virtual void autoScale();



		void setRed();
		int getType() const;
		void setLock(bool isLock, int chair_id);
		bool getLock(int chair_id) const;
		///< 是否出界
		bool isOutWindow();
		///< 自动回调
		void autoCallBack();
		///, 暂停状态
		void pauseBird(bool p_t);
		Bird* bird;
		cocos2d::Action * birdMove;

		virtual void update(float delta);
		///< 暂停状态
		bool pause_time;

		/*	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) override;*/
	protected:
		int mType;

		///< 是否锁定
		bool mLock[6];
		///<  鱼大小
		cocos2d::Size _BirdSize;

	};

	class SpecialBirdNode : public BirdNode
	{
	public:

		virtual void SetBitStatus();
		//嗯哼 就是要你自己膨胀吧
		void    SetPanZiScale();

		SpecialBirdNode();
		virtual ~SpecialBirdNode();
		static SpecialBirdNode* create(int type);
		virtual void born(bool isShadow);
		///< 死亡特效
		virtual void death();
		virtual bool init(int type);
		//virtual const Size & getSize() const;
		void setBirdNum(int num) { mBirdNum = num; }
		int getBirdNum() { return mBirdNum; }
		///< 设置特效
		void setEffect(cocos2d::Sprite * father, cocos2d::Animate * animate);
	protected:
		std::vector<cocos2d::Sprite *> mBirdList;
		///< 创建鱼的数量,默认为1
		int mBirdNum;

	private:
		///< 获得鱼的位置,  参数是鱼的排名
		cocos2d::Vec2 getBirdPostion(int bird_rank);
	};
}
#endif // _BirdNode_H_