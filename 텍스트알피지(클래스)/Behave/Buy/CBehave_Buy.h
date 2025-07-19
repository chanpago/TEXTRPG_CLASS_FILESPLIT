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
	void Initialize()override;
	void Update()override;
	void Release()override;

	bool Buy(CPlayer* player, std::shared_ptr<CBaseThing> something);
private:
	
};

