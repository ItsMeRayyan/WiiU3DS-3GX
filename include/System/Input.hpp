#pragma once

#include <CTRPluginFramework.hpp>

struct Context;

class Input
{
public:
    bool Initialize();

    void Update(Context& context);

    // True for one update when HOME is double-tapped.
    bool OverlayToggleRequested() const;

    // WiiU3DS receives input while the game continues running.
    void Capture();
    void Release();

    bool IsCaptured() const;

    void Shutdown();

private:
    bool captured = false;
    bool overlayToggleRequested = false;

    // HOME double-tap detection
    bool homeWasPressed = false;
    unsigned long lastHomePressTime = 0;

    static constexpr unsigned long DoubleTapWindowMs = 350;
};
