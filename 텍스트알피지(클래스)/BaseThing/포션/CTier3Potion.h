#pragma once
#include "CBasePotion.h"
class CTier3Potion : public CBasePotion
{
public:
	CTier3Potion();
	~CTier3Potion();

public:
	void Initialize()override;
	void Update()override;
	void Render()override;
	void Release()override;
};

