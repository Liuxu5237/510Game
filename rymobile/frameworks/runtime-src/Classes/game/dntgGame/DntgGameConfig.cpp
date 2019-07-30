#include "DntgGameConfig.h"

using namespace Dntg;

///////////////////////////////////////////////////////////////////////////
GameConfig::GameConfig()
{
	ex_bullet_count_ = 1;
	ex_score_count_ = 1;
	cannon_type_max_ = 40;
	cannon_price_base_ = 25;
	mulriple_count_ = 0;
	memset(cannon_mulriple_, 0, sizeof(cannon_mulriple_));
	memset(bullet_config_, 0, sizeof(bullet_config_));
}

void GameConfig::init(CMD_S_StatusFree *status_free)
{
	ex_bullet_count_ = status_free->ex_ratio_birdscore_;
	ex_score_count_ = status_free->ex_ratio_userscore_;
	
	if (status_free->mulriple_count_ == 0)
	{
		mulriple_count_ = 6;
		cannon_mulriple_[0] = 1000;
		cannon_mulriple_[1] = 3000;
		cannon_mulriple_[2] = 5000;
		cannon_mulriple_[3] = 7000;
		cannon_mulriple_[4] = 9000;
		cannon_mulriple_[5] = 9900;
	}
	else
	{
		mulriple_count_ = status_free->mulriple_count_;
		memcpy(cannon_mulriple_, status_free->cannon_mulriple_, sizeof(cannon_mulriple_));
	}
	
	memcpy(bullet_config_, status_free->bullet_config_, sizeof(bullet_config_));
}

int GameConfig::get_cannon_price(int cannon) const
{
	return cannon_price_base_ * (cannon + 1);
}

Bullet_Config GameConfig::get_bullet_config(const float speed, int &type)
{
	for (uint16 i = 0; i < BULLET_KIND_COUNT; i++)
	{
		if (bullet_config_[i].speed == speed)
		{
			type = i;
			return bullet_config_[i];
		}
	}
	type = 0;
	return bullet_config_[0];
}

Bullet_Config GameConfig::get_bullet_config(const int type)
{
	return bullet_config_[type];
}
///////////////////////////////////////////////////////////////////////////
