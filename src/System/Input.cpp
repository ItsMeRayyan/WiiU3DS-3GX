#include "System/Input.hpp"
#include "Core/Context.hpp"

bool Input::Initialize()
{
    captured = false;
    overlayToggleRequested = false;

    touchDown = false;
    touchHeld = false;
    touchReleased = false;
    previousTouchHeld = false;

    touchX = 0;
    touchY = 0;

    return true;
}

void Input::Update(Context& context)
{
    // Reset one-frame events.
    overlayToggleRequested = false;
    touchDown = false;
    touchReleased = false;

    hidScanInput();

    u32 held = hidKeysHeld();

    bool currentTouchHeld = (held & KEY_TOUCH) != 0;

    touchDown = currentTouchHeld && !previousTouchHeld;
    touchHeld = currentTouchHeld;
    touchReleased = !currentTouchHeld && previousTouchHeld;

    if (currentTouchHeld)
    {
        touchPosition touch;
        hidTouchRead(&touch);

        touchX = touch.px;
        touchY = touch.py;
    }

    previousTouchHeld = currentTouchHeld;

    /*
        TODO:
        Detect double-tap HOME.

        HOME is handled specially by the 3DS,
        so we will implement this separately.

        When detected:
        overlayToggleRequested = true;
    */

    if (context.overlayOpen)
    {
        Capture();
    }
    else
    {
        Release();
    }
}

bool Input::OverlayToggleRequested() const
{
    return overlayToggleRequested;
}

void Input::Capture()
{
    captured = true;

    /*
        TODO:
        Actually consume game input.

        WiiU3DS should receive buttons/touch input
        while the game itself continues running.
    */
}

void Input::Release()
{
    captured = false;
}

bool Input::IsCaptured() const
{
    return captured;
}

bool Input::IsTouchDown() const
{
    return touchDown;
}

bool Input::IsTouchHeld() const
{
    return touchHeld;
}

bool Input::IsTouchReleased() const
{
    return touchReleased;
}

int Input::GetTouchX() const
{
    return touchX;
}

int Input::GetTouchY() const
{
    return touchY;
}

void Input::Shutdown()
{
    captured = false;
    overlayToggleRequested = false;

    touchDown = false;
    touchHeld = false;
    touchReleased = false;
    previousTouchHeld = false;

    touchX = 0;
    touchY = 0;
}
