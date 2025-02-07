#pragma once


class Maze;
class Block;

class Player
{
private:
	
	//Path
	enum Direction
	{
		UP,
		LEFT,
		BOTTOM,
		RIGHT,
		DIR_COUNT
	};

	Vector frontPos[8] = {
		{0,-1},
		{-1,0},
		{0,1},
		{1,0},
		{-1,-1},
		{1,-1},
		{1,1},
		{-1,1}
	};

	struct Vertex
	{
		Vertex() :_pos(Vector(0, 0)), _cost(0) {}
		Vertex(Vector pos, int cost) :_pos(pos), _cost(cost) {}

		bool operator<(const Vertex& v) const
		{
			return _cost < v._cost;
		}
		bool operator>(const Vertex& v) const
		{
			return _cost > v._cost;
		}

		Vector _pos = Vector(0, 0);
		int _cost = 0;

	};




public:

	Player(shared_ptr<Maze> maze);
	~Player();


	void Update();
	void Render(HDC hdc);

	void RightHand();
	void BFS(Vector start); //�ּ� ������ ����.
	void StartDFS(Vector start); //�ּ� ������ ����.
	void DFS(Vector here); //�ּ� ������ ����.
	void Djikstra(Vector start);

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


	//Djikstra
	vector<vector<int>> _best;



};

