#include "UI/Button.hpp"
#include "System/Input.hpp"
#include "Graphics/Renderer.hpp"

Button::Button(
    const Rect& bounds,
    const std::string& text
)
    : text(text)
{
    SetBounds(bounds);
}

void Button::Update(Input& input)
{
    float x = static_cast<float>(input.GetTouchX());
    float y = static_cast<float>(input.GetTouchY());

    if (input.IsTouchDown() && bounds.Contains(x, y))
    {
        pressed = true;
    }

    if (input.IsTouchReleased())
    {
        if (pressed && bounds.Contains(x, y))
        {
            if (onClick)
            {
                onClick();
            }
        }

        pressed = false;
    }
}

void Button::Draw()
{
    Color background = pressed
        ? Color(180, 180, 180)
        : Color(220, 220, 220);

    Renderer::DrawRect(bounds, background);
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
