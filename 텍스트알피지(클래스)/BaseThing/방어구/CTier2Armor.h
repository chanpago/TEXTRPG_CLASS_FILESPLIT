#pragma once
#include "CBaseArmor.h"
class CTier2Armor : public CBaseArmor
{
public:
	CTier2Armor();
	~CTier2Armor();

public:
	void Initialize()override;
	void Update()override;
	void Render()override;
	void Release()override;
};

