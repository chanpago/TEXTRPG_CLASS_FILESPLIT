#include "pch.h"
#include "CPlayer.h"
#include "CObject.h"
#include "WarriorSkill.h"
#include "MagicianSkill.h"
#include "ThiefSkill.h"
#include "W0_BasicSkill.h"
#include "Skill.h"

#include "pch_Skill.h"





CPlayer::CPlayer() : m_pPlayerInfo(nullptr) {}																							 

CPlayer::~CPlayer()
{
	Release();
}

bool CPlayer::Initialize()
{
	int iInput(0);

	system("cls");
	std::cout << "1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ������ : ";
	std::cin >> iInput;

	switch (iInput)
	{
	case ����:
		SetObject("��ȣ", "����", ����);
		SetPlayerInfo();
		CreateSkill(����);
		break;
	case ������:
		SetObject("��ȣ", "������", ������);
		SetPlayerInfo();
		CreateSkill(������);
		break;
	case ����:
		SetObject("��ȣ", "����", ����);
		SetPlayerInfo();
		CreateSkill(����);
		break;
	case �ҷ�����:
		//Load();
		break;
	case ������:
		return false;
	default:
		std::cout << "�߸� �����̽��ϴ�" << std::endl;
		break;
	}
	return true;
}

void CPlayer::Update(const int iType, const int iNum)
{
	switch (iType)
	{
	case ����:
		break;
	case ������:
		SetObjectHP(GetObjectHP() - iNum);
		break;
	case HPȸ��:
		break;
	case MPȸ��:
		break;
	}
}

void CPlayer::Release()
{
	//SAFE_DELETE(*(GetObject()));
	SAFE_DELETE(m_pPlayerInfo->pSkills);
	SAFE_DELETE(m_pPlayerInfo);
}


void CPlayer::Render() const
{
	CObject::Render();
	std::cout << "STR : " << m_pPlayerInfo->iSTR << '\t' << "DEX : " << m_pPlayerInfo->iDEX << std::endl;
	std::cout << "INT : " << m_pPlayerInfo->iINT << '\t' << "LUK : " << m_pPlayerInfo->iLUK << std::endl;
	std::cout << "Stat Point : " << m_pPlayerInfo->iStatPoint << std::endl;


	std::cout << "==============" << GetObjectJob() << " ��ų" << "==============" << std::endl;

	int i = 1;
	for (auto skill : m_pPlayerInfo->pSkills->GetSkills())
	{
		std::cout << i++ << " : " << "[ " << skill->GetSkillName() << " ]" << std::endl;
	}
	std::cout << "========================================" << std::endl;
}


//void CPlayer::Load()
//{
//	std::string		sName, sHealthValue, sAttackValue;
//	std::ifstream	inFile("../Data/SavePlayer.txt", std::ios::in);
//
//	std::getline(inFile, sName);
//	std::getline(inFile, sHealthValue);
//	std::getline(inFile, sAttackValue);
//
//	inFile.close();
//
//	SetObject(sName, stoi(sHealthValue), stoi(sAttackValue));
//}
//
//bool CPlayer::Save()
//{
//	std::ofstream	outFile("../Data/SavePlayer.txt", std::ios::out);
//	if (!outFile.is_open()) {
//		std::cerr << "���� ���� ����" << std::endl;
//		return false;
//	}
//
//	outFile << GetObjectName() << '\n';
//	outFile << GetObjectHP() << '\n';
//	outFile << GetObjectATK() << '\n';
//	std::cout << "���� ���� ����" << std::endl;
//
//	system("pause");
//
//	return true;
//
//}

void CPlayer::CreateSkill(const int iNum)
{
	switch (iNum)
	{
	case 1:
		m_pPlayerInfo->pSkills = new WarriorSkill;
		m_pPlayerInfo->pSkills->AddSkill(new W1_PowerStrike);
		break;
	case 2:
		m_pPlayerInfo->pSkills = new MagicianSkill;
		m_pPlayerInfo->pSkills->AddSkill(new M1_MagicClaw);
		break;
	case 3:
		m_pPlayerInfo->pSkills = new ThiefSkill;
		m_pPlayerInfo->pSkills->AddSkill(new T1_LuckySeven);
		break;
	default :
		break;
	}
	
}

void CPlayer::AddEXP(const int iNum)
{
	(*GetObject())->iNowEXP += iNum;
	if ((*GetObject())->iNowEXP >= (*GetObject())->iMaxEXP) LevelUP();
	
}

void CPlayer::SetPlayerInfo()
{
	m_pPlayerInfo = new PLAYERINFO;
}

void CPlayer::LevelUP()
{
	(*GetObject())->iLevel++;
	(*GetObject())->iNowEXP -= (*GetObject())->iMaxEXP;
	(*GetObject())->iMaxEXP = static_cast<int>(static_cast<float>((*GetObject())->iMaxEXP) * 1.5f);
	m_pPlayerInfo->iStatPoint += 4;
	SetObjectHP((*GetObject())->iMaxHealthValue);
	(*GetObject())->iHealthValue = (*GetObject())->iMaxHealthValue;
	std::cout << "������ �ö����ϴ�!" << std::endl;
}

void CPlayer::SetStat()
{
	int iInput(0);


	while (true)
	{
		system("cls");
		Render();

		std::cout << "STR : 1" << "\t" << "DEX : 2" << std::endl;
		std::cout << "INT : 3" << "\t" << "LUK : 4" << std::endl;
		std::cout << "������ 0 " << std::endl;
		std::cout << "�ø� ������ �����ּ��� : ";
		std::cin >> iInput;

		if (m_pPlayerInfo->iStatPoint == 0)
		{
			std::cout << "��������Ʈ�� �����մϴ�!" << std::endl;
			system("pause");
			return;

		}
		else
		{
			switch (iInput)
			{
			case 0:
				return;
			case 1:
				AddStat(iInput);
				break;
			case 2:
				AddStat(iInput);
				break;
			case 3:
				AddStat(iInput);
				break;
			case 4:
				AddStat(iInput);
				break;
			default:
				std::cout << "�߸� �����̽��ϴ�" << std::endl;
				break;
			}
		}

	}
}

void CPlayer::AddStat(const int iType)
{
	switch (iType)
	{
	case 1:
		m_pPlayerInfo->iSTR++;
		break;
	case 2:
		m_pPlayerInfo->iDEX++;
		break;
	case 3:
		m_pPlayerInfo->iINT++;
		break;
	case 4:
		m_pPlayerInfo->iLUK++;
		break;
	}
	m_pPlayerInfo->iStatPoint--;
	
	CalcAttackValue();


}

void CPlayer::CalcAttackValue()
{
	if (GetObjectType() == ����)
	{
		(*GetObject())->iAttackValue = 10 + m_pPlayerInfo->iSTR;
		(*GetObject())->iMaxHealthValue = (*GetObject())->iLevel * 10 + m_pPlayerInfo->iSTR * 10;
	}
	if (GetObjectType() == ����)
		(*GetObject())->iAttackValue = static_cast<int>(10 + static_cast<float>(m_pPlayerInfo->iLUK)/2.0f);
}



