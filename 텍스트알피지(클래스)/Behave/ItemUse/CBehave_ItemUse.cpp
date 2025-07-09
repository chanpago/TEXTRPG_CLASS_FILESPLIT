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
			std::vector<std::pair<std::shared_ptr<CBaseThing>, int>>* inventory = (playerinventory->GetInventory());

			auto it = inventory->begin();
			auto itEnd = inventory->end() - 1;
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
					std::shared_ptr<CBaseThing> BeforeWeapon = playerEquipInven->GetWeapon();

					//2.��� ��ü
					it->first = BeforeWeapon;
					it->second = 1;
					player->SetObjectATK(player->GetObjectATK() - BeforeWeapon->GetValue());

					//3. ��� ���ε�
					playerEquipInven->SetWeapon(item);
					player->SetObjectATK(player->GetObjectATK() + item->GetValue());

				}
				else
				{
					player->SetObjectATK(player->GetObjectATK() + item->GetValue());
					playerEquipInven->SetWeapon(item);

					//�κ��丮���� ����
					// erase�ϸ� ������ ����� �پ��
					// �׳� it��ġ�� null�ϴ°� ������
					it->first = nullptr;
					it->second = 0;



					// ���⼭ �����ִ� �۾� + size���̱�
					int i = iInput;
					auto Nextit = it;
					for (; i < playerinventory->GetInventorySize() - 1; ++i)
					{
						++Nextit;
						it->first = Nextit->first;
						it->second = Nextit->second;
					}
				

					// ��������� ����
					Nextit->first = nullptr;
					Nextit->second = 0;

					playerinventory->SetGetInventorySize(playerinventory->GetInventorySize() - 1);
				}
				
			}
			// ��
			else if (item->GetUniqueNum() < 30)
			{
				CEquipmentInventory* playerEquipInven = player->GetEquipInventory();

				// ���� �̹� �ִٸ�
				if (playerEquipInven->IsArmor())
				{
					std::shared_ptr<CBaseThing> BeforeArmor = playerEquipInven->GetArmor();

					//2.��� ��ü
					it->first = BeforeArmor;
					it->second = 1;

					//3. ��� ���ε�
					playerEquipInven->SetArmor(item);

				}
				else
				{			
					playerEquipInven->SetArmor(item);

					//�κ��丮���� ����
					// erase�ϸ� ������ ����� �پ��
					// �׳� it��ġ�� null�ϴ°� ������
					it->first = nullptr;
					it->second = 0;



					// ���⼭ �����ִ� �۾� + size���̱�
					int i = iInput;
					auto Nextit = it;
					for (; i < playerinventory->GetInventorySize() - 1; ++i)
					{
						++Nextit;
						it->first = Nextit->first;
						it->second = Nextit->second;
					}


					// ��������� ����
					Nextit->first = nullptr;
					Nextit->second = 0;

					playerinventory->SetGetInventorySize(playerinventory->GetInventorySize() - 1);
				}
			}
		}
	}

	


}

