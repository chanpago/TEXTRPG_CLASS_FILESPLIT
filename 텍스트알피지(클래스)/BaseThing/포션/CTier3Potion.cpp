#include "CTier3Potion.h"

CTier3Potion::CTier3Potion()
{
}

CTier3Potion::~CTier3Potion()
{
	SAFE_DELETE(m_pPotionInfo);
}

void CTier3Potion::Initialize()
{
	// 이름, 가격, 등급, 타입, 회복량, 고유번호
	SetPotion(new POTIONINFO("초급 포션", 50, 3, 2, 50, 0));
}

void CTier3Potion::Update()
{
}

void CTier3Potion::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "이름 : " << m_pPotionInfo->sName << std::endl;
	std::cout << "가격 : " << m_pPotionInfo->iPrice << std::endl;
	std::cout << "티어 : " << m_pPotionInfo->iTier << std::endl;
	std::cout << "회복력 :" << m_pPotionInfo->iValue << std::endl;
	std::cout << "========================================" << std::endl;
}

void CTier3Potion::Release()
{
	SAFE_DELETE(m_pPotionInfo);
}

