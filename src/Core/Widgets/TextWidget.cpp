/**
* @file TextWidget.cpp
 * @brief Implementation for the TextWidget class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

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
