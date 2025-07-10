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
	1. �� ���� ����
	2. �κ��� �ֱ�
	*/



	if (player->GetInventory()->GetInventorySize() == 5)
	{
		std::cout << "�κ��丮�� �� á���ϴ�!" << std::endl;
		system("pause");
		return false;
	}

	// �� �� �ִ� ���
	if (player->GetMoney() >= something->GetPrice() && something)
	{
		//�÷��̾� �κ��丮�� �ִ´�
		player->GetInventory()->Update(something, something->GetType(), something->GetUniqueNum());

		//������
		player->SetMoney(player->GetMoney() - something->GetPrice());

		return true;
	}
	else
	{
		std::cout << "�������� �����մϴ�! " << std::endl;
		system("pause");
		return false;
	}

}
