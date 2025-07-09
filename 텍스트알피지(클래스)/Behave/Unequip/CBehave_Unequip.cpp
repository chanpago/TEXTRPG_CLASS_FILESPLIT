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
		std::cout << "���� ������ ��� �������ּ��� 0. ������ 1. ��� 2. �� :";
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
					std::cout << "�κ��丮�� �� á���ϴ� �κ��丮�� ����ּ���!" << std::endl;
				}
				else
				{
					std::shared_ptr<CBaseThing> CItem = player->GetEquipInventory()->GetWeapon();

					//���⼭ �κ��丮�� �߰�					
					player->GetInventory()->Update(CItem, CItem->GetType(), CItem->GetUniqueNum());

					player->GetEquipInventory()->SetWeapon(nullptr);
				}
			}
			else
			{
				std::cout << "��� �����ϴ�!" << std::endl;
			}
			break;

		case 2:
			if (player->GetEquipInventory()->IsArmor())
			{
				if (player->GetInventory()->GetInventorySize() == 5)
				{
					std::cout << "�κ��丮�� �� á���ϴ� �κ��丮�� ����ּ���!" << std::endl;
				}
				else
				{
					std::shared_ptr<CBaseThing> CItem = player->GetEquipInventory()->GetArmor();

					//���⼭ �κ��丮�� �߰�					
					player->GetInventory()->Update(CItem, CItem->GetType(), CItem->GetUniqueNum());

					player->GetEquipInventory()->SetArmor(nullptr);
				}
			}
			else
			{
				std::cout << "���� �����ϴ�!" << std::endl;
			}
			break;

		default:
			std::cout << "�� �� �Է��ϼ̽��ϴ�!" << std::endl;
			break;
		}

	}
}
