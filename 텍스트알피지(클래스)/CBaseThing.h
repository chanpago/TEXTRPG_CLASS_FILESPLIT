#pragma once
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
};

