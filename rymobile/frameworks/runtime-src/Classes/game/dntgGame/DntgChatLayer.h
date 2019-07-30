#ifndef _Dntg_ChatLayer_H_
#define _Dntg_ChatLayer_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "kernel/IChatSink.h"
#include "kernel/IStringMessageSink.h"
USING_NS_CC;
namespace  Dntg
{
	class ChatLayer
		: public cocos2d::Layer
		, public IChatSink
		, public IStringMessageSink
	{
	public:
		//CREATE_FUNC(ChatLayer);
		static ChatLayer * create();
	public:
		ChatLayer();
		~ChatLayer();
		bool init();

		//////////////////////////////////////////////////////////////////////////
		// IChatSink
		//表情消息
	public:
		//用户表情
		virtual bool InsertExpression(const char* pszSendUser, unsigned int index);
		//用户表情
		virtual bool InsertExpression(const char* pszSendUser, unsigned int index, bool bMyselfString);
		//用户表情
		virtual bool InsertExpression(const char* pszSendUser, const char* pszRecvUser, unsigned int index);

		//聊天消息
	public:
		//用户聊天
		virtual bool InsertUserChat(const char* pszSendUser, const char* pszString, unsigned int crColor);
		//用户聊天
		virtual bool InsertUserChat(const char* pszSendUser, const char* pszRecvUser, const char* pszString, unsigned int crColor);
		//用户私聊
		virtual bool InsertWhisperChat(const char* pszSendUser, const char* pszString, unsigned int crColor, bool bMyselfString);
		//用户喇叭
		virtual bool InsertUserTrumpet(const char* pszSendUser, const char* pszString, unsigned int crColor);
		//用户喇叭
		virtual bool InsertUserTyphon(const char* pszSendUser, const char* pszString, unsigned int crColor);

		//系统消息
	public:
		//系统消息
		virtual bool InsertSystemChat(const char* pszString);

		//////////////////////////////////////////////////////////////////////////
		// IStringMessageSink
		//事件消息
	public:
		//进入事件
		virtual bool InsertUserEnter(const char* pszUserName);

		//离开事件
		virtual bool InsertUserLeave(const char* pszUserName);
		//断线事件
		virtual bool InsertUserOffLine(const char* pszUserName);
		//字符消息
	public:
		//普通消息(窗口输出)
		virtual bool InsertNormalString(const char* pszString);
		//系统消息(窗口输出)
		virtual bool InsertSystemString(const char* pszString);
		//提示消息(对话框方式??)
		virtual int InsertPromptString(const char* pszString, int iButtonType);
		//公告消息(窗口输出)
		virtual bool InsertAfficheString(const char* pszString);

		//定制消息
	public:
		//喜报消息
		virtual bool InsertGladString(const char* pszContent, const char* pszNickName, const char* pszNum, dword colText, dword colName, dword colNum);

		virtual void MessageUpdate(float delta);
	private:
		void moveEndCall();
	private:
		ui::Layout * mBgLayout;
		Label * mLabMessage;
		bool isMove;
		///< 消息队列
		std::queue<std::string> mMessageQueue;
	};
}
#endif // _ChatLayer_H_