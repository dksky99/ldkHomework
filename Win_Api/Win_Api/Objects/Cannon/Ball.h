#pragma once
#include "Objects/Object.h"
class Ball :
    public Object
{
public:

    Ball();
    ~Ball();

    // Object을(를) 통해 상속됨
    virtual void Update() override;

    virtual void Render(HDC hdc) override;

    void AddVector(Vector v);
    
    void SetPos(Vector pos) { _circle->SetCenter(pos); _theta = 0;_gravityDir = Vector(0, 0.00001); }

    void SetDir(Vector v) { _ballDir = v.NormalVector(); }
    void GravityMove();
    void SinMove();
    void BasicMove();

    shared_ptr<CircleCollider> GetCollider() { return _circle; }
    
private:

private:
 
    float _ballSpeed=3;
    shared_ptr<class CircleCollider> _circle;

    Vector _ballDir = Vector(0, 0);
    Vector _addDir=Vector(0,0);
    const Vector _gravityWeight = Vector(0, 0.03);
    Vector _gravityDir = Vector(0, 0);
    float _theta=0;

};

