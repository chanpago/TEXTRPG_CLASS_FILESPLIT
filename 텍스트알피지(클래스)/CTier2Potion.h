#pragma once
#include "CBasePotion.h"
class CTier2Potion : public CBasePotion
{
public:
	CTier2Potion();
	~CTier2Potion();

public:
	void Initialize();
	void Update();

	void Render();
};

