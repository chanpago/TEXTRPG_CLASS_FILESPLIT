#pragma once
#include "pch.h"
#include "CEnemy.h"

class CEnemy_RibbonPig : public CEnemy
{
public:
	CEnemy_RibbonPig();
	~CEnemy_RibbonPig();
	
public:
	inline void			Die() const { std::cout << "¸®º»µÅÁö°¡ Á×¾ú½À´Ï´Ù! " << std::endl; }
};

