#pragma once

#include <3ds.h>

struct Context;

class Input
{
public:
    bool Initialize();

    void Update(Context& context);

    bool OverlayToggleRequested() const;

    void Capture();
    void Release();

    bool IsCaptured() const;

    bool IsTouchDown() const;
    bool IsTouchHeld() const;
    bool IsTouchReleased() const;

    int GetTouchX() const;
    int GetTouchY() const;

    void Shutdown();

private:
    bool captured = false;
    bool overlayToggleRequested = false;

    bool homeWasPressed = false;
    u64 lastHomePressTime = 0;

    bool touchDown = false;
    bool touchHeld = false;
    bool touchReleased = false;

    bool previousTouchHeld = false;

    int touchX = 0;
    int touchY = 0;
};
