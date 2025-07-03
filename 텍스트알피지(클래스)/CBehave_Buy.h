#pragma once
#include "CBehave.h"

class CPlayer;
class CBaseThing;

class CBehave_Buy : public CBehave
{
public:
	CBehave_Buy();
	~CBehave_Buy();

public:
	void Initialize();
	void Update();
	void Release();

	bool Buy(CPlayer* player, std::shared_ptr<CBaseThing> something);
};

