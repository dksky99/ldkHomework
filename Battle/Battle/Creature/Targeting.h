#pragma once
#include "pch.h"

class Creature;
class Targeting
{
public:
	Targeting() = default;
	~Targeting() {}
	virtual shared_ptr<Creature> operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys) ;
};

class RandomTargeting :public Targeting
{
public:
	RandomTargeting() = default;
	virtual shared_ptr<Creature> operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys) override;


};

class RevengeTargeting :public Targeting
{
public:
	RevengeTargeting() = default;
	virtual shared_ptr<Creature> operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys) override;
public:
	int rank=0;

};

class LowHPTargeting :public Targeting
{
public:
	virtual shared_ptr<Creature> operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys) override;


	LowHPTargeting() = default;
};
class HighHPTargeting :public Targeting
{
public:
	HighHPTargeting() = default;
	virtual shared_ptr<Creature> operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys) override;

};


class AggroTargeting :public Targeting
{
public:
	AggroTargeting() = default;
	virtual shared_ptr<Creature> operator()(shared_ptr<Creature> owner, vector< shared_ptr<Creature>>& enemys, vector< shared_ptr<Creature>>& friendlys) override;
	~AggroTargeting() ;
public:
	weak_ptr<Creature> target;

};



