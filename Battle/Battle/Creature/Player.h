#pragma once

//헤더파일에서 #include를 하지 않는 이유 : 
// 불필요하게 읽는것을 지양하기 위해서.
//전방 선언. :얘는 구체적인건 몰라도 Class는 맞다.
#include"Creature.h"

class Player:public Creature
{
public:
	Player(string name, int hp, int atk, int arm, int speed);


private:
};