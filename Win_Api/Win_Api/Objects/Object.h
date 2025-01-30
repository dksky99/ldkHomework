#pragma once
class Object
{
public:

	virtual ~Object() {}

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	bool isActive=false;
	bool activeGravity = false;


protected:
	Vector _position;
};

