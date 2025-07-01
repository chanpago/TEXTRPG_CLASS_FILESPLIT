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


	inline void SetArmor(ARMORINFO* ArmorInfo) {
		m_pArmorInfo = ArmorInfo;
	}
	
	inline ARMORINFO** GetArmorInfo()
	{
		return &m_pArmorInfo;
	}
private:
	ARMORINFO* m_pArmorInfo;

};

