// Copyright (c) 2024 Rich Spencer. All rights reserved.

#include <iostream>

#include <DungeonEngine.h>

#include "Levels/MainMenuLevel.h"
#include "Utilities/Constants.h"

/**
 * @class DungeonGame
 * @brief The DungeonGame class represents a game application based on the DungeonGame class.
 *
 * This class is derived from the Application class and provides functionality specific to the game.
 */
class DungeonGame : public Application
{
public:
    /**
     * @brief DungeonGame constructor.
     *
     * This constructor initializes a DungeonGame object with the specified window dimensions and title.
     * It also loads the Asset Manager and the Main Menu World.
     *
     * @param InWindowWidth The width of the game window.
     * @param InWindowHeight The height of the game window.
     * @param InTitle The title of the game window.
     */
    DungeonGame(int InWindowWidth, int InWindowHeight, const std::wstring& InTitle)
        : Application(InWindowWidth, InWindowHeight, InTitle)
    {
        // TODO: Load Asset Manager
        // Load Main Menu World
        WeakPtr<MainMenuLevel> NewWorld = LoadWorld<MainMenuLevel>();
    }
};

/**
 * @brief Retrieves the game application.
 *
 * This method creates a new instance of the DungeonGame class with the specified window width, window height, and game name.
 * The DungeonGame class is derived from the Application class and provides functionality specific to the game.
 * The newly created DungeonGame object is then returned as an Application pointer.
 *
 * @return A pointer to the game application.
 */
Application* GetApplication()
{
    return new DungeonGame(WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);
}
