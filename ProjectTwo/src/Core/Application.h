#pragma once

#include <string>

#include "Clock.h"
#include "Types.h"
#include "Windows.h"
#include "World.h"

class Application
{
public:
    Application() = default;
    Application(short InWindowWidth, short InWindowHeight, const std::wstring& InTitle);

    void Run();

    template<typename WorldType>
    WeakPtr<WorldType> LoadWorld();

    void SetRenderIsDirty(const bool bRenderIsDirty) { m_bRenderIsDirty = bRenderIsDirty; }

private:
    void TickInternal(float DeltaTime);
    void RenderInternal();

    virtual void Render();
    virtual void Tick();
    
private:
    HANDLE m_ConsoleHandle;
    COORD m_ConsoleBufferSize;

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
