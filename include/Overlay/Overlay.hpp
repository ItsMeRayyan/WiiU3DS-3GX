#pragma once

struct Context;

class Overlay
{
public:
    bool Initialize(Context& context);

    void Open(Context& context);
    void Close(Context& context);
    void Toggle(Context& context);

    void Update(Context& context);
    void Draw(Context& context);

    bool IsOpen(const Context& context) const;

    void Shutdown(Context& context);
};
