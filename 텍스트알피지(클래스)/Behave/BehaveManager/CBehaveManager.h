
class CBehave_ItemUse;
class CBehave_Unequip;
class CBehave_Sell;
class CBehave_Fight;

class CBehaveManager
{
public:
	CBehaveManager() : Behave_UseItem(nullptr), Behave_Unequip(nullptr), Behave_Sell(nullptr), Behave_Fight(nullptr) {};
	~CBehaveManager() { Release(); }

	void		Initialize();		
	void		Update();			
	void		Release();


	// getter
	inline CBehave_ItemUse* GetBehave_ItemUse() { return Behave_UseItem; }
	inline CBehave_Unequip* GetBehave_Unequip() { return Behave_Unequip; }
	inline CBehave_Sell*	GetBehave_Sell()	{ return Behave_Sell; }
	inline CBehave_Fight*	GetBehave_Fight()	{ return Behave_Fight; }

	// setter


private:
	CBehaveManager(const CBehaveManager&);
	CBehaveManager& operator=(const CBehaveManager&);

private:
	CBehave_ItemUse* Behave_UseItem;
	CBehave_Unequip* Behave_Unequip;
	CBehave_Sell*	 Behave_Sell;
	CBehave_Fight*   Behave_Fight;
};