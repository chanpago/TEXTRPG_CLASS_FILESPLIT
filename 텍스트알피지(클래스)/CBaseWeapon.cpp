#include "CBaseWeapon.h"

CBaseWeapon::CBaseWeapon() : m_pWeaponInfo(nullptr)
{

}

CBaseWeapon::~CBaseWeapon()
{
	std::cout << "베이스 무기 소멸" << std::endl;
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
