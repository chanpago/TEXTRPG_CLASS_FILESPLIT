#include "CBaseArmor.h"

CBaseArmor::CBaseArmor() :m_pArmorInfo(nullptr)
{
}

CBaseArmor::~CBaseArmor()
{
	//std::cout << "���̽� �Ƹ� �Ҹ��� ȣ�� " << std::endl;
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
