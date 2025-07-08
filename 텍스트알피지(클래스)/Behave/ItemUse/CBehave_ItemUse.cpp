#include "pch.h"
#include "CBehave_ItemUse.h"
#include "Player/CPlayer.h"
#include "ItemInventory/CPlayerInventory.h"
#include "EquipmentInventory/CEquipmentInventory.h"
#include "포션/CTier3Potion.h"
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
		std::cout << "사용할 아이템 번호를 입력해주세요 (0.나가기) : ";
		std::cin >> iInput;

		if (iInput == 0)break;
		else
		{
			CPlayerInventory* playerinventory = player->GetInventory();
			std::unordered_map<std::shared_ptr < CBaseThing>, int>* inventory = playerinventory->GetInventory();

			auto it = inventory->begin();
			iInput -= 1;

			for (int i = 0; i < iInput; ++i) it++;

			//iNum번째 아이템 정보

			std::shared_ptr<CBaseThing> item = it->first;
			int itemCount = it->second;

			// 이름, 가격, 등급, 타입, 회복량, 고유번호

			//포션
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
			//무기
			else if (item->GetUniqueNum() < 20)
			{
				CEquipmentInventory* playerEquipInven = player->GetEquipInventory();

				// 무기가 이미 있다면
				if (playerEquipInven->IsWeapon())
				{
					std::shared_ptr<CBaseThing> Weapon = playerEquipInven->GetWeapon();

					//인벤토리에서 삭제
					playerinventory->GetInventory()->erase(it);


					player->SetObjectATK(player->GetObjectATK() - Weapon->GetValue());

					//원래 끼고 있던 무기, 인벤토리에 업데이트
					playerinventory->Update(Weapon, Weapon->GetType(), Weapon->GetUniqueNum());

					//장비에 새로운 무기 등록
					playerEquipInven->SetWeapon(item);


					player->SetObjectATK(player->GetObjectATK() + item->GetValue());

				}
				else
				{
					player->SetObjectATK(player->GetObjectATK() + item->GetValue());
					playerEquipInven->SetWeapon(item);

					//인벤토리에서 삭제
					playerinventory->GetInventory()->erase(it);
				}
				
			}
			// 방어구
			else if (item->GetUniqueNum() < 30)
			{
				CEquipmentInventory* playerEquipInven = player->GetEquipInventory();

				// 방어구가 이미 있다면
				if (playerEquipInven->IsArmor())
				{
					std::shared_ptr<CBaseThing> Armor = playerEquipInven->GetArmor();

					//인벤토리에서 삭제
					playerinventory->GetInventory()->erase(it);

					//원래 끼고 있던 방어구, 인벤토리에 업데이트
					playerinventory->Update(Armor, Armor->GetType(), Armor->GetUniqueNum());

					//장비에 새로운 방어구 등록
					playerEquipInven->SetArmor(item);
				}
				else
				{
					playerEquipInven->SetArmor(item);

					//인벤토리에서 삭제
					playerinventory->GetInventory()->erase(it);
				}
			}
		}
	}

	


}

