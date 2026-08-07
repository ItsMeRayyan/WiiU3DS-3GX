
#pragma once

#include "Core/Context.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/Rect.hpp"

class Renderer
{
public:
    static bool Initialize(Context& context);

    static void BeginFrame(Context& context);
    static void EndFrame(Context& context);

    static void DrawRect(
        const Rect& rect,
        const Color& color
    );

    static void Shutdown(Context& context);

private:
    Renderer() = delete;
};
