#include "CPlayerInventory.h"
#include "CBaseThing.h"

CPlayerInventory::CPlayerInventory() : m_iInventorySize(0)
{
}

CPlayerInventory::~CPlayerInventory()
{
}

void CPlayerInventory::Initialize()
{
}

void CPlayerInventory::Update()
{
}




// �κ��丮 ���� ��
// �������� �����ε� �ʿ�
/*
void CPlayerInventory::Update(std::shared_ptr<CBaseThing> CItem, const int iItemtype, const int iUniqueNum)
{

	for (auto& Item : m_Inventory)
	{
		// ��� ���� ������ �������� ������ ��
		if ((1 != iItemtype) && (Item.first->GetUniqueNum() == iUniqueNum))
		{
			Item.second++;
			return;
		}	
	}
	m_Inventory.insert({ CItem,1 });
}
*/
void CPlayerInventory::Update(std::shared_ptr<CBaseThing> CItem, const int iItemtype, const int iUniqueNum)
{
	for (int i = 0; i < m_iInventorySize; ++i)
	{
		// ��� ���� ������ �������� ������ ��
		if ((1 != iItemtype) && (m_Inventory[i].first->GetUniqueNum() == iUniqueNum))
		{
			m_Inventory[i].second++;
			return;
		}
	}
	m_Inventory[m_iInventorySize].first = CItem;
	m_Inventory[m_iInventorySize].second++;
	m_iInventorySize++;
		
}


void CPlayerInventory::Release()
{

}

void CPlayerInventory::Render()
{
	std::cout << "=================�κ��丮===============" << std::endl;

	for (int i = 0; i < m_iInventorySize; ++i)
	{
		std::cout << m_Inventory[i].first->GetName() << " " << m_Inventory[i].second << "EA" << std::endl;
		m_Inventory[i].first->Render();
	}
	/*
	for (auto Item : m_Inventory)
	{
		std::cout << Item.first->GetName() << " " << Item.second << "EA" << std::endl;
		Item.first->Render();
	}
	*/
	std::cout << "========================================" << std::endl;
}
