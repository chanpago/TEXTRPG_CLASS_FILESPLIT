#include "pch.h"
#include "CBehave_Unequip.h"
#include "Player/CPlayer.h"
#include "ItemInventory/CPlayerInventory.h"
#include "EquipmentInventory/CEquipmentInventory.h"

#include "CBaseThing.h"

CBehave_Unequip::CBehave_Unequip()
{
}

CBehave_Unequip::~CBehave_Unequip()
{
}

void CBehave_Unequip::Initialize()
{
}

void CBehave_Unequip::Update()
{
}

void CBehave_Unequip::Release()
{
}

void CBehave_Unequip::UnEquipment(CPlayer* player)
{
	int iInput(0);
	while (true)
	{
		system("cls");
		player->Render();
		std::cout << "장착 해제할 장비를 선택해주세요 0. 나가기 1. 장비 2. 방어구 :";
		std::cin >> iInput;

		switch (iInput)
		{
		case 0:
			return;
		case 1:
			if (player->GetEquipInventory()->IsWeapon())
			{
				if (player->GetInventory()->GetInventorySize() == 5)
				{
					std::cout << "인벤토리가 꽉 찼습니다 인벤토리를 비워주세요!" << std::endl;
				}
				else
				{
					std::shared_ptr<CBaseThing> CItem = player->GetEquipInventory()->GetWeapon();

					//여기서 인벤토리에 추가					
					player->GetInventory()->Update(CItem, CItem->GetType(), CItem->GetUniqueNum());

					player->GetEquipInventory()->SetWeapon(nullptr);
				}
			}
			else
			{
				std::cout << "장비가 없습니다!" << std::endl;
			}
			break;

		case 2:
			if (player->GetEquipInventory()->IsArmor())
			{
				if (player->GetInventory()->GetInventorySize() == 5)
				{
					std::cout << "인벤토리가 꽉 찼습니다 인벤토리를 비워주세요!" << std::endl;
				}
				else
				{
					std::shared_ptr<CBaseThing> CItem = player->GetEquipInventory()->GetArmor();

					//여기서 인벤토리에 추가					
					player->GetInventory()->Update(CItem, CItem->GetType(), CItem->GetUniqueNum());

					player->GetEquipInventory()->SetArmor(nullptr);
				}
			}
			else
			{
				std::cout << "방어구가 없습니다!" << std::endl;
			}
			break;

		default:
			std::cout << "잘 못 입력하셨습니다!" << std::endl;
			break;
		}

	}
}
