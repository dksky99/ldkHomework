#pragma once
#include "Scene.h"
class PaintScene :
    public Scene
{
public:
    PaintScene();
    ~PaintScene() ;

    // Scene��(��) ���� ��ӵ�
    virtual void Update() override;
    
    virtual void Render(HDC hdc) override;

private:


    // ���� �׸��� ���� ��
    vector<HPEN> _pens;
    // ���� ������ ��.
    vector<HBRUSH> _brushes;


    Vector _circleCenter = { 0,0 };
    float _circleRadius=50;

    shared_ptr<class RectCollider> _square;
    shared_ptr<class CircleCollider> _circle;
    

};

