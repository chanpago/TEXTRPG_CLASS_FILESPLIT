#pragma once
#include "pch.h"

class W0_BasicSkill;

class Skill
{
public:

	Skill();
	virtual ~Skill();

public:
	void Initialize();
	void Update();
	void Release();


	inline void AddSkill(W0_BasicSkill* pObjectSkill) { ObjectSkills.push_back(pObjectSkill); }

	inline const std::vector< W0_BasicSkill*> GetSkills()const { return ObjectSkills; };

	inline const int GetSkillCount() const { return ObjectSkills.size(); }

	const W0_BasicSkill* operator[] (const int iNum) const ;
	W0_BasicSkill* operator[] (const int iNum);

protected:
	std::vector<W0_BasicSkill*> ObjectSkills;
};

