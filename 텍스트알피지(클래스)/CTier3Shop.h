#pragma once
#include "CBaseShop.h"

class CTier3Shop : public CBaseShop
{
public:

	CTier3Shop();
	~CTier3Shop();

public:
	void Initialize();
	void Update();
	void Release();

	void Render();

	void Sell(CBaseWeapon* m_pWeapon);
	void Sell(CBaseArmor* m_pArmor);


};

