#pragma once
#include "pch.h"
#include "CEnemy.h"

class CEnemy_MushMom : public CEnemy
{
public:
	CEnemy_MushMom();
	~CEnemy_MushMom();

public:
	inline void			Die() const { std::cout << "�ӽ����� �׾����ϴ�! " << std::endl; }
};

