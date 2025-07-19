#pragma once
#include "Define.h"
#include "CBaseThing.h"

class CBasePotion : public CBaseThing
{
public:
	CBasePotion() {};
	virtual ~CBasePotion() {};

	CBasePotion(const CBasePotion& Potion);

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Render();
	virtual void Release();
	

	// getter
	inline POTIONINFO**		GetPotionInfo()					{ return &m_pPotionInfo;}
	int						GetType()const override			{ return m_pPotionInfo->iType; }
	int						GetUniqueNum() const override   { return m_pPotionInfo->iUniqueNumber; }
	int						GetPrice()const	override		{ return m_pPotionInfo->iPrice; }
	std::string				GetName() const	override		{ return m_pPotionInfo->sName; }
	int						GetValue()const	override		{ return m_pPotionInfo->iValue; }


	// setter
	inline void SetPotion(POTIONINFO* PotionInfo) { m_pPotionInfo = PotionInfo; }

protected:
	POTIONINFO* m_pPotionInfo{};
};
