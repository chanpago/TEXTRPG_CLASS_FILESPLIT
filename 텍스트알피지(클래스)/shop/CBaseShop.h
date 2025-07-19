#pragma once

class CPlayer;

class CBaseShop
{
public:
	CBaseShop() {};
	virtual ~CBaseShop() {};

public:
	virtual void Initialize() = 0;
	virtual void Update(CPlayer* player) = 0;
	virtual void Release() = 0;

	virtual void Render() = 0;

	//virtual void Sell() = 0;

private:
	CBaseShop(const CBaseShop&);
	CBaseShop& operator=(const CBaseShop&);
};

