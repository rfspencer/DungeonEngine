
#include <iostream>
#include <ostream>

#include <Core.h>

#include "MainMenuLevel.h"

const std::wstring GAME_NAME = L"Dungeon Crawler";
constexpr short WINDOW_WIDTH = 90;
constexpr short WINDOW_HEIGHT = 15;

class DungeonGame : public Application
{
public:
    DungeonGame(short InWindowWidth, short InWindowHeight, const std::wstring& InTitle)
        : Application(InWindowWidth, InWindowHeight, InTitle)
    {
        // Load Asset Manager
        // Load Main Menu World
        WeakPtr<MainMenuLevel> NewWorld = LoadWorld<MainMenuLevel>();
    }
};

Application* GetApplication()
{
    return new DungeonGame(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);
}
