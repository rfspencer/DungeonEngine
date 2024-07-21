#include "Application.h"

#include <iostream>
#include <ostream>

Application::Application(const short InWindowWidth, const short InWindowHeight, const std::wstring& InTitle)
    : m_WindowWidth(InWindowWidth), m_WindowHeight(InWindowHeight), m_Title(InTitle), m_bRenderIsDirty(true)
{
}

void Application::Run()
{
    std::cout << "Application Running" << std::endl;

    bool bAppRunning = true;
    while (bAppRunning)
    {
        // Poll input events
        
        // Dispatch events
        
        // Handle tick, timers

        // Render
        if (m_bRenderIsDirty)
        {
            RenderInternal();
        }
    }
}

void Application::RenderInternal()
{
    // Clear Screen buffer

    // Render()

    // Display buffer

    
    m_bRenderIsDirty = false;
    
    // Get the console handle
    m_ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
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
    WriteConsoleW(m_ConsoleHandle, m_Title.c_str(), m_Title.length(), nullptr, nullptr);
}
