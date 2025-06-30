#pragma once
#include "pch.h"
#include "CEnemy.h"


class CEnemy_Slime : public CEnemy
{
public:

	CEnemy_Slime();
	~CEnemy_Slime();


	
public:
	inline void			Die() const { std::cout << "슬라임이 죽었습니다! " << std::endl; }

};

