#pragma once
#include "Player.h"
class Archer :
    public Player
{
public:

	Archer(string name, int hp, int atk, int arm, int speed);
	void Act(vector<Creature*>& enemys, vector<Creature*>& friendlys) override;

	void Multishot(vector<Creature*>& enemys, vector<Creature*>& friendlys);
	void Sniping(vector<Creature*>& enemys, vector<Creature*>& friendlys);
	
	
};

