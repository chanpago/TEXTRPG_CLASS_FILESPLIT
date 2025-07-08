#include "pch.h"
#include "CMainGame.h"
#include "Player/CPlayer.h"
#include "W0_BasicSkill.h"
#include "CTier3Shop.h"
#include "CTier2Shop.h"
#include "CBehave.h"
#include "ItemUse/CBehave_ItemUse.h"

CMainGame::CMainGame(): m_pPlayer(nullptr), Behave_UseItem(nullptr){}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Release()
{
	SAFE_DELETE(Behave_UseItem);
	SAFE_DELETE(m_pPlayer);
}
																																			   
bool CMainGame::Initialize()
{
	Behave_UseItem = new CBehave_ItemUse;


	//���⿡ �÷��̾� �����ϴ� �Լ� ���� �ҵ�
	if (!m_pPlayer)
	{
		m_pPlayer = new CPlayer;
		return m_pPlayer->Initialize();
	}
	
}

void CMainGame::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		// �÷��̾� ���� ����Լ�
		m_pPlayer->Render();
		std::cout << "1. ����� 2. ���� 3. ������ ��� 4. ���� : ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			Field();
			break;
		case 2:
			Shop();
			break;
		case 3:
			Behave_UseItem->UseItem(m_pPlayer);
			break;
		case 4:
			return;
		default:
			std::cout << "�߸� �����̽��ϴ�" << std::endl;
			break;
		}


	}
	
}


void CMainGame::Field()
{
	int		iInput(0);
	bool	bSave(false);

	CObject* pEnemy = nullptr;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		std::cout << "1. �ʱ� 2. �߱� 3. ��� 4. �����ϱ� 5. ������� 6. �� �ܰ� : ";
		std::cin >> iInput;

		// ���� �� ������Ʈ �Ķ���� ����
		// �̸�, ����, ���ݷ�, ü��, ����, ����ġ, ����, Ÿ��
		switch (iInput)
		{
		case 1:
			pEnemy = new CEnemy_Slime;
			pEnemy->SetObject("������", "����", 5 * iInput, 50, 0, 8, 1, 0);
			break;
		case 2:
			pEnemy = new CEnemy_RibbonPig;
			pEnemy->SetObject("��������", "����", 5 * iInput, 80, 0, 15, 1, 0);
			break;
		case 3:
			pEnemy = new CEnemy_MushMom;
			pEnemy->SetObject("�ӽ���", "����", 5 * iInput, 100, 0, 30, 1, 0);
			break;
		case 4:
			// save ����
			//bSave = m_pPlayer->Save();
			break;
		case 5:
			m_pPlayer->SetStat();
			break;
		case 6:
			return;
		default:
			std::cout << "�߸� �����̽��ϴ�" << std::endl;
			break;

		}

		if (bSave)
		{
			bSave = false;
			continue;
		}
		if (iInput == 5)continue;
		else
		{
			// fight
			Fight(m_pPlayer, pEnemy);
			SAFE_DELETE(pEnemy);
		}

	}
}

void CMainGame::Fight(CPlayer* pPlayer, CObject* pEnemy)
{
	int iInput(0);


	while (true)
	{
		system("cls");
		pPlayer->Render();

		std::cout << std::endl;
		std::cout << std::endl;

		pEnemy->Render();
		std::cout << "1. ���� 2.��ų ��� 3. ���� : ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			pEnemy->Update(2,pPlayer->GetObjectATK());
			pPlayer->Update(2,pEnemy->GetObjectATK());
			break;
		case 2:
			SkillAttack(pPlayer, pEnemy);
			break;
		case 3:
			return;
		default:
			std::cout << "�߸� �����̽��ϴ�" << std::endl;
			break;
		}

		if (pEnemy->GetObjectHP() <= 0)
		{
			pEnemy->Die();
			std::cout << "�¸�!" << std::endl;
			std::cout << "����ġ " << pEnemy->GetEXP() << "�� ȹ�� �Ͽ����ϴ�!" << std::endl;
			pPlayer->AddEXP(pEnemy->GetEXP());
			system("pause");

			if (m_pPlayer->GetObjectHP() <= 0) m_pPlayer->SetObjectHP(100);

			return;
		}
		else if (pPlayer->GetObjectHP() <= 0)
		{
			
			pPlayer->Die();
			pPlayer->SetObjectHP(100);
			system("pause");
			return;
		}
	}
}

void CMainGame::Shop()
{
	int iInput(0);

	CBaseShop* pShop = nullptr;

	while (true)
	{
		SAFE_DELETE(pShop);


		system("cls");
		m_pPlayer->Render();
		//std::cout << "========================================" << std::endl;
		std::cout << "1. �ʱ޻��� 2. �߱޻��� 3. ��޻��� 4.������: ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			pShop = new CTier3Shop();
			pShop->Initialize();
			pShop->Update(m_pPlayer);


			break;
		case 2:
			pShop = new CTier2Shop();
			pShop->Initialize();
			pShop->Update(m_pPlayer);
			break;
		case 3:
			break;
		case 4:
			SAFE_DELETE(pShop);
			return;
		default:
			std::cout << "�߸� �����̽��ϴ�" << std::endl;
			break;
		}
	}
}

void CMainGame::SkillAttack(CPlayer* pPlayer, CObject* pEnemy)
{
	int iInput(0);

	while (true)
	{
		if (pEnemy->GetObjectHP() <= 0)return;
		system("cls");
		pPlayer->Render();
		pEnemy->Render();
		std::cout << "�� ��° ��ų�� ����Ͻðڽ��ϱ�? 0�Է�->������ :";
		std::cin >> iInput;

		if (iInput > pPlayer->GetSkillsCount() || iInput < 0)
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
			std::cout << "����� ��ų: [ " << pPlayer->GetSkill(iInput - 1)->GetSkillName() << " ]" << std::endl;

			pEnemy->Update(2,pPlayer->GetSkill(iInput - 1)->UseSkill(pPlayer->GetObjectATK()));
			pPlayer->Update(2,pEnemy->GetObjectATK());
			system("pause");
		}
	}
	
}
