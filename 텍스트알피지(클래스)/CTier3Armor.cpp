#include "CTier3Armor.h"

CTier3Armor::CTier3Armor()
{
}

CTier3Armor::~CTier3Armor()
{
}

void CTier3Armor::Initialize()
{
	SetArmor(new ARMORINFO(500, 3, 2));
}

void CTier3Armor::Update()
{
}

void CTier3Armor::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "티어 " << (*GetArmorInfo())->iTier << " ";

	switch ((*GetArmorInfo())->iType)
	{
	case 2:
		std::cout << "기본 방어구" << std::endl;
		break;
	default:
		std::cout << "오류무기";
		break;
	}
	std::cout << "가격 : " << (*GetArmorInfo())->iPrice << std::endl;
	std::cout << "========================================" << std::endl;
}
