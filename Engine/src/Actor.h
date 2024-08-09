// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

#include <string>

#include "Object.h"
#include "Utilities/Vector2i.h"
#include "Utilities/Transform.h"

class Renderer;
class World;

/**
 * @class Actor
 * @brief Represents an actor in the game world
 *
 * The Actor class is the base class for all game objects in the game world. Actors
 * have a position, size, and can be rendered to the screen.
 */
class Actor : public Object
{
public:
    Actor(World* InOwningWorld);
    virtual ~Actor();

    /**
     * @brief Executes the internal BeginPlay logic for the Actor
     *
     * The BeginPlayInternal method is called internally to execute the begin play logic for the Actor.
     * It sets the m_HasBeganPlay flag to true if it has not been set already, and then calls the BeginPlay method.
     *
     * @note This method is called automatically and should not be called directly.
     */
    void BeginPlayInternal();
    /**
     * @brief Updates the actor's internal state based on the elapsed time.
     *
     * @param DeltaTime The time elapsed since the last update in seconds.
     */
    void TickInternal(float DeltaTime);
    /**
     * @brief Called when the actor begins playing in the game world
     *
     * This method is called when an actor begins playing in the game world. It is responsible
     * for initializing any necessary variables and setting up the actor for gameplay.
     */
    virtual void BeginPlay();
    /**
     * @brief Executes the tick behavior of the Actor.
     *
     * This method is called every frame to update the state of the Actor.
     *
     * @param DeltaTime The time elapsed since the last frame.
     */
    virtual void Tick(float DeltaTime);
    /**
     * @brief Renders the actor using the provided renderer.
     *
     * This method renders the actor using the specified renderer. If the actor is pending destroy,
     * it will not be rendered. The actor's sprite and override color will be used for rendering.
     *
     * @param InRendererRef The reference to the renderer to use for rendering.
     */
    virtual void Render(Renderer& InRendererRef);

    /**
     * @brief Sets the location of the actor to the specified position.
     *
     * This method sets the location of the actor to the specified position in the game world.
     *
     * @param InNewLocation The new location to set for the actor.
     */
    void SetActorLocation(const Vector2i InNewLocation);
    /**
     * @brief Returns the location of the actor.
     *
     * This method returns the current location of the actor as a Vector2i object.
     *
     * @return The location of the actor.
     */
    Vector2i GetActorLocation() const { return m_Transform.GetPosition(); }

    /**
     * @brief Sets the size of the actor.
     *
     * This method sets the size of the actor to the specified size.
     *
     * @param InSize The new size to set for the actor.
     */
    void SetActorSize(const Vector2i InSize);
    /**
     * @brief Returns the size of the actor.
     *
     * This method returns the size of the actor as a Vector2i object.
     *
     * @return The size of the actor.
     */
    Vector2i GetActorSize() const { return m_Transform.GetSize(); }

    /**
     * @brief Checks if the actor has moved during the current frame.
     *
     * This method checks if the actor has moved during the current frame by calling the HasMovedThisFrame method of the Transform component.
     *
     * @return True if the actor has moved during the current frame, false otherwise.
     */
    bool HasMovedThisFrame() const { return m_Transform.HasMovedThisFrame(); }
    /**
     * @brief Returns the previous position of the actor.
     *
     * This method returns the previous position of the actor as a Vector2i object. The previous
     * position is obtained from the Transform component of the actor.
     *
     * @return The previous position of the actor.
     */
    Vector2i GetPreviousPosition() const { return m_Transform.GetPreviousPosition(); }

    const World* GetWorld() const { return m_OwningWorld; }
    World* GetWorld() { return m_OwningWorld; }

    virtual void Destroy() override;

    virtual void ApplyDamage(float InAmount);

    /**
     * @brief Returns the sprite of the actor.
     *
     * This method returns the sprite of the actor as a reference to a std::string object.
     *
     * @return A reference to the sprite of the actor.
     */
    std::string& GetSprite() { return m_Sprite; }
    /**
     * @brief Sets the sprite of the actor.
     *
     * This method sets the sprite of the actor to the specified string.
     *
     * @param InString The new sprite to set for the actor.
     */
    void SetSprite(const std::string& InString) { m_Sprite = InString; }

    /**
     * @brief Returns the override color of the actor.
     *
     * This method returns the override color of the actor. The override color is used when rendering
     * the actor to the screen to modify its appearance.
     *
     * @return The override color of the actor as an integer value.
     */
    int GetOverrideColor() const { return m_OverrideColor; }
    /**
     * @brief Sets the override color for the actor.
     *
     * This method sets the override color for the actor. The override color is used during rendering to replace the tint of the sprite.
     * The color is specified as an integer value.
     *
     * @param InColor The new override color to set for the actor.
     */
    void SetOverrideColor(const int InColor) { m_OverrideColor = InColor; }

private:
    World* m_OwningWorld;
    bool m_HasBeganPlay;
    bool m_IsRenderable;

    std::string m_Sprite = "*";
    int m_OverrideColor = 7;

    Transform m_Transform = Transform();
};
