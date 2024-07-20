
#include <iostream>
#include <ostream>

#include <Core.h>

class Game : public Application
{
public:
    Game()
    {
        // Load Asset Manager
        // Load Main Menu World
        
        std::cout << "Game Constructed" << std::endl;
    }
};

Application* GetApplication()
{
    return new Game();
}
