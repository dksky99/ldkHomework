#pragma once
class Program
{

public:

	Program();
	~Program();

	void Update();

	void Render(HDC hdc);




public:
	//Buffer : 임시 저장소 (곧 누군가에게 전달하거나 , 전달 받을 곳
	static HDC backbuffer;

private:

	shared_ptr<Scene> _scene;

	HBITMAP _hBitMap;


};

