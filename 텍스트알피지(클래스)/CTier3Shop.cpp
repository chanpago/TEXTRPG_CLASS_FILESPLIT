#include "CTier3Shop.h"
#include "CBaseWeapon.h"
#include "CTier3Weapon.h"

#include "CBaseArmor.h"
#include "CTier3Armor.h"

CTier3Shop::CTier3Shop()
{
}

CTier3Shop::~CTier3Shop()
{
}

void CTier3Shop::Initialize()
{
	SetWeapon(new CTier3Weapon);
	(*GetWeapon())->Initialize();

	SetArmor(new CTier3Armor);
	(*GetArmor())->Initialize();

}

void CTier3Shop::Update()
{
	int iInput(0);

	Render();
	std::cout << "몇번째 물품을 사시겠습니까? (1. 기본 무기 2. 기본 방어구 3. 나가기) : ";
	std::cin >> iInput;

	switch (iInput)
	{
	case 1:

		break;
	case 2:

		break;

	case 3:
		CBaseShop::Release();
		return;
	default:
		std::cout << "잘못 누르셨습니다" << std::endl;
		break;
	}
}

void CTier3Shop::Release()
{

}

void CTier3Shop::Render()
{
	std::cout << "=================초급상점================" << std::endl;
	(*GetWeapon())->Render();
	(*GetArmor())->Render();
	std::cout << "========================================" << std::endl;
}

void CTier3Shop::Sell(CBaseWeapon* m_pWeapon)
{

}

void CTier3Shop::Sell(CBaseArmor* m_pArmor)
{

}

