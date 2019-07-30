#ifndef _Dntg_Bird_H_
#define _Dntg_Bird_H_
#pragma once
///////////////////////////////////////////////////////////////////////////////////////////
#include "DntgBirdDefine.h"
#include "DntgBullet.h"
#include "tools/manager/Move_Point_Manager.h"
namespace  Dntg
{
	class Bird
	{
	public:
		Bird()
		{
			reset();
		}

		void reset()
		{
			rotation_ = 0;
			type_ = 0;
			item_ = 0;
			live_ = 1;
			path_id_ = 0;
			path_type_ = 0;
			path_delay_ = 0;
			elapsed_ = 0;
			speed_ = (float)BIRD_MOVE_NORMAL;
			node_ = 0;
			shadow_ = 0;
			effect_ = 0;
			//is_red_ = false;
			link_bird_id_ = -1;
		}

	public:
		uint32	id_;
		float	rotation_;
		xSize	size_;
		xPoint	position_;
		uint8	type_;
		uint8	item_;
		uint8	live_;
		uint16	path_id_;
		uint8	path_type_;
		float	path_delay_;
		xPoint	path_offset_;
		float	elapsed_;
		float	speed_;
		uint32	move_action_id_;
		int	link_bird_id_;

		void* node_;
		void* shadow_;
		void* effect_;
	};

	///////////////////////////////////////////////////////////////////////////////////////////
	typedef std::map<uint32_t, Bird*>	BirdManager;
	typedef BirdManager::iterator		BirdManagerIter;
	///< 鱼死亡计数管理器
	typedef std::map<uint32, uint32>	BirdDealCountManager;
}
#endif // _Bird_H_