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
		std::cout << "�Ǹ� �Ͻ� �����۸� �������ּ��� 0. ������ : ";
		std::cin >> iInput;

		if (iInput == 0)
		{
			break;
		}
		if (iInput < 0 || iInput > player->GetInventory()->GetInventorySize())
		{
			std::cout << "������ ��ȣ�� �߸��Ǿ����ϴ� �ٽ��Է����ּ���" << std::endl;
			system("pause");
		}
		else
		{
			--iInput;
			CPlayerInventory* playerinventory = player->GetInventory();
			std::vector<std::pair<std::shared_ptr<CBaseThing>, int>>* inventory = (playerinventory->GetInventory());

			// �Է¹��� ������ ��ġ�� �̵�
			auto it = inventory->begin();
			for (int i = 0; i < iInput; ++i) it++;

			// ���⼭ ������ �Ǹ��ൿ
			player->SetMoney(player->GetMoney() + it->first->GetPrice());
			
			if (it->second != 1)
			{
				it->second--;
			}
			else
			{
				it->first = nullptr;
				it->second = 0;

				// ���⼭ �����ִ� �۾� + size���̱�
				int i = iInput;
				auto Nextit = it + 1;
				for (; i < playerinventory->GetInventorySize() - 1; ++i)
				{
					
					it->first = Nextit->first;
					it->second = Nextit->second;
					++it;
					++Nextit;
				}

				// ��������� ����
				it->first = nullptr;
				it->second = 0;

				playerinventory->SetGetInventorySize(playerinventory->GetInventorySize() - 1);
			}
		}
	}
}
