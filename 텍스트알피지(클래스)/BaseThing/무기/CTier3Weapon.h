#pragma once
#include "CBaseWeapon.h"


class CTier3Weapon : public CBaseWeapon
{
public:
	CTier3Weapon();
	~CTier3Weapon();


public:
	void Initialize()override;
	void Update()override;
	void Render()override;
	void Release()override;
};

