#pragma once
class Arkanoid_Map
{

public:
	Arkanoid_Map();
	~Arkanoid_Map();

	void Init(shared_ptr<class Arkanoid_Player> player);

	void Update();
	void Render(HDC hdc);

	vector<vector<shared_ptr<class Arkanoid_Wall>>>& GetWalls() { return _walls; }


	void IsCollision_Walls(shared_ptr<class Arkanoid_Ball> ball);

	void IsCollidsion_Items(shared_ptr<class Arkanoid_Player> player);
private:
	vector<vector<shared_ptr<class Arkanoid_Wall>>> _walls;
	vector<shared_ptr<class Arkanoid_Item>> _items;
	int _countX=7;
	int _countY=3;
	Vector _wallSize = Vector(80, 30);
	Vector _wallGap = Vector(2, 2);




};

