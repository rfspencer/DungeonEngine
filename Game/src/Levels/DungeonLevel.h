// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

#include "World.h"

class Player;
class GameplayHUD;
class Map;

/**
 * @class DungeonLevel
 * @brief Represents a dungeon level within the game world.
 *
 * The DungeonLevel class is a child class of World and represents a specific level
 * within the game world. It provides methods for starting the level, updating it over time,
 * handling player input, and quitting the game. The DungeonLevel class also maintains
 * references to the player character, gameplay HUD, and the map associated with the level.
 */
class DungeonLevel : public World
{
public:
    DungeonLevel(Application* InOwningApp);

    /**
     * @brief Method called at the beginning of the game level.
     *
     * This method is called at the beginning of the game level. It initializes
     * the level by listening for input events, spawning actors and HUD, creating
     * the player character, and placing pickups in the level.
     *
     * The method does the following:
     *
     * 1. Sets up a listener for the "Quit game" input event.
     * 2. Spawns a Map actor using the DATA_DUNGEON_MAP_PATH.
     * 3. Spawns a GameplayHUD actor.
     * 4. Creates a new player character using the PlayerManager.
     * 5. Sets the player start location to (14, 22).
     * 6. Binds delegates for the GameplayHUD.
     * 7. Spawns multiple PickUp actors for gold and potions at specific locations in the map.
     * 8. Adds the spawned PickUp actors to the Map.
     */
    void BeginPlay() override;

    /**
     * @brief Updates the dungeon level over time.
     *
     * The `Tick` method is called repeatedly to update the dungeon level
     * based on the elapsed time `DeltaTime`. It is used to handle game logic,
     * update player input, and perform other necessary operations.
     *
     * @param DeltaTime The elapsed time since the last update in seconds.
     */
    void Tick(float DeltaTime) override;

    /**
     * @brief Remove a listener from the input event.
     *
     * This method removes a listener from the input event. It compares the target type of the listener with the callback passed as an argument.
     *
     * @param Callback The callback function to remove from the input event.
     *
     * @see DungeonLevel::HandleInput
     * @see Input::RemoveListener
     */
    void RemoveListenerForInput() const;

    /**
     * @brief Get the map associated with the dungeon level.
     *
     * This method returns a WeakPtr to the Map object associated with the DungeonLevel.
     * The Map represents the game world layout for the specific level. This method allows other
     * classes to access and interact with the Map object.
     *
     * @return A WeakPtr to the Map object.
     */
    WeakPtr<Map> GetMap() const { return m_Map; }

    /**
     * @brief Get the player character associated with the dungeon level.
     *
     * This method returns a weak pointer to the player character object that is associated with the
     * dungeon level. The weak pointer is used to safely access the player object, if it exists. If the
     * player character does not exist, the weak pointer will be empty.
     *
     * @return Weak pointer to the player character object.
     */
    WeakPtr<Player> GetPlayer() override { return m_Player; }

    /**
     * @brief Quit the game.
     *
     * The QuitGame method is used to quit the game. It performs the following tasks:
     *
     * 1. Resets the player.
     * 2. Clears the console screen.
     * 3. Loads the MainMenuLevel world.
     */
    void QuitGame();
    
private:
    /**
     * @brief Handles the input from the player.
     *
     * The HandleInput method is called when the player inputs a key. This method
     * is responsible for processing the input and performing the corresponding actions.
     *
     * @param InKeyPressed The key pressed by the player.
     *                     Valid values are ASCII values for characters.
     */
    void HandleInput(int InKeyPressed);

    /**
     * @var WeakPtr<Player> m_Player
     * @brief Represents the player character associated with the dungeon level.
     *
     * The m_Player variable is a weak pointer to the Player class object. It represents the player character
     * that is associated with the dungeon level. The weak pointer ensures that accessing the player character
     * is safe, even if the object has been destroyed. If the player character does not exist, the weak pointer
     * will be empty.
     */
    WeakPtr<Player> m_Player;
    /**
     * @var WeakPtr<Player> m_GameplayHUD
     * @brief Weak pointer to the GameplayHUD object associated with the DungeonLevel.
     *
     * The m_GameplayHUD variable is a weak pointer to the GameplayHUD object associated with the DungeonLevel.
     * The GameplayHUD provides the user interface elements for the gameplay, such as health bar, score display, etc.
     * The weak pointer is used to safely access the GameplayHUD object, if it exists. If the GameplayHUD object
     * does not exist, the weak pointer will be empty.
     */
    WeakPtr<GameplayHUD> m_GameplayHUD;

    /**
     * @var WeakPtr<Map> m_Map
     * @brief A weak pointer to the Map associated with the dungeon level.
     *
     * The m_Map variable represents a weak pointer to the Map object that is associated
     * with the dungeon level. It allows for accessing and manipulating the map data,
     * such as querying tile information, updating tile states, and performing operations
     * related to the game world within the current dungeon level.
     *
     * Note that a weak pointer is used to indicate that the ownership of the Map object
     * is not solely within the DungeonLevel class. Other parts of the code may also hold
     * references to the Map object, and the weak pointer should be used with caution to
     * handle potential null or expired pointer scenarios.
     */
    WeakPtr<Map> m_Map;
    
    /**
     * @brief Represents a callback function for handling input events.
     *
     * This variable is a std::function object that stores a callable object that takes
     * an integer as a parameter. It is used to implement a callback mechanism for handling
     * input events within the program. The callable object can be any function or lambda expression
     * that accepts an integer parameter and returns nothing.
     *
     * The purpose of this variable is to provide a way to pass input events, such as key presses
     * or mouse clicks, between different parts of the program. It can be assigned a function or
     * lambda expression that will be called whenever an input event occurs. The integer parameter
     * represents the specific input event that occurred, allowing the callback function to handle
     * different types of events in a flexible manner.
     */
    std::function<void(int)> m_InputEvent;
};
