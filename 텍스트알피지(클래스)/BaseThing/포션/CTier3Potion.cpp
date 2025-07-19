#include "CTier3Potion.h"

CTier3Potion::CTier3Potion()
{
}

CTier3Potion::~CTier3Potion()
{
	SAFE_DELETE(m_pPotionInfo);
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
	std::cout << "�̸� : " << m_pPotionInfo->sName << std::endl;
	std::cout << "���� : " << m_pPotionInfo->iPrice << std::endl;
	std::cout << "Ƽ�� : " << m_pPotionInfo->iTier << std::endl;
	std::cout << "ȸ���� :" << m_pPotionInfo->iValue << std::endl;
	std::cout << "========================================" << std::endl;
}

void CTier3Potion::Release()
{
	SAFE_DELETE(m_pPotionInfo);
}

