#pragma once
#include "CBaseWeapon.h"


class CTier3Weapon : public CBaseWeapon
{
public:
	CTier3Weapon();
	~CTier3Weapon();


public:
	void Initialize();
	void Update();

	void Render();
};

