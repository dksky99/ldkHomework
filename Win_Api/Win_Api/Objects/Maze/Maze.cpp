#include "framework.h"

#include "Objects/Maze/Block.h"

#include "Maze.h"

Maze::Maze()
{
	//offset : 기준점에서 떨어뜨려놓는 Vector

	_blocks.resize(MAX_Y);

	for (int y = 0;y < MAX_Y;y++)
	{
		_blocks[y].reserve(MAX_X);
		for (int x = 0;x < MAX_X;x++)
		{

			shared_ptr<Block> temp= make_shared<Block>();
			temp->SetType(Block::Type::BLOCKED);
			int xPos = BLOCK_X + BLOCK_MARGIN;
			int yPos = BLOCK_Y + BLOCK_MARGIN;

			temp->SetCenter(xPos * x+OFFSET_X, yPos * y+OFFSET_Y);
			_blocks[y].push_back(temp);
		}
	}
	CreateMaze();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto blockV : _blocks)
	{
		for (auto block : blockV)
		{
			block->Update();
		}
	}
}

void Maze::Render(HDC hdc)
{
	for (auto blockV : _blocks)
	{
		for (auto block : blockV)
		{
			block->Render(hdc);
		}
	}
}

void Maze::CreateMaze()
{
	//프로그래머를 위한 미로만들기



	//갈 수 있는 노드 만들기
	for (int y = 0;y < MAX_Y;y++)
	{
		for (int x = 0;x < MAX_X;x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_blocks[y][x]->SetType(Block::Type::BLOCKED);

			}
			else
			{
				_blocks[y][x]->SetType(Block::Type::ABLE);

			}

		}
	}



	for (int y = 0;y < MAX_Y;y++)
	{
		for (int x = 0;x < MAX_X;x++)
		{
			//시작점 뚫기
			if (x == 1 && y == 1)
			{

				_blocks[y][x]->SetType(Block::Type::ABLE);
			}
			//끝점 뚫기
			if (x == MAX_X - 2 && y == MAX_Y - 2)
			{
				_blocks[y][x]->SetType(Block::Type::ABLE);
			}
			//연결할 노드 뚫기
			if (x % 2 == 0 || y % 2 == 0)
			{

				continue;
			}
			//맨 아랫길 뚫기
			if (x == MAX_X - 2)
			{
				_blocks[y+1][x]->SetType(Block::Type::ABLE);
				continue;

			}
			//맨 오른쪽 뚫기
			if (y == MAX_Y - 2)
			{
				_blocks[y][x+1]->SetType(Block::Type::ABLE);
				continue;

			}

			//랜덤하게 아래 혹은 오른쪽으로 길 뚫기
			int randNum = rand()%2;
			if (randNum == 0)
			{
				_blocks[y+1][x]->SetType(Block::Type::ABLE);
				
			}
			else
			{
				_blocks[y][x+1]->SetType(Block::Type::ABLE);

			}

		}
	}
}

Block::Type Maze::GetBlockType(Vector pos)
{
	return _blocks[pos.y][pos.x]->GetBlockType();
}

void Maze::SetBlockType(Vector pos, Block::Type type)
{
	_blocks[pos.y][pos.x]->SetType(type);
}
