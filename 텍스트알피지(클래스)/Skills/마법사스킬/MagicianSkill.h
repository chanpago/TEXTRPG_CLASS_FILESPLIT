#pragma once
#include "pch.h"
#include "Skill.h"


class MagicianSkill : public Skill
{
public:
	MagicianSkill();
	virtual ~MagicianSkill();

	void Initialize();
	void Update();
	void Release();

};


