#pragma once
#include "Scene.h"
class ArkanoidScene :
    public Scene
{
public:
    ArkanoidScene();
    ~ArkanoidScene();

    // Scene��(��) ���� ��ӵ�
    void Update() override;

    void Render(HDC hdc) override;

private:

    shared_ptr<class Arkanoid_Player> _player;

    UINT _poolCount = 21;
    vector<shared_ptr<class Arkanoid_Wall>> _walls;


};

