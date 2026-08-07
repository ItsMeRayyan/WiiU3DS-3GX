#include "System/Input.hpp"
#include "Core/Context.hpp"

bool Input::Initialize()
{
    captured = false;
    overlayToggleRequested = false;
    homeWasPressed = false;
    lastHomePressTime = 0;

    return true;
}

void Input::Update(Context& context)
{
    overlayToggleRequested = false;

    /*
        TODO: HOME interception

        HOME is not a normal HID button like A/B/X/Y.

        The final WiiU3DS behavior will be:

            HOME once:
                normal HOME Menu behavior

            HOME twice quickly:
                suppress HOME Menu transition
                request WiiU3DS overlay toggle

        Do not implement this using an imaginary KEY_HOME.
    */

    if (context.overlayOpen)
        Capture();
    else
        Release();
}

bool Input::OverlayToggleRequested() const
{
    return overlayToggleRequested;
}

void Input::Capture()
{
    captured = true;

    /*
        TODO v0.0.1:
        Consume gameplay input while overlay is open.

        The game itself must continue executing.
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
