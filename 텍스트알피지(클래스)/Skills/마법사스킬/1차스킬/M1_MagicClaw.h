#pragma once
#include "pch.h"
#include "W0_BasicSkill.h"

class M1_MagicClaw : public W0_BasicSkill
{
public:
	M1_MagicClaw();
	~M1_MagicClaw();

	float						UseSkill(const float iStat);

private:
	M1_MagicClaw(const M1_MagicClaw&);
	M1_MagicClaw& operator=(const M1_MagicClaw&);

private:
	inline float MagicClaw(const float iStat) { return iStat + 1.5f * static_cast<float>(GetSkillPoint()); }
};


