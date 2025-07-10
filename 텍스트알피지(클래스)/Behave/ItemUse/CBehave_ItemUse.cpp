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
			std::vector<std::pair<std::shared_ptr<CBaseThing>, int>>* inventory = (playerinventory->GetInventory());

			if (iInput > playerinventory->GetInventorySize())
			{
				std::cout << "잘못된 입력입니다!" << std::endl;
				system("pause");
				return;
			}

			auto it = inventory->begin();
			auto itEnd = inventory->end() - 1;
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
						//inventory->erase(it);
						it->first = nullptr;
						it->second = 0;

						// 여기서 땡겨주는 작업 + size줄이기
						int i = iInput;
						auto Nextit = it + 1;
						for (; i < playerinventory->GetInventorySize() - 1; ++i)
						{

							it->first = Nextit->first;
							it->second = Nextit->second;
							++it;
							++Nextit;
						}

						// 마지막요소 삭제
						Nextit->first = nullptr;
						Nextit->second = 0;

						playerinventory->SetGetInventorySize(playerinventory->GetInventorySize() - 1);
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
					std::shared_ptr<CBaseThing> BeforeWeapon = playerEquipInven->GetWeapon();

					//2.장비 교체
					it->first = BeforeWeapon;
					it->second = 1;
					player->SetObjectATK(player->GetObjectATK() - BeforeWeapon->GetValue());

					//3. 장비 업로드
					playerEquipInven->SetWeapon(item);
					player->SetObjectATK(player->GetObjectATK() + item->GetValue());

				}
				else
				{
					player->SetObjectATK(player->GetObjectATK() + item->GetValue());
					playerEquipInven->SetWeapon(item);

					it->first = nullptr;
					it->second = 0;

					// 여기서 땡겨주는 작업 + size줄이기
					int i = iInput;
					auto Nextit = it + 1;
					for (; i < playerinventory->GetInventorySize() - 1; ++i)
					{

						it->first = Nextit->first;
						it->second = Nextit->second;
						++it;
						++Nextit;
					}

					// 마지막요소 삭제
					Nextit->first = nullptr;
					Nextit->second = 0;

					playerinventory->SetGetInventorySize(playerinventory->GetInventorySize() - 1);
				}
				
			}
			// 방어구
			else if (item->GetUniqueNum() < 30)
			{
				CEquipmentInventory* playerEquipInven = player->GetEquipInventory();

				// 방어구가 이미 있다면
				if (playerEquipInven->IsArmor())
				{
					std::shared_ptr<CBaseThing> BeforeArmor = playerEquipInven->GetArmor();

					//2.장비 교체
					it->first = BeforeArmor;
					it->second = 1;

					//3. 장비 업로드
					playerEquipInven->SetArmor(item);

				}
				else
				{			
					playerEquipInven->SetArmor(item);

					//인벤토리에서 삭제
					it->first = nullptr;
					it->second = 0;

					// 여기서 땡겨주는 작업 + size줄이기
					int i = iInput;
					auto Nextit = it + 1;
					for (; i < playerinventory->GetInventorySize() - 1; ++i)
					{

						it->first = Nextit->first;
						it->second = Nextit->second;
						++it;
						++Nextit;
					}

					// 마지막요소 삭제
					it->first = nullptr;
					it->second = 0;

					playerinventory->SetGetInventorySize(playerinventory->GetInventorySize() - 1);
				}
			}
		}
	}

	


}

