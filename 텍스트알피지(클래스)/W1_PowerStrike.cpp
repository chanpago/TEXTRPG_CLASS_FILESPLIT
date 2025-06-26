#include "pch.h"
#include "W1_PowerStrike.h"

W1_PowerStrike::W1_PowerStrike(): W0_BasicSkill("파워 스트라이크") {}

W1_PowerStrike::~W1_PowerStrike()
{
}

float W1_PowerStrike::UseSkill(const float iStat)
{
	return PowerStrike(iStat);
}
