#pragma once
#include "CBaseArmor.h"
class CTier2Armor : public CBaseArmor
{
public:
	CTier2Armor();
	~CTier2Armor();

public:
	void Initialize();
	void Update();

	void Render();
};

