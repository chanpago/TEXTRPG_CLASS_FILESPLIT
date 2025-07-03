#pragma once
class CBaseInventory
{
public:
	CBaseInventory();
	virtual ~CBaseInventory();

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Release() = 0;

	virtual void Render() = 0;

private:
	CBaseInventory(const CBaseInventory&);
	CBaseInventory& operator=(const CBaseInventory&);
};

