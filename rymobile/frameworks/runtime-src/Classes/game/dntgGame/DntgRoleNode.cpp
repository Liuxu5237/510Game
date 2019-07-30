#include "DntgRoleNode.h"
#include "tools/tools/MTNotification.h"
#include "DntgGameScene.h"
#include "DntgSimpleTools.h"
#include "tools/manager/SpriteHelper.h"
#include "tools/manager/SoundManager.h"
#include "DntgActionCustom.h"
#include "kernel/game/IClientKernel.h"
#include "DntgGameHeader.h"
#include "DntgGameConfig.h"


USING_NS_CC;
using namespace Dntg;
//////////////////////////////////////////////////////////////////////////
const int BUFF_Y_OFFSET = 30;
const int BUFF_ITEM_HEIGHT = 32;
//////////////////////////////////////////////////////////////////////////
RoleNode* RoleNode::create(int char_id)
{
	RoleNode* role = new RoleNode();
	if (role && role->init(char_id))
	{
		role->autorelease();
		return role;
	}

	delete role;
	return 0;
}
//////////////////////////////////////////////////////////////////////////
RoleNode::RoleNode()
{
	_mLockBird = nullptr;
	rotation_ = 0.0f;
}

RoleNode::~RoleNode()
{

}

bool RoleNode::init(int char_id)
{
	do
	{
		CC_BREAK_IF(!CCNode::init());

		chair_id_ = char_id;
		gold_ = 0;
		cannon_type_ = 0;
		buy_bird_gold_ = 0;
		buy_jinbi_gold_ = 0;
		fire_mode_ = 0;
		level_ = 0;
		is_buttons_ = false;
		cannon_mulriple_ = 0;
		cannon_speed_ = 0;

		//key_timer_.reset();
		buff_list_.clear();

		Size size = Director::getInstance()->getWinSize();

		CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
		char name[128];

		batch_node_ = CCSpriteBatchNode::createWithTexture(cache->spriteFrameByName("PaoTai.png")->getTexture());
		addChild(batch_node_);

		mCoinsShow = CoinsNodeX::create();
		addChild(mCoinsShow);

		//��̨
		mSptPaoTai = CCSprite::createWithSpriteFrameName("PaoTai.png");
		mSptPaoTai->setScale(1);
		batch_node_->addChild(mSptPaoTai);

		//�Ƿ���
		sprintf(name, "JiFenPai%d.png", chair_id_ + 1);
		mSptJiFenPai = CCSprite::createWithSpriteFrameName(name);
		batch_node_->addChild(mSptJiFenPai);

		//�����ź�
		mSptNetState = CCSprite::createWithSpriteFrameName("NetState_01.png");
		batch_node_->addChild(mSptNetState);

		//����
		mLbJiFen = Label::createWithBMFont("bmfonts/JinbiFont.fnt", "0123456789");
		mLbJiFen->setAnchorPoint(cocos2d::Vec2(0, 1));
		this->addChild(mLbJiFen);

		//��
		mSptBow = CCSprite::createWithSpriteFrameName("Bow1_01.png");
		mSptBow->setScale(1);
		batch_node_->addChild(mSptBow);

		//��
		mSptTrack = CCSprite::createWithSpriteFrameName("board.png");
		mSptBow->addChild(mSptTrack);
		mSptTrack->setVisible(false);

		//��̨����
		mSptPaoTaiOver = CCSprite::createWithSpriteFrameName("seat.png");
		mSptPaoTaiOver->setScale(1);
		batch_node_->addChild(mSptPaoTaiOver);

		//��̨����
		mLbBow = Label::createWithBMFont("bmfonts/BowNumber.fnt", "100");
		this->addChild(mLbBow);

		mLbName = Label::create("", "Arial", 18, CCSizeMake(170, 25));
		mLbName->setAnchorPoint(cocos2d::Vec2(0, 1));
		this->addChild(mLbName);

		//��ͷָʾ��
		mSptMark = CCSprite::createWithSpriteFrameName("Mark_01.png");
		mSptMark->setVisible(false);
		batch_node_->addChild(mSptMark);

		///< ���񶯻�
		mMoneyGoldAnimation = Sprite::createWithSpriteFrameName("Net40_01.png");
		auto animate = SpriteHelper::createAnimate("MoneyGold");
		mMoneyGoldAnimation->runAction(RepeatForever::create(animate));
		mMoneyGoldAnimation->setVisible(false);
		batch_node_->addChild(mMoneyGoldAnimation);


		///< ��������
		Sprite * img_paotai_shlw = Sprite::createWithSpriteFrameName("img_paotai_shlw.png");
		img_paotai_shlw->setTag(100 + BIRD_TYPE_24);
		batch_node_->addChild(img_paotai_shlw);
		mSmallDargonKing.push_back(img_paotai_shlw);
		///< ��������
		Sprite * img_paotai_bhlw = Sprite::createWithSpriteFrameName("img_paotai_bhlw.png");
		img_paotai_bhlw->setTag(100 + BIRD_TYPE_25);
		batch_node_->addChild(img_paotai_bhlw);
		mSmallDargonKing.push_back(img_paotai_bhlw);
		///< �Ϻ�����
		Sprite * img_paotai_nhlw = Sprite::createWithSpriteFrameName("img_paotai_nhlw.png");
		img_paotai_nhlw->setTag(100 + BIRD_TYPE_26);
		batch_node_->addChild(img_paotai_nhlw);
		mSmallDargonKing.push_back(img_paotai_nhlw);
		///< ��������
		Sprite * img_paotai_dhlw = Sprite::createWithSpriteFrameName("img_paotai_dhlw.png");
		img_paotai_dhlw->setTag(100 + BIRD_TYPE_27);
		batch_node_->addChild(img_paotai_dhlw);
		mSmallDargonKing.push_back(img_paotai_dhlw);

		clearDragonKingShow();

		mSptLuckyAni = CCSprite::createWithSpriteFrameName("LuckyAni_01.png");
		mSptLuckyAni->setVisible(false);
		batch_node_->addChild(mSptLuckyAni);

		mSptWarningFire = CCSprite::createWithSpriteFrameName("WarningFire.png");
		mSptWarningFire->setScale(1.3f);
		mSptWarningFire->setVisible(false);
		batch_node_->addChild(mSptWarningFire);

		time = 60;
		mLbWarningFire = LabelAtlas::create(__String::createWithFormat("%d", time)->getCString(), "bmfonts/WarningFireNumber.png", 27, 39, '100');
		mLbWarningFire->setScale(1.6f);
		mLbWarningFire->setVisible(false);
		this->addChild(mLbWarningFire);

		mSptPaoTaiEffect = CCSprite::createWithSpriteFrameName("PaoTaiEffect_01.png");
		mSptPaoTaiEffect->setVisible(false);
		batch_node_->addChild(mSptPaoTaiEffect);

		mLockIcon = Sprite::createWithSpriteFrameName(StringUtils::format("lock_flag_%d.png", char_id + 1));
		CCAssert(mLockIcon, "");
		mSptPaoTaiEffect->setVisible(false);
		this->addChild(mLockIcon, 0XFFF);

		mLockLineLayout = Sprite::create();
		CCAssert(mLockLineLayout, "");
		mLockLineLayout->setVisible(false);
		this->addChild(mLockLineLayout, 0XFFFF);
		for (int i = 0; i < 15; i++)
		{
			Sprite * lockLine = Sprite::createWithSpriteFrameName("img_lock_line.png");
			lockLine->setTag(i);
			mLockLineLayout->addChild(lockLine);
		}

		mLockIconStatic = Sprite::createWithSpriteFrameName("img_lockBg.png");
		CCAssert(mLockIconStatic, "");
		mLockIconStatic->setVisible(false);
		this->addChild(mLockIconStatic);


		mLockBirdAnimate = BirdNode::create(-1);
		CCAssert(mLockBirdAnimate, "");
		mLockBirdEffect = Sprite::create();
		CCAssert(mLockBirdEffect, "");
		//mLockBirdAnimate->setVisible(true);
		mLockIconStatic->addChild(mLockBirdAnimate, 1);
		mLockIconStatic->addChild(mLockBirdEffect, 0);
		//mSptCannonAdd = CCSprite::createWithSpriteFrameName("cannon_add.png");
		//mSptCannonAdd->setVisible(false);
		//batch_node_->addChild(mSptCannonAdd);

		//mSptCannonSub = CCSprite::createWithSpriteFrameName("cannon_sub.png");
		//mSptCannonSub->setVisible(false);
		//batch_node_->addChild(mSptCannonSub);

		int pao_x = CANNON_POSITION[chair_id_][0];
		int pao_y = CANNON_POSITION[chair_id_][1];

		if (chair_id_ == 0 || chair_id_ == 1 || chair_id_ == 2)
		{
			mSptMark->setPosition(toCCP(pao_x, pao_y + 100));
			mSptPaoTaiOver->setPosition(toCCP(pao_x, pao_y - 23 + 10));

			mSptPaoTaiEffect->setPosition(toCCP(pao_x, pao_y));

			mSptJiFenPai->setPosition(toCCP(pao_x + 160, pao_y - 8));
			mSptNetState->setPosition(toCCP(pao_x + 90, pao_y - 8));
			mLbJiFen->setPosition(toCCP(pao_x + 100, pao_y - 20));

			mSptBow->setPosition(toCCP(pao_x, pao_y - 15 + 10));
			mLbBow->setPosition(toCCP(pao_x, pao_y - 18 + 8));

			mSptWarningFire->setPosition(batch_node_->convertToNodeSpace(Vec2(size.width / 2, size.height / 2)));
			mLbWarningFire->setPosition(mSptWarningFire->getPositionX() / 3 * 2 - 80, mSptWarningFire->getPositionY() - 65);

			mLbName->setPosition(toCCP(pao_x + 87, pao_y - 40 - 10));

			mCoinsShow->setPosition(toCCP(pao_x - 140, pao_y - 45));

			//mSptCannonSub->setPosition(toCCP(pao_x - 200,pao_y+200));
			//mSptCannonAdd->setPosition(toCCP(pao_x + 200,pao_y+200));
			mSptPaoTai->setPosition(toCCP(pao_x, pao_y - 20));
			mSptTrack->setPosition(Vec2(45, 135));

			mLockIconStatic->setPosition(mSptBow->getPosition() + Vec2(-40, -100));

			///< ����
			mMoneyGoldAnimation->setPosition(toCCP(pao_x, pao_y + 130));
			///< �ĺ�����
			img_paotai_bhlw->setPosition(toCCP(pao_x + 100, pao_y + 40));
			img_paotai_dhlw->setPosition(toCCP(pao_x + 135, pao_y + 40));
			img_paotai_nhlw->setPosition(toCCP(pao_x + 170, pao_y + 40));
			img_paotai_shlw->setPosition(toCCP(pao_x + 205, pao_y + 40));

		}
		else if (chair_id_ == 3 || chair_id_ == 4 || chair_id_ == 5)
		{
			mSptMark->setPosition(toCCP(pao_x, pao_y - 100));
			mSptPaoTaiOver->setPosition(toCCP(pao_x, pao_y + 23 - 10));

			mSptPaoTaiEffect->setPosition(toCCP(pao_x, pao_y));

			mSptJiFenPai->setPosition(toCCP(pao_x + 160, pao_y + 8));
			mSptNetState->setPosition(toCCP(pao_x + 90, pao_y + 8));
			mLbJiFen->setPosition(toCCP(pao_x + 100, pao_y - 4));


			mSptBow->setPosition(toCCP(pao_x, pao_y + 15 - 10));
			mLbBow->setPosition(toCCP(pao_x, pao_y + 20 - 5));

			mSptWarningFire->setPosition(batch_node_->convertToNodeSpace(Vec2(size.width / 2, size.height / 2)));
			mLbWarningFire->setPosition(mSptWarningFire->getPositionX() / 3 * 2 - 80, mSptWarningFire->getPositionY() - 65);

			mLbName->setPosition(toCCP(pao_x + 87 , pao_y + 24 + 10));

			mCoinsShow->setPosition(toCCP(pao_x - 140, pao_y + 45));

			//mSptCannonSub->setPosition(toCCP(pao_x - 200,pao_y-200));
			//mSptCannonAdd->setPosition(toCCP(pao_x + 200,pao_y-200));
			mSptPaoTai->setPosition(toCCP(pao_x, pao_y + 35));
			mSptTrack->setPosition(Vec2(45, 135));

			mLockIconStatic->setPosition(mSptBow->getPosition() + Vec2(-40, 100));

			mMoneyGoldAnimation->setPosition(toCCP(pao_x, pao_y - 130));

			img_paotai_bhlw->setPosition(toCCP(pao_x + 100, pao_y - 40));
			img_paotai_dhlw->setPosition(toCCP(pao_x + 135, pao_y - 40));
			img_paotai_nhlw->setPosition(toCCP(pao_x + 170, pao_y - 40));
			img_paotai_shlw->setPosition(toCCP(pao_x + 205, pao_y - 40));
		}
		Vec2 now_p = mLockIconStatic->getPosition();
		CCActionInterval * repeatForever = SimpleTools::getCircularAction(mLockIconStatic->getPosition(), 25);
		mLockIconStatic->runAction(repeatForever);
		mLockBirdAnimate->setPosition(mLockIconStatic->getAnchorPointInPoints());
		mLockBirdEffect->setPosition(mLockIconStatic->getAnchorPointInPoints());

		///< ����
		mMoneyGoldAnimation->setRotation(CANNON_ANGLE[chair_id_]);
		///< �ĺ�����
		img_paotai_bhlw->setRotation(CANNON_ANGLE[chair_id_]);
		img_paotai_dhlw->setRotation(CANNON_ANGLE[chair_id_]);
		img_paotai_nhlw->setRotation(CANNON_ANGLE[chair_id_]);
		img_paotai_shlw->setRotation(CANNON_ANGLE[chair_id_]);
		mSptPaoTai->setRotation(CANNON_ANGLE[chair_id_]);
		mSptLuckyAni->setPosition(toCCP(pao_x, pao_y));
		mSptLuckyAni->setRotation(CANNON_ANGLE[chair_id_]);
		mSptMark->setRotation(CANNON_ANGLE[chair_id_]);
		mSptBow->setRotation(CANNON_ANGLE[chair_id_]);
		mSptPaoTaiOver->setRotation(CANNON_ANGLE[chair_id_]);
		mSptPaoTaiEffect->setRotation(CANNON_ANGLE[chair_id_]);
		mCoinsShow->setRotation(CANNON_ANGLE[chair_id_]);
		Vec2 tPos = mSptPaoTai->convertToWorldSpace(mSptPaoTai->getAnchorPointInPoints());
		mLockLineLayout->setPosition(this->convertToNodeSpace(tPos));
		//mSptCannonType->setRotation(CANNON_ANGLE[chair_id_]);

		//mSptCannonSub->setRotation(CANNON_ANGLE[chair_id_]);
		//mSptCannonAdd->setRotation(CANNON_ANGLE[chair_id_]);

		set_net_state(0);
		show(false,false);
		this->scheduleUpdate();
		return true;
	} while (0);

	return false;
}

void RoleNode::show(bool bShow,bool bShowGame)
{
	this->setVisible(bShow);

	BUFF_LIST_ITER it = buff_list_.begin();
	for (; it != buff_list_.end(); ++it)
	{
		CCNode* node = *it;
		node->stopAllActions();
		node->removeAllChildrenWithCleanup(true);
	}
	buff_list_.clear();

	mSptMark->setVisible(false);

	mSptLuckyAni->setVisible(false);
	mSptWarningFire->setVisible(false);
	mLbWarningFire->setVisible(false);
	mSptPaoTaiEffect->setVisible(false);

	mSptBow->setRotation(CANNON_ANGLE[chair_id_]);
	set_gold(0);
	show_warning_fire(false);

	// ����mSptMark
	if (bShowGame)
	{
		//��������
		set_cannon(0);
		set_level(0);
		set_fire_mode(0);

		//���ų��ֶ���
		mSptPaoTaiEffect->setVisible(true);
		mSptPaoTaiEffect->stopAllActions();
		mSptPaoTaiEffect->runAction(CCSequence::create(SpriteHelper::createAnimate("PaoTaiEffect"), CCCallFuncN::create(this, callfuncN_selector(RoleNode::func_born_end)), 0));
	}
}



std::string RoleNode::stringIntercept(std::string input, int signlen)
{
	string signstr = "";
	int strlen =1;
	for (int i = 0; i < input.length(); ++i)
	{
		if (strlen > signlen)
			break;
		int dropping = (unsigned char)(input[i]);
		if (dropping >= 0x80)
		{
			strlen += 2;
			signstr += input[i];
			i++;
		}
		else
		{
			strlen += 1;
		}
		signstr += input[i];
	}
	if (strlen > signlen)
		signstr += "...";
	return signstr;
}
void RoleNode::show_coin(int count, int score, int chair_id_)
{
	mCoinsShow->show_coin_animtion(count, score,chair_id_);
}

void RoleNode::set_bow_angle(float angle)
{
	//	log("angle is %f", (angle));
	rotation_ = angle;
	mSptBow->setRotation(toCCRotation(rotation_));
	//mSptBow->setRotation(CC_RADIANS_TO_DEGREES(rotation_));
}

float RoleNode::get_bow_angle() const
{
	return rotation_;
}

bool RoleNode::can_fire()
{
	return GameConfig::getInstance().get_cannon_price(cannon_type_) <= gold_;
}

void RoleNode::fire(bool isSelf, bool bNoter)
{
	static int no_play_sound_count = 0;
	

	//

	if (isSelf && bNoter)
	{
		set_gold(gold_ - cannon_mulriple_);
	}
	
	char name[64] = { 0 };
	char sSnd[16] = { 0 };

	if (bNoter && bNoter)
	{
		sprintf(name, "Bow%d", get_cannon_index_by(level_));
		mSptBow->runAction(CCSequence::create(SpriteHelper::createAnimate(name), 0));
		sprintf(sSnd, "fire%d", get_sound_index());
	}
	

	if (isSelf)
	{
		if (bNoter)SoundManager::shared()->playSound(sSnd);
		else SoundManager::shared()->playSound("TempBg.mp3");
		no_play_sound_count = 0;
	}
	else
	{
		no_play_sound_count++;
		if (no_play_sound_count > 2)
		{
			if (bNoter )SoundManager::shared()->playSound(sSnd);
			else SoundManager::shared()->playSound("TempBg.mp3");
			no_play_sound_count = 0;
		}
	}

}

void RoleNode::set_gold(int64 gold)
{
	gold_ = gold;

	std::ostringstream ostr;
	ostr.str("");
	ostr << gold_;
	mLbJiFen->setString(ostr.str().c_str());
}


void RoleNode::set_cannon(uint16 cannon)
{
	if (cannon_type_ <= GameConfig::getInstance().get_mulriple_count())
	{
		cannon_type_ = cannon;
		set_cannon_mulriple(GameConfig::getInstance().get_cannon_mulriple(cannon_type_));
		//showPowerRoleCompleteEffect();
		//mLbBow->setString(toString((int)gGameConfig.get_cannon_price(cannon_type_)));
	}
}

void RoleNode::set_cannon_mulriple(uint32 cannon_mulriple)
{
	if (cannon_mulriple_ != cannon_mulriple)
	{
		cannon_mulriple_ = cannon_mulriple;
		mLbBow->setString(toString((int)cannon_mulriple));
	}
}

void RoleNode::set_level(uint16 level)
{
	level_ = level;
	char name[64] = { 0 };
	sprintf(name, "Bow%d", get_cannon_index_by(level_));
	mSptBow->setDisplayFrameWithAnimationName(name, 0);

	//sprintf(name, "BowType%d.png", get_cannon_index_by(level_) + 1);
	//mSptCannonType->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name));
}



//void CStringToSingleStr(const std::string input, std::vector &output)
//{
//	std::string ch;
//	for (size_t i = 0, len = 0; i != input.length(); i += len)
//	{
//		unsigned char byte = (unsigned)input[i];
//		if (byte >= 0xFC)//length 6
//		{
//			len = 6;
//		}
//		else if (byte >= 0xF8)
//		{
//			len = 5;
//		}
//		else if (byte >= 0xF0)
//		{
//			len = 4;
//		}
//		else if (byte >= 0xE0)
//		{
//			len = 3;
//		}
//		else if (byte >= 0xC8)
//		{
//			len = 2;
//		}
//		else
//		{
//			len = 1;
//		}
//		ch = input.substr(i, len);
//		output.push_back(ch);
//	}
//}

void RoleNode::set_nickname(const std::string& nickname)
{
	
		string ppp = a_u8(nickname.c_str());
		string ppp1 = u8_a(nickname.c_str());
		std::string strMaskNick = stringIntercept(ppp1, 16);
		string strGameNick1 = a_u8(strMaskNick.c_str());

		mLbName->setString(strGameNick1);

	
}

bool RoleNode::is_warning_fire_show() const
{
	return mSptWarningFire->isVisible();
}

void RoleNode::show_warning_fire(bool isShow)
{
	mSptWarningFire->setVisible(isShow);
	mLbWarningFire->setVisible(isShow);
}

void RoleNode::set_warning_time(int time)
{
	char buf[64] = { 0 };
	sprintf(buf, "%02d", time);
	mLbWarningFire->setString(buf);
}

void RoleNode::set_net_state(uint32 difference)
{
	int type = 2;
	if (difference < 100)
		type = 0;
	else if (difference < 200)
		type = 1;

	char name[64] = { 0 };
	sprintf(name, "NetState_%02d.png", type + 1);
	mSptNetState->setDisplayFrame(CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(name));

	//sprintf(name, "%dms", difference);
	//mLbTrad->setString(name);
}


void RoleNode::set_fire_mode(int mode)
{
	//fire_mode_ = mode != 0 ? 1 : 0;
	//mSptEffectFire0->setVisible(fire_mode_ == 0);
	//mSptEffectFire1->setVisible(fire_mode_ != 0);
}


//////////////////////////////////////////////////////////////////////////
// Ч������
void RoleNode::net_skill(int skill, int cast)
{
	if (cast)
	{
		int type = skill % 10;
		int pao_x = CANNON_POSITION[chair_id_][0];
		int pao_y = CANNON_POSITION[chair_id_][1] + (type == 0 ? (chair_id_ <= 2 ? -10 : +10) : (chair_id_ <= 2 ? 150 : -150));

		char sAni[32] = { 0 };
		sprintf(sAni, "Skill%d", skill);
		CCAnimate* animate = SpriteHelper::createAnimate(sAni);

		if (animate != 0)
		{
			CCSprite* spt = CCSprite::create();
			spt->setPosition(toCCP(pao_x, pao_y));
			this->addChild(spt);
			spt->setRotation(CANNON_ANGLE[chair_id_]);
			spt->runAction(
				CCSequence::create(
				animate,
				RemoveAction::create(),
				0));
		}

		add_buff(skill + 100, xPoint(pao_x, pao_y));

		SoundManager::shared()->playSound("skill_cast");
	}
	else
	{
		remove_buff(skill + 100);
	}
}

void RoleNode::net_effect(int effect, int bird_id, const xPoint &pt_brid)
{
	if (effect == BIRD_EFFECT_GOLDX2)
	{
		if (bird_id == 0)
		{
			remove_buff(effect);
		}
		else
		{
			add_buff(effect, pt_brid);
		}

		return;
	}

	if (effect == BIRD_EFFECT_LUCKY)
	{
		if (bird_id == 0)
		{
			mSptLuckyAni->setVisible(false);
			mSptLuckyAni->pauseSchedulerAndActions();
			remove_buff(effect);
		}
		else
		{
			mSptLuckyAni->setVisible(true);
			mSptLuckyAni->pauseSchedulerAndActions();
			mSptLuckyAni->runAction(CCRepeatForever::create(SpriteHelper::createAnimate("LuckyAni")));
			add_buff(effect, pt_brid);
		}

		return;
	}

	if (effect == BIRD_EFFECT_TOR)
	{
		if (bird_id == 0)
		{
			remove_buff(effect);
		}
		else
		{
			add_buff(effect, pt_brid);
		}

		return;
	}

	if (effect == BIRD_EFFECT_EEL)
	{
		if (bird_id == 0)
		{
			remove_buff(effect);
		}
		else
		{
			add_buff(effect, pt_brid);
		}

		return;
	}
}

void RoleNode::add_buff(int buff, const xPoint& pt_bird)
{
	BUFF_LIST_ITER it = buff_list_.begin();

	for (; it != buff_list_.end(); ++it)
	{
		CCNode* node = *it;
		if (node->getTag() == buff)
			return;
	}

	xPoint pt = toNetPoint(mSptCannonType->getPosition());
	int buff_cnt = buff_list_.size();

	if (chair_id_ < 3)
	{
		pt.offset(0, BUFF_Y_OFFSET + buff_cnt * BUFF_ITEM_HEIGHT);
	}
	else
	{
		pt.offset(0, -BUFF_Y_OFFSET - buff_cnt * BUFF_ITEM_HEIGHT);
	}

	char sBuff[32] = { 0 };
	sprintf(sBuff, "PaoTaiBuff%03d.png", buff);
	CCSprite* spt = CCSprite::createWithSpriteFrameName(sBuff);
	spt->setTag(buff);
	spt->setPosition(toCCP(pt_bird));
	spt->setOpacity(0);
	CCSequence* act = CCSequence::create(
		CCFadeIn::create(0.01f),
		CCMoveTo::create(1, toCCP(pt)),
		0);
	spt->runAction(act);
	batch_node_->addChild(spt);

	buff_list_.push_back(spt);
}

void RoleNode::remove_buff(int buff)
{
	BUFF_LIST_ITER it = buff_list_.begin();

	for (; it != buff_list_.end(); ++it)
	{
		CCNode* node = *it;

		if (node->getTag() == buff)
		{
			// ����������ƶ�
			CCPoint pt_move = node->getPosition();

			BUFF_LIST_ITER itNext = it;
			itNext++;
			for (; itNext != buff_list_.end(); ++itNext)
			{
				CCNode* spr_next = *itNext;
				spr_next->stopAllActions();
				spr_next->runAction(CCMoveTo::create(1.0f, pt_move));

				pt_move = spr_next->getPosition();
			}
			break;
		}
	}

	if (it == buff_list_.end())
		return;
	CCNode* node = *it;

	buff_list_.erase(it);
	node->stopAllActions();
	node->removeFromParentAndCleanup(true);
}

//////////////////////////////////////////////////////////////////////////

void RoleNode::show_buttons(bool bShow)
{
	if (is_buttons_ == bShow)
		return;

	is_buttons_ = bShow;
	int pao_x = CANNON_POSITION[chair_id_][0];
	int pao_y = CANNON_POSITION[chair_id_][1];
	CCPoint ptCannonSubFrom(toCCP(pao_x, pao_y)), ptCannonSubTo(toCCP(pao_x, pao_y));
	CCPoint ptCannonAddFrom(toCCP(pao_x, pao_y)), ptCannonAddTo(toCCP(pao_x, pao_y));

	if (bShow)
	{
		float duration = 2;

		if (chair_id_ == 0 || chair_id_ == 1 || chair_id_ == 2)
		{
			ptCannonSubTo = toCCP(pao_x - 60, pao_y - 30);
			ptCannonAddTo = toCCP(pao_x + 60, pao_y - 30);
		}
		else if (chair_id_ == 3 || chair_id_ == 4 || chair_id_ == 5)
		{
			ptCannonSubTo = toCCP(pao_x - 60, pao_y + 30);
			ptCannonAddTo = toCCP(pao_x + 60, pao_y + 30);
		}

		//mSptCannonSub->setVisible(true);
		//change by xy
		//ptCannonSub->setVisible(false);
		//change
		//mSptCannonSub->setPosition(ptCannonSubTo);
		//mSptCannonSub->setVisible(true);
		//mSptCannonSub->setScale(0);
		//mSptCannonSub->stopAllActions();
		//mSptCannonSub->runAction(CCEaseElasticOut::create(CCSpawn::create(CCScaleTo::create(duration, 1), CCMoveTo::create(duration, ptCannonSubTo), 0)));

		//mSptCannonAdd->setVisible(true);
		//change by xy
		//ptCannonAdd->setVisible(false);
		//change
		//mSptCannonAdd->setPosition(ptCannonAddTo);
		//mSptCannonAdd->setVisible(true);
		//mSptCannonAdd->setScale(0);
		//mSptCannonAdd->stopAllActions();
		//mSptCannonAdd->runAction(CCEaseElasticOut::create(CCSpawn::create(CCScaleTo::create(duration, 1), CCMoveTo::create(duration, ptCannonAddTo), 0)));

	}
	else
	{
		float duration = 1;

		if (chair_id_ == 0 || chair_id_ == 1 || chair_id_ == 2)
		{
			ptCannonSubFrom = toCCP(pao_x - 100, pao_y + 100);
			ptCannonAddFrom = toCCP(pao_x + 100, pao_y + 100);
		}
		else if (chair_id_ == 3 || chair_id_ == 4 || chair_id_ == 5)
		{
			ptCannonSubFrom = toCCP(pao_x - 100, pao_y - 100);
			ptCannonAddFrom = toCCP(pao_x + 100, pao_y - 100);
		}

		//mSptCannonSub->setVisible(true);
		//change by xy
		//mSptCannonSub->setVisible(false);
		//change
		//mSptCannonSub->setPosition(ptCannonSubFrom);
		//mSptCannonSub->setScale(1);
		//mSptCannonSub->stopAllActions();
		//mSptCannonSub->runAction(CCEaseElasticIn::create(CCSequence::create(CCSpawn::create(CCScaleTo::create(duration, 0), CCMoveTo::create(duration, ptCannonSubTo), 0), CCHide::create(), 0)));

		//mSptCannonAdd->setVisible(true);
		//change by xy
		//mSptCannonAdd->setVisible(false);
		//change
		//mSptCannonAdd->setPosition(ptCannonAddFrom);
		//mSptCannonAdd->setScale(1);
		//mSptCannonAdd->stopAllActions();
		//mSptCannonAdd->runAction(CCEaseElasticIn::create(CCSequence::create(CCSpawn::create(CCScaleTo::create(duration, 0), CCMoveTo::create(duration, ptCannonAddTo), 0), CCHide::create(), 0)));
	}
}

//bool RoleNode::handle_click(const CCPoint& pt)
//{
//	if (is_buttons_)
//	{
//		if (mSptCannonAdd->boundingBox().containsPoint(pt))
//		{
//			G_NOTIFY_D("CANNON_ADD", 0);
//			return true;
//		}
//		else if (mSptCannonSub->boundingBox().containsPoint(pt))
//		{
//			G_NOTIFY_D("CANNON_SUB", 0);
//			return true;
//		}
//	}
//
//	//if (this->can_fire())
//	//{
//	//	if (mSptPaoTai->boundingBox().containsPoint(pt))
//	//	{
//	//		show_buttons(!is_buttons_);
//	//		return true;
//	//	}
//	//	else if (is_buttons_)
//	//	{
//	//		show_buttons(false);
//	//	}
//	//}
//	
//	return false;
//}

//////////////////////////////////////////////////////////////////////////
int RoleNode::get_cannon_index_by(int connon_type) const
{
	int cannon_index = connon_type / MAX_WEAPON_SUB_LEVEL;
	int count = GameConfig::getInstance().get_mulriple_count()/3;//�ȼ���
	if(count <= 0)
	{
		count = 1;
	}

	cannon_index = connon_type/count;
	//if (cannon_index >= MAX_WEAPON_MAIN_LEVEL)
	//	cannon_index = MAX_WEAPON_MAIN_LEVEL - 1;

	return cannon_index;
}

int RoleNode::get_net_index_by(int level) const
{
	if (buff_list_.size() != 0)
	{
		CCNode* node = buff_list_.back();

		switch (node->getTag())
		{
		case BIRD_EFFECT_GOLDX2:	return 3;
		case BIRD_EFFECT_TOR:		return 4;
		case BIRD_EFFECT_EEL:		return 5;
			//��������
		case 110:					return 10;
		case 120:					return 20;
		case 130:					return 30;
		case 140:					return 40;
		case 150:					return 50;
			//	//��������
			//case 121:					return 20;
			//case 131:					return 30;
			//case 132:					return 30;
			//case 141:					return 40;
			//case 142:					return 40;
			//case 143:					return 40;
			//case 151:					return 50;
			//case 152:					return 50;
			//case 153:					return 50;
			//case 154:					return 50;
		}
	}

	switch (get_cannon_index_by(level))
	{
	case 0: return 0;
	case 1:return 1;
	case 2:	
	case 3:
	case 4:	return 2;
	}

	return 2;
}


int RoleNode::get_bullet_index_by(int level) const
{
	switch (get_cannon_index_by(level))
	{
	case 0: return 0;
	case 1:return 1;
	case 2:	
	case 3:
	case 4:	return 2;
	}

	return 0;
}

int RoleNode::get_sound_index() const
{
	return get_sound_index_by(level_);
}

int RoleNode::get_sound_index_by(int level) const
{
	if (buff_list_.size() != 0)
	{
		CCNode* node = buff_list_.back();

		switch (node->getTag())
		{
		case BIRD_EFFECT_EEL:		return 2;
		case BIRD_EFFECT_TOR:		return 1;
		}
	}

	return 0;
}

//////////////////////////////////////////////////////////////////////////
void RoleNode::func_mark_end(cocos2d::Node* node)
{
	node->setVisible(false);
	node->pauseSchedulerAndActions();
}

void RoleNode::func_born_end(cocos2d::Node* node)
{
	node->setVisible(false);
	node->pauseSchedulerAndActions();

	IClientKernel* kernel = IClientKernel::get();
	// ����mSptMark
	if (kernel != 0 && chair_id_ == kernel->GetMeChairID())
	{
		mSptMark->setVisible(true);
		mSptMark->stopAllActions();
		mSptMark->runAction(CCRepeatForever::create(SpriteHelper::createAnimate("Mark")));
		mSptMark->runAction(CCSequence::create(CCFadeIn::create(0.5f), CCDelayTime::create(5), CCFadeOut::create(1), CCCallFuncN::create(this, callfuncN_selector(RoleNode::func_mark_end)), 0));
		show_buttons(true);
	}
}

///< ��������ͼ���λ��
void RoleNode::update(float delta)
{
	if (Director::getInstance()->getRunningScene() == nullptr) 
		return;

	cocos2d::Vec2 bird_pos = this->getLockBirdPos();
	IClientKernel* kernel = IClientKernel::get();
	if (bird_pos != Vec2(0, 0))
	{
		///< ֤����Ҫ����
		///< ��ʾ׷����
		mLockLineLayout->setVisible(true);
		///< ����λ��
		this->correctLockLine(bird_pos);
		///< �ı�
		mLockIcon->setVisible(true);
		//Vec2 tWPos = this->convertToWorldSpace(Vec2(0, 0));
		Vec2 tPos = this->convertToNodeSpace(bird_pos);
		mLockIcon->setPosition(tPos);

		///<������ͼƬ,����Ҫ�ж��ǲ����Լ�
		if (kernel && kernel->GetMeChairID() == chair_id_)
			this->openCircularLockIcon();
	}
	else
	{

		mLockIcon->setVisible(false);
		mLockLineLayout->setVisible(false);
		if (kernel && kernel->GetMeChairID() == chair_id_)
			this->closeCircularLockIcon();
	}

}

void RoleNode::correctLockLine(const cocos2d::Vec2 & bird_pos)
{
	///< 1.����Ƕ� 2.���㳤�� 3. ƽ������㵽ÿ��λ�� 4.��ת�ߵĽǶ� 
	Vec2 paotaiPos = mSptBow->convertToWorldSpace(mSptBow->getAnchorPointInPoints());
	Vec2 now_p = ccpSub(paotaiPos, bird_pos);
	float angle = ccpToAngle(now_p);
	float distance = paotaiPos.getDistance(bird_pos);
	float x_1 = distance * sin(angle);
	float x_2 = distance * cos(angle);
	float tAngle = bird_pos.x + x_2;
	float zAngle = bird_pos.y + x_1;
	cocos2d::Vector<Node *> tAllLockLine = mLockLineLayout->getChildren();
	///< �����
	int qCount = distance / 50;
	if (qCount < 2) qCount = 2;
	if (qCount > tAllLockLine.size()) qCount = tAllLockLine.size();

	float average = distance / qCount;

	for (int i = 0; i < qCount; i++)
	{
		Node * tLockLine = tAllLockLine.at(i);
		CCAssert(tLockLine, "");
		tLockLine->setVisible(true);
		float _x = average * (i + 1) * cos(angle);
		float _y = average * (i + 1) * sin(angle);
		//Vec2 tLinePos = paotaiPos + Vec2(_x, _y);
		Vec2 tLockLinePos = bird_pos + Vec2(_x, _y);
		tLockLine->setPosition(mLockLineLayout->convertToNodeSpace(tLockLinePos));
	}

	for (int i = qCount; i < tAllLockLine.size(); i++)
	{
		Node * tLockLine = tAllLockLine.at(i);
		tLockLine->setVisible(false);
	}
	//value_1 *= -1;
	//mLockLineLayout->setRotation(angle);
	float value_1 = SimpleTools::calcRotate(chair_id_, toNetPoint(bird_pos));
	this->set_bow_angle(value_1);
}

cocos2d::Vec2 RoleNode::getPaoTaiPos()
{
	Vec2 tPos = mSptPaoTai->convertToWorldSpace(mSptPaoTai->getAnchorPointInPoints());
	return tPos;
}


void RoleNode::cancelBirdLock(cocos2d::Ref * obj)
{
	_mLockBird = nullptr;

}

cocos2d::Vec2 RoleNode::getLockBirdPos() const
{
	if (_mLockBird != nullptr)
	{
		Vec2 tBirdPos = _mLockBird->convertToWorldSpace(_mLockBird->getAnchorPointInPoints());
		//Size tBirdSize = _mLockBird->getContentSize();
		//Vec2 tCenPos = Vec2(tBirdPos.x + tBirdSize.width / 2, tBirdPos.y + tBirdSize.height / 2);
		return tBirdPos;
	}

	else
	{
		return Vec2(0, 0);
	}

}

bool RoleNode::isLockBird()
{
	if (_mLockBird != nullptr)
		return true;
	else
		return false;
}

float RoleNode::getMyRoloRoration()
{
	return this->get_bow_angle();
}

cocos2d::Vec2 RoleNode::getMyRoloWorldPostion()
{
	return this->getPaoTaiPos();
}

xPoint RoleNode::getFishNextPosition(float elapsed)
{
	if (_mLockBird != nullptr)
	{
		Action * taction = _mLockBird->birdMove;

		Action_Base_Bird_Move * action = dynamic_cast<Action_Base_Bird_Move *>(taction);
		if (action != nullptr)
			return action->BirdMoveTo(elapsed);
	}
	return xPoint();
}

void RoleNode::setLockBird(BirdNode * lockBird)
{
	/*	return;*/
	_mLockBird = lockBird;

	this->getLockBirdAnimationAndRun();
}

void RoleNode::openCircularLockIcon()
{
	mLockIconStatic->setVisible(true);

	mLockBirdAnimate->setRotation(_mLockBird->getRotation());
	if (_mLockBird->bird && _mLockBird->bird->type_ == BIRD_TYPE_INGOT)
	{
		///< ���ýǶ�
		//int Rangle = (int)_mLockBird->getRotation() % 360;
		mLockBirdEffect->setRotation(_mLockBird->getRotation() + 90);
		///< ����λ��
		Vec2 bird_pos = mLockBirdAnimate->getPosition();
		float angle = mLockBirdAnimate->getRotation();
		bool big_angle = angle > 180 || angle < -180 ? true : false;
		angle = angle > 180 ? angle - 180 : angle < -180 ? angle + 180 : angle;
		angle = -angle;
		float dregress = CC_DEGREES_TO_RADIANS(angle);

		Vec2 effect_pos;
		if (big_angle)
		{
			effect_pos = Vec2(bird_pos.x - 30 * cos(dregress), bird_pos.y - 30 * sin(dregress));
		}
		else
		{
			effect_pos = Vec2(bird_pos.x + 30 * cos(dregress), bird_pos.y + 30 * sin(dregress));
		}

		mLockBirdEffect->setPosition(effect_pos);

	}
	else
	{
		mLockBirdEffect->setRotation(_mLockBird->getRotation());
	}

}

void RoleNode::closeCircularLockIcon()
{
	mLockIconStatic->setVisible(false);
	///< �����

}
static int BirdType = -1;
static int BirdTypeSpecial = -1;
void RoleNode::getLockBirdAnimationAndRun()
{
	IClientKernel* kernel = IClientKernel::get();
	if (!_mLockBird || kernel->GetMeChairID() != chair_id_) return;
	int bird_type = _mLockBird->getType();
	int bird_type_special = _mLockBird->bird->type_;
	///< �����������, ������������Ͳ����ڱ�����������. ������������Ͳ����ڴ������������
	if (_mLockBird && (bird_type_special != BirdTypeSpecial || BirdType != bird_type))
	{

		mLockBirdAnimate->stopAllActions();
		mLockBirdEffect->stopAllActions();

		mLockBirdAnimate->setColor(ccc3(255, 255, 255));
		///< �Ƴ��ö���
		mLockBirdAnimate->removeFromParent();
		mLockBirdAnimate = nullptr;
		//< �Ƴ���Ч�����нڵ�
		mLockBirdEffect->removeFromParent();

		mLockBirdEffect = Sprite::create();
		mLockIconStatic->addChild(mLockBirdEffect, 0);
		///< ������
		BirdType = _mLockBird->getType();
		BirdTypeSpecial = _mLockBird->bird->type_;
		///< ��Ϊ�����������.���Ϊ��Ч��ȡ

		if (SimpleTools::isDntgSpecialBird(_mLockBird->bird->type_))
		{
			///< ��������������ȥ����
			if (SimpleTools::isDntgSpecialRoundBird(_mLockBird->bird->type_))
			{
				mLockBirdAnimate = SpecialBirdNode::create(_mLockBird->bird->item_);
				dynamic_cast<SpecialBirdNode *>(mLockBirdAnimate)->setBirdNum(_mLockBird->bird->type_ - BIRD_TYPE_ONE + 1);
			}
			else
			{
				mLockBirdAnimate = BirdNode::create(_mLockBird->bird->item_);
			}

			//animate_id = _mLockBird->bird->item_;

		}
		else
		{
			mLockBirdAnimate = BirdNode::create(_mLockBird->bird->type_);
		}
		mLockBirdAnimate->born(false);

		///< ���ú�������ں���.
		if (_mLockBird->bird->type_ == BIRD_TYPE_RED)
			mLockBirdAnimate->setColor(ccc3(255, 0, 0));
		mLockBirdAnimate->setPosition(mLockIconStatic->getAnchorPointInPoints());
		mLockIconStatic->addChild(mLockBirdAnimate);
		char sEffect[32] = { 0 };
		sprintf(sEffect, "BirdEffect%d", _mLockBird->bird->type_);
		//< ��Ч
		CCAnimate* effect_animate = SpriteHelper::createAnimate(sEffect);

		// 		auto animation = animate->getAnimation();
		// 		float delety = animation->getDelayPerUnit();
		if (effect_animate) ///< ��Ч��Ϊ�ղ����
		{
			mLockBirdEffect->setVisible(true);
			///< ʹ�����������еķ���ȷ��λ��
			if (SimpleTools::isDntgSpecialRoundBird(_mLockBird->bird->type_))
			{
				dynamic_cast<SpecialBirdNode *>(mLockBirdAnimate)->setEffect(mLockBirdEffect, effect_animate);
			}
			else
				mLockBirdEffect->runAction(CCRepeatForever::create(CCSequence::create(effect_animate, NULL)));

			if (BirdTypeSpecial == BIRD_TYPE_CHAIN || BirdTypeSpecial == BIRD_TYPE_INGOT) ///< ��������,������
				mLockBirdEffect->setZOrder(2);
		}
		else
		{
			mLockBirdEffect->setVisible(false);
			mLockBirdEffect->setZOrder(0);
		}

		///< ��������!!
		Vec2 scale_rate(1, 1);
		if (_mLockBird->bird->type_ == BIRD_TYPE_INGOT)
		{
			scale_rate.x = 0.5f;
			scale_rate.y = 0.5f;
		}
		else if (_mLockBird->bird->type_ > 14)
		{
			scale_rate.x = 0.5f;
			scale_rate.y = 0.5f;
		}
		else if (!SimpleTools::isDntgSpecialRoundBird(_mLockBird->bird->type_))
		{
			Size bgSize = mLockIconStatic->getContentSize();
			Size birdSize = _mLockBird->getSize();

			///< ��Ŀ��,������Ŀ��
			scale_rate = Vec2(bgSize.width / birdSize.width, bgSize.height / birdSize.height);
			///< ��ȡ��Сֵ
			if (scale_rate.x > scale_rate.y) scale_rate.x = scale_rate.y;
			else scale_rate.y = scale_rate.x;
			///< �ڼ���Ƿ����1,///< �ڼ���Ƿ����0
			if (scale_rate.x > 0.75f || scale_rate.x <= 0.0f) scale_rate.x = scale_rate.y = 0.75f;
		}
		else
		{
			if (_mLockBird->bird->type_ == BIRD_TYPE_ONE)
			{
				scale_rate.x = 0.5f;
				scale_rate.y = 0.5f;
			}
			else if (_mLockBird->bird->type_ == BIRD_TYPE_TWO)
			{
				scale_rate.x = 0.4f;
				scale_rate.y = 0.4f;
			}
			else if (_mLockBird->bird->type_ == BIRD_TYPE_THREE)
			{
				scale_rate.x = 0.35f;
				scale_rate.y = 0.35f;
			}
			else if (_mLockBird->bird->type_ == BIRD_TYPE_FOUR)
			{
				scale_rate.x = 0.3f;
				scale_rate.y = 0.3f;
			}
			else if (_mLockBird->bird->type_ == BIRD_TYPE_FIVE)
			{
				scale_rate.x = 0.3f;
				scale_rate.y = 0.3f;
			}

		}

		mLockBirdAnimate->setScale(scale_rate.x);
		mLockBirdEffect->setScale(scale_rate.x);

		///< ����λ��
		Vec2 bird_pos = mLockBirdAnimate->getPosition();
		float angle = mLockBirdAnimate->getRotation();
		bool big_angle = angle > 180 || angle < -180 ? true : false;
		angle = angle > 180 ? angle - 180 : angle < -180 ? angle + 180 : angle;
		angle = -angle;
		float dregress = CC_DEGREES_TO_RADIANS(angle);

		Vec2 effect_pos;
		if (big_angle)
		{
			effect_pos = Vec2(bird_pos.x - 30 * cos(dregress), bird_pos.y - 30 * sin(dregress));
		}
		else
		{
			effect_pos = Vec2(bird_pos.x + 30 * cos(dregress), bird_pos.y + 30 * sin(dregress));
		}

		if (_mLockBird->bird->type_ == BIRD_TYPE_INGOT)
		{
			mLockBirdEffect->setPosition(effect_pos);
		}
		else
		{
			mLockBirdEffect->setPosition(mLockIconStatic->getAnchorPointInPoints());
		}

	}
	else if (!_mLockBird)
	{
		mLockBirdAnimate->stopAllActions();
		mLockBirdEffect->stopAllActions();
		BirdType = -1;
		BirdTypeSpecial = -1;
		mLockBirdAnimate->setScale(1);
		mLockBirdEffect->setScale(1);
		mLockBirdAnimate->setColor(ccc3(255, 255, 255));
		mLockBirdEffect->setVisible(false);
		mLockBirdEffect->setZOrder(0);
		mLockBirdEffect->setPosition(mLockIconStatic->getAnchorPointInPoints());
	}

}

void RoleNode::showPowerRoleCompleteEffect()
{
	mSptPaoTaiEffect->setVisible(true);
	auto effect = SpriteHelper::createAnimate("PaoTaiEffect");
	mSptPaoTaiEffect->runAction(effect);
}

void RoleNode::showDeadDragonKingSmallHead(int bird_id)
{

	for (int i = 0; i < (int)mSmallDargonKing.size(); i++)
	{
		Sprite * smallDargon = mSmallDargonKing[i];
		int tag = smallDargon->getTag() - 100;
		if (tag == bird_id)
		{
			smallDargon->setVisible(true);
			break;
		}
	}

	checkDragonKingComplete();
}

void RoleNode::clearDragonKingShow()
{
	for (int i = 0; i < (int)mSmallDargonKing.size(); i++)
	{
		Sprite * smallDargon = mSmallDargonKing[i];
		smallDargon->setVisible(false);
	}
}

void RoleNode::checkDragonKingComplete()
{
	int count = 0;
	for (int i = 0; i < (int)mSmallDargonKing.size(); i++)
	{
		Sprite * smallDargon = mSmallDargonKing[i];
		bool isVisible_ = smallDargon->isVisible();
		count += isVisible_;
	}

	if (count >= 4)
	{
		///��ʾ���񶯻�
		mMoneyGoldAnimation->setVisible(true);
		FadeOut * fade = FadeOut::create(1.0f);
		Sequence * quence = Sequence::create(DelayTime::create(3.0f), fade, CallFunc::create(this, callfunc_selector(RoleNode::func_money_gold_callBack)), NULL);
		mMoneyGoldAnimation->runAction(quence);
	}
}

void RoleNode::func_money_gold_callBack()
{
	mMoneyGoldAnimation->setOpacity(GLubyte(255));
	mMoneyGoldAnimation->setVisible(false);
	clearDragonKingShow();
}



