#pragma once
#include "Scene.h"
class ArkanoidScene :
    public Scene
{
public:
    ArkanoidScene();
    ~ArkanoidScene();

    // Scene을(를) 통해 상속됨
    void Update() override;

    void Render(HDC hdc) override;

    void CollisionCheck();

    void BallDead();

private:

    shared_ptr<class Arkanoid_Player> _player;

    int _lifeCount = 3;
    UINT _poolCount = 21;
    vector<shared_ptr<class Arkanoid_Wall>> _walls;

    vector<shared_ptr<class CircleCollider>> _hpUI;

};

