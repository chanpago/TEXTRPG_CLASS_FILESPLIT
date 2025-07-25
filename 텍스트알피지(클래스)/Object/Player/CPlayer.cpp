#include "pch.h"
#include "CPlayer.h"
#include "CObject.h"
#include "전사스킬/WarriorSkill.h"
#include "마법사스킬/MagicianSkill.h"
#include "도적스킬/ThiefSkill.h"
#include "W0_BasicSkill.h"
#include "Skill.h"

#include "ItemInventory/CPlayerInventory.h"
#include "EquipmentInventory/CEquipmentInventory.h"

#include "pch_Skill.h"





CPlayer::CPlayer(){}																							 

CPlayer::~CPlayer()
{
	Release();
}

bool CPlayer::Initialize()
{
	int iInput(0);

	system("cls");
	std::cout << "1. 전사 2. 마법사 3. 도적 4. 불러오기 5. 나가기 : ";
	std::cin >> iInput;

	switch (iInput)
	{
	case 전사:
		SetObject("찬호", "전사", 전사);
		SetPlayerInfo();
		SetPlayerInven();
		SetPlayerEquipInven();
		CreateSkill(전사);
		break;
	case 마법사:
		SetObject("찬호", "마법사", 마법사);
		SetPlayerInfo();
		SetPlayerInven();
		SetPlayerEquipInven();
		CreateSkill(마법사);
		break;
	case 도적:
		SetObject("찬호", "도적", 도적);
		SetPlayerInfo();
		SetPlayerInven();
		SetPlayerEquipInven();
		CreateSkill(도적);
		break;
	case 불러오기:
		//Load();
		break;
	case 나가기:
		return false;
	default:
		std::cout << "잘못 누르셨습니다" << std::endl;
		break;
	}
	return true;
}

void CPlayer::Update(const int iType, const int iNum)
{
	switch (iType)
	{
	case 공격:
		break;
	case 데미지:
		SetObjectHP(GetObjectHP() - iNum);
		break;
	case HP회복:
		break;
	case MP회복:
		break;
	}
}

void CPlayer::Release()
{
	//SAFE_DELETE(*(GetObject()));
	SAFE_DELETE(m_pPlayerInfo->pSkills);
	SAFE_DELETE(m_pPlayerInfo);
	SAFE_DELETE(m_pEquipmentInventory);
	SAFE_DELETE(m_pPlayerInventory);
}


void CPlayer::Render() const
{
	CObject::Render();
	std::cout << "STR : " << m_pPlayerInfo->iSTR << '\t' << "DEX : " << m_pPlayerInfo->iDEX << std::endl;
	std::cout << "INT : " << m_pPlayerInfo->iINT << '\t' << "LUK : " << m_pPlayerInfo->iLUK << std::endl;
	std::cout << "Stat Point : " << m_pPlayerInfo->iStatPoint << std::endl;


	std::cout << "================" << GetObjectJob() << " 스킬" << "===============" << std::endl;

	int i = 1;
	for (auto skill : m_pPlayerInfo->pSkills->GetSkills())
	{
		std::cout << i++ << " : " << "[ " << skill->GetSkillName() << " ]" << std::endl;
	}
	std::cout << "========================================" << std::endl;
	std::cout << std::endl;
	std::cout << "소지금 : " << m_pPlayerInfo->iMoney << "메소" << std::endl;
	m_pEquipmentInventory->Render();
	m_pPlayerInventory->Render();
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
//		std::cerr << "파일 저장 실패" << std::endl;
//		return false;
//	}
//
//	outFile << GetObjectName() << '\n';
//	outFile << GetObjectHP() << '\n';
//	outFile << GetObjectATK() << '\n';
//	std::cout << "파일 저장 성공" << std::endl;
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
		if (!m_pPlayerInfo->pSkills)return;
		m_pPlayerInfo->pSkills->AddSkill(new W1_PowerStrike);
		break;
	case 2:
		m_pPlayerInfo->pSkills = new MagicianSkill;
		if (!m_pPlayerInfo->pSkills)return;
		m_pPlayerInfo->pSkills->AddSkill(new M1_MagicClaw);
		break;
	case 3:
		m_pPlayerInfo->pSkills = new ThiefSkill;
		if (!m_pPlayerInfo->pSkills)return;
		m_pPlayerInfo->pSkills->AddSkill(new T1_LuckySeven);
		break;
	default :
		break;
	}
	
}

void CPlayer::AddEXP(const int iNum)
{
	m_pObject->iNowEXP += iNum;
	if (m_pObject->iNowEXP >= m_pObject->iMaxEXP) LevelUP();
	
}

void CPlayer::SetPlayerInfo()
{
	m_pPlayerInfo = new PLAYERINFO;
}

void CPlayer::SetPlayerInven()
{
	m_pPlayerInventory = new CPlayerInventory;
}

void CPlayer::SetPlayerEquipInven()
{
	m_pEquipmentInventory = new CEquipmentInventory;
}

void CPlayer::LevelUP()
{
	m_pObject->iLevel++;
	m_pObject->iNowEXP -= m_pObject->iMaxEXP;
	m_pObject->iMaxEXP = static_cast<int>(static_cast<float>(m_pObject->iMaxEXP) * 1.5f);
	m_pPlayerInfo->iStatPoint += 4;
	SetObjectHP(m_pObject->iMaxHealthValue);
	m_pObject->iHealthValue = m_pObject->iMaxHealthValue;
	std::cout << "레벨이 올랐습니다!" << std::endl;
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
		std::cout << "나가기 0 " << std::endl;
		std::cout << "올릴 스텟을 눌러주세요 : ";
		std::cin >> iInput;

		if (m_pPlayerInfo->iStatPoint == 0)
		{
			std::cout << "스텟포인트가 부족합니다!" << std::endl;
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
				std::cout << "잘못 누르셨습니다" << std::endl;
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
	if (GetObjectType() == 전사)
	{
		m_pObject->iAttackValue = m_pObject->iAttackValue + m_pPlayerInfo->iSTR;
		m_pObject->iMaxHealthValue = m_pObject->iLevel * 10 + m_pPlayerInfo->iSTR * 10;
	}
	if (GetObjectType() == 도적)
		m_pObject->iAttackValue = static_cast<int>(10 + static_cast<float>(m_pPlayerInfo->iLUK)/2.0f);
}



