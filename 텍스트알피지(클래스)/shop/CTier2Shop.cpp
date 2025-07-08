#include "CTier2Shop.h"

#include "CBaseThing.h"
#include "무기/CTier2Weapon.h"
#include "방어구/CTier2Armor.h"
#include "포션/CTier2Potion.h"
#include "Buy/CBehave_Buy.h"
#include "Player/CPlayer.h"

CTier2Shop::CTier2Shop() : BuyItem(nullptr)
{
}

CTier2Shop::~CTier2Shop()
{
	Release();
}

void CTier2Shop::Initialize()
{
	ItemList.insert(std::make_pair(new CTier2Weapon, 1));
	ItemList.insert(std::make_pair(new CTier2Armor, 1));
	ItemList.insert(std::make_pair(new CTier2Potion, 10));

	for (auto Item : ItemList)
	{
		Item.first->Initialize();
	}

	BuyItem = new CBehave_Buy;
}

void CTier2Shop::Update(CPlayer* player)
{
	int iInput(0);
	int ItemListSize = ItemList.size();

	while (true)
	{
		system("cls");
		player->Render();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "=================중급상점===============" << std::endl;
		Render();
		std::cout << "몇번째 물품을 사시겠습니까? (0. 나가기) : ";
		std::cin >> iInput;

		if (iInput == 0) break;
		else if (iInput > ItemListSize)
		{
			std::cout << "잘못 누르셨습니다" << std::endl;
		}
		else
		{
			auto it = ItemList.begin();
			for (int i = 0; i < iInput - 1; ++i)
			{
				++it;
			}
			if (it->second <= 0)
			{
				std::cout << "수량이 부족합니다.." << std::endl;
				system("pause");
			}
			else if (BuyItem->Buy(player, it->first))
			{
				it->second--;
			}
		}
	}
}

void CTier2Shop::Release()
{
	SAFE_DELETE(BuyItem);
}

void CTier2Shop::Render()
{
	int iNum = 1;
	for (auto Item : ItemList)
	{
		std::cout << iNum++ << " " << "번째 물품     " << " 수량 : " << Item.second << std::endl;
		Item.first->Render();
	}
}


