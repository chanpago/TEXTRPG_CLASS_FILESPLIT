#include "CTier3Potion.h"

CTier3Potion::CTier3Potion()
{
}

CTier3Potion::~CTier3Potion()
{
}

void CTier3Potion::Initialize()
{
	// �̸�, ����, ���, Ÿ��, ȸ����, ������ȣ
	SetPotion(new POTIONINFO("�ʱ� ����", 50, 3, 2, 50, 0));
}

void CTier3Potion::Update()
{
}

void CTier3Potion::Render()
{
	std::cout << "========================================" << std::endl;
	std::cout << "�̸� : " << (*GetPotionInfo())->sName << std::endl;
	std::cout << "���� : " << (*GetPotionInfo())->iPrice << std::endl;
	std::cout << "Ƽ�� : " << (*GetPotionInfo())->iTier << std::endl;
	std::cout << "ȸ���� :" << (*GetPotionInfo())->iValue << std::endl;
	std::cout << "========================================" << std::endl;
}

