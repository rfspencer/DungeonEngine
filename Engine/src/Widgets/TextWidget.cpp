// Copyright (c) 2024 Rich Spencer. All rights reserved.

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

void TextWidget::Render(Renderer& InRendererRef, bool bIsMultiLine)
{
    if (GetDoesNeedUpdate())
    {
        InRendererRef.DrawUI(*this, GetWidgetPosition(), bIsMultiLine);
    }
    SetDoesNeedUpdate(false);
}
