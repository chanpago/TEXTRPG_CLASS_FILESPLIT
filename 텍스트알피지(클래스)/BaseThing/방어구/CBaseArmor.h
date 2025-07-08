#pragma once
#include "pch.h"
#include "Define.h"
#include "CBaseThing.h"

class CBaseArmor : public CBaseThing
{
public:
	CBaseArmor();
	virtual ~CBaseArmor();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Release();
	
	// getter
	inline ARMORINFO**		GetArmorInfo()			{ return &m_pArmorInfo;}
	int						GetType()const			{ return m_pArmorInfo->iType; }
	int						GetUniqueNum() const	{ return m_pArmorInfo->iUniqueNumber; }
	int						GetPrice()const			{ return m_pArmorInfo->iPrice; }
	std::string				GetName() const			{ return m_pArmorInfo->sName; }
	int						GetValue()const			{ return m_pArmorInfo->iArmorRate; }

	// setter
	inline void				SetArmor(ARMORINFO* ArmorInfo) { m_pArmorInfo = ArmorInfo; }

private:
	ARMORINFO* m_pArmorInfo;

};

