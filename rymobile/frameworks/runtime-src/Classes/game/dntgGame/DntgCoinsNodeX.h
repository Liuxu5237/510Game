#ifndef _Dntg_CoinsNodeX_H_
#define _Dntg_CoinsNodeX_H_

#include "cocos2d.h"
#include "DntgCoinsNode.h"
#include "Tools/Dialog/Timer.h"

namespace  Dntg
{


	class CoinsNodeX : public cocos2d::Node
	{
	public:
		CREATE_FUNC(CoinsNodeX);

	private:
		CoinsNodeX();
		~CoinsNodeX();
		bool init();
	public:
		void show_coin_animtion(int count, int score, int chair_id_);

	protected:
		void pop_front();
		void func_show_pos_animtion_end(cocos2d::Node* node, void* data);
		int get_coin_offset(int pos);

	private:
		typedef std::list<CoinsNode*> NodeList;
		typedef NodeList::iterator	  NodeListIter;

		NodeList coins_;
		NodeList using_;
		
	};
}
#endif // _CoinsNodeX_H_