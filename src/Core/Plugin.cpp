
#include "Core/plugin.hpp"

#include "System/Input.hpp"
#include "Overlay/Overlay.hpp"
#include "Graphics/Renderer.hpp"
#include "Widgets/Widgets.hpp"

bool Plugin::Initialize()
{
    Renderer::Initialize();

    Input::Initialize();
    Overlay::Initialize();
    Widgets::Initialize();

    return true;
}

void Plugin::Update()
{
    Input::Update();

    if (Input::OverlayToggleRequested())
        Overlay::Toggle();

    Overlay::Update();
    Widgets::Update();
}

void Plugin::Draw()
{
    Renderer::BeginFrame();

    Overlay::Draw();

    if (Overlay::IsOpen())
        Widgets::Draw();

    Renderer::EndFrame();
}

void Plugin::Exit()
{
    Widgets::Exit();
    Overlay::Exit();
    Input::Exit();
    Renderer::Exit();
}
