#pragma once

#include <string>

#include "Application.h"
#include "Core/Actor.h"
#include "Core/Widgets/TextWidget.h"


class Map : public Actor
{
public:
    Map(World* InOwningWorld, const std::string& InPath = "");

    void Init(const std::string& InPath);

    // Overideing Render from Actor to draw as UI instead of an Actor
    // void Render(Renderer& InRendererRef) override;

    std::array<char, WINDOW_WIDTH * WINDOW_HEIGHT>& GetMap() { return m_MapLayout; }

private:

    // The actual map data to test against
    std::array<char, WINDOW_WIDTH * WINDOW_HEIGHT> m_MapLayout;
};
