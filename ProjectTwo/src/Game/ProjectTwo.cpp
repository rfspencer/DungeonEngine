
#include <iostream>
#include <ostream>

#include <Core.h>

const std::wstring GAME_NAME = L"Dungeon Crawler";
constexpr short WINDOW_WIDTH = 90;
constexpr short WINDOW_HEIGHT = 15;

class Game : public Application
{
public:
    Game(short InWindowWidth, short InWindowHeight, const std::wstring& InTitle)
        : Application(InWindowWidth, InWindowHeight, InTitle)
    {
        // Load Asset Manager
        // Load Main Menu World
        
        std::cout << "Game Constructed" << std::endl;
    }
};

Application* GetApplication()
{
    return new Game(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);
}
