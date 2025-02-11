#pragma once
#include "Objects/Object.h"
class Arkanoid_Ball : public Object
{
public:
    Arkanoid_Ball();
    ~Arkanoid_Ball();
    // Object을(를) 통해 상속됨
    virtual void Update() override;

    virtual void Render(HDC hdc) override;

    void AddVector(Vector v);

    void SetPos(Vector pos);

    void SetDir(Vector v) { _ballDir = v.NormalVector(); }
    void BasicMove();
    void CheckWall();
    void BlockReflection(shared_ptr<class RectCollider> other);
    void RegularReflection(shared_ptr<class RectCollider> other);
    void DiffuseReflection(shared_ptr<class RectCollider> other);

    void SetBallDead(function<void(void)> fn) { ballDead = fn; }
    void BallDead();
    shared_ptr<class CircleCollider> GetCollider() { return _circle; }

private:

    float _ballSpeed = 9;
    shared_ptr<class CircleCollider> _circle;

    Vector _ballDir = Vector(0, 0);

    function<void(void)> ballDead;

};

