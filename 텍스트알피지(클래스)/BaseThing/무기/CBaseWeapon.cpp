#include "CBaseWeapon.h"

CBaseWeapon::CBaseWeapon() : m_pWeaponInfo(nullptr)
{

}

CBaseWeapon::~CBaseWeapon()
{
	Release();
}

void CBaseWeapon::Initialize()
{
}

void CBaseWeapon::Update()
{
}

void CBaseWeapon::Release()
{
	SAFE_DELETE(m_pWeaponInfo);
}
