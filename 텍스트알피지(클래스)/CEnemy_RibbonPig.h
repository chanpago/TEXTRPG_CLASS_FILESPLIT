#pragma once
#include "pch.h"
#include "CEnemy.h"

class CEnemy_RibbonPig : public CEnemy
{
public:
	CEnemy_RibbonPig();
	~CEnemy_RibbonPig();
	
public:
	inline void			Die() const { std::cout << "���������� �׾����ϴ�! " << std::endl; }
};

