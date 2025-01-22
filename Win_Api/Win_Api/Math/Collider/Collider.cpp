#include "framework.h"
#include "Collider.h"

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
