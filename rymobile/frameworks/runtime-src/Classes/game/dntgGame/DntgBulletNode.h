#ifndef _Dntg_BulletNode_H_
#define _Dntg_BulletNode_H_

#include "cocos2d.h"
#include "ui/UIScale9Sprite.h"

USING_NS_CC;
namespace  Dntg
{
	class BulletNode
		: public cocos2d::Sprite
	{
	public:

		static BulletNode* create(int chair_id, int bullet_type, int bird_id = -1);
	public:
		BulletNode();
		virtual ~BulletNode();
		bool init(int chair_id, int bullet_type, int bird_id);
		void  setNetType(int net) { mNetType = net; }
		int  getNetType() const { return mNetType; }
		int  getBulletType() const  { return mBulletType; }
		int  getChairID() const { return mChairId; }
		void born(bool isShadow);
		void setBirdId(int bird_id) { mBirdId = bird_id; }
		int getBirdId() { return mBirdId; }

	protected:
		int mBulletType;
		int mChairId;
		int mNetType;
		int mBirdId;

	};

	///< ÄÜÁ¿ÅÚ
	class EnergyBulletNode : public BulletNode
	{
	public:
		static EnergyBulletNode * create(int chair_id, int bullet_type, int bird_id = -1);

		bool init(int chair_id, int bullet_type, int bird_id);

		void setRotation(float rotation);
	protected:
		ui::Scale9Sprite * laser;

	};
}
#endif // _BulletNode_H_