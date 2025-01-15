#include "pch.h"

#include"Creature/Creature.h"

bool CheckEnemysAlive(vector<Creature*>& enemys)
{
	
	return any_of(enemys.begin(), enemys.end(), [](Creature* e) {return e->IsAlive();});

}