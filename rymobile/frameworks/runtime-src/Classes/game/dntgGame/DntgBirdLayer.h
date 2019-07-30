#ifndef _Dntg_BirdLayer_H_
#define _Dntg_BirdLayer_H_

#include "cocos2d.h"

namespace  Dntg
{
	class Bird;
	class BirdNode;
	class Action_Bird_Move;
	class Action_Base_Bird_Move;

	class BirdLayer
		: public cocos2d::Layer
	{
	public:
		//CREATE_FUNC(BirdLayer);
		static BirdLayer * create();
	public:
		BirdLayer();
		virtual ~BirdLayer();
		bool init();

		void send_bird(Bird* bird);

		//场景鱼阵
		void send_scene_bird(Bird* bird, Action_Bird_Move* action);

		void bird_dead(Bird* bird, bool isCleanup = false);

		void set_ding_bird(bool ding);
		///< 显示闪电线的链接
		void showLightLineConnection(cocos2d::Vec2 start_p, std::vector<cocos2d::Vec2> other_p, int bird_type);
		///< 创建鱼游动的动作
		void create_bird_move_action(BirdNode * node, Bird * bird, Action_Base_Bird_Move * action = nullptr);
	private:
		void func_bird_hide(cocos2d::Node* node, void* data);
		void func_bird_end(cocos2d::Node* node, void* data);
		void func_bird_effect_end(cocos2d::Node* node, void* data);
		void func_bird_dead_end(cocos2d::Node* node, void* data);
		///< 闪电链消失
		void func_light_line_end(cocos2d::Node* node, void* data);
	private:
		bool dinged_;
		///< 现在精灵节点就能保证在一张父亲图上面只渲染一次了
		cocos2d::SpriteBatchNode* batch_node1_;
		cocos2d::SpriteBatchNode* batch_node2_;
	};
}
#endif // _BirdLayer_H_