#pragma once
#include "Scene.h"
class PaintScene :
    public Scene
{
public:
    PaintScene();
    ~PaintScene() ;

    // Scene을(를) 통해 상속됨
    virtual void Update() override;
    
    virtual void Render(HDC hdc) override;

private:


    // 선을 그릴떄 선의 색
    vector<HPEN> _pens;
    // 도형 내부의 색.
    vector<HBRUSH> _brushes;


    Vector _circleCenter = { 0,0 };
    float _circleRadius=50;

    shared_ptr<class RectCollider> _square;
    shared_ptr<class CircleCollider> _circle;
    

};

