#pragma once

#include "Core/Context.hpp"

class Renderer
{
public:
    static bool Initialize(Context& context);
    static void BeginFrame(Context& context);
    static void EndFrame(Context& context);
    static void Shutdown(Context& context);

private:
    Renderer() = delete;
};
