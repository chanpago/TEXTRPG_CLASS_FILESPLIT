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
	bool						Initialize(); // 멤버 변수의 값 초기화 함수
	void						Update(const int iType, const int iNum);
	void						Release();
	void						Render() const;

	//void						Load();
	//bool						Save();

	void						CreateSkill(const int iNum);
	void						AddEXP(const int iNum);
	void						LevelUP();
	inline void					Die() const { std::cout << "플레이어가 죽었습니다! " << std::endl; }
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


