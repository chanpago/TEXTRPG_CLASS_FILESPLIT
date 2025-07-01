#include "CTier3Weapon.h"

CTier3Weapon::CTier3Weapon()
{
}

CTier3Weapon::~CTier3Weapon()
{
	std::cout << "티어3 무기 소멸" << std::endl;
}

void CTier3Weapon::Initialize()
{
	SetWeapon(new WEAPONINFO(500, 3, 1));
}

void CTier3Weapon::Update()
{

}

void CTier3Weapon::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "티어 " << (*GetWeaponInfo())->iTier << " ";
	
	switch ((*GetWeaponInfo())->iType)
	{
	case 1:
		std::cout << "기본 무기" << std::endl;
		break;
	default:
		std::cout << "오류무기";
		break;
	}
	std::cout << "가격 : " << (*GetWeaponInfo())->iPrice << std::endl;
	std::cout << "========================================" << std::endl;
	
}
