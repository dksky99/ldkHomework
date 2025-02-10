#pragma once

#include "Block.h"

#define MAX_X 25
#define MAX_Y 25
#define BLOCK_MARGIN 6;
#define OFFSET_X 400
#define OFFSET_Y 150

class Maze
{

	struct Edge
	{
		Vector u;
		Vector v;
		int cost;

	};



public:
	Maze();
	~Maze();
	void Update();
	void Render(HDC hdc);

	void CreateMaze();
	void CreateMaze_Kruskal();

	Vector StartPos() { return Vector(1, 1); }
	Vector EndPos() { return Vector(MAX_X - 2, MAX_Y - 2); }


	Block::Type GetBlockType(Vector pos);

	void SetBlockType(Vector pos, Block::Type type);


private:

	vector < vector<shared_ptr<Block>>> _blocks;




};

