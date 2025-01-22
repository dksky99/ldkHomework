#include "framework.h"

#include "Math/Collider/CircleCollider.h"
#include "Math/Collider/RectCollider.h"

#include "PaintScene.h"

PaintScene::PaintScene()
{
	_circle = make_shared<CircleCollider>(100,100,50);
	_square = make_shared<RectCollider>(400,300,40,100);


	//스마트포인터로 만드는게 아닌 마이크로소프트에서 정해준 함수로 만들어야함.

	_pens.push_back(CreatePen(1, 1, RGB(164, 119, 100)));
	_pens.push_back(CreatePen(1, 1, RGB(30, 30, 160)));

	_brushes.push_back(CreateSolidBrush(RGB(164, 119, 100)));
	_brushes.push_back(CreateSolidBrush(RGB(30, 30, 160)));
	
}

PaintScene::~PaintScene()
{
	for (auto& i : _pens)
	{
		DeleteObject(i);
	}
	_pens.clear();
	for (auto& i : _brushes)
	{
		DeleteObject(i);
	}
	_brushes.clear();
}

void PaintScene::Update()
{

	Vector rectCenter = _square->GetCenter();
	rectCenter= LERP(rectCenter, mousePos, 0.03);

	_square->SetCenter(rectCenter);


	_circle->Update();
	_square->Update();
}

void PaintScene::Render(HDC hdc)
{
	//이 색깔로 칠할게
	SelectObject(hdc, _pens[0]);
	SelectObject(hdc, _brushes[0]);
	_circle->Render(hdc);

	SelectObject(hdc, _pens[1]);
	SelectObject(hdc, _brushes[1]);
	_square->Render(hdc);
}
