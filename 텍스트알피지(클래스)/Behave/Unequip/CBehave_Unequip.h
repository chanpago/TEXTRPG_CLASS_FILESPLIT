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
	void Initialize();
	void Update();
	void Release();

	void UnEquipment(CPlayer* player);
private:
	
};

