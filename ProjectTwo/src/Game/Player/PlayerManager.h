/**
* @file PlayerManager.h
 * @brief Header for the PlayerManager class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include "Player.h"

/**
 * @class PlayerManager
 * @brief The PlayerManager class manages the creation and retrieval of Player objects.
 *
 * The PlayerManager class is responsible for creating new Player objects and providing access to them.
 * It ensures that only one instance of PlayerManager exists by implementing the singleton pattern.
 * PlayerManager also allows resetting the currently active Player.
 */
class PlayerManager
{
public:
    /**
     * @brief Creates a new Player and adds it to the PlayerManager.
     *
     * This method creates a new Player object and adds it to the PlayerManager's list of players.
     * The new player is associated with the given world.
     *
     * @param InOwningWorld A pointer to the World object that the new Player will be associated with.
     *
     * @return A weak pointer to the newly created Player.
     */
    WeakPtr<Player> CreateNewPlayer(World* InOwningWorld);

    /**
     * @brief Retrieves the active Player.
     *
     * The GetPlayer method retrieves the currently active Player object. It returns a weak pointer to the Player object.
     *
     * @return A weak pointer to the currently active Player object.
     */
    WeakPtr<Player> GetPlayer();
    WeakPtr<Player> GetPlayer() const;

    /**
     * @fn PlayerManager & PlayerManager::Get()
     * @brief Retrieves the singleton instance of PlayerManager.
     *
     * The Get method retrieves the singleton instance of the PlayerManager class.
     *
     * @return A reference to the singleton instance of PlayerManager.
     */
    static PlayerManager& Get();

    /**
     * @brief Resets the currently active Player.
     *
     * The ResetPlayer method clears the list of players in the PlayerManager,
     * effectively resetting the active Player.
     */
    void ResetPlayer();

protected:
    PlayerManager() = default;

private:
    /**
     * @brief List of shared pointers to Player objects.
     *
     * The m_Players variable is a list of shared pointers to Player objects.
     * It is used by the PlayerManager class to manage the creation and retrieval of Player objects.
     * Each shared pointer represents a Player object and allows for easy access and manipulation of the Player objects.
     * The list can contain zero or more Player objects.
     */
    List<SharedPtr<Player>> m_Players;

    /**
     * @var PlayerManager::m_PlayerManager
     * @brief A pointer to the singleton instance of PlayerManager.
     *
     * The m_PlayerManager variable is a pointer to the singleton instance of the PlayerManager class.
     * It is used to ensure that only one instance of PlayerManager exists by implementing the singleton pattern.
     * The variable is initialized as nullptr and will be assigned the instance of PlayerManager when the Get() method is called.
     * Once initialized, this variable provides access to the PlayerManager instance across the application.
     * It is a private variable and cannot be accessed directly from outside the PlayerManager class.
     * To retrieve the singleton instance of PlayerManager, use the Get() method.
     *
     * @see PlayerManager::Get()
     */
    static UniquePtr<PlayerManager> m_PlayerManager;
};
