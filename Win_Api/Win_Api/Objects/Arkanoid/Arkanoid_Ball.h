#pragma once
#include "Objects/Object.h"
class Arkanoid_Ball : public Object
{
public:
    Arkanoid_Ball();
    ~Arkanoid_Ball();
    // Object��(��) ���� ��ӵ�
    virtual void Update() override;

    virtual void Render(HDC hdc) override;

    void AddVector(Vector v);

    void SetPos(Vector pos);

    void SetDir(Vector v) { _ballDir = v.NormalVector(); }
    void BasicMove();
    void CheckWall();
    void BallDead();
    shared_ptr<class CircleCollider> GetCollider() { return _circle; }

private:

    float _ballSpeed = 3;
    shared_ptr<class CircleCollider> _circle;

    Vector _ballDir = Vector(0, 0);

    function<void(void)> ballDead;

};

