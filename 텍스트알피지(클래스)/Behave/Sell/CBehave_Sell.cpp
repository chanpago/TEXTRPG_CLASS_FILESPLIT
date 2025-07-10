#include "pch.h"
#include "CBehave_Sell.h"
#include "ItemInventory/CPlayerInventory.h"
#include "Player/CPlayer.h"
#include "CBaseThing.h"

CBehave_Sell::CBehave_Sell()
{
}

CBehave_Sell::~CBehave_Sell()
{
}

void CBehave_Sell::Initialize()
{
}

void CBehave_Sell::Update()
{
}

void CBehave_Sell::Release()
{
}

void CBehave_Sell::Sell(CPlayer* player)
{
	int iInput(0);

	while (true)
	{
		system("cls");
		player->Render();
		std::cout << "판매 하실 아이템를 선택해주세요 0. 나가기 : ";
		std::cin >> iInput;

		if (iInput == 0)
		{
			break;
		}
		if (iInput < 0 || iInput > player->GetInventory()->GetInventorySize())
		{
			std::cout << "아이템 번호가 잘못되었습니다 다시입력해주세요" << std::endl;
			system("pause");
		}
		else
		{
			--iInput;
			CPlayerInventory* playerinventory = player->GetInventory();
			std::vector<std::pair<std::shared_ptr<CBaseThing>, int>>* inventory = (playerinventory->GetInventory());

			// 입력받은 아이템 위치로 이동
			auto it = inventory->begin();
			for (int i = 0; i < iInput; ++i) it++;

			// 여기서 아이템 판매행동
			player->SetMoney(player->GetMoney() + it->first->GetPrice());
			
			if (it->second != 1)
			{
				it->second--;
			}
			else
			{
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
