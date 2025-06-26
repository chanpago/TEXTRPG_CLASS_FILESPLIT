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
		���� = 1,
		������,
		����,
		�ҷ�����,
		������
	};

	enum SKILLCLASSIFICATION
	{
		���� = 1,
		������,
		HPȸ��,
		MPȸ��
	};

public:
	bool					Initialize(); // ��� ������ �� �ʱ�ȭ �Լ�
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

