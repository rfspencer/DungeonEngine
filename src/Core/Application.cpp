/**
* @file Application.cpp
 * @brief Implementation for the Application class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#include "Core/Application.h"

#include <memory>

#include "Core/Input.h"

Application::Application(const int InWindowWidth, const int InWindowHeight, const std::wstring& InTitle)
    : m_WindowWidth(InWindowWidth), m_WindowHeight(InWindowHeight), m_Title(InTitle),
        m_TargetFrameRate(60.f), m_TickClock(), m_CurrentWorld(nullptr), m_PendingWorld(nullptr)
{
}

void Application::Run()
{
    // Create the renderer and initialize
    m_Renderer = std::make_unique<Renderer>();
    m_Renderer->Init(m_Title);

    // Reset and start the TickClock
    m_TickClock.Restart();
    float AccumulatedTime = 0.f;
    float TargetDeltaTime = 1.f / m_TargetFrameRate;
    
    bool bAppRunning = true;
    while (bAppRunning)
    {        
        // Poll input events
        ProcessInput();
        
        // TODO: Dispatch application events
        
        // Handle tick, timers
        float FrameDeltaTime = m_TickClock.Restart();
        AccumulatedTime += FrameDeltaTime;

        // Render only if current frame is dirty AND if we've accumulated time outside TargetDeltaTime
        if (AccumulatedTime > TargetDeltaTime)
        {
            AccumulatedTime -= TargetDeltaTime;
            TickInternal(TargetDeltaTime);
            RenderInternal(*m_Renderer);
        }
    }
}

void Application::TickInternal(float DeltaTime)
{
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
