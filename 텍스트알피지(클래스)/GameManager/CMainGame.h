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
	void		Initialize();		// 멤버 변수의 값 초기화 함수
	void		Update();			// 메 프레임마다 변경되는 값에 대한 적용함수
	void		Release();			// 동적할당한 메모리 헤제 코드 모아놓는함수
	void		Field();
	void		Shop();



// 메인게임 복사금지
private:
	CMainGame(const CMainGame&);
	CMainGame& operator=(const CMainGame&);

private:
	CPlayer*				m_pPlayer;
	CBehaveManager*			m_pBehaveManager;
};

