#pragma once
#include "pch.h"
#include "CBaseInventory.h"


class CBaseThing;
class CBaseWeapon;

class CEquipmentInventory : public CBaseInventory
{
public:
	CEquipmentInventory();
	~CEquipmentInventory();


public:
	void Initialize();
	void Update();
	void Release();

	void Render();

	bool IsWeapon() const;
	bool IsArmor() const;

	inline std::shared_ptr<CBaseThing> GetWeapon() { return m_pWeapon; }
	inline std::shared_ptr<CBaseThing> GetArmor()  { return m_pArmor; }

	inline void SetWeapon(std::shared_ptr<CBaseThing> Weapon) { m_pWeapon = Weapon; }
	inline void SetArmor(std::shared_ptr<CBaseThing> Armor)	  { m_pArmor = Armor; }

private:
	std::shared_ptr<CBaseThing> m_pWeapon;
	std::shared_ptr<CBaseThing> m_pArmor;

};

