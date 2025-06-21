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
	std::cout << "1. ���� 2. ������ 3. ���� 4. �ҷ����� 5. ������ : ";
	std::cin >> iInput;

	switch (iInput)
	{
	case ����:
		SetObject("����", 100, 10);
		break;
	case ������:
		SetObject("����", 100, 10);
		break;
	case ����:
		SetObject("������", 100, 10);
		break;
	case �ҷ�����:
		Load();
		break;
	case ������:
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

void CObject::Render() const
{
	std::cout << "=====================================" << std::endl;
	std::cout << "�̸� : " << m_pObject->sName << std::endl;
	std::cout << "ü�� : " << m_pObject->iHealthValue << '\t' << "���ݷ� : " << m_pObject->iAttackValue << std::endl;
}

void CObject::SetObject(const std::string _sName, const unsigned int _iHealthValue, const unsigned int _iAttackValue)
{
	m_pObject = new INFO(_sName, _iHealthValue, _iAttackValue);
}

