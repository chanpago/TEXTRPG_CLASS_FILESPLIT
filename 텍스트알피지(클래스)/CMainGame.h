#pragma once

#include "CObject.h"

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
	void		Fight(CObject* pPlayer, CObject* pEnemy);
private:
	CObject*		m_pPlayer;

};

