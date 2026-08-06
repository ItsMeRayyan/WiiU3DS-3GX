class Plugin
{
public:
    bool Initialize();
    void Update();
    void Draw();
    void Shutdown();

    bool IsRunning() const;
};
