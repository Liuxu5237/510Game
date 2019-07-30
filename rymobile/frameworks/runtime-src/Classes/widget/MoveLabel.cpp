#include "MoveLabel.h"
#include "../Script/ScriptData.h"
#include "../Script/UtilityFun.h"

USING_NS_CC;

static int s_iMoveAbleMaxNum = 10;

std::vector<MoveLabel*> MoveLabel::s_pTargets;

MoveLabel::MoveLabel(std::string kFontName,int iFontSzie,cocos2d::Size kSize)
	:m_kSize(kSize)
	,m_fActMoveDis(0)
	,m_iActIndex(0)
	,m_fWaitTime(0)
	,m_bStart(false)
	,m_fShowTime(0)
	,m_pTarget(NULL)
{
	
	m_pRootNode1 = cocos2d::Node::create();
	m_pRootNode1->retain();
	m_pRootNode1->setPosition(ccp(10,0));
	m_pRootNode = cocos2d::Node::create();
	m_pRootNode->setPosition(ccp(m_kSize.width/2,m_kSize.height/2));
	m_pRootNode1->addChild(m_pRootNode);

	m_pLables[0] = CCLabelTTF::create(" ",kFontName.c_str(),iFontSzie,m_kSize,kCCTextAlignmentLeft);
	m_pLables[0]->setPosition(ccp(m_kSize.width/2-m_kSize.width,0));
	m_pLables[1] = CCLabelTTF::create(" ",kFontName.c_str(),iFontSzie,m_kSize,kCCTextAlignmentLeft);
	m_pLables[1]->setPosition(ccp(m_kSize.width/2,0));
	m_pLables[0]->setColor(utility::parseColour("8 122 181"));
	m_pLables[1]->setColor(utility::parseColour("8 122 181"));
	m_pRootNode->addChild(m_pLables[0]);
	m_pRootNode->addChild(m_pLables[1]);

	this->scheduleUpdateWithPriority(1);

	s_pTargets.push_back(this);
}
MoveLabel::~MoveLabel()
{
	if (m_pRootNode)
	{
		m_pRootNode->release();
	}
	std::vector<MoveLabel*>::iterator itor = s_pTargets.begin();
	for (;itor != s_pTargets.end();itor++)
	{
		if (*itor == this)
		{
			s_pTargets.erase(itor);
			break;
		}
		
	}
	
}
void MoveLabel::ClearRenderTarget()
{
	if (m_pTarget)
	{
		m_pTarget->removeFromParent();
		m_pTarget = NULL;
	}
}
void MoveLabel::clearAllRenderTarget()
{
	std::vector<MoveLabel*>::iterator itor = s_pTargets.begin();
	for (;itor != s_pTargets.end();itor++)
	{
		(*itor)->ClearRenderTarget();
	}
}
void MoveLabel::setColour(std::string kColour)
{
	m_pLables[0]->setColor(utility::parseColour(kColour));
	m_pLables[1]->setColor(utility::parseColour(kColour));
}
void MoveLabel::update(float delta)
{
	m_fShowTime -= delta; 
	if (m_fWaitTime >0.0f || m_kShowInfo.size() == 0)
	{
		m_fWaitTime -= delta;
		if (m_fWaitTime < 0.0f)
		{
			m_fWaitTime = 0.0f;
			showNext();
		}
		return;
	}
	if (m_fActMoveDis < 0)
	{
		return;
	}
	ScriptData<int> s_iMoveLableSpd("MoveLableSpd");
	if (m_bStart)
	{
		m_fActMoveDis -= delta*s_iMoveLableSpd.Value();
	}
	else
	{
		m_fActMoveDis -= delta*s_iMoveLableSpd.Value()/8.f;
	}
	cocos2d::Point kPos = m_pRootNode->getPosition();
	if (m_bStart)
	{
		kPos.x = m_fActMoveDis;
	}
	else
	{
		kPos.y = m_fActMoveDis;
	}
	m_pRootNode->setPosition(kPos);
	if (m_fActMoveDis < 0)
	{
		ScriptData<int> s_iMoveLableWaitTime("MoveLableWaitTime");
		m_fWaitTime = s_iMoveLableWaitTime.Value();
		m_fActMoveDis = 0;
		if (m_bStart)
		{
			m_bStart = false;
		}
	}
}
void MoveLabel::addTxt(std::string kTxt)
{
	while ((int)m_kShowInfo.size() >= s_iMoveAbleMaxNum)
	{
		m_kShowInfo.erase(m_kShowInfo.begin());
	}
	
	m_kActShowTxt = kTxt;
	m_iActIndex = m_kShowInfo.size();
	m_kShowInfo.push_back(kTxt);

	m_bStart = true;
	m_fWaitTime = 0.0f;
	m_fShowTime = 13;
	showIdex(m_iActIndex);
}
void MoveLabel::setTxtDirect(std::string kTxt)
{
	m_pLables[0]->setString(kTxt.c_str());
	m_pLables[1]->setString(kTxt.c_str());
}
void MoveLabel::clearTxt()
{
	m_kShowInfo.clear();
}
void MoveLabel::showNext()
{
	if (m_kShowInfo.size() == 0)
	{
		return;
	}
	m_iActIndex++;
	if (m_iActIndex >= (int)m_kShowInfo.size())
	{
		m_iActIndex = 0;
	}
	showIdex(m_iActIndex);
}
void MoveLabel::setShowTxtList(std::vector<std::string> kTxts)
{
	if (m_kShowInfo.size() == 0)
	{
		m_kActShowTxt = kTxts.front();
		m_iActIndex = 0;
	}
	m_kShowInfo = kTxts;
	m_bStart = true;
	m_fWaitTime = 0.0f;
	m_fShowTime = 13;
	showIdex(m_iActIndex);
}
void MoveLabel::showIdex(int iIdex)
{
	CCAssert(iIdex<(int)m_kShowInfo.size(),"");
	m_kActShowTxt = m_kShowInfo[iIdex];
	m_pLables[0]->setString(m_pLables[1]->getString());
	m_pLables[1]->setString(m_kActShowTxt.c_str());
	m_iActIndex = iIdex;
	if (m_bStart)
	{
		m_fActMoveDis = m_kSize.width;
		m_pLables[0]->setPosition(ccp(m_kSize.width/2-m_kSize.width,0));
		m_pLables[1]->setPosition(ccp(m_kSize.width/2,0));
	}
	else
	{
		m_fActMoveDis = m_kSize.height;
		m_pLables[0]->setPosition(ccp(m_kSize.width/2,-m_kSize.height/2));
		m_pLables[1]->setPosition(ccp(m_kSize.width/2,m_kSize.height/2));
	}
	m_pRootNode->setPosition(ccp(m_pRootNode->getPosition().x,m_kSize.height/2));
	update(0.018f);
}

void MoveLabel::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{
	if (!m_pTarget)
	{
		m_pTarget = RenderTexture::create(m_kSize.width,m_kSize.height, kCCTexture2DPixelFormat_RGBA8888);
		addChild(m_pTarget);
	}
	
	if(m_pTarget && m_pRootNode)
	{
		m_pTarget->clear(0,0,0,0);
		m_pTarget->begin();
		m_pRootNode1->visit();
		m_pTarget->end();
	}
}

void MoveLabel::showLastTxt()
{
	int nIndex = (int)m_kShowInfo.size();
	showIdex(nIndex-2);
}
void MoveLabel::setMaxNum(int iNum)
{
	s_iMoveAbleMaxNum = iNum;
}
