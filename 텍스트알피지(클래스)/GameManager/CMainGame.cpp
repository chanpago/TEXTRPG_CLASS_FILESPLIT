#include "pch.h"
#include "CMainGame.h"
#include "Player/CPlayer.h"
#include "CTier3Shop.h"
#include "CTier2Shop.h"
#include "CBehave.h"

#include "BehaveManager/CBehaveManager.h"
#include "ItemUse/CBehave_ItemUse.h"
#include "Buy/CBehave_Buy.h"
#include "Unequip/CBehave_Unequip.h"
#include "Sell/CBehave_Sell.h"
#include "Fight/CBehave_Fight.h"



CMainGame::CMainGame(): m_pPlayer(nullptr), m_pBehaveManager(nullptr){}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Release()
{
	
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pBehaveManager);
}
																																			   
void CMainGame::Initialize()
{
	//여기에 플레이어 생성하는 함수 들어가야 할듯
	
	m_pPlayer = new CPlayer;
	if (!m_pPlayer) return;

	m_pPlayer->Initialize();
	

	m_pBehaveManager = new CBehaveManager;
	if (!m_pBehaveManager) return;

	m_pBehaveManager->Initialize();
	
}

void CMainGame::Update()
{
	int iInput(0);

	while (true)
	{
		system("cls");

		// 플레이어 정보 출력함수
		m_pPlayer->Render();
		std::cout << "1. 사냥터 2. 상점 3. 아이템 사용 4. 아이템 장착 해제 5. 종료 : ";
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
			m_pBehaveManager->GetBehave_ItemUse()->UseItem(m_pPlayer);
			break;
		case 4:
			m_pBehaveManager->GetBehave_Unequip()->UnEquipment(m_pPlayer);
			break;
		case 5:
			return;
		default:
			std::cout << "잘못 누르셨습니다" << std::endl;
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
		std::cout << "1. 초급 2. 중급 3. 고급 4. 저장하기 5. 스텟찍기 6. 전 단계 : ";
		std::cin >> iInput;

		// 몬스터 셋 오브젝트 파라미터 설명
		// 이름, 종류, 공격력, 체력, 마나, 경험치, 레벨, 타입
		switch (iInput)
		{
		case 1:
			pEnemy = new CEnemy_Slime;
			pEnemy->SetObject("슬라임", "몬스터", 5 * iInput, 50, 0, 8, 1, 0);
			break;
		case 2:
			pEnemy = new CEnemy_RibbonPig;
			pEnemy->SetObject("리본돼지", "몬스터", 5 * iInput, 80, 0, 15, 1, 0);
			break;
		case 3:
			pEnemy = new CEnemy_MushMom;
			pEnemy->SetObject("머쉬맘", "몬스터", 5 * iInput, 100, 0, 30, 1, 0);
			break;
		case 4:
			// save 구현
			//bSave = m_pPlayer->Save();
			break;
		case 5:
			m_pPlayer->SetStat();
			break;
		case 6:
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
		if (iInput == 5)continue;
		else
		{
			m_pBehaveManager->GetBehave_Fight()->Fight(m_pPlayer, pEnemy);
			SAFE_DELETE(pEnemy);
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
		std::cout << "1. 초급상점 2. 중급상점 3. 고급상점 4. 아이템 팔기 5.나가기: ";
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
			m_pBehaveManager->GetBehave_Sell()->Sell(m_pPlayer);
			break;
		case 5:
			SAFE_DELETE(pShop);
			return;
		default:
			std::cout << "잘못 누르셨습니다" << std::endl;
			break;
		}
	}
}

