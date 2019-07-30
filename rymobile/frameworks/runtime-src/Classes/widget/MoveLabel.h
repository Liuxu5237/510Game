#pragma once
#include "cocos2d.h"

class MoveLabel:
	public cocos2d::Node
{
public:
	MoveLabel(std::string kFontName,int iFontSzie,cocos2d::Size kSize);
	~MoveLabel();
public:
	virtual void update(float delta);
	virtual void draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags);

	void ClearRenderTarget();

	static void clearAllRenderTarget();
public:
	void setShowTxtList(std::vector<std::string> kTxts);
	void showIdex(int iIdex);
	void showNext();
	void addTxt(std::string kTxt);
	void clearTxt();
	void setTxtDirect(std::string kTxt);
	void showLastTxt();
	void setColour(std::string kColour);
	static void setMaxNum(int iNum);
private:
	std::string		m_kActShowTxt;
	int				m_iActIndex;
	float			m_fActMoveDis;
	float			m_fWaitTime;
	float			m_fShowTime;
	cocos2d::Size m_kSize;

	cocos2d::CCLabelTTF* m_pLables[2];
	std::vector<std::string> m_kShowInfo;
	cocos2d::Node* m_pRootNode1;
	cocos2d::Node* m_pRootNode;
	cocos2d::RenderTexture* m_pTarget;
	bool m_bStart;
	static std::vector<MoveLabel*> s_pTargets;
};
