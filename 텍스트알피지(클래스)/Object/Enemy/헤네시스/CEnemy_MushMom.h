#pragma once
#include "pch.h"
#include "Enemy/CEnemy.h"

class CEnemy_MushMom : public CEnemy
{
public:
	CEnemy_MushMom();
	~CEnemy_MushMom();

public:
	inline void	Die() const override { std::cout << "�ӽ����� �׾����ϴ�! " << std::endl; }
};

