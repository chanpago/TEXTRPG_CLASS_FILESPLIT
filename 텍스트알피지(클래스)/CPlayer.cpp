#include "pch.h"
#include "CPlayer.h"
#include "WarriorSkill.h"
#include "MagicianSkill.h"
#include "ThiefSkill.h"
#include "W0_BasicSkill.h"
#include "Skill.h"

#include "pch_Skill.h"





CPlayer::CPlayer() : Skills(nullptr)
{
}

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
		SetObject("전사", 100, 10);
		CreateSkill(전사);
		break;
	case 마법사:
		SetObject("마법사", 100, 10);
		CreateSkill(마법사);	
		break;
	case 도적:
		SetObject("도적", 100, 10);
		CreateSkill(도적);
		break;
	case 불러오기:
		Load();
		break;
	case 나가기:
		return false;
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
	SAFE_DELETE(Skills);
}

void CPlayer::Render() const
{
	CObject::Render();
	std::cout << "==============" << GetObjectName() << " 스킬" << "==============" << std::endl;

	int i = 1;
	for (auto skill : Skills->GetSkills())
	{
		std::cout << i++ << " : " << "[ " << skill->GetSkillName() << " ]" << std::endl;
	}
	std::cout << "=====================================" << std::endl;
}

void CPlayer::Load()
{
	std::string		sName, sHealthValue, sAttackValue;
	std::ifstream	inFile("../Data/SavePlayer.txt", std::ios::in);

	std::getline(inFile, sName);
	std::getline(inFile, sHealthValue);
	std::getline(inFile, sAttackValue);

	inFile.close();

	SetObject(sName, stoi(sHealthValue), stoi(sAttackValue));
}

bool CPlayer::Save()
{
	std::ofstream	outFile("../Data/SavePlayer.txt", std::ios::out);
	if (!outFile.is_open()) {
		std::cerr << "파일 저장 실패" << std::endl;
		return false;
	}

	outFile << GetObjectName() << '\n';
	outFile << GetObjectHP() << '\n';
	outFile << GetObjectATK() << '\n';
	std::cout << "파일 저장 성공" << std::endl;

	system("pause");

	return true;

}

void CPlayer::CreateSkill(const int iNum)
{
	switch (iNum)
	{
	case 1:
		Skills = new WarriorSkill;
		Skills->AddSkill(new W1_PowerStrike);
		break;
	case 2:
		Skills = new MagicianSkill;
		Skills->AddSkill(new M1_MagicClaw);
		break;
	case 3:
		Skills = new ThiefSkill;
		Skills->AddSkill(new T1_LuckySeven);
		break;
	default :
		break;
	}
	
}


