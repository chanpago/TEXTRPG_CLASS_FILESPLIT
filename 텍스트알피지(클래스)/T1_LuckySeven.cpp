#include "pch.h"
#include "T1_LuckySeven.h"

T1_LuckySeven::T1_LuckySeven() : W0_BasicSkill("��Ű ����") {}


T1_LuckySeven::~T1_LuckySeven()
{
}

float T1_LuckySeven::UseSkill(const float iStat)
{
	// ������ ó�������� Ŀ�����ϰ� ó���� �� ����

	return LuckySeven(iStat);
}
