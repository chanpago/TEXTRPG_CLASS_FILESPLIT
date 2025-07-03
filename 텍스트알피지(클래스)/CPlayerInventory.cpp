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

void CPlayerInventory::Release()
{

}

void CPlayerInventory::Render()
{
	std::cout << "=================�κ��丮===============" << std::endl;
	for (auto Item : m_Inventory)
	{
		std::cout << Item.first->GetName() << " " << Item.second << "EA" << std::endl;
		Item.first->Render();
	}
	std::cout << "========================================" << std::endl;
}
