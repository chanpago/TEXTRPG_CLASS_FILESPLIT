#pragma once
#include "CBaseWeapon.h"
class CTier2Weapon : public CBaseWeapon
{
public:
	CTier2Weapon();
	~CTier2Weapon();

public:

public:
	void Initialize()override;
	void Update()override;
	void Render()override;
	void Release()override;
};

