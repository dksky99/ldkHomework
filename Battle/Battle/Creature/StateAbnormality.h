#pragma once
enum EStateAbnormality
{
	//지속피해
	Dot = 1,
	//행동불능
	Inability = 1 << 1,
	//타겟 강제지정
	Aggro = 1 << 2,
	//타겟 랜덤
	Disarray = 1 << 3

};


class StateAbnormality
{
public:
	virtual ~StateAbnormality() {};
	void TurnDown() { _duration--; }
	bool GetPurifiable() { return _purifiable; }
	bool IsFinished() { return _duration==0; }
	void Purify() {}
	EStateAbnormality GetType() { return _state; }

protected:

	bool _purifiable=true;
	int _duration=0;
	EStateAbnormality _state;
};





class StateAbnormality_Aggro : public StateAbnormality
{
public:
	virtual ~StateAbnormality_Aggro()override ;
	void SetTarget(class Creature* target, int duration)
	{
		_duration = duration;
		_targeting = new class AggroTargeting();
		_targeting->target = target;
	}
	class Targeting* GetTargeting(){return _targeting;}


private:

	class AggroTargeting* _targeting;


};
