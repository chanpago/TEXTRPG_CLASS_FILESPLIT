#include "CTier2Weapon.h"

CTier2Weapon::CTier2Weapon()
{
}

CTier2Weapon::~CTier2Weapon()
{
}

void CTier2Weapon::Initialize()
{
	// �̸�, ����, ���, Ÿ��, ���ݷ�, ������ȣ
	SetWeapon(new WEAPONINFO("�߱� ����", 1000, 2, 1, 20, 11));
}

void CTier2Weapon::Update()
{
}

void CTier2Weapon::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "�̸� : " << (*GetWeaponInfo())->sName << std::endl;
	std::cout << "���� : " << (*GetWeaponInfo())->iPrice << std::endl;
	std::cout << "Ƽ�� : " << (*GetWeaponInfo())->iTier << std::endl;
	std::cout << "���ݷ� :" << (*GetWeaponInfo())->iAttackValue << std::endl;
	std::cout << "========================================" << std::endl;
}
