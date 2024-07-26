#pragma once

#include <string>

#include "Core/Clock.h"
#include "Core/Renderer.h"
#include "Core/Types.h"
#include "Core/World.h"

class Application
{
public:
    Application() = default;
    Application(const int InWindowWidth, const int InWindowHeight, const std::wstring& InTitle);

    void Run();

    template<typename WorldType>
    WeakPtr<WorldType> LoadWorld();

    void SetRenderIsDirty(const bool bRenderIsDirty) { m_bRenderIsDirty = bRenderIsDirty; }

private:    
    void TickInternal(float DeltaTime);
    void RenderInternal(Renderer& InRendererRef);

    virtual void Render(Renderer& InRendererRef);
    virtual void Tick();
    
    void ProcessInput();
    
private:
    short m_WindowWidth;
    short m_WindowHeight;
    std::wstring m_Title;

    float m_TargetFrameRate;
    Clock m_TickClock;

    SharedPtr<World> m_CurrentWorld;
    SharedPtr<World> m_PendingWorld;
    
    bool m_bRenderIsDirty;
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
