#include "pch.h"
#include "Creature/Creature.h"
#include "Targeting.h"
#include "StateAbnormality.h"

StateAbnormality_Aggro::~StateAbnormality_Aggro()
{
	if (_targeting != nullptr)
	{
		delete _targeting;
		_targeting = nullptr;
	}

}
