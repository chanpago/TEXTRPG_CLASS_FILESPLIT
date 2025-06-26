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
	std::cout << "1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ������ : ";
	std::cin >> iInput;

	switch (iInput)
	{
	case ����:
		SetObject("����", 100, 10);
		CreateSkill(����);
		break;
	case ������:
		SetObject("������", 100, 10);
		CreateSkill(������);	
		break;
	case ����:
		SetObject("����", 100, 10);
		CreateSkill(����);
		break;
	case �ҷ�����:
		Load();
		break;
	case ������:
		return false;
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
	SAFE_DELETE(Skills);
}

void CPlayer::Render() const
{
	CObject::Render();
	std::cout << "==============" << GetObjectName() << " ��ų" << "==============" << std::endl;

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
		std::cerr << "���� ���� ����" << std::endl;
		return false;
	}

	outFile << GetObjectName() << '\n';
	outFile << GetObjectHP() << '\n';
	outFile << GetObjectATK() << '\n';
	std::cout << "���� ���� ����" << std::endl;

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


