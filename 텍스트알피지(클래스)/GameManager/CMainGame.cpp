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
	//���⿡ �÷��̾� �����ϴ� �Լ� ���� �ҵ�
	
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

		// �÷��̾� ���� ����Լ�
		m_pPlayer->Render();
		std::cout << "1. ����� 2. ���� 3. ������ ��� 4. ������ ���� ���� 5. ���� : ";
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
		std::cout << "1. �ʱ޻��� 2. �߱޻��� 3. ��޻��� 4. ������ �ȱ� 5.������: ";
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
			std::cout << "�߸� �����̽��ϴ�" << std::endl;
			break;
		}
	}
}

