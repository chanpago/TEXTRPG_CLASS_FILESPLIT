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

// 인벤토리 들어올 때
// 나갈때도 오버로딩 필요
void CPlayerInventory::Update(std::shared_ptr<CBaseThing> CItem, const int iItemtype, const int iUniqueNum)
{

	for (auto& Item : m_Inventory)
	{
		// 장비 말고 동일한 아이템이 들어왔을 때
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
	std::cout << "=================인벤토리===============" << std::endl;
	for (auto Item : m_Inventory)
	{
		std::cout << Item.first->GetName() << " " << Item.second << "EA" << std::endl;
		Item.first->Render();
	}
	std::cout << "========================================" << std::endl;
}
