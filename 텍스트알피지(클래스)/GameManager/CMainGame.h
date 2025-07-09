#pragma once
#include "pch.h"
#include "pch_Monster.h"



class CPlayer;
class CBehaveManager;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();


public:
	

public:
	void		Initialize();		// ��� ������ �� �ʱ�ȭ �Լ�
	void		Update();			// �� �����Ӹ��� ����Ǵ� ���� ���� �����Լ�
	void		Release();			// �����Ҵ��� �޸� ���� �ڵ� ��Ƴ����Լ�
	void		Field();
	void		Shop();



// ���ΰ��� �������
private:
	CMainGame(const CMainGame&);
	CMainGame& operator=(const CMainGame&);

private:
	CPlayer*				m_pPlayer;
	CBehaveManager*			m_pBehaveManager;
};

