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

// �ൿ ������ Ŭ������ ���� �Ұ�
private:
	CBehave(const CBehave&);
	CBehave& operator=(const CBehave&);
};

