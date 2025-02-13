#pragma once
#include "UI.h"
class HPBar :
    public UI
{
public:

    HPBar(Vector center, Vector size);
    ~HPBar();

    // UI을(를) 통해 상속됨
    void Update() override;

    void Render(HDC hdc) override;
    
    void SetValue(float p);



private:

    shared_ptr<class RectCollider> _bg;
    shared_ptr<class RectCollider> _value;

    HBRUSH _redBrush;
    HBRUSH _oldBrush;

};

