#pragma once
#include "Scene.h"
class LineScene :
    public Scene
{

public:
    LineScene();

    ~LineScene();
    // Scene을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render(HDC hdc) override;


private:
    shared_ptr<class Line> _floor;
    shared_ptr<class Line> _line1;
    shared_ptr<class Line> _shadow;

};

