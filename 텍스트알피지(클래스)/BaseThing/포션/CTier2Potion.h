#pragma once
#include "CBasePotion.h"
class CTier2Potion : public CBasePotion
{
public:
	CTier2Potion();
	~CTier2Potion();

public:
	void Initialize()override;
	void Update()override;
	void Render()override;
	void Release()override;
};

