#include "CTier3Weapon.h"

CTier3Weapon::CTier3Weapon()
{
}

CTier3Weapon::~CTier3Weapon()
{
	Release();
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
	std::cout << "�̸� : " << m_pWeaponInfo->sName << std::endl;
	std::cout << "���� : " << m_pWeaponInfo->iPrice << std::endl;
	std::cout << "Ƽ�� : " << m_pWeaponInfo->iTier << std::endl;
	std::cout << "���ݷ� :" << m_pWeaponInfo->iAttackValue << std::endl;
	std::cout << "========================================" << std::endl;
}

void CTier3Weapon::Release()
{
	SAFE_DELETE(m_pWeaponInfo);
}
