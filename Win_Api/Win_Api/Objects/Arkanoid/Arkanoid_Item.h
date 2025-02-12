#pragma once
#include "Objects/Object.h"
class Arkanoid_Item :
    public Object
{

public:
    Arkanoid_Item();
    ~Arkanoid_Item();



    // Object을(를) 통해 상속됨
    void Update() override;

    void Render(HDC hdc) override;
    void Drop();

    void ItemLiberation() { isLiberation = true; };
    Vector GetPos();
    void SetPos(Vector dir);

    bool IsCollision(shared_ptr<class Arkanoid_Player> player);

    void SetItemSkill(function<void(void)> fn);

private:
    shared_ptr<class CircleCollider> _body;
    Vector _dir = Vector::Down();

    float _speed = 4.0f;

    bool isLiberation = false;

    function<void(void)> _itemSkill=nullptr;


};

