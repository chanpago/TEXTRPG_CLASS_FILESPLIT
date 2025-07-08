#include "pch.h"
#include "CBehave_ItemUse.h"
#include "Player/CPlayer.h"
#include "ItemInventory/CPlayerInventory.h"
#include "EquipmentInventory/CEquipmentInventory.h"
#include "����/CTier3Potion.h"
#include "CBaseThing.h"

CBehave_ItemUse::CBehave_ItemUse()
{
}

CBehave_ItemUse::~CBehave_ItemUse()
{
}

void CBehave_ItemUse::Initialize()
{
}

void CBehave_ItemUse::Update()
{
}

void CBehave_ItemUse::Release()
{
}

void CBehave_ItemUse::UseItem(CPlayer* player)
{
	int iInput(0);

	

	while (true)
	{
		system("cls");
		player->Render();
		std::cout << "����� ������ ��ȣ�� �Է����ּ��� (0.������) : ";
		std::cin >> iInput;

		if (iInput == 0)break;
		else
		{
			CPlayerInventory* playerinventory = player->GetInventory();
			std::unordered_map<std::shared_ptr < CBaseThing>, int>* inventory = playerinventory->GetInventory();

			auto it = inventory->begin();
			iInput -= 1;

			for (int i = 0; i < iInput; ++i) it++;

			//iNum��° ������ ����

			std::shared_ptr<CBaseThing> item = it->first;
			int itemCount = it->second;

			// �̸�, ����, ���, Ÿ��, ȸ����, ������ȣ

			//����
			if (item->GetUniqueNum() < 10)
			{
				if (itemCount > 0)
				{
					int PlayerNowHP = player->GetObjectHP();
					PlayerNowHP += item->GetValue();
					PlayerNowHP > player->GetMAXHP() ? PlayerNowHP = player->GetMAXHP() : PlayerNowHP;
					player->SetObjectHP(PlayerNowHP);

					if (itemCount == 1)
					{
						inventory->erase(it);
					}
					else
					{
						it->second--;
					}
				}
			}
			//����
			else if (item->GetUniqueNum() < 20)
			{
				CEquipmentInventory* playerEquipInven = player->GetEquipInventory();

				// ���Ⱑ �̹� �ִٸ�
				if (playerEquipInven->IsWeapon())
				{
					std::shared_ptr<CBaseThing> Weapon = playerEquipInven->GetWeapon();

					//�κ��丮���� ����
					playerinventory->GetInventory()->erase(it);


					player->SetObjectATK(player->GetObjectATK() - Weapon->GetValue());

					//���� ���� �ִ� ����, �κ��丮�� ������Ʈ
					playerinventory->Update(Weapon, Weapon->GetType(), Weapon->GetUniqueNum());

					//��� ���ο� ���� ���
					playerEquipInven->SetWeapon(item);


					player->SetObjectATK(player->GetObjectATK() + item->GetValue());

				}
				else
				{
					player->SetObjectATK(player->GetObjectATK() + item->GetValue());
					playerEquipInven->SetWeapon(item);

					//�κ��丮���� ����
					playerinventory->GetInventory()->erase(it);
				}
				
			}
			// ��
			else if (item->GetUniqueNum() < 30)
			{
				CEquipmentInventory* playerEquipInven = player->GetEquipInventory();

				// ���� �̹� �ִٸ�
				if (playerEquipInven->IsArmor())
				{
					std::shared_ptr<CBaseThing> Armor = playerEquipInven->GetArmor();

					//�κ��丮���� ����
					playerinventory->GetInventory()->erase(it);

					//���� ���� �ִ� ��, �κ��丮�� ������Ʈ
					playerinventory->Update(Armor, Armor->GetType(), Armor->GetUniqueNum());

					//��� ���ο� �� ���
					playerEquipInven->SetArmor(item);
				}
				else
				{
					playerEquipInven->SetArmor(item);

					//�κ��丮���� ����
					playerinventory->GetInventory()->erase(it);
				}
			}
		}
	}

	


}

