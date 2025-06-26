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
	std::cout << "=====================================" << std::endl;
	std::cout << "이름 : " << m_pObject->sName << std::endl;
	std::cout << "체력 : " << m_pObject->iHealthValue << '\t' << "공격력 : " << m_pObject->iAttackValue << std::endl;
}

void CObject::SetObject(const std::string _sName, const int _iHealthValue, const int _iAttackValue)
{
	m_pObject = new INFO(_sName, _iHealthValue, _iAttackValue);
}

