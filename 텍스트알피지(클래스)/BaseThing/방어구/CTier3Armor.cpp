#include "CTier3Armor.h"

CTier3Armor::CTier3Armor()
{
}

CTier3Armor::~CTier3Armor()
{
}

void CTier3Armor::Initialize()
{
	// �̸�, ����, ���, Ÿ��, �Ƹӷ�, ������ȣ
	SetArmor(new ARMORINFO("�ʱ� ��", 500, 3, 1, 10, 20));
}

void CTier3Armor::Update()
{
}

void CTier3Armor::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "�̸� : " << (*GetArmorInfo())->sName << std::endl;
	std::cout << "���� : " << (*GetArmorInfo())->iPrice << std::endl;
	std::cout << "Ƽ�� : " << (*GetArmorInfo())->iTier << std::endl;
	std::cout << "���� :" << (*GetArmorInfo())->iArmorRate << std::endl;
	std::cout << "========================================" << std::endl;
}