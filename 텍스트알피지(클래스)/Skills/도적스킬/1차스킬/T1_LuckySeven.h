#pragma once
#include "pch.h"
#include "W0_BasicSkill.h"

class T1_LuckySeven : public W0_BasicSkill
{
public:
	T1_LuckySeven();
	~T1_LuckySeven();

	float						UseSkill(const float iStat);

private:
	T1_LuckySeven(const T1_LuckySeven&);
	T1_LuckySeven& operator=(const T1_LuckySeven&);

private:
	inline float LuckySeven(const float iStat) { return iStat + 1.5f * static_cast<float>(GetSkillPoint()); }


};



