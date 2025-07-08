#pragma once
#include "pch.h"

class CBaseThing
{
public:
	CBaseThing();
	virtual ~CBaseThing();

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Release() = 0;

	virtual void Render() = 0;

	// getter
	virtual int			GetType() const			= 0;
	virtual int			GetUniqueNum() const	= 0;
	virtual int			GetPrice() const		= 0;
	virtual std::string GetName() const			= 0;
	virtual int			GetValue() const		= 0;
};

