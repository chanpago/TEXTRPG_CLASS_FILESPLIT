#include "CTier2Potion.h"

CTier2Potion::CTier2Potion()
{
}

CTier2Potion::~CTier2Potion()
{
	Release();
}

void CTier2Potion::Initialize()
{
	// 이름, 가격, 등급, 타입, 회복량, 고유번호
	SetPotion(new POTIONINFO("중급 포션", 100, 2, 2, 100, 1));
}

void CTier2Potion::Update()
{
}

void CTier2Potion::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "이름 : " << m_pPotionInfo->sName << std::endl;
	std::cout << "가격 : " << m_pPotionInfo->iPrice << std::endl;
	std::cout << "티어 : " << m_pPotionInfo->iTier << std::endl;
	std::cout << "회복력 :" << m_pPotionInfo->iValue << std::endl;
	std::cout << "========================================" << std::endl;
}

void CTier2Potion::Release()
{
	SAFE_DELETE(m_pPotionInfo);
}
