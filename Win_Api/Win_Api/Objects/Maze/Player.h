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

	struct Vertex_Djikstra
	{
		Vertex_Djikstra() :_pos(Vector(0, 0)), _cost(0) {}
		Vertex_Djikstra(Vector pos, int cost) :_pos(pos), _cost(cost) {}

		bool operator<(const Vertex_Djikstra& v) const
		{
			return _cost < v._cost;
		}
		bool operator>(const Vertex_Djikstra& v) const
		{
			return _cost > v._cost;
		}

		Vector _pos = Vector(0, 0);
		int _cost = 0;

	};

	struct Vertex
	{
		Vertex()  {}
		Vertex(Vector pos, int g,int h) :_pos(pos), g(g),h(h),f(g+h) {}

		bool operator<(const Vertex& v) const
		{
			return f < v.f;
		}
		bool operator>(const Vertex& v) const
		{
			return f > v.f;
		}

		Vector _pos = Vector(0, 0);
		int g = 0;
		int h;
		int f; //f=g+h

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
	void Djikstra(Vector start);
	void AStart(Vector start, Vector end);

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

