#pragma once


class Maze;
class Block;

class Player
{
public:
	Player(shared_ptr<Maze> maze);
	~Player();

	void Update();
	void Render(HDC hdc);

	void RightHand();

	bool CanGo(Vector pos);


private:
	weak_ptr<Maze> _maze;

	Vector _pos = { 1,1 };

	vector<Vector> _path;
	vector<Vector> _vertex;
	int _pathIndex = 0;
	float _delayTime = 0.0f;

	//Path
	enum Direction
	{
		UP,
		LEFT,
		BOTTOM,
		RIGHT,
		DIR_COUNT
	};

	Vector frontPos[4] = {
		{0,-1},
		{-1,0},
		{0,1},
		{1,0}
	};


	//RightHand
	Vector _dir = Vector(0, -1);

};

