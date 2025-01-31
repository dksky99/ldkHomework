#pragma once
#include "Scene.h"

class CannonScene :
    public Scene, public enable_shared_from_this<CannonScene>
{
public:

    enum ECannonTurn
    {
        ONE,
        TWO,
        TURNCOUNT
    };


    CannonScene();
    ~CannonScene();

    // Scene을(를) 통해 상속됨
    void Update() override;

    void Render(HDC hdc) override;

    void TurnFinish();
private:
    void CollisionCheck();
private:
    shared_ptr<class Cannon> _cannon1;
    shared_ptr<class Cannon> _cannon2;
    
    ECannonTurn _curTurn;

};


typedef void(CannonScene::*TurnFinishFunc)(void);