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
		���� = 1,
		������,
		����,
		�ҷ�����,
		������
	};
public:
	bool		Initialize(); // ��� ������ �� �ʱ�ȭ �Լ�
	void		Update(const int iDamaged);	  // �� �����Ӹ��� ����Ǵ� ���� ���� ���� �Լ�
	void		Release();	  // �����Ҵ��� �޸� ���� �ڵ带 ��� ���� �Լ�

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

