#ifndef _Dntg_RoleLayer_H_
#define _Dntg_RoleLayer_H_

#include "cocos2d.h"
#include "DntgCMD_CatchBird.h"

namespace  Dntg
{
	class RoleNode;

	class RoleLayer
		: public cocos2d::Layer
	{
	public:
		CREATE_FUNC(RoleLayer);

	public:
		RoleLayer();
		~RoleLayer();
		bool init();

		RoleNode* get_role(int chair_id);
		void set_gold(int chair_id, longlong gold);
		void add_gold(int chair_id, longlong gold);
		void set_cannon(int chair_id, int cannon_type);
		void set_level(int chair_id, int level);
		void bullet_send(int chair_id, int cannon_mulriple, float rotation, int trad);
		void set_cannon_mulriple(int chair_id, int cannon_mulriple);
	private:
		bool		mIsTouchEnabled;
		RoleNode*	mRoleNode[GAME_PLAYER];
	};
}
#endif // _RoleLayer_H_