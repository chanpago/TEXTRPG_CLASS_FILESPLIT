#include "CTier2Weapon.h"

CTier2Weapon::CTier2Weapon()
{
}

CTier2Weapon::~CTier2Weapon()
{
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
	std::cout << "이름 : " << (*GetWeaponInfo())->sName << std::endl;
	std::cout << "가격 : " << (*GetWeaponInfo())->iPrice << std::endl;
	std::cout << "티어 : " << (*GetWeaponInfo())->iTier << std::endl;
	std::cout << "공격력 :" << (*GetWeaponInfo())->iAttackValue << std::endl;
	std::cout << "========================================" << std::endl;
}
