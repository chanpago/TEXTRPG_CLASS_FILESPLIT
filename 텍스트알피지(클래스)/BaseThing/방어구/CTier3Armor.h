#pragma once
#include "CBaseArmor.h"


class CTier3Armor : public CBaseArmor
{
public:
	CTier3Armor();
	~CTier3Armor();

public:
	void Initialize();
	void Update();

	void Render();
};

