#include "framework.h"

#include "Objects/Maze/Maze.h"
#include "Objects/Maze/Block.h"


#include "Player.h"

Player::Player(shared_ptr<Maze> maze) : _maze(maze)
{
	_maze.lock()->SetBlockType(_pos, Block::Type::PLAYER);
	Djikstra(_maze.lock()->StartPos());
}

Player::~Player()
{
}

void Player::Update()
{
	if (_pathIndex >= _path.size())
	{

		//_maze.lock()->SetBlockType(_pos, Block::Type::FOOTPRINT);
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

void Player::BFS(Vector start)
{
	_discovered = vector<vector<bool>>(MAX_Y, vector<bool>(MAX_X, false));
	_parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));

	queue<Vector> q;
	q.push(start);
	_discovered[start.y][start.x] = true;
	_parent[start.y][start.x] = start;

	while (true)
	{
		Vector here = q.front();
		q.pop();
		if (here == _maze.lock()->EndPos())
		{
			break;
		}
		for (int i = 0;i < 4;i++)
		{
			Vector there = here + frontPos[i];

			//동일 블록이냐 -> 가능성은 없지만 일단.
			if (here == there)
				continue;
			//갈 수 있는곳이냐
			if (CanGo(there)==false)
				continue;
			//이미 다녀온곳이냐
			if (_discovered[there.y][there.x] == true)
				continue;

			q.push(there);
			_discovered[there.y][there.x] = true;
			_parent[there.y][there.x] = here;
			_maze.lock()->SetBlockType(there, Block::Type::SEARCHED);




		}

	}
	//끝점이 누구한테서 발견되었는지 타고올라가보기
	Vector vertex = _maze.lock()->EndPos();
	while (true)
	{
		if (start == vertex)
			break;


		vertex = _parent[vertex.y][vertex.x];
		_path.push_back(vertex);
	}
	reverse(_path.begin(), _path.end());
}

void Player::StartDFS(Vector start)
{
	_discovered = vector<vector<bool>>(MAX_Y, vector<bool>(MAX_X, false));
	
	DFS(start);
}

void Player::DFS(Vector here)
{
	_discovered[here.y][here.x] = true;
	for (int i = 0;i < 4;i++)
	{
		Vector there = here + frontPos[i];

		//동일 블록이냐 -> 가능성은 없지만 일단.
		if (here == there)
			continue;
		//갈 수 있는곳이냐
		if (CanGo(there) == false)
			continue;
		//이미 다녀온곳이냐
		if (_discovered[there.y][there.x] == true)
			continue;
	}


}

void Player::Djikstra(Vector start)
{

	_parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));
	_best = vector<vector<int>>(MAX_Y, vector<int>(MAX_X, INT_MAX));

	priority_queue<Vertex,vector<Vertex>,greater<Vertex>> pq;
	_parent[start.y][start.x] = start;
	_best[start.y][start.x] = 0;

	pq.push(Vertex(start, 0));

	while (true)
	{
		if (pq.empty())
			break;

		Vertex hereV = pq.top();
		pq.pop();
		Vector herePos = hereV._pos;

		if (_best[herePos.y][herePos.x] < hereV._cost)
			continue;

		for (int i = 0;i < 8;i++)
		{
			Vector therePos = herePos + frontPos[i];

			if (CanGo(therePos) == false)
				continue;

			int thereCost = hereV._cost +( i < 4 ? 10 : 14);

			if (_best[therePos.y][therePos.x] < thereCost)
				continue;

			//예약
			Vertex thereV=Vertex(therePos, thereCost);

			pq.push(thereV);
			_parent[therePos.y][therePos.x] = herePos;
			_best[therePos.y][therePos.x] = thereCost;

		}

	}
	//끝점이 누구한테서 발견되었는지 타고올라가보기
	Vector vertex = _maze.lock()->EndPos();
	while (true)
	{
		if (start == vertex)
			break;


		vertex = _parent[vertex.y][vertex.x];
		_path.push_back(vertex);
	}
	reverse(_path.begin(), _path.end());

}

bool Player::CanGo(Vector pos)
{

	if (_maze.lock()->GetBlockType(pos) == Block::Type::BLOCKED)
	{
		return false;

	}
	return true;
	
}
