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

	void						SetObject(const std::string _sName, const int _iHealthValue, const int _iAttackValue);
	inline INFO**				GetObject()					{ return &m_pObject; }


	inline const int			GetObjectHP()const			{ return m_pObject->iHealthValue; }
	inline const int			GetObjectATK() const		{ return m_pObject->iAttackValue; }
	inline const std::string	GetObjectName() const		{ return m_pObject->sName; }
	inline void					SetObjectHP(int iHPValue)	{ m_pObject->iHealthValue = iHPValue; }


private:
	INFO*		m_pObject;
};

