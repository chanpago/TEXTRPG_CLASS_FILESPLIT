#pragma once
#include "CBehave.h"

class CPlayer;
class CBaseThing;

class CBehave_Unequip : public CBehave
{
public:
	CBehave_Unequip();
	~CBehave_Unequip();

public:
	void Initialize()override;
	void Update()override;
	void Release()override;

	void UnEquipment(CPlayer* player);
private:
	
};

