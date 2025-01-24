#pragma once
#include "Scene.h"
class CannonScene :
    public Scene
{
public:
    CannonScene();
    ~CannonScene();

    // Scene��(��) ���� ��ӵ�
    void Update() override;

    void Render(HDC hdc) override;

private:
    shared_ptr<class Cannon> _cannon;

};

