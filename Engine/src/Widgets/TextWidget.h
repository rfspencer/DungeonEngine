﻿// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

#include <string>

#include "Widget.h"

/**
 * @class TextWidget
 * @brief A class that represents a text widget.
 *
 * The TextWidget class inherits from the Widget class and provides functionality to display and manipulate text.
 */
class TextWidget : public Widget
{
public:
    TextWidget() = default;
    TextWidget(const std::string& InText);

    void SetText(const std::string& InString);
    std::string GetText() { return m_Text; }

private:
    void Render(Renderer& InRendererRef, bool bIsMultiLine = false) override;

    std::string m_Text;
};
