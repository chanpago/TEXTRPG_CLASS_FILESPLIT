#include "CTier2Armor.h"

CTier2Armor::CTier2Armor()
{
}

CTier2Armor::~CTier2Armor()
{
	Release();
}

void CTier2Armor::Initialize()
{
	// 이름, 가격, 등급, 타입, 아머량, 고유번호
	SetArmor(new ARMORINFO("중급 방어구", 1000, 2, 1, 30, 21));
}

void CTier2Armor::Update()
{
}

void CTier2Armor::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "이름 : " << (*GetArmorInfo())->sName << std::endl;
	std::cout << "가격 : " << (*GetArmorInfo())->iPrice << std::endl;
	std::cout << "티어 : " << (*GetArmorInfo())->iTier << std::endl;
	std::cout << "방어력 :" << (*GetArmorInfo())->iArmorRate << std::endl;
	std::cout << "========================================" << std::endl;
}

void CTier2Armor::Release()
{
	SAFE_DELETE(m_pArmorInfo);
}
