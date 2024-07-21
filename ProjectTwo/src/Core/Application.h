#pragma once
#include <string>

#include "Windows.h"

class Application
{
public:
    Application() = default;
    Application(short InWindowWidth, short InWindowHeight, const std::wstring& InTitle);

    void Run();

    void SetRenderIsDirty(const bool bRenderIsDirty) { m_bRenderIsDirty = bRenderIsDirty; }

private:
    void RenderInternal();
    
private:
    HANDLE m_ConsoleHandle;
    COORD m_ConsoleBufferSize;

    short m_WindowWidth;
    short m_WindowHeight;
    std::wstring m_Title;

    bool m_bRenderIsDirty;
};

// Gets defined in the Game
Application* GetApplication();
