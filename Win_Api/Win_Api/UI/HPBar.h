#pragma once
#include "UI.h"
class HPBar :
    public UI
{
public:

    HPBar(Vector center, Vector size);
    ~HPBar();

    // UI��(��) ���� ��ӵ�
    void Update() override;

    void Render(HDC hdc) override;
    
    void SetValue(float p);



private:

    shared_ptr<class RectCollider> _bg;
    shared_ptr<class RectCollider> _value;

    HBRUSH _redBrush;
    HBRUSH _oldBrush;

};

