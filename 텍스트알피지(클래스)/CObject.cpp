#include "pch.h"
#include "CObject.h"

CObject::CObject()
{
	m_pObject = nullptr;
}

CObject::~CObject()
{
	Release();
}

bool CObject::Initialize()
{
	int iInput(0);

	system("cls");
	std::cout << "1. 전사 2. 마법사 3. 도적 4. 불러오기 5. 나가기 : ";
	std::cin >> iInput;

	switch (iInput)
	{
	case 전사:
		SetObject("전사", 100, 10);
		break;
	case 마법사:
		SetObject("도적", 100, 10);
		break;
	case 도적:
		SetObject("마법사", 100, 10);
		break;
	case 불러오기:
		Load();
		break;
	case 나가기:
		return false;
	}
	return true;
}

void CObject::Update(const int iDamaged)
{
	SetObjectHP(GetObjectHP() - iDamaged);
}

void CObject::Release()
{
	SAFE_DELETE(m_pObject);
}

void CObject::Load()
{
	std::string		sName, sHealthValue, sAttackValue;
	std::ifstream	inFile("../Data/SavePlayer.txt", std::ios::in);
	
	std::getline(inFile, sName);
	std::getline(inFile, sHealthValue);
	std::getline(inFile, sAttackValue);

	inFile.close();

	SetObject(sName, stoi(sHealthValue), stoi(sAttackValue));
}

bool CObject::Save()
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

void CObject::Render() const
{
	std::cout << "=====================================" << std::endl;
	std::cout << "이름 : " << m_pObject->sName << std::endl;
	std::cout << "체력 : " << m_pObject->iHealthValue << '\t' << "공격력 : " << m_pObject->iAttackValue << std::endl;
}

void CObject::SetObject(const std::string _sName, const unsigned int _iHealthValue, const unsigned int _iAttackValue)
{
	m_pObject = new INFO(_sName, _iHealthValue, _iAttackValue);
}

