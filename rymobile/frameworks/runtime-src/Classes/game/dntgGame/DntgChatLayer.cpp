#include "platform/PlatformHeader.h"
#include "DntgChatLayer.h"
#include "tools/tools/MTNotification.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
ChatLayer::ChatLayer() : isMove(false)
{
}

ChatLayer::~ChatLayer()
{
	this->unschedule(SEL_SCHEDULE(&ChatLayer::MessageUpdate));
}

//初始化方法
bool ChatLayer::init()
{
	do
	{
		CC_BREAK_IF(!CCLayer::init());

		//mBgLayout = ui::Layout::create();
		//mBgLayout->setAnchorPoint(Vec2(0.5f, 0.5f));
		//mBgLayout->setContentSize(Size(905, 100));
		//mBgLayout->setSize(Size(905, 100));
		//mBgLayout->setBackGroundColorType(ui::Layout::BackGroundColorType::SOLID);
		//mBgLayout->setBackGroundColor(Color3B(0x30, 0x30, 0x30));
		//mBgLayout->setBackGroundColorOpacity(150);
		////		mBgLayout->setBackGroundImageColor(Color3B(0xFF, 0x30, 0x30));
		//Size winSize = Director::getInstance()->getWinSize();
		//mBgLayout->setPosition(Vec2(winSize.width / 2 + mBgLayout->getContentSize().width/2, winSize.height - 50));
		//mBgLayout->setClippingEnabled(true);
		//mBgLayout->setClippingType(ui::Layout::ClippingType::SCISSOR);
		//this->addChild(mBgLayout);


		mLabMessage = Label::create();
		mLabMessage->setSystemFontSize(34);
		mLabMessage->setTextColor(Color4B::YELLOW);
		mLabMessage->setAnchorPoint(Vec2(0.0f, 0.0f));

		mBgLayout->addChild(mLabMessage);


		this->schedule(SEL_SCHEDULE(&ChatLayer::MessageUpdate), 3);
		return true;
	} while (0);

	return false;
}

//////////////////////////////////////////////////////////////////////////
// IChatSink

//////////////////////////////////////////////////////////////////////////
//表情消息

//用户表情
bool ChatLayer::InsertExpression(const char* pszSendUser, unsigned int index)
{
	//PLAZZ_PRINTF(t8("%s 发送表情:%d\n"), pszSendUser, index);

	////变量定义
	//CExpressionManager * pExpressionManager=CExpressionManager::GetInstance();
	//CExpression * pExpressionItem=pExpressionManager->GetExpressionItem(pUserExpression->wItemIndex);

	////插入表情
	//if (pExpressionItem!=0)
	//{
	//	//获取路径
	//	char szImagePath[MAX_PATH]=TEXT("");
	//	pExpressionItem->GetExpressionPath(szImagePath,CountArray(szImagePath));

	//	//插入消息
	//	const char* pszSendUser=pISendUserItem->GetNickName();
	//	m_ChatMessage.InsertExpression(pszSendUser,szImagePath);
	//}
	return true;
}

//用户表情
bool ChatLayer::InsertExpression(const char* pszSendUser, unsigned int index, bool bMyselfString)
{
	//PLAZZ_PRINTF(t8("%s 发送表情:%d\n"), pszSendUser, index);
	return true;
}

//用户表情
bool ChatLayer::InsertExpression(const char* pszSendUser, const char* pszRecvUser, unsigned int index)
{
	//PLAZZ_PRINTF(t8("%s 对 %s 发送表情:%d\n"), pszSendUser, pszRecvUser, index);
	return true;
}

//////////////////////////////////////////////////////////////////////////
//聊天消息

//用户聊天
bool ChatLayer::InsertUserChat(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 说:%s\n"), pszSendUser, pszString);
	return true;
}
//用户聊天
bool ChatLayer::InsertUserChat(const char* pszSendUser, const char* pszRecvUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 对 %s 说:%s\n"), pszSendUser, pszRecvUser, pszString);
	return true;
}
//用户私聊
bool ChatLayer::InsertWhisperChat(const char* pszSendUser, const char* pszString, unsigned int crColor, bool bMyselfString)
{
	//PLAZZ_PRINTF(t8("%s 对你说:%s\n"), pszSendUser, pszString);
	return true;
}
//用户喇叭
bool ChatLayer::InsertUserTrumpet(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 发送Trumpet喇叭:%s\n"), pszSendUser, pszString);
	return true;
}
//用户喇叭
bool ChatLayer::InsertUserTyphon(const char* pszSendUser, const char* pszString, unsigned int crColor)
{
	//PLAZZ_PRINTF(t8("%s 发送Typhon喇叭:%s\n"), pszSendUser, pszString);
	return true;
}

//////////////////////////////////////////////////////////////////////////
//系统消息

//系统消息
bool ChatLayer::InsertSystemChat(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertSystemChat");
	//PLAZZ_PRINTF(t8("系统消息:%s \n"), pszString);
	return true;
}

//////////////////////////////////////////////////////////////////////////
// IStringMessageSink

//////////////////////////////////////////////////////////////////////////
//事件消息

//进入事件
bool ChatLayer::InsertUserEnter(const char* pszUserName)
{
	PLAZZ_PRINTF("ChatLayer::InsertUserEnter");
	//PLAZZ_PRINTF(t8("%s 进入房间\n"), pszUserName);
	return true;
}

//离开事件
bool ChatLayer::InsertUserLeave(const char* pszUserName)
{
	PLAZZ_PRINTF("ChatLayer::InsertUserLeave");
	//PLAZZ_PRINTF(t8("%s 离开房间\n"), pszUserName);
	return true;
}

//断线事件
bool ChatLayer::InsertUserOffLine(const char* pszUserName)
{
	PLAZZ_PRINTF("ChatLayer::InsertUserOffLine");
	//PLAZZ_PRINTF(t8("%s 断线\n"), pszUserName);
	return true;
}

//////////////////////////////////////////////////////////////////////////
//字符消息

//普通消息(窗口输出)
bool ChatLayer::InsertNormalString(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertNormalString");
	//PLAZZ_PRINTF(t8("普通消息:%s\n"), pszString);
	return true;
}
//系统消息(窗口输出)
bool ChatLayer::InsertSystemString(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertSystemString");
	log("message is %s ", pszString);

	mMessageQueue.push(pszString);
	//PLAZZ_PRINTF(t8("系统消息:%s\n"), pszString);
	//	G_NOTIFY_D("GLAD_MSG", MTData::create(0, 0, 0, pszString, "", ""));
	return true;
}
//提示消息(对话框方式??)
int ChatLayer::InsertPromptString(const char* pszString, int iButtonType)
{
	PLAZZ_PRINTF("ChatLayer::InsertPromptString");
	//PLAZZ_PRINTF(t8("提示消息:%s[%s]\n"), pszString, iButtonType == 0 ? t8("确认"):t8("确认,取消"));
	return 0;
}
//公告消息(窗口输出)
bool ChatLayer::InsertAfficheString(const char* pszString)
{
	PLAZZ_PRINTF("ChatLayer::InsertAfficheString");
	//PLAZZ_PRINTF(t8("公告消息:%s\n"), pszString);
	return true;
}


//喜报消息
bool ChatLayer::InsertGladString(const char* pszContent, const char* pszNickName, const char* pszNum, dword colText, dword colName, dword colNum)
{
	G_NOTIFY_D("GLAD_MSG", MTData::create(colText, colName, colNum, pszContent, pszNickName, pszNum));
	return true;
}

void ChatLayer::moveEndCall()
{
	log("come in!!");
	isMove = false;
	if (mMessageQueue.size() < 1)
		mBgLayout->setVisible(false);
}

void ChatLayer::MessageUpdate(float delta)
{
	///< 更新消息
	if (isMove) return;
	if (mMessageQueue.size() < 1) return;
	mBgLayout->setVisible(true);
	std::string text = mMessageQueue.front();
	mMessageQueue.pop();
	mLabMessage->setString(text);

	isMove = true;
	Size label_pos = mBgLayout->getSize();
	mLabMessage->setPosition(Vec2(label_pos.width, 5));
	float move_distance = text.size() * 21;// +label_pos.width;
	if (move_distance < label_pos.width * 1.5f)
		move_distance += label_pos.width;

	float time = move_distance / 100 < 25 ? 25 : move_distance / 100;
	auto move = MoveBy::create(move_distance / 100, Vec2(-move_distance, 0));
	auto sequence = Sequence::create(move, CallFunc::create(this, callfunc_selector(ChatLayer::moveEndCall)), NULL);
	mLabMessage->runAction(sequence);

}

ChatLayer * ChatLayer::create()
{
	ChatLayer * layer = new ChatLayer;
	if (layer && layer->init())
	{
		layer->autorelease();
		return layer;
	}
	delete layer;
	layer = nullptr;
	return nullptr;
}
