#pragma once
#include "Player.h"
class Knight :
    public Player
{
public:


	Knight(string name, int hp, int atk, int arm, int speed);


	void Act(vector<Creature*>& enemys, vector<Creature*>& friendlys) override;

	void Smite(vector<Creature*>& enemys, vector<Creature*>& friendlys);
	void MoonSlash(vector<Creature*>& enemys, vector<Creature*>& friendlys);


};

