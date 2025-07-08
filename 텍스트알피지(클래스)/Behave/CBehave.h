#pragma once
class CBehave
{
public:
	CBehave();
	virtual ~CBehave();

public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Release() = 0;

// 행동 개념의 클래스는 복사 불가
private:
	CBehave(const CBehave&);
	CBehave& operator=(const CBehave&);
};

