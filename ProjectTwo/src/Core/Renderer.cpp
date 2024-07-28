#include "Core/Renderer.h"

#include <ostream>

#include "Core/Actor.h"
#include "Widgets/TextWidget.h"
#include "Widgets/Widget.h"

Renderer::Renderer()
    : m_RenderBuffer()
{
    FixConsoleWindow();
    HideCursor();
}

void Renderer::Init(std::wstring InTitle)
{
    // Initializing the buffer to remove garbage from previous console sessions
    HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD DWBufferSize = { WINDOW_WIDTH, WINDOW_HEIGHT };
    COORD DWBufferCoord = { 0, 0 };
    SMALL_RECT RCRegion = {0, 0, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1 };

    ReadConsoleOutput(OutputHandle, m_RenderBuffer.data(), DWBufferSize, DWBufferCoord, &RCRegion);
}

void Renderer::ClearConsoleScreen()
{
    HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    DWORD CellCount;
    DWORD Count;
    
    // Get the number cells in the current buffer
    if (!GetConsoleScreenBufferInfo(OutputHandle, &CSBI)) return;
    CellCount = CSBI.dwSize.X *CSBI.dwSize.Y;

    // Fill the entire buffer with spaces
    if (!FillConsoleOutputCharacter(OutputHandle, (TCHAR)' ', CellCount, {0,0}, &Count)) return;
    if (!FillConsoleOutputAttribute(OutputHandle, CSBI.wAttributes, CellCount, {0,0}, &Count)) return;

    // Clear the Render buffer
    CHAR_INFO Sprite;
    Sprite.Char.UnicodeChar = ' ';
    Sprite.Attributes = 0x0E; // Yellow color in decimal
    m_RenderBuffer.fill(Sprite);
    
    // Move cursor home
    SetConsoleCursorPosition(OutputHandle, {0,0});
}

void Renderer::DisplayRenderBuffer()
{
    HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD DWBufferSize = {WINDOW_WIDTH, WINDOW_HEIGHT};
    COORD DWBufferCoord = {0, 0};
    SMALL_RECT RCRegion = {0, 0, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1 };

    WriteConsoleOutput(OutputHandle, m_RenderBuffer.data(), DWBufferSize, DWBufferCoord, &RCRegion);
}

void Renderer::FixConsoleWindow()
{
    HWND ConsoleWindow = GetConsoleWindow();
    LONG Style = GetWindowLong(ConsoleWindow, GWL_STYLE);
    Style = Style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(ConsoleWindow, GWL_STYLE, Style);
}

void Renderer::HideCursor()
{
    HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    CursorInfo.bVisible = 0;
    CursorInfo.dwSize = 1;
    SetConsoleCursorInfo(ConsoleOutput, &CursorInfo);
}

void Renderer::GoToXY(int InX, int InY)
{
    COORD Coord;
    Coord.X = InX;
    Coord.Y = InY;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
}

void Renderer::DrawActor(Actor& InActor)
{
    // Actor calls this to add itself to a location in the Render buffer
    // TODO: Check if valid first
    Vector2i Location = InActor.GetActorLocation();
    int OverrideColor = InActor.GetOverrideColor();

    CHAR_INFO Sprite;
    Sprite.Char.UnicodeChar = InActor.GetSprite().at(0);
    Sprite.Attributes = static_cast<WORD>(OverrideColor);
    AddElementToRenderBuffer(Sprite, Location);

    // Erasing the sprite from the previous position
    if (InActor.HasMovedThisFrame())
    {
        Sprite.Char.UnicodeChar = ' ';
        Sprite.Attributes = static_cast<WORD>(OverrideColor);
        AddElementToRenderBuffer(Sprite, InActor.GetPreviousPosition());
    }
}

void Renderer::DrawUI(Widget& InWidget, Vector2i InPosition, bool bIsMultiLine)
{
    // TODO: Need to setup a Delegate system for the UI so the UI can update when game state changes
    // If we're trying to draw a TextWidget
    if(TextWidget* Text = dynamic_cast<TextWidget*>(&InWidget))
    {
        std::string TempStr = Text->GetText();
        for(size_t i = 0; i < TempStr.length(); ++i)
        {                
            CHAR_INFO Sprite;
            Sprite.Char.UnicodeChar = Text->GetText().at(i);
            Sprite.Attributes = static_cast<WORD>(InWidget.GetOverrideColor()); 
            Vector2i Position = Text->GetWidgetPosition();
            Position.X += static_cast<int>(i);
            if (bIsMultiLine)
            {
                Position.Y = TempStr.length() % (WINDOW_WIDTH);
            }
            AddElementToRenderBuffer(Sprite, Position);
        }
    }
}

void Renderer::AddElementToRenderBuffer(CHAR_INFO InSprite, Vector2i InPosition)
{
    // Y is the stride (rows), Y * 120. X is the count inside current stride (columns).
    // Add the element to render to the buffer
    int Y = InPosition.Y;
    int X = InPosition.X;
    m_RenderBuffer[Y * WINDOW_WIDTH + X] = InSprite;
}

void Renderer::SetConsoleColor(int InColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), InColor);
}