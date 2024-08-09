/**
* @file Map.h
 * @brief Header for the Map class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include <string>

#include "Application.h"
#include "Core/Actor.h"

/**
 * @class Map
 *
 * @brief A class representing a map in the game.
 *
 * The Map class is derived from the Actor class and represents a map in the game.
 * It contains methods for initializing the map, rendering it on the screen,
 * and performing various operations on the map data. The actual map data is stored
 * as a 2D array of characters.
 */
class Map : public Actor
{
public:
    Map(World* InOwningWorld, const std::string& InPath = "");

    /**
     * @brief Initialize the map.
     *
     * This method initializes the map by setting its size, loading the map layout from a file,
     * and broadcasting that the map is loaded.
     *
     * @param InPath The path to the file containing the map layout.
     *
     * @note This method assumes that the file exists and contains valid map data.
     */
    void Init(const std::string& InPath);

    /**
     * @brief Renders the map on the screen using the given renderer.
     *
     * This method is called to render the map on the screen. It takes a reference to a Renderer object as a parameter,
     * which is responsible for drawing the map. If the map is not pending destruction, it calls the DrawActor method of the
     * Renderer object to render the map.
     *
     * @param InRendererRef The Renderer object used to draw the map.
     */
    void Render(Renderer& InRendererRef) override;

    /**
     * @brief Checks if the tile at the specified position is empty.
     *
     * This method checks if the tile at the specified (x, y) position in the map
     * layout is empty. An empty tile is represented by a space character (' ').
     *
     * @param InPosition The position of the tile to check.
     * @return True if the tile is empty, false otherwise.
     */
    bool TileIsEmpty(Vector2i InPosition) const;

    /**
     * @brief Get the map layout.
     *
     * This method returns a pointer to the 2D array of characters representing the map layout.
     *
     * @return A pointer to the map layout.
     */
    std::array<std::array<char, WINDOW_WIDTH>, WINDOW_HEIGHT>* GetMap() { return &m_MapLayout; }

    /**
     * @brief Adds an actor to the map.
     *
     * This method adds the specified actor to the map by updating the appropriate
     * location in the map layout with the actor's sprite's first character. The actor's
     * location is obtained using its GetActorLocation() method, and the sprite character
     * is obtained using the actor's GetSprite() method.
     *
     * @param InActor The actor to be added to the map.
     */
    void AddActorToMap(Actor* InActor);

    /**
     * @brief Removes an actor from the map.
     *
     * This method removes the specified actor from the map by clearing its position on the map layout.
     * The actor's position is obtained using the `GetActorLocation()` method and the corresponding cell
     * in the map layout is set to a space character (' ') to clear it.
     *
     * @param InActor The actor to remove from the map.
     *
     * @note If `InActor` is `nullptr`, no action is performed.
     * @note The actor must exist within the map's layout.
     */
    void RemoveActorFromMap(Actor* InActor);

    // Delegate to notify subscribers that the Map is loaded
    Delegate<> OnMapLoaded;

private:

    // The actual map data to test against
    std::array<std::array<char, WINDOW_WIDTH>, WINDOW_HEIGHT> m_MapLayout;
};
