#include "pch.h"
#include "CBehaveManager.h"
#include "ItemUse/CBehave_ItemUse.h"
#include "Unequip/CBehave_Unequip.h"
#include "Sell/CBehave_Sell.h"
#include "Fight/CBehave_Fight.h"


void CBehaveManager::Initialize()
{
	Behave_UseItem = new CBehave_ItemUse;
	Behave_Unequip = new CBehave_Unequip;
	Behave_Sell	   = new CBehave_Sell;
	Behave_Fight   = new CBehave_Fight;
}

void CBehaveManager::Update()
{
}

void CBehaveManager::Release()
{
	SAFE_DELETE(Behave_UseItem);
	SAFE_DELETE(Behave_Unequip);
	SAFE_DELETE(Behave_Sell);
	SAFE_DELETE(Behave_Fight);
}
