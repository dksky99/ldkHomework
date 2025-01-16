#pragma once
#include "pch.h"

class Creature;
class Targeting
{
public:
	Targeting() = default;
	~Targeting() {}
	virtual  Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys) ;
};

class RandomTargeting :public Targeting
{
public:
	RandomTargeting() = default;
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys) override;


};

class RevengeTargeting :public Targeting
{
public:
	RevengeTargeting() = default;
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys)override;
public:
	int rank=0;

};

class LowHPTargeting :public Targeting
{
public:
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys)override;


	LowHPTargeting() = default;
};
class HighHPTargeting :public Targeting
{
public:
	HighHPTargeting() = default;
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys)override;

};


class AggroTargeting :public Targeting
{
public:
	AggroTargeting() = default;
	virtual Creature* operator()(Creature& owner, vector<Creature*> enemys, vector<Creature*> friendlys)override;
	~AggroTargeting() ;
public:
	Creature* target=nullptr;

};



