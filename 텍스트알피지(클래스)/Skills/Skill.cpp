#include "Skill.h"
#include "W0_BasicSkill.h"

Skill::Skill()
{
}

Skill::~Skill()
{
	Release();
}

void Skill::Release()
{
	for (auto ObjectSkill : ObjectSkills)
	{
		SAFE_DELETE(ObjectSkill);
	}
}

const W0_BasicSkill* Skill::operator[](const int iNum) const
{
	return ObjectSkills[iNum];
}

W0_BasicSkill* Skill::operator[](const int iNum)
{
	return ObjectSkills[iNum];
}
