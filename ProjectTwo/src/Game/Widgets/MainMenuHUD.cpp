#include "MainMenuHUD.h"

#include <iostream>
#include <ostream>

MainMenuHUD::MainMenuHUD()
    : m_MenuTitleText("Main Menu"),
      m_NewGameText("New Game"),
      m_QuitGameText("Quit")
{
    Init();
}

void MainMenuHUD::Render(Renderer& InRendererRef)
{
    m_MenuTitleText.RenderInternal(InRendererRef);
    m_NewGameText.RenderInternal(InRendererRef);
    m_QuitGameText.RenderInternal(InRendererRef);
}

bool MainMenuHUD::HandleEvent()
{
    return false;
}

void MainMenuHUD::Init()
{
    m_MainMenuLayout.SetWidgetPosition(0, 0);
    m_MenuTitleText.SetWidgetPosition(40, 10);
    m_NewGameText.SetWidgetPosition(40, 11);
    m_QuitGameText.SetWidgetPosition(40, 12);
}
