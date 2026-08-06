bool Plugin::Initialize()
{
    Renderer::Initialize();
    Overlay::Initialize();
    Widgets::Initialize();

    return true;
}

void Plugin::Update()
{
    Input::Update();
    Overlay::Update();
    Widgets::Update();
}

void Plugin::Draw()
{
    Renderer::BeginFrame();

    Overlay::Draw();
    Widgets::Draw();

    Renderer::EndFrame();
}

void Plugin::Exit()
{
    Widgets::Exit();
    Overlay::Exit();
    Renderer::Exit();
}
