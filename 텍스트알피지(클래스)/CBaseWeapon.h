#pragma once
#include "pch.h"
#include "Define.h"
#include "CBaseThing.h"

class CBaseWeapon : public CBaseThing
{
public:
	CBaseWeapon();
	virtual ~CBaseWeapon();

public:
	virtual void Initialize();
	virtual void Update();
	virtual void Release();



	inline void SetWeapon(WEAPONINFO* WeaponInfo) {
		m_pWeaponInfo = WeaponInfo;
	}

	inline WEAPONINFO** GetWeaponInfo()
	{
		return &m_pWeaponInfo;
	}
	int GetType()const { return m_pWeaponInfo->iType; }
	int GetUniqueNum() const { return m_pWeaponInfo->iUniqueNumber; }
	int GetPrice()const { return m_pWeaponInfo->iPrice; }
	std::string GetName() const { return m_pWeaponInfo->sName; }
	int GetValue()const { return m_pWeaponInfo->iAttackValue; }
private:
	WEAPONINFO* m_pWeaponInfo;
};

