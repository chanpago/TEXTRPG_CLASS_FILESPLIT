#pragma once
#include "pch.h"
#include "CObject.h"
#include "Define.h"
#include "Skill.h"

class W0_BasicSkill;
class CPlayerInventory;
class CEquipmentInventory;




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
	bool						Initialize(); // ��� ������ �� �ʱ�ȭ �Լ�
	void						Update(const int iType, const int iNum);
	void						Release();
	void						Render() const;

	//void						Load();
	//bool						Save();

	void						CreateSkill(const int iNum);
	void						AddEXP(const int iNum);
	void						LevelUP();
	inline void					Die() const { std::cout << "�÷��̾ �׾����ϴ�! " << std::endl; }
	void						AddStat(const int iType);
	void						CalcAttackValue();


	// getter
	inline const int			GetSkillsCount() const		{ return m_pPlayerInfo->pSkills->GetSkillCount(); }
	inline Skill*				GetSkills() const			{ return m_pPlayerInfo->pSkills; }
	inline W0_BasicSkill*		GetSkill(const int iNum)	{ return (*GetSkills())[iNum]; }
	inline int					GetMoney()const				{ return m_pPlayerInfo->iMoney; }
	inline CPlayerInventory*	GetInventory()const			{ return m_pPlayerInventory; }
	inline CEquipmentInventory* GetEquipInventory()const	{ return m_pEquipmentInventory; }
	inline int					GetMAXHP()					{ return m_pObject->iMaxHealthValue; }

	// setter
	inline void					SetEXP(const int iNum)			{ m_pObject->iNowEXP = iNum; }
	inline void					SetMoney(const int iNewMoney)   { m_pPlayerInfo->iMoney = iNewMoney; }
	void						SetPlayerInfo();
	void						SetPlayerInven();
	void						SetPlayerEquipInven();
	void						SetStat();



	

private:
	CPlayer(const CPlayer&);
	CPlayer& operator=(const CPlayer&);

private:
	PLAYERINFO* m_pPlayerInfo{};
	CEquipmentInventory* m_pEquipmentInventory{};
	CPlayerInventory* m_pPlayerInventory{};


};


