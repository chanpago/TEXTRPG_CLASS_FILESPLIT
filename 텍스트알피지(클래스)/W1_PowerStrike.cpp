#include "pch.h"
#include "W1_PowerStrike.h"

W1_PowerStrike::W1_PowerStrike(): W0_BasicSkill("�Ŀ� ��Ʈ����ũ") {}

W1_PowerStrike::~W1_PowerStrike()
{
}

float W1_PowerStrike::UseSkill(const float iStat)
{
	return PowerStrike(iStat);
}
