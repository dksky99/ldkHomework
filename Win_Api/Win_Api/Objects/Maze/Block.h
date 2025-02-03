#pragma once
#include "Math/Collider/RectCollider.h"


#define BLOCK_X 13
#define BLOCK_Y 13

class Block :
    public RectCollider
{

public:

    enum class Type
    {
        NONE,
        ABLE,
        BLOCKED,

        TYPE_COUNT
    };




    Block();
    ~Block();

    virtual void Update() override;
    virtual void Render(HDC hdc) override;


    void SetType(Block::Type type) { _curType = type; }
    Block::Type GetBlockType() { return _curType; }

private:

    Block::Type _curType = Type::NONE;

    vector<HBRUSH> _brushes;





};

