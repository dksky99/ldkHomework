#include "framework.h"
#include "Collider.h"
#include "RectCollider.h"
#include "CircleCollider.h"

Collider::~Collider()
{
	for (auto& i : _pens)
	{
		DeleteObject(i);
	}
	_pens.clear();
}

void Collider::Init()
{
	_pens.push_back(CreatePen(1, 3, GREEN));
	_pens.push_back(CreatePen(1, 3, RED));
}

bool Collider::IsCollision(shared_ptr<Collider>other)
{
	ColType otherType = other->_type;

	switch (otherType)
	{
	case Collider::ColType::None:
		break;
	case Collider::ColType::Circle:
		return IsCollision(static_pointer_cast<CircleCollider>(other));
		break;
	case Collider::ColType::Rect:
		return IsCollision(static_pointer_cast<RectCollider>(other));
		break;
	default:
		break;
	}

}
