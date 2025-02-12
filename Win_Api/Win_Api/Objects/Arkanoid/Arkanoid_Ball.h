#pragma once
#include "Objects/Object.h"
class Arkanoid_Ball : public Object
{
public:
    Arkanoid_Ball();
    Arkanoid_Ball(shared_ptr<class Arkanoid_Player> _player);
    ~Arkanoid_Ball();
    // Object을(를) 통해 상속됨
    virtual void Update() override;

    virtual void Render(HDC hdc) override;

    void AddVector(Vector v);

    void SetPos(Vector pos);

    void SetDir(Vector v) { _ballDir = v.NormalVector(); }
    Vector GetDir() { return _ballDir; }
    void BasicMove();
    void FollowMove();
    void CheckWall();
    void BlockReflection(shared_ptr<class RectCollider> other);
    void RegularReflection(shared_ptr<class RectCollider> other);
    void DiffuseReflection(shared_ptr<class RectCollider> other);

    void SetBallDead(function<void(void)> fn) { ballDead = fn; }
    void BallDead();
    shared_ptr<class CircleCollider> GetCollider() { return _circle; }

    bool IsFired() { return isActive==true&&_ballDir.Length() != 0.0f; }

private:
    weak_ptr<class Arkanoid_Player> _player;
    float _ballSpeed = 9;
    shared_ptr<class CircleCollider> _circle;

    Vector _ballDir = Vector(0, 0);

    function<void(void)> ballDead;

};

