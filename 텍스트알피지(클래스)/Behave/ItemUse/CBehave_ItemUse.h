#pragma once
#include "CBehave.h"

class CPlayer;

class CBehave_ItemUse : public CBehave
{
public:
	CBehave_ItemUse();
	~CBehave_ItemUse();

public:
	void Initialize()override;
	void Update()override;
	void Release()override;

	void UseItem(CPlayer* player);
};

