#pragma once
#include "pch.h"
#include "Define.h"



class CObject
{
public:
	CObject();
	virtual ~CObject();


public:
	virtual bool				Initialize(); // ��� ������ �� �ʱ�ȭ �Լ�
	virtual void				Update(const int iType, const int iNum);	  // �� �����Ӹ��� ����Ǵ� ���� ���� ���� �Լ�
	virtual void				Release();	  // �����Ҵ��� �޸� ���� �ڵ带 ��� ���� �Լ�

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

