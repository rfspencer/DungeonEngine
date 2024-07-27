#include "Core/Application.h"

#include <iomanip>
#include <iostream>
#include <memory>

#include "Core/Input.h"

Application::Application(const int InWindowWidth, const int InWindowHeight, const std::wstring& InTitle)
    : m_WindowWidth(InWindowWidth), m_WindowHeight(InWindowHeight), m_Title(InTitle),
        m_TargetFrameRate(60.f), m_TickClock(), m_CurrentWorld(nullptr), m_PendingWorld(nullptr), m_bRenderIsDirty(true)
{
}

void Application::Run()
{
    // Create the renderer and initialize
    UniquePtr<Renderer> Console(new Renderer());
    Console->Init(m_Title);

    // Reset and start the TickClock
    m_TickClock.Restart();
    float AccumulatedTime = 0.f;
    float TargetDeltaTime = 1.f / m_TargetFrameRate;
    
    bool bAppRunning = true;
    while (bAppRunning)
    {        
        // Poll input events
        ProcessInput();
        
        // Dispatch events
        
        // Handle tick, timers
        float FrameDeltaTime = m_TickClock.Restart();
        AccumulatedTime += FrameDeltaTime;

        // Render only if current frame is dirty AND if we've accumulated time outside TargetDeltaTime
        if (m_bRenderIsDirty && AccumulatedTime > TargetDeltaTime)
        {
            AccumulatedTime -= TargetDeltaTime;
            TickInternal(TargetDeltaTime);
            RenderInternal(*Console);
        }
    }
}

void Application::TickInternal(float DeltaTime)
{
    // std::cout << "Ticking...DeltaTime: " << std::fixed << std::setprecision(9) << DeltaTime << std::endl;

    if (m_CurrentWorld)
    {
        m_CurrentWorld->TickInternal(DeltaTime);
    }

    if (m_PendingWorld && m_PendingWorld != m_CurrentWorld)
    {
        m_CurrentWorld = m_PendingWorld;

        m_CurrentWorld->BeginPlayInternal();
    }
}

void Application::RenderInternal(Renderer& InRendererRef)
{
    // Clear Screen buffer, Windows only
    // InRendererRef.ClearConsoleScreen();

    // Populate the render buffer
    Render(InRendererRef);

    // Display buffer
    InRendererRef.DisplayRenderBuffer();
}

void Application::Render(Renderer& InRendererRef)
{
    m_CurrentWorld->Render(InRendererRef);
}

void Application::ProcessInput()
{
    Input::Update();
}

void Application::Tick()
{
}

void Application::QuitApplication()
{
    ExitProcess(0);
}
