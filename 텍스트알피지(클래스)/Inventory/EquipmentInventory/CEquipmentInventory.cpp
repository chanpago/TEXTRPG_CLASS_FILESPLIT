#include "CEquipmentInventory.h"
#include "CBaseThing.h"

CEquipmentInventory::CEquipmentInventory()
{
}

CEquipmentInventory::~CEquipmentInventory()
{
}

void CEquipmentInventory::Initialize()
{
}

void CEquipmentInventory::Update()
{
}

void CEquipmentInventory::Release()
{

}

void CEquipmentInventory::Render()
{

	std::cout << "==================���=================" << std::endl;

	if (m_pWeapon && m_pArmor)
	{
		std::cout << "���� : " << m_pWeapon->GetName() << std::endl;
		std::cout << "�� : " << m_pArmor->GetName() << std::endl;
	}
	else if (m_pWeapon && !m_pArmor)
	{
		std::cout << "���� : " << m_pWeapon->GetName() << std::endl;
		std::cout << "�� : ����" << std::endl;
	}
	else if (!m_pWeapon && m_pArmor)
	{
		std::cout << "���� : ����" << std::endl;
		std::cout << "�� : " << m_pArmor->GetName() << std::endl;
	}
	else
	{
		std::cout << "���� : ����" << std::endl;
		std::cout << "�� : ����" << std::endl;
	}
	
	
	std::cout << "========================================" << std::endl;
}

bool CEquipmentInventory::IsWeapon() const
{
	if (m_pWeapon) return true;
	return false;
}
bool CEquipmentInventory::IsArmor() const
{
	if (m_pArmor) return true;
	return false;
}
