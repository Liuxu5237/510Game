#pragma once

#include "cocos2d.h"

namespace ArmFun
{
	int WavToArm(std::string pchWAVEFilename, std::string pchAMRFileName);
	int ArmToWav(std::string pchAMRFileName,std::string pchWAVEFilename);
}