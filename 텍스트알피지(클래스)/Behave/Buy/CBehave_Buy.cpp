#include "pch.h"
#include "CBehave_Buy.h"
#include "Player/CPlayer.h"
#include "ItemInventory/CPlayerInventory.h"
#include "CBaseThing.h"

CBehave_Buy::CBehave_Buy()
{
}

CBehave_Buy::~CBehave_Buy()
{
}

void CBehave_Buy::Initialize()
{
}

void CBehave_Buy::Update()
{
}

void CBehave_Buy::Release()
{
}

bool CBehave_Buy::Buy(CPlayer* player, std::shared_ptr<CBaseThing> something)
{
	/*
	1. 돈 가능 여부
	2. 인벤에 넣기
	*/



	if (player->GetInventory()->GetInventorySize() == 5)
	{
		std::cout << "인벤토리가 다 찼습니다!" << std::endl;
		system("pause");
		return false;
	}

	// 살 수 있는 경우
	if (player->GetMoney() >= something->GetPrice() && something)
	{
		//플레이어 인벤토리에 넣는다
		player->GetInventory()->Update(something, something->GetType(), something->GetUniqueNum());

		//돈감소
		player->SetMoney(player->GetMoney() - something->GetPrice());

		return true;
	}
	else
	{
		std::cout << "소지금이 부족합니다! " << std::endl;
		system("pause");
		return false;
	}

}
