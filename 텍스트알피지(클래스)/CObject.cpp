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
	return true;
}

void CObject::Update(const int iType, const int iNum)
{
	switch (iType)
	{
	case 2:
		SetObjectHP(GetObjectHP() - iNum);
		break;
	default:
		break;
	}
	
}

void CObject::Release()
{
	SAFE_DELETE(m_pObject);
}



void CObject::Render() const
{
	std::cout << "========================================" << std::endl;
	std::cout << "이름 : " << m_pObject->sName << '\t' << "직업 : " << m_pObject->sJob << '\t' << "레벨 : " << m_pObject->iLevel << std::endl;
	std::cout << "공격력 : " << m_pObject->iAttackValue << std::endl;
	std::cout << "HP : " << m_pObject->iHealthValue << '/' << m_pObject->iMaxHealthValue << '\t' << std::endl;
	std::cout << "MP : " << m_pObject->iManaValue << '/' << m_pObject->iMaxManaValue << std::endl;
	std::cout << "EXP : " << m_pObject->iNowEXP << '/' << m_pObject->iMaxEXP << std::endl;
	std::cout << "========================================" << std::endl;
}

void CObject::SetObject(const std::string _sName, const std::string _sJob, const int _iObjectType)
{
	m_pObject = new OBJECTINFO(_sName, _sJob, _iObjectType);
}

void CObject::SetObject(const std::string _sName, const std::string _sJob, const int AttackValue, const int MaxHealthValue, const int MaxManaValue, const int EXP , const int Level, const int _iObjectType)
{
	m_pObject = new OBJECTINFO(_sName, _sJob, AttackValue, MaxHealthValue, MaxManaValue, EXP, Level, _iObjectType);
}

