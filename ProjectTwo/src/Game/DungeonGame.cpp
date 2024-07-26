
#include <iostream>
#include <ostream>

#include <Core.h>

#include "MainMenuLevel.h"
#include "Game/Utilities/Constants.h"

class DungeonGame : public Application
{
public:
    DungeonGame(int InWindowWidth, int InWindowHeight, const std::wstring& InTitle)
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
