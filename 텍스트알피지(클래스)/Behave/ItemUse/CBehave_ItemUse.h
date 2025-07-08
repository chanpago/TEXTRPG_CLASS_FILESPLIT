#pragma once
#include "CBehave.h"

class CPlayer;

class CBehave_ItemUse : public CBehave
{
public:
	CBehave_ItemUse();
	~CBehave_ItemUse();

public:
	void Initialize();
	void Update();
	void Release();

	void UseItem(CPlayer* player);
};

