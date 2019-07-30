#ifndef _Dntg_BirdFactory_H_
#define _Dntg_BirdFactory_H_

#include "cocos2d.h"


namespace  Dntg
{
	class Bird;
	class BirdNode;
	class BulletNode;
	class Bullet;

	class ObjectPool
	{
	private:
		static ObjectPool* msInstance;
	public:
		static ObjectPool* shared();
		static void purge();

	public:
		Bird*		createBird();
		void		destoryBird(Bird* bird);

		BirdNode*	createBirdNode(int type, bool isSpecail = false);
		void		destroyBirdNode(BirdNode* node);

		Bullet*		createBullet();
		void		destoryBullet(Bullet* bullet);
		BulletNode*	createBulletNode(int chair_id, int type, bool isSpecail = false);
		void		destoryBulletNode(BulletNode* node);
		bool		bulletCountAdd();
		bool		bulletCountSub();
		int			getBulletCount();
		bool		clearBulletCount();
		void		pauseBulletSend();
		void		resumeBulletSend();
	private:
		ObjectPool();
		~ObjectPool();
	private:
		std::list<Bird*>		mBirds;
		std::list<Bird*>		mBirdUsing;
		cocos2d::CCDictionary*	mBirdNodes;
		cocos2d::CCArray*		mBirdNodeUsing;

		std::list<Bullet*>		mBullets;
		std::list<Bullet*>		mBulletUsing;
		cocos2d::CCDictionary*	mBulletNodes;
		cocos2d::CCArray*		mBulletNodeUsing;
		int						mBulletCount;

	}; // ObjectPool
}
#endif // _BirdFactory_H_