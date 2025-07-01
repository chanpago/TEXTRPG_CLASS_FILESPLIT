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
	std::cout << "Ƽ�� " << (*GetArmorInfo())->iTier << " ";

	switch ((*GetArmorInfo())->iType)
	{
	case 2:
		std::cout << "�⺻ ��" << std::endl;
		break;
	default:
		std::cout << "��������";
		break;
	}
	std::cout << "���� : " << (*GetArmorInfo())->iPrice << std::endl;
	std::cout << "========================================" << std::endl;
}
