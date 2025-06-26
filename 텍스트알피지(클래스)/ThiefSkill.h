#pragma once
#include "pch.h"
#include "Skill.h"

class ThiefSkill : public Skill
{
public:

	ThiefSkill();
	 ~ThiefSkill();

	void Initialize();
	void Update();
	void Release();
};


