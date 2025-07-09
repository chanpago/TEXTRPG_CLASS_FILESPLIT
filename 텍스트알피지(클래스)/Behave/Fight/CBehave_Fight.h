#pragma once
#include "CBehave.h"


class CObject;
class CPlayer;

class CBehave_Fight : public CBehave
{
public:
	CBehave_Fight();
	~CBehave_Fight();

public:
	void Initialize();
	void Update();
	void Release();

	void Fight(CPlayer* player, CObject* monster);
	void SkillAttack(CPlayer* player, CObject* monster);
};

