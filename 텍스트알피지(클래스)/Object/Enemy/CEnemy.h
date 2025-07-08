#pragma once
#include "pch.h"
#include "CObject.h"
#include "Define.h"


class CEnemy : public CObject
{
public:
	CEnemy();
	virtual ~CEnemy();

	virtual void		Die() const;


private:
	CEnemy(const CEnemy&);
	CEnemy& operator=(const CEnemy&);
};

