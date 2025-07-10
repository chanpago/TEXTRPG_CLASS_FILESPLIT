#include "CTier3Armor.h"

CTier3Armor::CTier3Armor()
{
}

CTier3Armor::~CTier3Armor()
{
}

void CTier3Armor::Initialize()
{
	// 이름, 가격, 등급, 타입, 아머량, 고유번호
	SetArmor(new ARMORINFO("초급 방어구", 500, 3, 1, 10, 20));
}

void CTier3Armor::Update()
{
}

void CTier3Armor::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "이름 : " << (*GetArmorInfo())->sName << std::endl;
	std::cout << "가격 : " << (*GetArmorInfo())->iPrice << std::endl;
	std::cout << "티어 : " << (*GetArmorInfo())->iTier << std::endl;
	std::cout << "방어력 :" << (*GetArmorInfo())->iArmorRate << std::endl;
	std::cout << "========================================" << std::endl;
}