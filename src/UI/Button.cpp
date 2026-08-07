#include "UI/Button.hpp"
#include "Graphics/Renderer.hpp"

Button::Button(
    const Rect& bounds,
    const std::string& text
)
    : text(text)
{
    SetBounds(bounds);
}

void Button::Update()
{
    /*
        TODO:
        Read touch state from the WiiU3DS Input system.

        Planned behavior:

        touch down inside bounds
            -> pressed = true

        touch released inside bounds
            -> call onClick()

        touch released outside bounds
            -> pressed = false
    */
}

void Button::Draw()
{
    Color background = pressed
        ? Color(180, 180, 180)
        : Color(220, 220, 220);

    Renderer::DrawRect(bounds, background);

    /*
        TODO:
        Draw button text once Renderer::DrawText()
        exists.
    */
}

void Button::SetOnClick(
    const std::function<void()>& callback
)
{
    onClick = callback;
}

const std::string& Button::GetText() const
{
    return text;
}

void Button::SetText(
    const std::string& newText
)
{
    text = newText;
}
