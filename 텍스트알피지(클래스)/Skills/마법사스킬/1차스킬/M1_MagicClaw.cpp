#include "pch.h"
#include "M1_MagicClaw.h"

M1_MagicClaw::M1_MagicClaw() : W0_BasicSkill("���� Ŭ��") {}

M1_MagicClaw::~M1_MagicClaw()
{
}

float M1_MagicClaw::UseSkill(const float iStat)
{
	// ������ ó�������� Ŀ�����ϰ� ó���� �� ����

	return MagicClaw(iStat);
}
