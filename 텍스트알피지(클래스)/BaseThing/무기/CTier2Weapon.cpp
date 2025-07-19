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
	// �̸�, ����, ���, Ÿ��, ���ݷ�, ������ȣ
	SetWeapon(new WEAPONINFO("�߱� ����", 1000, 2, 1, 20, 11));
}

void CTier2Weapon::Update()
{
}

void CTier2Weapon::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "�̸� : " << m_pWeaponInfo->sName << std::endl;
	std::cout << "���� : " << m_pWeaponInfo->iPrice << std::endl;
	std::cout << "Ƽ�� : " << m_pWeaponInfo->iTier << std::endl;
	std::cout << "���ݷ� :" << m_pWeaponInfo->iAttackValue << std::endl;
	std::cout << "========================================" << std::endl;
}

void CTier2Weapon::Release()
{
	SAFE_DELETE(m_pWeaponInfo);
}
