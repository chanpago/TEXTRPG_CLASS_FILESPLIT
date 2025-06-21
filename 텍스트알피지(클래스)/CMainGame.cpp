#include "pch.h"
#include "CMainGame.h"

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
		m_pPlayer = new CObject;
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

void CMainGame::Fight(CObject* pPlayer, CObject* pEnemy)
{
	int iInput(0);


	while (true)
	{
		system("cls");
		pPlayer->Render();
		pEnemy->Render();
		std::cout << "1. 공격 2. 도망 : ";
		std::cin >> iInput;

		switch (iInput)
		{
		case 1:
			pEnemy->Update(pPlayer->GetObjectATK());
			pPlayer->Update(pEnemy->GetObjectATK());
			break;
		case 2:
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
