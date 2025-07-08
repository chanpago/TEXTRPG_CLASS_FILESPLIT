#include "CTier2Shop.h"

#include "CBaseThing.h"
#include "����/CTier2Weapon.h"
#include "��/CTier2Armor.h"
#include "����/CTier2Potion.h"
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
		std::cout << "=================�߱޻���===============" << std::endl;
		Render();
		std::cout << "���° ��ǰ�� ��ðڽ��ϱ�? (0. ������) : ";
		std::cin >> iInput;

		if (iInput == 0) break;
		else if (iInput > ItemListSize)
		{
			std::cout << "�߸� �����̽��ϴ�" << std::endl;
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
				std::cout << "������ �����մϴ�.." << std::endl;
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
		std::cout << iNum++ << " " << "��° ��ǰ     " << " ���� : " << Item.second << std::endl;
		Item.first->Render();
	}
}


