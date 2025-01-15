#pragma once
#include "Monster.h"
class Goblin :
    public Monster
{
public:
	Goblin(string name, int hp, int atk, int arm, int speed);
	void Act(vector<Creature*>& enemys, vector<Creature*>& friendlys) override;

	void Bite(vector<Creature*>& enemys, vector<Creature*>& friendlys);
};

