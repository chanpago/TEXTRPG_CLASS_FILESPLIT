#include "CTier2Potion.h"

CTier2Potion::CTier2Potion()
{
}

CTier2Potion::~CTier2Potion()
{
}

void CTier2Potion::Initialize()
{
	// �̸�, ����, ���, Ÿ��, ȸ����, ������ȣ
	SetPotion(new POTIONINFO("�߱� ����", 100, 2, 2, 100, 1));
}

void CTier2Potion::Update()
{
}

void CTier2Potion::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "�̸� : " << (*GetPotionInfo())->sName << std::endl;
	std::cout << "���� : " << (*GetPotionInfo())->iPrice << std::endl;
	std::cout << "Ƽ�� : " << (*GetPotionInfo())->iTier << std::endl;
	std::cout << "ȸ���� :" << (*GetPotionInfo())->iValue << std::endl;
	std::cout << "========================================" << std::endl;
}
