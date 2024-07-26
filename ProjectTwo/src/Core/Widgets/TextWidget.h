#pragma once

#include <string>

#include "Widget.h"

class TextWidget : public Widget
{
public:
    TextWidget() = default;
    TextWidget(const std::string& InText);

    void SetText(const std::string& InString);
    std::string GetText() { return m_Text; }

private:
    void Render(Renderer& InRendererRef) override;

    std::string m_Text;
};
