#include "CTier3Weapon.h"

CTier3Weapon::CTier3Weapon()
{
}

CTier3Weapon::~CTier3Weapon()
{

}

void CTier3Weapon::Initialize()
{
	// �̸�, ����, ���, Ÿ��, ���ݷ�, ������ȣ
	SetWeapon(new WEAPONINFO("�ʱ� ����", 500, 3, 1, 10, 10));
}

void CTier3Weapon::Update()
{

}

void CTier3Weapon::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "�̸� : " << (*GetWeaponInfo())->sName << std::endl;
	std::cout << "���� : " << (*GetWeaponInfo())->iPrice << std::endl;
	std::cout << "Ƽ�� : " << (*GetWeaponInfo())->iTier << std::endl;
	std::cout << "���ݷ� :" << (*GetWeaponInfo())->iAttackValue << std::endl;
	std::cout << "========================================" << std::endl;
}
