#include "DntgWeaponConfig.h"

using namespace Dntg;


void WeaponConfig::set_weapon_info(WeaponInfo weapon_info[MAX_WEAPON_MAIN_LEVEL])
{
	memcpy(weapons_, weapon_info, sizeof(weapons_));
}

const WeaponInfo* WeaponConfig::getWeapon(int main_level) const
{
	if (main_level >= 5) main_level = 4;
	if (main_level < 0) main_level = 0;

	return &weapons_[main_level];
}