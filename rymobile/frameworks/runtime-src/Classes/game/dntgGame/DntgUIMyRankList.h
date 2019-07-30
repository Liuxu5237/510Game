#ifndef _UIRankList_H_
#define _UIRankList_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "platform/df/types.h"
#include "platform/df/Struct.h"
#include "cocos-ext.h"


USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

using namespace cocos2d::ui;
namespace  Dntg
{
	class UIMyRankList : public cocos2d::CCLayer
	{
	public:
		CREATE_FUNC(UIMyRankList);

	public:
		UIMyRankList();
		~UIMyRankList();
		bool init();
	public:
		//virtual void onExit();
		//显示信息
		bool onShowInfo(word i, tagMatchSubRankList sRankData);

		//打开定时器
		bool openShowTimeSchedule();

	private:
		//void onCloseClick(cocos2d::CCObject* obj, cocos2d::extension::CCControlEvent e);

		//定时关闭游戏
		void showTime(float dt);
	private:
		//排行榜
		ui::Widget* mTimeRankListLayer;

		int mTimeCount;//定时计数器

		///<  时间计数
		LabelAtlas * lab_timeout;
	};
}
#endif // _UIRankList_H_