#pragma once
#include "pch.h"
#include "Enemy/CEnemy.h"

class CEnemy_RibbonPig : public CEnemy
{
public:
	CEnemy_RibbonPig();
	~CEnemy_RibbonPig();
	
public:
	inline void	Die() const override { std::cout << "���������� �׾����ϴ�! " << std::endl; }
};

