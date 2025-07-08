#include "CTier3Weapon.h"

CTier3Weapon::CTier3Weapon()
{
}

CTier3Weapon::~CTier3Weapon()
{

}

void CTier3Weapon::Initialize()
{
	// 이름, 가격, 등급, 타입, 공격량, 고유번호
	SetWeapon(new WEAPONINFO("초급 무기", 500, 3, 1, 10, 10));
}

void CTier3Weapon::Update()
{

}

void CTier3Weapon::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "이름 : " << (*GetWeaponInfo())->sName << std::endl;
	std::cout << "가격 : " << (*GetWeaponInfo())->iPrice << std::endl;
	std::cout << "티어 : " << (*GetWeaponInfo())->iTier << std::endl;
	std::cout << "공격력 :" << (*GetWeaponInfo())->iAttackValue << std::endl;
	std::cout << "========================================" << std::endl;
}
