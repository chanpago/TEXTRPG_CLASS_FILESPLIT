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

private:
	WEAPONINFO* m_pWeaponInfo;
};

