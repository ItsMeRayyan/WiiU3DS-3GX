#pragma once

class Input
{
public:
    static bool Initialize();

    static void Update();

    static bool OverlayToggleRequested();

    static void Capture();
    static void Release();

    static bool IsCaptured();

    static void Exit();

private:
    static bool captured;
    static bool overlayToggleRequested;

    // Reserved for double-HOME detection later.
    static bool homeWasPressed;
    static unsigned long lastHomePressTime;

    static constexpr unsigned long DoubleTapWindowMs = 350;
};
