#pragma once
#include "pch.h"

class W0_BasicSkill
{
public:
	W0_BasicSkill(const std::string& _sSkillName);
	virtual ~W0_BasicSkill();


public:
	inline const int			GetSkillPoint()const			{ return m_iSkillPoint; };
	inline void					SetSkillPoint(const int iNum)	{ m_iSkillPoint = iNum; };
	inline const std::string	GetSkillName()const				{ return m_sSkillName; };
	
	virtual float				UseSkill(const float) = 0;

private:
	std::string m_sSkillName;
	int m_iSkillPoint;
};

