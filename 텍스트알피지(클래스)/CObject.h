#pragma once
#include "pch.h"
#include "Define.h"



class CObject
{
public:
	CObject();
	virtual ~CObject();


public:
	virtual bool				Initialize(); // 멤버 변수의 값 초기화 함수
	virtual void				Update(const int iType, const int iNum);	  // 매 프레임마다 변경되는 값에 대한 적용 함수
	virtual void				Release();	  // 동적할당한 메모리 해제 코드를 모아 놓는 함수

	virtual void				Render() const;

	void						SetObject(const std::string _sName, const std::string _sJob, const int _iObjectType);
	void						SetObject(const std::string _sName, const std::string _sJob, const int AttackValue, const int MaxHealthValue, const int MaxManaValue, const int EXP, const int Level, const int _iObjectType);
	inline OBJECTINFO**			GetObject()					{ return &m_pObject; }


	inline void					SetObjectHP(int iHPValue)   { m_pObject->iHealthValue = iHPValue; }
	inline const int			GetObjectHP()const			{ return m_pObject->iHealthValue; }

	inline const int			GetObjectATK() const		{ return m_pObject->iAttackValue; }
	inline const std::string	GetObjectJob() const		{ return m_pObject->sJob; }
	
	inline const int			GetEXP() const				{ return m_pObject->iMaxEXP; }
	
	inline const int			GetObjectType() const		{ return m_pObject->iObjectType; }


	virtual void		Die() const = 0;
private:
	OBJECTINFO*		m_pObject;
};

