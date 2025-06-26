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
	//여기에 플레이어 생성하는 함수 들어가야 할듯
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

		// 플레이어 정보 출력함수
		m_pPlayer->Render();
		std::cout << "1. 사냥터 2. 종료 : ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			Field();
			break;
		case 2:
			return;
		default:
			std::cout << "잘못 누르셨습니다" << std::endl;
			break;
		}


	}
	
}

void CMainGame::Release()
{
	// player가 delete될 때 player의 소멸자가 호출됨
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
		std::cout << "1. 초급 2. 중급 3. 고급 4. 저장하기 5. 전 단계 : ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			CEnemy = new CObject;
			CEnemy->SetObject("초급", 30 * iInput, 3 * iInput);
			break;
		case 2:
			CEnemy = new CObject;
			CEnemy->SetObject("중급", 30 * iInput, 3 * iInput);
			break;
		case 3:
			CEnemy = new CObject;
			CEnemy->SetObject("고급", 30 * iInput, 3 * iInput);
			break;
		case 4:
			// save 구현
			bSave = m_pPlayer->Save();
			break;
		case 5:
			return;
		default:
			std::cout << "잘못 누르셨습니다" << std::endl;
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
		std::cout << "1. 공격 2.스킬 사용 3. 도망 : ";
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
			std::cout << "잘못 누르셨습니다" << std::endl;
			break;
		}

		if (pEnemy->GetObjectHP() <= 0)
		{
			std::cout << "승리!" << std::endl;
			system("pause");

			if (m_pPlayer->GetObjectHP() <= 0) m_pPlayer->SetObjectHP(100);

			return;
		}
		else if (pPlayer->GetObjectHP() <= 0)
		{
			std::cout << "패배..." << std::endl;

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
		std::cout << "몇 번째 스킬을 사용하시겠습니까? 0입력->나가기 :";
		std::cin >> iInput;

		if (iInput > pPlayer->GetSkillsCount() || iInput < 0)
		{
			std::cout << "잘못 누르셨습니다" << std::endl;
			system("pause");
			continue;
		}
		else if (iInput == 0)
		{
			return;
		}
		else
		{
			
			// 스킬 이름 출력
			std::cout << "사용한 스킬: [ " << pPlayer->GetSkill(iInput - 1)->GetSkillName() << " ]" << std::endl;

			pEnemy->Update(2,pPlayer->GetSkill(iInput - 1)->UseSkill(pPlayer->GetObjectATK()));
			pPlayer->Update(2,pEnemy->GetObjectATK());
			system("pause");
		}
	}
	
}
