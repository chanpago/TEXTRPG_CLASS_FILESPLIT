#include "CBasePotion.h"





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

void CBasePotion::Render()
{
}

void CBasePotion::Release()
{
	
}
