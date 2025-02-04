#include "framework.h"
#include "Block.h"

Block::Block():RectCollider(Vector(WIN_CENTER.x,WIN_CENTER.y),Vector(BLOCK_X,BLOCK_Y))
{
	_brushes.push_back(CreateSolidBrush(BLACK)); //None
	_brushes.push_back(CreateSolidBrush(GREEN)); //Able
	_brushes.push_back(CreateSolidBrush(RED)); //Blocked
	_brushes.push_back(CreateSolidBrush(WINE)); //Player
	_brushes.push_back(CreateSolidBrush(WHITE)); //Player
	_brushes.push_back(CreateSolidBrush(BLUE)); //Player

	_pens.push_back(CreatePen(1, 3, WINE));
	_pens.push_back(CreatePen(1, 3, WHITE));
	_pens.push_back(CreatePen(1, 3, BLUE));
}

Block::~Block()
{
	for (auto brush : _brushes)
	{
		DeleteObject(brush);
	}
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
