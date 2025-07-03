#pragma once
#include "pch.h"
#include "CBaseShop.h"

class CBaseThing;
class CBehave_Buy;
class CPlayer;

class CTier2Shop : public CBaseShop
{
public:

	CTier2Shop();
	~CTier2Shop();
	
public:
	void Initialize();
	void Update(CPlayer* player);
	void Release();

	void Render();


private:
	std::unordered_map<std::shared_ptr<CBaseThing>, int> ItemList;
	CBehave_Buy* BuyItem;
};

