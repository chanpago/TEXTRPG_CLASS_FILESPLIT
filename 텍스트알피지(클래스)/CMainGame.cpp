#include "pch.h"
#include "CMainGame.h"
#include "W0_BasicSkill.h"

CMainGame::CMainGame(): m_pPlayer(nullptr) {}

CMainGame::~CMainGame()
{
	Release();
}
																																			   
bool CMainGame::Initialize()
{
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
		std::cout << "1. ����� 2. ���� : ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			Field();
			break;
		case 2:
			return;
		default:
			std::cout << "�߸� �����̽��ϴ�" << std::endl;
			break;
		}


	}
	
}

void CMainGame::Release()
{
	// player�� delete�� �� player�� �Ҹ��ڰ� ȣ���
	SAFE_DELETE(m_pPlayer);
}

void CMainGame::Field()
{
	int		iInput(0);
	bool	bSave(false);

	CObject* CEnemy = nullptr;
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		std::cout << "1. �ʱ� 2. �߱� 3. ��� 4. �����ϱ� 5. �� �ܰ� : ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			CEnemy = new CObject;
			CEnemy->SetObject("�ʱ�", 30 * iInput, 3 * iInput);
			break;
		case 2:
			CEnemy = new CObject;
			CEnemy->SetObject("�߱�", 30 * iInput, 3 * iInput);
			break;
		case 3:
			CEnemy = new CObject;
			CEnemy->SetObject("���", 30 * iInput, 3 * iInput);
			break;
		case 4:
			// save ����
			bSave = m_pPlayer->Save();
			break;
		case 5:
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
		else
		{
			// fight
			Fight(m_pPlayer, CEnemy);		
			SAFE_DELETE(CEnemy);
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
			std::cout << "�¸�!" << std::endl;
			system("pause");

			if (m_pPlayer->GetObjectHP() <= 0) m_pPlayer->SetObjectHP(100);

			return;
		}
		else if (pPlayer->GetObjectHP() <= 0)
		{
			std::cout << "�й�..." << std::endl;

			pPlayer->SetObjectHP(100);
			system("pause");
			return;
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
