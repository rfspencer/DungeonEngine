#include "Application.h"

#include <iomanip>
#include <iostream>
#include <ostream>

Application::Application(const short InWindowWidth, const short InWindowHeight, const std::wstring& InTitle)
    : m_WindowWidth(InWindowWidth), m_WindowHeight(InWindowHeight), m_Title(InTitle),
        m_TargetFrameRate(60.f), m_TickClock(), m_CurrentWorld(nullptr), m_PendingWorld(nullptr), m_bRenderIsDirty(true)
{
}

void Application::Run()
{
    m_TickClock.Restart();
    float AccumulatedTime = 0.f;
    float TargetDeltaTime = 1.f / m_TargetFrameRate;
    
    bool bAppRunning = true;
    while (bAppRunning)
    {
        // Poll input events
        
        // Dispatch events
        
        // Handle tick, timers
        float FrameDeltaTime = m_TickClock.Restart();
        AccumulatedTime += FrameDeltaTime;

        // Render only if current frame is dirty AND if we've accumulated time outside TargetDeltaTime
        if (m_bRenderIsDirty && AccumulatedTime > TargetDeltaTime)
        {
            AccumulatedTime -= TargetDeltaTime;
            TickInternal(TargetDeltaTime);
            RenderInternal();
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

void Application::RenderInternal()
{
    // Clear Screen buffer

    // Render()

    // Display buffer
    
    
    //m_bRenderIsDirty = false;
    
    /*// Get the console handle
    m_ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Set cursor properties
    CONSOLE_CURSOR_INFO ConCurInfo;
    ConCurInfo.dwSize = 10;
    ConCurInfo.bVisible = false;
    SetConsoleCursorInfo(m_ConsoleHandle, &ConCurInfo);
    
    // Set the console window size
    m_ConsoleBufferSize = {m_WindowWidth, m_WindowHeight};
    SetConsoleScreenBufferSize(m_ConsoleHandle, m_ConsoleBufferSize);
    
    // Get the console screen buffer info
    CONSOLE_SCREEN_BUFFER_INFO CSBI;
    GetConsoleScreenBufferInfo(m_ConsoleHandle, &CSBI);

    // Calculate the position to center the text, screen width and height from CSBI
    COORD CursorPosition;
    CursorPosition.X = (CSBI.dwSize.X - m_Title.length()) / 2;
    CursorPosition.Y = CSBI.dwSize.Y / 2;

    // Set cursor position
    SetConsoleCursorPosition(m_ConsoleHandle, CursorPosition);

    // Write the text to the console
    DWORD Length;
    WriteConsoleW(m_ConsoleHandle, m_Title.c_str(), m_Title.length(), nullptr, nullptr);*/
}

void Application::Render()
{
}

void Application::Tick()
{
}
