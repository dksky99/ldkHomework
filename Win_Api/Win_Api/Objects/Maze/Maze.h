#pragma once

class Block;

#define MAX_X 25
#define MAX_Y 25
#define BLOCK_MARGIN 6;
#define OFFSET_X 400
#define OFFSET_Y 150

class Maze
{
public:
	Maze();
	~Maze();
	void Update();
	void Render(HDC hdc);

	void CreateMaze();



private:

	vector < vector<shared_ptr<Block>>> _blocks;


};

