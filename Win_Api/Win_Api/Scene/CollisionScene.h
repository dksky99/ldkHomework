#pragma once
#include "Scene.h"
class CollisionScene :
    public Scene
{
public:
    CollisionScene();
    ~CollisionScene();


    // Scene��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render(HDC hdc) override;


private:

    shared_ptr<class CircleCollider> _circle;
    shared_ptr<class CircleCollider> _movingCircle;


    shared_ptr<class RectCollider> _rect;
    shared_ptr<class RectCollider> _movingRect;



};

