#pragma once

class Overlay
{
public:
    static bool Initialize();

    static void Open();
    static void Close();
    static void Toggle();

    static void Update();
    static void Draw();

    static bool IsOpen();

    static void Exit();

private:
    static bool open;
};
