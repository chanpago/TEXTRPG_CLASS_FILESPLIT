#pragma once

class CBaseWeapon;
class CBaseArmor;

class CBaseShop
{
public:
	CBaseShop();
	virtual ~CBaseShop();

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Release();

	virtual void Render() = 0;

	//virtual void Sell() = 0;

	inline void SetWeapon(CBaseWeapon* Weapon) { m_pWeapon = Weapon; }
	inline void SetArmor(CBaseArmor* Armor) { m_pArmor = Armor; }

	inline CBaseWeapon**	GetWeapon(){ return &m_pWeapon; }
	inline CBaseArmor**	GetArmor(){ return &m_pArmor; }

private:
	CBaseShop(const CBaseShop&);
	CBaseShop& operator=(const CBaseShop&);

private:
	CBaseWeapon* m_pWeapon;
	CBaseArmor* m_pArmor;
};

