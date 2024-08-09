// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

#include <string>

#include "Clock.h"
#include "Renderer.h"
#include "Types.h"
#include "World.h"

class Input;

/**
 * @class Application
 * @brief The main application class that controls the execution of the game.
 */
class Application
{
public:
    Application() = default;
    Application(const int InWindowWidth, const int InWindowHeight, const std::wstring& InTitle);

    /**
     * @brief Runs the application and controls the execution of the game.
     *
     * This method is responsible for creating the renderer, initializing it,
     * and controlling the game loop. It handles input processing, tick updates,
     * and rendering of the game world.
     *
     * The game loop runs continuously until the application is quit. In each
     * iteration of the loop, it first checks for input events, then updates the
     * game state based on the elapsed time since the last iteration. If the
     * current frame is marked as "dirty" and enough time has accumulated outside
     * the target delta time, the game world is ticked and rendered using the
     * Renderer.
     *
     * @note The actual game logic and rendering should be implemented in the
     * derived classes by overriding the Render and Tick methods as needed.
     */
    void Run();
    
    /**
     * @brief Loads a new world of type WorldType into the application.
     *
     * This method creates a new instance of WorldType and stores it as the pending world
     * in the Application object. It then returns a weak pointer to the new world.
     *
     * @tparam WorldType The type of the world to be loaded.
     * @return A weak pointer to the new world.
     */
    template<typename WorldType>
    WeakPtr<WorldType> LoadWorld();

    /**
     * @brief Returns a reference to the Renderer object used by the Application.
     *
     * This method returns a reference to the Renderer object that is stored in the m_Renderer member
     * variable of the Application class.
     *
     * @return A reference to the Renderer object.
     */
    inline Renderer& GetRendererRef() const { return *(m_Renderer.get()); }
    
    void QuitApplication();


private:
    /**
     * @brief Handles the internal tick of the Application.
     *
     * This method is called internally by the Application to update the current World, if it exists,
     * and handle the loading of a pending World, if one exists. It calls the TickInternal method of the
     * current World to update the game logic.
     *
     * @param DeltaTime The elapsed time since the last tick in seconds.
     */
    void TickInternal(float DeltaTime);
    /**
     * @brief Renders the game world using the provided Renderer.
     *
     * This method is responsible for initiating the rendering process. It clears the screen buffer,
     * populates the render buffer with the game world objects, and displays the render buffer
     * onto the screen.
     *
     * @param InRendererRef The reference to the Renderer object used for rendering.
     */
    void RenderInternal(Renderer& InRendererRef);

    /**
     * @brief Renders the game world using the provided Renderer.
     *
     * This method is responsible for initiating the rendering process. It clears the screen buffer,
     * populates the render buffer with the game world objects, and displays the render buffer
     * onto the screen.
     *
     * @param InRendererRef The reference to the Renderer object used for rendering.
     */
    virtual void Render(Renderer& InRendererRef);
    /**
     * @brief Updates the game logic of the current world.
     *
     * This method is called internally by the Application to update the game logic of the current world.
     * It should be overridden in the derived classes to implement the specific game logic.
     *
     * This method should be called continuously in the game loop to update the game state based on the elapsed time.
     */
    virtual void Tick();

    /**
     * @brief Processes the input events for the application.
     *
     * This method is responsible for updating the input state of the application.
     * It calls the Update method of the Input class to update the input state,
     * such as the currently pressed key. The Input class encapsulates the input
     * handling and provides methods to query the current input state.
     *
     * @note This method should be called once per frame before handling the input state.
     */
    void ProcessInput();
    
private:
    short m_WindowWidth;
    short m_WindowHeight;
    std::wstring m_Title;

    float m_TargetFrameRate;
    Clock m_TickClock;

    SharedPtr<World> m_CurrentWorld;
    SharedPtr<World> m_PendingWorld;

    UniquePtr<Renderer> m_Renderer;
};

// Gets defined in the Game
Application* GetApplication();

template<typename WorldType>
WeakPtr<WorldType> Application::LoadWorld()
{
    SharedPtr<WorldType> NewWorld{new WorldType{this}};
    m_PendingWorld = NewWorld;
    return NewWorld;
}
