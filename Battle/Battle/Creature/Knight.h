#pragma once
#include "Player.h"
class Knight :
    public Player
{
public:


	Knight(string name, int hp, int atk, int arm, int speed);
	void Act(Creature* enemys[], int enemyCount, Creature* friendlys[], int friendCount) override;

	void Smite(Creature* enemys[], int enemyCount);
	void MoonSlash(Creature* enemys[], int enemyCount);

};

