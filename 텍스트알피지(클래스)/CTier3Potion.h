#pragma once
#include "CBasePotion.h"
class CTier3Potion : public CBasePotion
{
public:
	CTier3Potion();
	~CTier3Potion();

public:
	void Initialize();
	void Update();

	void Render();
};

