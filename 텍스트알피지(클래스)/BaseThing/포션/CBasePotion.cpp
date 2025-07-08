#include "CBasePotion.h"

CBasePotion::CBasePotion() : m_pPotionInfo(nullptr)
{
}

CBasePotion::~CBasePotion()
{
	Release();
}

CBasePotion::CBasePotion(const CBasePotion& Potion)
{
	m_pPotionInfo = new POTIONINFO(*(Potion.m_pPotionInfo));
}

void CBasePotion::Initialize()
{
}

void CBasePotion::Update()
{
}

void CBasePotion::Release()
{
	SAFE_DELETE(m_pPotionInfo);
}
