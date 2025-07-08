#include "pch.h"
#include "T1_LuckySeven.h"

T1_LuckySeven::T1_LuckySeven() : W0_BasicSkill("럭키 세븐") {}


T1_LuckySeven::~T1_LuckySeven()
{
}

float T1_LuckySeven::UseSkill(const float iStat)
{
	// 데미지 처리공식을 커스텀하게 처리할 수 있음

	return LuckySeven(iStat);
}
