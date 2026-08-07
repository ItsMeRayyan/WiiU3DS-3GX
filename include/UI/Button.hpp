#pragma once

#include "UI/Widget.hpp"
#include "Graphics/Color.hpp"

#include <string>
#include <functional>

class Button : public Widget
{
public:
    Button(
        const Rect& bounds,
        const std::string& text
    );

    void Update(Input& input) override;
    void Draw() override;

    void SetOnClick(const std::function<void()>& callback);

    const std::string& GetText() const;
    void SetText(const std::string& text);

private:
    std::string text;
    std::function<void()> onClick;

    bool pressed = false;
};
