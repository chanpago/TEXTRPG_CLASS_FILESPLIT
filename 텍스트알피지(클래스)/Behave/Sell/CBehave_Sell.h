#pragma once
#include "CBehave.h"

class CPlayer;
class CBaseThing;

class CBehave_Sell : public CBehave
{
public:
	CBehave_Sell();
	~CBehave_Sell();

public:
	void Initialize()override;
	void Update()override;
	void Release()override;

	void Sell(CPlayer* player);
};

