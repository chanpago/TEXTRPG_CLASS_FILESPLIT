#pragma once
#include "pch.h"
#include "pch_Monster.h"



class CPlayer;
class CBehave_ItemUse;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();


public:
	

public:
	bool		Initialize();		// ��� ������ �� �ʱ�ȭ �Լ�
	void		Update();			// �� �����Ӹ��� ����Ǵ� ���� ���� �����Լ�
	void		Release();			// �����Ҵ��� �޸� ���� �ڵ� ��Ƴ����Լ�
	void		Field();
	void		Fight(CPlayer* pPlayer, CObject* pEnemy);
	void		Shop();
	void		SkillAttack(CPlayer* pPlayer, CObject* pEnemy);
private:
	CPlayer*		m_pPlayer;
	CBehave_ItemUse*		Behave_UseItem;
};

