#include "Overlay/Overlay.hpp"
#include "Core/Context.hpp"

bool Overlay::Initialize(Context& context)
{
    context.overlayOpen = false;
    return true;
}

void Overlay::Open(Context& context)
{
    context.overlayOpen = true;
}

void Overlay::Close(Context& context)
{
    context.overlayOpen = false;
}

void Overlay::Toggle(Context& context)
{
    context.overlayOpen = !context.overlayOpen;
}

void Overlay::Update(Context& context)
{
    if (!context.overlayOpen)
        return;

    // Overlay input/navigation will go here.
    //
    // IMPORTANT:
    // The game itself should keep running.
    // Later, WiiU3DS 3GX will consume controller input
    // while the overlay owns it.
}

void Overlay::Draw(Context& context)
{
    if (!context.overlayOpen)
        return;

    // v0.0.1 Beta Debug rendering goes here.
    //
    // Later this will use:
    // context.renderer
    //
    // For now we're just establishing the overlay lifecycle.
}

bool Overlay::IsOpen(const Context& context) const
{
    return context.overlayOpen;
}

void Overlay::Shutdown(Context& context)
{
    context.overlayOpen = false;
}
