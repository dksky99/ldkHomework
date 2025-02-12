#pragma once
#include "Objects/Object.h"
class Arkanoid_Wall : public Object
{
	friend class Arkanoid_Map;
public:

	Arkanoid_Wall();
	Arkanoid_Wall(Vector pos);
	~Arkanoid_Wall();


	void SetPos(Vector pos) ;

	// Object을(를) 통해 상속됨
	void Update() override;

	void Render(HDC hdc) override;

	shared_ptr<class RectCollider> GetCollider() { return _collider; }
	bool IsCollision(shared_ptr<class Arkanoid_Ball> ball);
	void ItemLiberation();
	void SetItem(shared_ptr<class Arkanoid_Item> item);
private:
	shared_ptr<class RectCollider> _collider;

	weak_ptr<class Arkanoid_Item> _item;

};

