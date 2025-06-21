#pragma once

#include "Define.h"

class CObject
{
public:
	CObject();
	~CObject();


public:
	enum CHOICE
	{
		전사 = 1,
		마법사,
		도적,
		불러오기,
		나가기
	};
public:
	bool		Initialize(); // 멤버 변수의 값 초기화 함수
	void		Update(const int iDamaged);	  // 매 프레임마다 변경되는 값에 대한 적용 함수
	void		Release();	  // 동적할당한 메모리 해제 코드를 모아 놓는 함수

	void		Load();
	bool		Save();
	void		Render() const;

	void		SetObject(const std::string _sName, const unsigned int _iHealthValue, const unsigned int _iAttackValue);

	inline const int GetObjectHP()const { return m_pObject->iHealthValue; }
	inline const int GetObjectATK() const { return m_pObject->iAttackValue; }
	inline const std::string  GetObjectName() const { return m_pObject->sName; }
	inline void	SetObjectHP(int iHPValue) { m_pObject->iHealthValue = iHPValue; }
private:
	INFO*		m_pObject;
};

