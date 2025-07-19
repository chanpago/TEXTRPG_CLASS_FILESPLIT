#pragma once
#include "CBaseArmor.h"


class CTier3Armor : public CBaseArmor
{
public:
	CTier3Armor();
	~CTier3Armor();

public:
	void Initialize()override;
	void Update()override;
	void Render()override;	
	void Release()override;
};

