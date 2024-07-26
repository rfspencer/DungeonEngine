#include "TextWidget.h"

#include <iostream>

#include "Renderer.h"

TextWidget::TextWidget(const std::string& InText)
    : m_Text(InText)
{
}

void TextWidget::SetText(const std::string& InString)
{
    m_Text = InString;
    SetDoesNeedUpdate(true);
}

void TextWidget::Render(Renderer& InRendererRef)
{
    InRendererRef.DrawUI(*this, GetWidgetPosition());
    SetDoesNeedUpdate(false);
}
