#pragma once
#include "pch.h"
#include "CBaseInventory.h"
class CBaseThing;

class CPlayerInventory : public CBaseInventory
{
public:
	CPlayerInventory();
	~CPlayerInventory();

public:
	void Initialize();
	void Update();
	void Update(std::shared_ptr<CBaseThing> CItem, const int iItemtype, const int iUniqueNum);
	void Release();

	void Render();

	// getter
	//std::unordered_map< std::shared_ptr < CBaseThing>, int>* GetInventory() { return &m_Inventory; }
	inline std::vector<std::pair<std::shared_ptr<CBaseThing>, int>>* GetInventory() { return &m_Inventory; }
	inline int GetInventorySize() const{ return m_iInventorySize; }
	inline void SetGetInventorySize(const int iNum) { m_iInventorySize = iNum; }

private:
	CPlayerInventory(const CPlayerInventory&);
	CPlayerInventory& operator=(const CPlayerInventory&);

private:
	//std::unordered_map<std::shared_ptr<CBaseThing>,int> m_Inventory;
	std::vector<std::pair<std::shared_ptr<CBaseThing>, int>> m_Inventory{ 5 };
	int m_iInventorySize;
};

