#pragma once

#include <array>
#include <string>

#include "Windows.h"
#include "Core/World.h"
#include "Game/Utilities/Constants.h" // TODO: not great to include game stuff here. Find a way to keep this in Game
#include "Utilities/Vector2i.h"

class Map;
class Widget;

class Renderer
{
public:
    Renderer();
    
    void Init(std::wstring InTitle);

    void ClearConsoleScreen();

    void DrawActor(Actor& InActor);
    void DrawActor(Map* InMap);
    void DrawUI(Widget& InWidget, Vector2i InPosition, bool bIsMultiLine = false);
    
    void DisplayRenderBuffer();
    
private:
    void FixConsoleWindow();
    void HideCursor();
    void GoToXY(int InX, int InY);
    void AddElementToRenderBuffer(CHAR_INFO InSprite, Vector2i InPosition);

    void SetConsoleColor(int InColor);

    // Render buffer array
    std::array<CHAR_INFO, WINDOW_WIDTH * WINDOW_HEIGHT> m_RenderBuffer;
};

