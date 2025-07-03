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

	std::cout << "==================장비=================" << std::endl;

	if (m_pWeapon && m_pArmor)
	{
		std::cout << "무기 : " << m_pWeapon->GetName() << std::endl;
		std::cout << "방어구 : " << m_pArmor->GetName() << std::endl;
	}
	else if (m_pWeapon && !m_pArmor)
	{
		std::cout << "무기 : " << m_pWeapon->GetName() << std::endl;
		std::cout << "방어구 : 없음" << std::endl;
	}
	else if (!m_pWeapon && m_pArmor)
	{
		std::cout << "무기 : 없음" << std::endl;
		std::cout << "방어구 : " << m_pArmor->GetName() << std::endl;
	}
	else
	{
		std::cout << "무기 : 없음" << std::endl;
		std::cout << "방어구 : 없음" << std::endl;
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
