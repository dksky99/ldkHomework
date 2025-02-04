#include "framework.h"

#include "Objects/Maze/Maze.h"
#include "Objects/Maze/Block.h"


#include "Player.h"

Player::Player(shared_ptr<Maze> maze) : _maze(maze)
{
	_maze.lock()->SetBlockType(_pos, Block::Type::PLAYER);
	RightHand();
}

Player::~Player()
{
}

void Player::Update()
{
	if (_pathIndex >= _path.size())
	{
		return;
	}
	_delayTime += 0.03f;
	if (_delayTime > 1.0f)
	{
		_delayTime = 0.0f;
		_maze.lock()->SetBlockType(_pos, Block::Type::FOOTPRINT);
		_pos = _path[_pathIndex];

		_maze.lock()->SetBlockType(_pos, Block::Type::PLAYER);

		_pathIndex++;
	}

}

void Player::Render(HDC hdc)
{
}

void Player::RightHand()
{

	shared_ptr<Maze> maze = _maze.lock();

	Vector pos = maze->StartPos();
	Vector endPos = maze->EndPos();
	int curDir = Direction::UP;
	while (true)
	{
		if (pos == endPos)
			break;

		int newDir = (curDir - 1 + DIR_COUNT) % DIR_COUNT;
		Vector oldVector = pos + frontPos[curDir];
		Vector newVector = pos + frontPos[newDir];

		//오른쪽으로 갈 수 있다 -> 오른쪽으로 회전
		if (CanGo(newVector))
		{
			curDir = newDir;
			pos = newVector;
			_path.push_back(pos);
		}

		//오른쪽은 막혀있고 앞이 열려있을때
		else if(CanGo(oldVector))
		{
			pos = oldVector;
			_path.push_back(pos);

		}
		//오른쪽은 막혀있고 진행방향도 막혀있다 -> 회전
		else
		{
			curDir = (curDir+1+DIR_COUNT)%DIR_COUNT;

		}
	}


	stack<Vector> s;
	//사이클 처리
	for (int i = 0;i < _path.size() - 1;i++)
	{

		_maze.lock()->SetBlockType(_path[i], Block::Type::SEARCHED);

		if (s.empty() == false && s.top() == _path[i + 1])
		{
			s.pop();
		}
		else
		{
			s.push(_path[i]);

		}
	}

	_path.clear();
	while (true)
	{
		if (s.empty() == true)
			break;
		Vector top = s.top();
		_path.push_back(top);
		s.pop();
	}
	std::reverse(_path.begin(), _path.end());


}

bool Player::CanGo(Vector pos)
{

	if (_maze.lock()->GetBlockType(pos) == Block::Type::BLOCKED)
	{
		return false;

	}
	return true;
	
}
