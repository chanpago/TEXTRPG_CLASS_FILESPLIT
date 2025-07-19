#include "CTier2Weapon.h"

CTier2Weapon::CTier2Weapon()
{
}

CTier2Weapon::~CTier2Weapon()
{
	Release();
}

void CTier2Weapon::Initialize()
{
	// 이름, 가격, 등급, 타입, 공격량, 고유번호
	SetWeapon(new WEAPONINFO("중급 무기", 1000, 2, 1, 20, 11));
}

void CTier2Weapon::Update()
{
}

void CTier2Weapon::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "이름 : " << m_pWeaponInfo->sName << std::endl;
	std::cout << "가격 : " << m_pWeaponInfo->iPrice << std::endl;
	std::cout << "티어 : " << m_pWeaponInfo->iTier << std::endl;
	std::cout << "공격력 :" << m_pWeaponInfo->iAttackValue << std::endl;
	std::cout << "========================================" << std::endl;
}

void CTier2Weapon::Release()
{
	SAFE_DELETE(m_pWeaponInfo);
}
