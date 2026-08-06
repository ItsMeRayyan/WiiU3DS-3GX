#include "Core/Plugin.hpp"

int main()
{
    Plugin plugin;

    if (!plugin.Initialize())
        return -1;

    while (plugin.IsRunning())
    {
        plugin.Update();
        plugin.Draw();
    }

    plugin.Exit();

    return 0;
}
