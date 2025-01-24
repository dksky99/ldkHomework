#include "framework.h"
#include "Math/Collider/CircleCollider.h"
#include "Math/Collider/Line.h"
#include "Objects/Cannon/Cannon.h"
#include "Barrel.h"

Barrel::Barrel(shared_ptr<CircleCollider> cannon)
{
	_cannonBody = cannon;
	_barrelLength = 120;
	_barrelDir = Vector(1, 0);
	_angle = 0;
	_barrel = make_shared<Line>(_cannonBody.lock()->GetCenter(), _cannonBody.lock()->GetCenter() + _barrelDir * _barrelLength);


}

Barrel::~Barrel()
{
}

void Barrel::Update()
{
	if (_cannonBody.expired())
		return;
	shared_ptr<CircleCollider> cannon = _cannonBody.lock();

	_barrelDir = Vector(cosf(_angle), sinf(_angle));
	_barrel->start = cannon->GetCenter();
	_barrel->end = _barrel->start + _barrelDir * _barrelLength;
	_barrel->Update();
}

void Barrel::Render(HDC hdc)
{
	_barrel->Render(hdc);
}
