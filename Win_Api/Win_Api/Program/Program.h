#pragma once
class Program
{

public:

	Program();
	~Program();

	void Update();

	void Render(HDC hdc);




public:
	//Buffer : �ӽ� ����� (�� ���������� �����ϰų� , ���� ���� ��
	static HDC backbuffer;

private:

	shared_ptr<Scene> _scene;

	HBITMAP _hBitMap;


};

