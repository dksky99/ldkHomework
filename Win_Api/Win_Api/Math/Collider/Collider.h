#pragma once
class Collider
{
public:

	//enum의 단점 : 편히 쓰라고 enum의 이름을 적지않고 멤버만 적어도 사용가능한데
	//그때 이름이 겹치면 모호해진다. enum class는 무조껀 enum의 이름을쓰고 그뒤 에 멤버를 적어야
	//사용 가능함. 다른건 차이가 없다. 
	enum class ColType
	{
		None,
		Circle,
		Rect
	};



	Collider() :_center(0, 0) { Init(); };
	Collider(float x, float y) :_center(x, y) { Init(); };
	Collider(Vector v) :_center(v) { Init(); };
	virtual ~Collider();

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;
	
	void SetCenter(float x, float y) {_center.x = x;_center.y = y;}
	void SetCenter(const Vector& v) {_center= v;}
	Vector GetCenter() { return _center; }

	void SetColor(int n) { _curPen = n; }
	void SetBlack() { _curPen = 0; }
	void SetGreen() { _curPen = 1; }
	void SetRed() { _curPen = 2; }

	bool IsCollision(shared_ptr<Collider>other);
	virtual bool IsCollision(const Vector& pos) { return false; };
	virtual bool IsCollision(shared_ptr<class CircleCollider> other) { return false; };
	virtual bool IsCollision(shared_ptr<class RectCollider> other) { return false; };

private:
	void Init();

protected:

	ColType _type = ColType::None;

	UINT				_curPen=0;
	// 선을 그릴떄 선의 색
	vector<HPEN>		_pens;
	Vector				_center;

};

