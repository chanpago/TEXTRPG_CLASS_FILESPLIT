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
		iStatPoint(0), iSTR(4), iDEX(4), iINT(4), iLUK(4), iMoney(2000) {}



	Skill* pSkills;


	int iStatPoint;

	int iSTR;
	int iDEX;
	int iINT;
	int iLUK;

	int iMoney;

};


enum THINGTYPE
{
	장비 = 1,
	소비,
	기타
};

struct WEAPONINFO 
{
	// 이름, 가격, 등급, 타입, 공격량, 고유번호
	WEAPONINFO(std:: string _sName, int _iPrice, int _iTier, int _iType, int _iAttackValue, int _iUniqueNumber) : sName(_sName), iPrice(_iPrice), iTier(_iTier), iType(_iType), iAttackValue(_iAttackValue), iUniqueNumber(_iUniqueNumber) {}

	std::string sName;
	int iPrice;
	int iTier;
	int iType;
	int iAttackValue;

	const int iUniqueNumber;
};

struct ARMORINFO 
{
	// 이름, 가격, 등급, 타입, 아머량, 고유번호
	ARMORINFO(std::string _sName, int _iPrice, int _iTier, int _iType, int _iArmorRate, int _iUniqueNumber) : sName(_sName), iPrice(_iPrice), iTier(_iTier), iType(_iType), iArmorRate(_iArmorRate), iUniqueNumber(_iUniqueNumber) {}

	std::string sName;
	int iPrice;
	int iTier;
	int iType;
	int iArmorRate;

	const int iUniqueNumber;
};

struct POTIONINFO
{
	// 이름, 가격, 등급, 타입, 회복량, 고유번호
	POTIONINFO(std::string _sName, int _iPrice, int _iTier, int _iType, int _iValue, int _iUniqueNumber) : sName(_sName), iPrice(_iPrice), iTier(_iTier), iType(_iType), iValue(_iValue), iUniqueNumber(_iUniqueNumber){}

	POTIONINFO(const POTIONINFO& potion)
	{
		sName = potion.sName;
		iPrice = potion.iPrice;
		iTier = potion.iTier;
		iType = potion.iType;
		iValue = potion.iValue;
	}

	std::string sName;
	int iPrice;
	int iTier;
	int iType;
	int iValue;

	int iUniqueNumber;
};