#pragma once
#include "pch.h"
#include "CEnemy.h"

class CEnemy_MushMom : public CEnemy
{
public:
	CEnemy_MushMom();
	~CEnemy_MushMom();

public:
	inline void			Die() const { std::cout << "¸Ó½¬¸¾ÀÌ Á×¾ú½À´Ï´Ù! " << std::endl; }
};

