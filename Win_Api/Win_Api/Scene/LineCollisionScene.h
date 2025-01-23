#pragma once
#include "Scene.h"
class LineCollisionScene :
    public Scene
{
public:
    LineCollisionScene();
    ~LineCollisionScene();


    // Scene을(를) 통해 상속됨
    void Update() override;

    void Render(HDC hdc) override;


private:
    shared_ptr<class Line> _line1;
    shared_ptr<class Line> _line2;
    shared_ptr<class CircleCollider> _collidePoint;

};

