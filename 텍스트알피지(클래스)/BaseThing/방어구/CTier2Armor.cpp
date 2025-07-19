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
	// �̸�, ����, ���, Ÿ��, �Ƹӷ�, ������ȣ
	SetArmor(new ARMORINFO("�߱� ��", 1000, 2, 1, 30, 21));
}

void CTier2Armor::Update()
{
}

void CTier2Armor::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "�̸� : " << (*GetArmorInfo())->sName << std::endl;
	std::cout << "���� : " << (*GetArmorInfo())->iPrice << std::endl;
	std::cout << "Ƽ�� : " << (*GetArmorInfo())->iTier << std::endl;
	std::cout << "���� :" << (*GetArmorInfo())->iArmorRate << std::endl;
	std::cout << "========================================" << std::endl;
}

void CTier2Armor::Release()
{
	SAFE_DELETE(m_pArmorInfo);
}
