#ifndef _Dntg_Bullet_H_
#define _Dntg_Bullet_H_
#pragma once
#include "platform/df/types.h"
namespace  Dntg
{
	class Bullet
	{
	public:
		uint32	id_;
		float	rotation_;
		uint16	chair_id_;
		uint16	cannon_type_;
		uint32	move_action_id_;
		float	speed_;
		void*   node_;
		void*   shadow_;
		uint16  bullet_type_;
		uint16  net_type_;
		uint32 lock_bird_id_;
		Bullet()
		{
			node_ = NULL;
			shadow_ = NULL;
		}
	};

	///////////////////////////////////////////////////////////////////////////////////////////
	typedef std::list<Bullet*> BulletManager;
	typedef BulletManager::iterator		BulletManagerIter;
}
#endif // _Bullet_H_