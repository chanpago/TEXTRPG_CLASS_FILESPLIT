#pragma once
#include "pch.h"


class Skill;

struct OBJECTINFO
{
	//플레이어용
	OBJECTINFO(std::string _sName, std::string _sJob, int _iObjectType) :
		sName(_sName), sJob(_sJob), iAttackValue(10), iHealthValue(50), iMaxHealthValue(50),
		iManaValue(50), iMaxManaValue(50), iMaxEXP(15), iNowEXP(0), iLevel(1), iObjectType(_iObjectType){}


	//몬스터용
	OBJECTINFO(std::string _sName, std::string _sJob, int _iAttackValue, int _iMaxHealthValue, int _iMaxManaValue, int _iMaxEXP, int _iLevel, int _iObjectType) :
		sName(_sName), sJob(_sJob), iAttackValue(_iAttackValue), iHealthValue(_iMaxHealthValue), iMaxHealthValue(_iMaxHealthValue), 
		iManaValue(_iMaxManaValue), iMaxManaValue(_iMaxManaValue), iMaxEXP(_iMaxEXP), iNowEXP(0), iLevel(_iLevel), iObjectType(_iObjectType) {}


	std::string		sName;
	std::string		sJob;
	int	iAttackValue;
	int iHealthValue, iMaxHealthValue;
	int iManaValue, iMaxManaValue;
	int iNowEXP, iMaxEXP;
	int iLevel;
	int iObjectType;
};

struct PLAYERINFO
{
	PLAYERINFO() : pSkills(nullptr),
		iStatPoint(0), iSTR(4), iDEX(4), iINT(4), iLUK(4) {}



	Skill* pSkills;


	int iStatPoint;

	int iSTR;
	int iDEX;
	int iINT;
	int iLUK;

};