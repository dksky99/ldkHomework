#pragma once
#include "Scene.h"

class CannonScene :
    public Scene, public enable_shared_from_this<CannonScene>
{
public:
    CannonScene();
    ~CannonScene();

    // Scene��(��) ���� ��ӵ�
    void Update() override;

    void Render(HDC hdc) override;

    void TurnFinish();
private:

private:
    shared_ptr<class Cannon> _cannon1;
    shared_ptr<class Cannon> _cannon2;
    bool _turn=true;

};


typedef void(CannonScene::*TurnFinishFunc)(void);