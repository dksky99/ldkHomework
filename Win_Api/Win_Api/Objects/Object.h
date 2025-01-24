#pragma once
class Object
{
public:

	virtual ~Object() {}

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	bool isActive=false;
protected:

};

