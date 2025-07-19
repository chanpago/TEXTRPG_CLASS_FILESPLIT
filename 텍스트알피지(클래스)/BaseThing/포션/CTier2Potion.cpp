#include "CTier2Potion.h"

CTier2Potion::CTier2Potion()
{
}

CTier2Potion::~CTier2Potion()
{
	Release();
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
	std::cout << "�̸� : " << m_pPotionInfo->sName << std::endl;
	std::cout << "���� : " << m_pPotionInfo->iPrice << std::endl;
	std::cout << "Ƽ�� : " << m_pPotionInfo->iTier << std::endl;
	std::cout << "ȸ���� :" << m_pPotionInfo->iValue << std::endl;
	std::cout << "========================================" << std::endl;
}

void CTier2Potion::Release()
{
	SAFE_DELETE(m_pPotionInfo);
}
