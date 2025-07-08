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
		std::cout << "1. 사냥터 2. 상점 3. 아이템 사용 4. 종료 : ";
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
			pEnemy->Die();
			std::cout << "승리!" << std::endl;
			std::cout << "경험치 " << pEnemy->GetEXP() << "를 획득 하였습니다!" << std::endl;
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
		std::cout << "1. 초급상점 2. 중급상점 3. 고급상점 4.나가기: ";
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
			std::cout << "잘못 누르셨습니다" << std::endl;
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
