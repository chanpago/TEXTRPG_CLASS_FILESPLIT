#pragma once
#include "pch.h"
#include "CBaseShop.h"

class CBaseThing;
class CBehave_Buy;
class CPlayer;

class CTier3Shop : public CBaseShop
{
public:

	CTier3Shop() {};
	~CTier3Shop();

public:
	void Initialize()override;
	void Update(CPlayer* player)override;
	void Release()override;

	void Render()override;


private:
	std::unordered_map<std::shared_ptr<CBaseThing>,int> ItemList;
	CBehave_Buy* BuyItem{};
};

