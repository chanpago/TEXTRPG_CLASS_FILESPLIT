#pragma once
#include "pch.h"
#include "CObject.h"
#include "Define.h"
#include "Skill.h"

class W0_BasicSkill;

class CPlayer : public CObject
{
public:
	CPlayer();
	~CPlayer();

public:
	enum JOBCHOICE
	{
		전사 = 1,
		마법사,
		도적,
		불러오기,
		나가기
	};

	enum SKILLCLASSIFICATION
	{
		공격 = 1,
		데미지,
		HP회복,
		MP회복
	};

public:
	bool					Initialize(); // 멤버 변수의 값 초기화 함수
	void					Update(const int iType, const int iNum);
	void					Release();
	void					Render() const;

	void					Load();
	bool					Save();
	void					CreateSkill(const int iNum);

	inline const int		GetSkillsCount() const		{ return Skills->GetSkillCount(); }
	inline Skill*			GetSkills() const			{ return Skills; }
	inline W0_BasicSkill*	GetSkill(const int iNum)	{ return (*GetSkills())[iNum]; }

private:
	Skill* Skills;

};

