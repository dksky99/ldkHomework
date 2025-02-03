#include "framework.h"
#include "Block.h"

Block::Block():RectCollider(Vector(WIN_CENTER.x,WIN_CENTER.y),Vector(BLOCK_X,BLOCK_Y))
{
	_brushes.push_back(CreateSolidBrush(BLACK)); //None
	_brushes.push_back(CreateSolidBrush(GREEN)); //Able
	_brushes.push_back(CreateSolidBrush(RED)); //Blocked
}

Block::~Block()
{
}

void Block::Update()
{
	RectCollider::Update();
}

void Block::Render(HDC hdc)
{
	//¿Œµ¶Ω∫ ∏ «Œ
	SelectObject(hdc, _brushes[static_cast<int>(_curType)]);
	_curPen = static_cast<int>(_curType);
	RectCollider::Render(hdc);
}
