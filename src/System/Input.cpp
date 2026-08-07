#include "System/Input.hpp"
#include "Core/Context.hpp"

bool Input::Initialize()
{
    captured = false;
    overlayToggleRequested = false;

    return true;
}

void Input::Update(Context& context)
{
    // Reset this every frame.
    overlayToggleRequested = false;

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

void Input::Shutdown()
{
    captured = false;
    overlayToggleRequested = false;
}
