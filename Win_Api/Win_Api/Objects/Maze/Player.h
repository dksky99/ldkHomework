#pragma once


class Maze;
class Block;

class Player
{
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

public:
	Player(shared_ptr<Maze> maze);
	~Player();

	void Update();
	void Render(HDC hdc);

	void RightHand();
	void BFS(Vector start); //최소 간선의 개수.
	void StartDFS(Vector start); //최소 간선의 개수.
	void DFS(Vector here); //최소 간선의 개수.
	bool CanGo(Vector pos);


private:
	weak_ptr<Maze> _maze;

	Vector _pos = { 1,1 };

	vector<Vector> _path;
	vector<Vector> _vertex;
	int _pathIndex = 0;
	float _delayTime = 0.0f;

	


	//RightHand
	Vector _dir = Vector(0, -1);


	//BFS
	vector<vector<bool>> _discovered;
	vector<vector<Vector>> _parent; 

};

