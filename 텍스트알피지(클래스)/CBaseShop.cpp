#include "pch.h"
#include "CBaseShop.h"
#include "CBaseWeapon.h"
#include "CBaseArmor.h"

CBaseShop::CBaseShop() : m_pWeapon(nullptr), m_pArmor(nullptr)
{
}

CBaseShop::~CBaseShop()
{
	Release();
}

void CBaseShop::Release()
{
	SAFE_DELETE(m_pWeapon);
	SAFE_DELETE(m_pArmor);
}

