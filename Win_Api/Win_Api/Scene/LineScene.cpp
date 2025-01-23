#include "framework.h"
#include "Math/Collider/Line.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_floor  = make_shared<Line>(Vector(100, 600), Vector(1200, 500));
	_line1  = make_shared<Line>(Vector(100, 100), Vector(100, 100));
	_shadow = make_shared<Line>(Vector(100, 500), Vector(101, 500));
	
}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	_floor->Update();
	_line1->Update();
	_shadow->Update();

	_line1->end = mousePos;

	//floor에 line1을 투영
	Vector floordir = _floor->end - _floor->start;
	Vector linedir = _line1->end - _line1->start;
	float shadowLength= floordir.NormalVector().Dot(linedir);
	_shadow->end = (floordir.NormalVector() * shadowLength + _shadow->start);


}

void LineScene::Render(HDC hdc)
{

	_floor ->Render(hdc);
	_line1 ->Render(hdc);
	_shadow->Render(hdc);
}
