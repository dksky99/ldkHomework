#pragma once

//������Ͽ��� #include�� ���� �ʴ� ���� : 
// ���ʿ��ϰ� �д°��� �����ϱ� ���ؼ�.
//���� ����. :��� ��ü���ΰ� ���� Class�� �´�.
#include"Creature.h"

class Player:public Creature
{
public:
	Player(string name, int hp, int atk, int arm, int speed);


private:
};