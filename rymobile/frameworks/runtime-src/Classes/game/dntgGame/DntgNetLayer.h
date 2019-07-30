#ifndef _Dntg_NetLayer_H_
#define _Dntg_NetLayer_H_

#include "cocos2d.h"
namespace  Dntg
{
	class NetLayer
		: public cocos2d::Layer
	{
	public:
		CREATE_FUNC(NetLayer);

	public:
		NetLayer();
		~NetLayer();
		bool init();

		void net_open(int char_id, int net, const cocos2d::Vec2& pt);
	private:
		void func_net_end(cocos2d::Node* node, void* data);

	private:
		cocos2d::SpriteBatchNode* batch_node1_;
		cocos2d::SpriteBatchNode* batch_node2_;
	};
}
#endif // _BirdLayer_H_