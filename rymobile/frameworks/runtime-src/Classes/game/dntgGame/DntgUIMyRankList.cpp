#include "DntgUIMyRankList.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "tools/tools/Convert.h"
//////////////////////////////////////////////////////////////////////////
using namespace Dntg;

#define CLOSE_TIME_NUMBER 99 //�������ر���Ϸ

template<class T>

void to_string(std::string & result, const T& t)

{

	std::ostringstream oss;//����һ����

	oss << t;//��ֵ����������

	result = oss.str();//��ȡת������ַ�ת������д��result
}

//////////////////////////////////////////////////////////////////////////
UIMyRankList::UIMyRankList()
{
	mTimeRankListLayer = nullptr;
}

UIMyRankList::~UIMyRankList()
{

}

//��ʼ������
bool UIMyRankList::init()
{
	do 
	{
		CC_BREAK_IF(!CCLayer::init());
		//CC_BREAK_IF(!BaseLayer::initWithJsonFile("cocos_ui/NewUI/ranklistLayer.json"));

		//���а�
		ui::Widget *widget_ = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocos_ui/NewUI/ranklistLayer.json");
		if (!widget_){
			//MessageBoxA(NULL, "g", "b", 0);
			assert(false);
			return false;
		}
		mTimeRankListLayer = widget_;

		ui::Widget* wenzi = dynamic_cast<ui::Widget *>(mTimeRankListLayer->getChildByName("wenzi"));
		if (NULL == wenzi)
		{
			assert(false);
			return false;
		}

		/*lab_timeout = ui::LabelAtlas::create();
		lab_timeout->setProperty("20", "fonts/img_exit_window_continue_num.png", 33, 46, "0");
		lab_timeout->setPosition(CCPoint(700, 150));
		mTimeRankListLayer->addChild(lab_timeout);*/
		lab_timeout = dynamic_cast<LabelAtlas *>(wenzi->getChildByName("timeout"));
		if (NULL == lab_timeout)
		{
			assert(false);
			return false;
		}

		addChild(widget_);

		return true;
	} while (0);

	return false;
}

bool UIMyRankList::onShowInfo(word i, tagMatchSubRankList sRankData)
{
	assert(i <= MAX_MATCH_SHOW_NUMBER);
	if (i >= MAX_MATCH_SHOW_NUMBER)
	{
		//MessageBoxA(NULL, "h", "b", 0);
		assert(false);
		return false;
	}
	
	std::stringstream ss;
	std::string str = "";
	ui::Widget* wenzi = dynamic_cast<ui::Widget *>(mTimeRankListLayer->getChildByName("wenzi"));
	if (NULL == wenzi)
	{
		assert(false);
		return false;
	}

	//ss.clear();
	//ss << (i + 1);//���а��1��ʼ
	std::string tmpStr;
	to_string(tmpStr, (i + 1));
	str = std::string("rank") + tmpStr;
	ui::Widget* rank = dynamic_cast<ui::Widget *>(wenzi->getChildByName(str.c_str()));
	if (NULL == rank)
	{
		assert(false);
		return false;
	}
	//����
	//ss.clear();
	//ss << (i+1);//���ִ�1��ʼ
	//to_string(str, (i + 1));
	//Label* paiming = dynamic_cast<Label *>(rank->getChildByName("paiming"));
	//paiming->setText(str);

	//����
	str = std::string(u2_8(&sRankData.szUserName[0]));
	//ss.clear();
	//ss << sRankData.lGold;
	Label* nickname = dynamic_cast<Label *>(rank->getChildByName("nickname"));
	nickname->setString(str);

	//��Ϸid
	//ss.clear();
	//ss << sRankData.dwIngot;
	to_string(str, sRankData.dwGameID);
	LabelAtlas* gameid = dynamic_cast<LabelAtlas *>(rank->getChildByName("userid"));
	gameid->setString(str);

	//���б�
	//ss.clear();
	//ss << sRankData.lGold;
	//to_string(str, sRankData.lGold);
	//LabelAtlas* dushibi = dynamic_cast<LabelAtlas *>(rank->getChildByName("dushibi"));
	//dushibi->setStringValue(str);

	//����
	//ss.clear();
	//ss << sRankData.lGrade;
	to_string(str, sRankData.lGrade);
	LabelAtlas* fenshu = dynamic_cast<LabelAtlas *>(rank->getChildByName("fenshu"));
	fenshu->setString(str);
	
	rank->setVisible(true);

	return true;
}

bool UIMyRankList::openShowTimeSchedule()
{
	schedule(schedule_selector(UIMyRankList::showTime), 1.0f);
	mTimeCount = CLOSE_TIME_NUMBER;

	return true;
}

void UIMyRankList::showTime(float dt)
{
	--mTimeCount;
	if (mTimeCount <= 0)
	{
		CCDirector::sharedDirector()->end();//�ر���Ϸ
	}
	else
	{
		std::stringstream ss;
		ss << mTimeCount;
		lab_timeout->setString(ss.str());
	}
}