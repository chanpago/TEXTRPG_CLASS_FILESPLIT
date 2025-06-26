#pragma once
#include "pch.h"
#include "Skill.h"

class W0_BasicSkill;

class WarriorSkill : public Skill
{
public:
	WarriorSkill();
	virtual ~WarriorSkill();

	void Initialize();
	void Update();
	void Release();

};

