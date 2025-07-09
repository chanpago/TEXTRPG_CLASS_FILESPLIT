#include "CBehave_Fight.h"

#include "W0_BasicSkill.h"
#include "Player/CPlayer.h"
#include "pch_Monster.h"

CBehave_Fight::CBehave_Fight()
{
}

CBehave_Fight::~CBehave_Fight()
{
}

void CBehave_Fight::Initialize()
{
}

void CBehave_Fight::Update()
{
}

void CBehave_Fight::Release()
{
}

void CBehave_Fight::Fight(CPlayer* player, CObject* monster)
{
	int iInput(0);


	while (true)
	{
		system("cls");
		player->Render();

		std::cout << std::endl;
		std::cout << std::endl;

		monster->Render();
		std::cout << "1. ���� 2.��ų ��� 3. ���� : ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			monster->Update(2, player->GetObjectATK());
			player->Update(2, monster->GetObjectATK());
			break;
		case 2:
			SkillAttack(player, monster);
			break;
		case 3:
			return;
		default:
			std::cout << "�߸� �����̽��ϴ�" << std::endl;
			break;
		}

		if (monster->GetObjectHP() <= 0)
		{
			monster->Die();
			std::cout << "�¸�!" << std::endl;
			std::cout << "����ġ " << monster->GetEXP() << "�� ȹ�� �Ͽ����ϴ�!" << std::endl;
			player->AddEXP(monster->GetEXP());
			system("pause");

			if (player->GetObjectHP() <= 0) player->SetObjectHP(100);

			return;
		}
		else if (player->GetObjectHP() <= 0)
		{

			player->Die();
			player->SetObjectHP(100);
			system("pause");
			return;
		}
	}
}

void CBehave_Fight::SkillAttack(CPlayer* player, CObject* monster)
{
	int iInput(0);

	while (true)
	{
		if (monster->GetObjectHP() <= 0)return;
		system("cls");
		player->Render();
		monster->Render();
		std::cout << "�� ��° ��ų�� ����Ͻðڽ��ϱ�? 0�Է�->������ :";
		std::cin >> iInput;

		if (iInput > player->GetSkillsCount() || iInput < 0)
		{
			std::cout << "�߸� �����̽��ϴ�" << std::endl;
			system("pause");
			continue;
		}
		else if (iInput == 0)
		{
			return;
		}
		else
		{
			// ��ų �̸� ���
			std::cout << "����� ��ų: [ " << player->GetSkill(iInput - 1)->GetSkillName() << " ]" << std::endl;

			monster->Update(2, player->GetSkill(iInput - 1)->UseSkill(player->GetObjectATK()));
			player->Update(2, monster->GetObjectATK());
			system("pause");
		}
	}
}
