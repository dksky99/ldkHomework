#include "framework.h"
#include "Objects/Arkanoid/Arkanoid_Wall.h"
#include "Objects/Arkanoid/Arkanoid_Item.h"
#include "Objects/Arkanoid/Arkanoid_Player.h"
#include "Objects/Arkanoid/Arkanoid_Ball.h"
#include "Arkanoid_Map.h"

Arkanoid_Map::Arkanoid_Map()
{

	Vector offset;
	offset.x = (_wallSize.x + _wallGap.x) * _countX;
	offset.x /= 2;
	offset.x = WIN_CENTER.x - offset.x;
	offset.y = (_wallSize.y + _wallGap.y) * _countY;
	offset.y /= 2;
	offset.y = WIN_CENTER.y - offset.y;

	for (int y = 0;y < _countY;y++)
	{
		_walls.push_back(vector<shared_ptr<Arkanoid_Wall>>());
		for (int x = 0;x < _countX;x++)
		{
			shared_ptr<Arkanoid_Wall> wall = make_shared<Arkanoid_Wall>();

			Vector wallPos;
			wallPos.x = offset.x+(_wallSize.x+_wallGap.x) * x;
			wallPos.y = offset.y+(_wallSize.y+_wallGap.y) * y;

			wall->SetPos(wallPos);
			_walls[y].push_back(wall);

		}
	}



}

Arkanoid_Map::~Arkanoid_Map()
{
}

void Arkanoid_Map::Init(shared_ptr<class Arkanoid_Player> player)
{
	shared_ptr<Arkanoid_Item> item = make_shared<Arkanoid_Item>();
	item->SetItemSkill(std::bind(&Arkanoid_Player::ItemSkill, player));
	_items.push_back(item);
	_walls[0][0]->SetItem(item);
}

void Arkanoid_Map::Update()
{
	for (auto walls : _walls)
	{
		for (auto wall : walls)
		{
			wall->Update();
		}
	}
	for (auto item : _items)
	{
		item->Update();
		
	}


}

void Arkanoid_Map::Render(HDC hdc)
{
	for (auto walls : _walls)
	{
		for (auto wall : walls)
		{
			wall->Render(hdc);
		}
	}

	for (auto item : _items)
	{
		
		item->Render(hdc);
		
	}

}

void Arkanoid_Map::IsCollision_Walls(shared_ptr<class Arkanoid_Ball> ball)
{
	for (auto walls : _walls)
	{
		for (auto wall : walls)
		{
			wall->IsCollision(ball);
		}
	}
}

void Arkanoid_Map::IsCollidsion_Items(shared_ptr<class Arkanoid_Player> player)
{
	for (auto item : _items)
	{
		
		item->IsCollision(player);
		
	}

}
