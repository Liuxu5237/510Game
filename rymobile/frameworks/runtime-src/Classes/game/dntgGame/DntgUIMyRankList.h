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
		//��ʾ��Ϣ
		bool onShowInfo(word i, tagMatchSubRankList sRankData);

		//�򿪶�ʱ��
		bool openShowTimeSchedule();

	private:
		//void onCloseClick(cocos2d::CCObject* obj, cocos2d::extension::CCControlEvent e);

		//��ʱ�ر���Ϸ
		void showTime(float dt);
	private:
		//���а�
		ui::Widget* mTimeRankListLayer;

		int mTimeCount;//��ʱ������

		///<  ʱ�����
		LabelAtlas * lab_timeout;
	};
}
#endif // _UIRankList_H_