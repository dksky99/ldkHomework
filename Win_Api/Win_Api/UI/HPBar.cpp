#include "framework.h"
#include "Math/Collider/RectCollider.h"
#include "HPBar.h"

HPBar::HPBar(Vector center, Vector size)
{
	_bg = make_shared<RectCollider>(center, size);

	_value = make_shared<RectCollider>(center, size);

	_redBrush = CreateSolidBrush(RED);
	_oldBrush = CreateSolidBrush(WHITE);

	
}

HPBar::~HPBar()
{
	DeleteObject(_redBrush);
	DeleteObject(_oldBrush);
}



void HPBar::Update()
{
	_bg->Update();

	_value->Update();
}

void HPBar::Render(HDC hdc)
{
	
	_bg->Render(hdc);
	SelectObject(hdc, _redBrush);
	_value->Render(hdc);
	SelectObject(hdc, _oldBrush);
}

void HPBar::SetValue(float p)
{
	float newSize = _bg->GetRect().x;
	float newCenter = _bg->GetCenter().x;
	newSize *= p;
	newCenter = newCenter - (_bg->GetRect().x - newSize) / 2;
	_value->SetCenter(Vector(newCenter,_bg->GetCenter().y));
	_value->SetRect(newSize,_bg->GetRect().y);


}
