#pragma once

#include "Graphics/Rect.hpp"

class Widget
{
public:
    virtual ~Widget() = default;

    virtual void Update() = 0;
    virtual void Draw() = 0;

    void SetBounds(const Rect& rect)
    {
        bounds = rect;
    }

    const Rect& GetBounds() const
    {
        return bounds;
    }

protected:
    Rect bounds{0, 0, 0, 0};
};
