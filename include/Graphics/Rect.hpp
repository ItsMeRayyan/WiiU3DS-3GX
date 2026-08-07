#pragma once

struct Rect
{
    float x;
    float y;
    float width;
    float height;

    constexpr Rect(
        float xPosition,
        float yPosition,
        float rectWidth,
        float rectHeight
    )
        : x(xPosition),
          y(yPosition),
          width(rectWidth),
          height(rectHeight)
    {
    }

    constexpr float Left() const
    {
        return x;
    }

    constexpr float Right() const
    {
        return x + width;
    }

    constexpr float Top() const
    {
        return y;
    }

    constexpr float Bottom() const
    {
        return y + height;
    }

    constexpr bool Contains(float px, float py) const
    {
        return px >= Left() &&
               px <= Right() &&
               py >= Top() &&
               py <= Bottom();
    }
};
