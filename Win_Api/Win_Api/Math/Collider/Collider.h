#pragma once
class Collider
{
public:
	Collider() :_center(0, 0) { Init(); };
	Collider(float x, float y) :_center(x, y) { Init(); };
	Collider(Vector v) :_center(v) { Init(); };
	virtual ~Collider();

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;
	
	void SetCenter(float x, float y) {_center.x = x;_center.y = y;}
	void SetCenter(const Vector& v) {_center= v;}
	Vector GetCenter() { return _center; }

	void SetGreen() { _curPen = 0; }
	void SetRed() { _curPen = 1; }

private:
	void Init();

protected:

	UINT				_curPen=0;
	// 선을 그릴떄 선의 색
	vector<HPEN>		_pens;
	Vector				_center;

};

