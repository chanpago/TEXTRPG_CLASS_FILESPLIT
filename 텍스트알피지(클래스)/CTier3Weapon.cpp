#include "CTier3Weapon.h"

CTier3Weapon::CTier3Weapon()
{
}

CTier3Weapon::~CTier3Weapon()
{
	std::cout << "Ƽ��3 ���� �Ҹ�" << std::endl;
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
	std::cout << "Ƽ�� " << (*GetWeaponInfo())->iTier << " ";
	
	switch ((*GetWeaponInfo())->iType)
	{
	case 1:
		std::cout << "�⺻ ����" << std::endl;
		break;
	default:
		std::cout << "��������";
		break;
	}
	std::cout << "���� : " << (*GetWeaponInfo())->iPrice << std::endl;
	std::cout << "========================================" << std::endl;
	
}
