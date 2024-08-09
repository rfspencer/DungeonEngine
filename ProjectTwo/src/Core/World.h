/**
* @file World.h
 * @brief Header for the World class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include "Core/Object.h"
#include "Core/Types.h"

class Player;
class Actor;
class Application;
class HUD;
class Renderer;

/**
 * @class World
 * @brief The World class represents the game world in the application.
 *
 * The World class is responsible for managing the game world, including
 * initializing and updating objects, as well as handling rendering.
 */
class World : public Object
{
public:
    World(Application* OwningApp);

    /**
     * @brief Begins playing the game world.
     *
     * The BeginPlayInternal method is called to begin the gameplay in the game world.
     * It checks if the game world has already been initialized by checking the value of
     * the m_bBeginPlay flag. If the flag is false, it sets it to true and calls the
     * BeginPlay method to perform any necessary initialization for the game world.
     *
     * @note This method should only be called once in the lifetime of the game world.
     */
    void BeginPlayInternal();

    /**
     * @brief Calls the TickInternal method on all actors in the world and updates the game world.
     *
     * This method is responsible for updating the game world by calling the TickInternal method on all actors
     * in the world. It also handles the initialization of new actors and the removal of pending actors.
     *
     * @param DeltaTime The time elapsed since the last tick, in seconds.
     */
    void TickInternal(float DeltaTime);

    /**
     * @brief Renders the game world using the given renderer.
     *
     * This method renders the game world by calling the Render method of each actor in the world,
     * and then rendering the HUD.
     *
     * @param InRendererRef - A reference to the renderer used to render the game world.
     */
    void Render(Renderer& InRendererRef);

    /** @class World
     *  @brief The World class represents the game world in the application.
     *
     *  The World class is responsible for managing the game world, including
     *  initializing and updating objects, as well as handling rendering.
     */
    virtual ~World();

    /**
     * @brief Spawns a new actor of type ActorType in the world.
     *
     * @tparam ActorType The type of actor to spawn.
     * @tparam Args The argument types required to construct an instance of ActorType.
     * @param InArgs The arguments to pass to the constructor of ActorType.
     * @return WeakPtr<ActorType> A weak pointer to the newly spawned actor.
     */
    template<typename ActorType, typename... Args>
    WeakPtr<ActorType> SpawnActor(Args... InArgs);

    /**
     * @brief Spawns a new instance of a HUD and sets it as the current HUD of the World.
     *
     * This method creates a new instance of the specified HUD type using the provided arguments,
     * and sets it as the current HUD of the World. The previous HUD, if any, will be replaced.
     *
     * @tparam HUDType The type of the HUD to spawn.
     * @tparam Args The types of the arguments to pass to the HUD constructor.
     * @param InArgs The arguments to pass to the HUD constructor.
     * @return A weak pointer to the newly created HUD instance.
     */
    template<typename HUDType, typename... Args>
    WeakPtr<HUDType> SpawnHUD(Args... InArgs);

    /**
     * @brief Returns a pointer to the Application that owns the World.
     *
     * This method returns a pointer to the Application object that owns the World.
     *
     * @return Application* - Pointer to the Application object that owns the World.
     */
    Application* GetApplication() { return m_OwningApp; }

    /**
     * @brief Returns a constant pointer to the Application object.
     *
     * The GetApplication method returns a constant pointer to the Application object which is responsible for
     * managing the game world, initializing and updating objects, and handling rendering.
     * This method is declared as const, which means it does not modify the state of the World object.
     *
     * @return const Application* - A constant pointer to the Application object.
     */
    const Application* GetApplication() const { return m_OwningApp; }

    /**
     * @brief Retrieves the player object.
     *
     * This function retrieves a weak reference to the player object in the game world.
     * The weak reference allows you to hold a non-owning reference to the player object.
     * If all strong references to the player object are destroyed, the weak reference
     * will become invalid.
     *
     * @return WeakPtr<Player> - A weak reference to the player object.
     */
    virtual WeakPtr<Player> GetPlayer() { return WeakPtr<Player>{}; }

    // TODO: Not ideal. Future refactoring will need to fix this
    // Ideally, Player would be the controller which would spawn the Pawn in the World.
    friend class PlayerManager;

private:
    /**
     * @brief Begins the play of the game world.
     *
     * The BeginPlay method is called at the start of the game to initialize the game world
     * and prepare it for gameplay. This method should be overridden in derived classes to
     * add custom initialization logic.
     *
     * @note This method is automatically called by the game engine and should not be called
     * directly by the user.
     */
    virtual void BeginPlay();

    /**
     * @brief Updates the game world.
     *
     * The Tick method is responsible for updating the game world by
     * advancing the simulation of objects and performing any necessary
     * calculations or updates. It is called every frame with the time
     * difference between frames as the DeltaTime parameter.
     *
     * @param DeltaTime The time difference between frames in seconds.
     *   This value is used to ensure consistent movement and calculations
     *   regardless of the frame rate.
     */
    virtual void Tick(float DeltaTime);

    /**
     * @brief Renders the HUD (Heads-Up Display) in the game world.
     *
     * This method is responsible for rendering the HUD (Heads-Up Display) in the game world.
     * It takes a reference to a Renderer object as a parameter, through which the HUD is rendered.
     * If the game's HUD exists in the game world, it will be rendered using the provided Renderer object.
     *
     * @param InRendererRef The reference to the Renderer object used for rendering the HUD.
     *                      This object must be previously initialized and represent a valid rendering context.
     *                      The HUD will be rendered using this Renderer object.
     *
     * @note This method assumes that the World object contains a valid HUD object.
     *       If the HUD does not exist, this method will do nothing.
     *       Ensure that the HUD is properly initialized and assigned to the World object before calling this method.
     */
    void RenderHUD(Renderer& InRendererRef);
    
private:
    Application* m_OwningApp;
    bool m_bBeginPlay;

    List<SharedPtr<Actor>> m_Actors;
    List<SharedPtr<Actor>> m_PendingActors;

    SharedPtr<HUD> m_HUD;
    
};

template<typename ActorType, typename... Args>
WeakPtr<ActorType> World::SpawnActor(Args... InArgs)
{
    SharedPtr<ActorType> NewActor{ new ActorType(this, InArgs...) };
    m_PendingActors.push_back(NewActor);
    return NewActor;
}

template<typename HUDType, typename... Args>
WeakPtr<HUDType> World::SpawnHUD(Args... InArgs)
{
    SharedPtr<HUDType> NewHUD{ new HUDType(InArgs...) };
    m_HUD = NewHUD;
    return NewHUD;
}
