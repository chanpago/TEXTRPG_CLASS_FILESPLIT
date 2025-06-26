#pragma once
#include "pch.h"




struct INFO
{
	INFO(std::string _sName, unsigned int  _iHealthValue, unsigned int _iAttackValue) :
		sName(_sName), iHealthValue(_iHealthValue), iAttackValue(_iAttackValue) {}
	std::string		sName;
	int	iHealthValue, iAttackValue;
};