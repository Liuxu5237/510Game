#ifndef _Dntg_BulletLayer_H_
#define _Dntg_BulletLayer_H_

#include "cocos2d.h"
#include "tools/manager/Move_Point_Manager.h"
namespace  Dntg
{
	class Bullet;
	class BulletNode;

	class BulletLayer
		: public cocos2d::Layer
	{
	public:
		CREATE_FUNC(BulletLayer);

	public:
		BulletLayer();
		~BulletLayer();
		bool init();

		void send_bullet(Bullet* bullet, const cocos2d::Vec2& pt, int trad);

		float fire(Bullet* bullet, int trad = 0, bool isSpecialBullet = false);
		void fire_failed(int id);
		///< 开火的后端动作处理
		float fire_process(BulletNode * node, BulletNode* shadow, Bullet * bullet, cocos2d::Vec2 pt_bullet, float trad);
		///< 开火的后端动作处理
		float fire_process(BulletNode * node, BulletNode* shadow, Bullet * bullet, float trad);
		///< 激光炮的后端动作处理
		float energy_fire_process(BulletNode * node, BulletNode* shadow, Bullet * bullet, cocos2d::Vec2 pt_bullet, float trad);

		float bulletMoveDuration(const xPoint & start, const xPoint & end, float bullet_speed);

		float bulletMoveAngle(const xPoint & start, const xPoint & end);
	private:
		cocos2d::SpriteBatchNode* batch_node_;
	};
}
#endif // _BulletLayer_H_