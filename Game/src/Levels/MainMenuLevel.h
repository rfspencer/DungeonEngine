// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

#include "World.h"

class MainMenuHUD;

/**
 * @class MainMenuLevel
 *
 * @brief The MainMenuLevel class represents the main menu level in the game world.
 *
 * It is a subclass of the World class and provides functionality for handling input, starting the game,
 * and quitting the game. It also contains a weak pointer to the MainMenuHUD class for displaying the main menu UI.
 */
class MainMenuLevel : public World
{
public:
    MainMenuLevel(Application* OwningApp);

    /**
     * @brief BeginPlay function for the MainMenuLevel class.
     * This function is called when the MainMenuLevel is initialized and ready to begin playing.
     * It binds the HandleInput function to the m_InputEvent member and adds it as a listener to the Input class.
     * This enables input handling for the main menu level.
     */
    void BeginPlay() override;

    /**
     * @brief The Tick method updates the main menu level every frame.
     *
     * The Tick method is called by the game engine every frame to update the state of the main menu level.
     * It takes in the amount of time that has passed since the previous frame as a parameter.
     *
     * @param DeltaTime The time, in seconds, that has passed since the previous frame.
     */
    void Tick(float DeltaTime) override;

    /**
     * @brief Remove the listener for input events.
     *
     * This method removes the listener for input events by calling the static method `RemoveListener` in the `Input` class.
     * The listener function that will be removed from the input event is the one specified by `m_InputEvent`.
     *
     * @return void
     */
    void RemoveListenerForInput() const;
    
private:
    /**
     * @brief Handles the input for the main menu level.
     *
     * This method is called when a key is pressed in the main menu level.
     * It checks the value of the input key and performs the corresponding action.
     *
     * @param InKeyPressed The key code of the pressed key.
     * @return void
     */
    void HandleInput(int InKeyPressed);

    /**
     * @brief Starts the game by loading the DungeonLevel world and clearing the console screen.
     *
     * This method is called when the user starts the game from the main menu. It first clears the console screen
     * using the `ClearConsoleScreen` method from the `Renderer` class. Then it removes the listener for input events
     * using the `RemoveListenerForInput` method from the `MainMenuLevel` class. Finally, it loads and initializes
     * the `DungeonLevel` world by calling the `LoadWorld` method from the `Application` class.
     *
     * @return void
     */
    void StartGame();

    /**
     * @brief Quit the game.
     *
     * This method is called to quit the game. It calls the QuitApplication method of the Application class to terminate the game.
     *
     * @return void
     */
    void QuitGame();

    /**
     * @brief The m_MainMenuHUD variable represents a weak pointer to the MainMenuHUD class.
     *
     * The MainMenuLevel class requires an instance of the MainMenuHUD class to display the main menu UI.
     * Using a weak pointer allows for flexibility in managing the lifetime of the MainMenuHUD instance,
     * ensuring it is cleaned up properly when no longer needed.
     */
    WeakPtr<MainMenuHUD> m_MainMenuHUD;

    /**
     * @brief m_InputEvent represents a callback function for handling input events.
     *
     * This variable is of type std::function<void(int)> and is used to store a function pointer or lambda
     * that takes an int parameter and returns void. The function or lambda can be assigned to this variable
     * and later called to handle input events. The int parameter represents the key code of the pressed key.
     */
    std::function<void(int)> m_InputEvent;
};
