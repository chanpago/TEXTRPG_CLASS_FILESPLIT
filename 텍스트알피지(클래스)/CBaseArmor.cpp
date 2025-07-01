#include "CBaseArmor.h"

CBaseArmor::CBaseArmor() :m_pArmorInfo(nullptr)
{
}

CBaseArmor::~CBaseArmor()
{
	//std::cout << "베이스 아머 소멸자 호출 " << std::endl;
	Release();
}

void CBaseArmor::Initialize()
{
}

void CBaseArmor::Update()
{
}

void CBaseArmor::Release()
{
	SAFE_DELETE(m_pArmorInfo);
}
