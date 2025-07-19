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
	void Initialize()override;
	void Update()override;
	void Release()override;

	void Fight(CPlayer* player, CObject* monster);
	void SkillAttack(CPlayer* player, CObject* monster);
};

