#pragma once
#include "pch.h"
#include "W0_BasicSkill.h"


class W1_PowerStrike : public W0_BasicSkill
{
public:
	W1_PowerStrike();
	~W1_PowerStrike();

	float						UseSkill(const float iStat);

private:
	W1_PowerStrike(const W1_PowerStrike&);
	W1_PowerStrike& operator=(const W1_PowerStrike&);

private:
	inline float PowerStrike(const float iStat) { return iStat + 1.5f * static_cast<float>(GetSkillPoint()); }

};

