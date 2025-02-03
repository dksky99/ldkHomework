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

private:

    shared_ptr<class Arkanoid_Player> _player;



};

