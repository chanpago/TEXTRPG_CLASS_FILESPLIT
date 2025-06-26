#include "pch.h"
#include "M1_MagicClaw.h"

M1_MagicClaw::M1_MagicClaw() : W0_BasicSkill("매직 클로") {}

M1_MagicClaw::~M1_MagicClaw()
{
}

float M1_MagicClaw::UseSkill(const float iStat)
{
	// 데미지 처리공식을 커스텀하게 처리할 수 있음

	return MagicClaw(iStat);
}
