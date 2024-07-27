#include "MainMenuHUD.h"

#include "Core/Utilities/FileHandler.h"

#include <iostream>
#include <ostream>

const char* DATA_MAINMENU_LAYOUT_PATH = "src/Game/Data/MainMenu.layout";

MainMenuHUD::MainMenuHUD()
    : m_MenuTitleText("Main Menu"),
      m_NewGameText("N: New Game"),
      m_QuitGameText("Q: Quit")
{
    Init();
}

void MainMenuHUD::Render(Renderer& InRendererRef)
{
    m_MainMenuBackground.RenderInternal(InRendererRef, true);
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
    // TODO: Ideally this should be handled in an Asset Manager class and cached
    bool temp = FileHandler::DoesFileExist(DATA_MAINMENU_LAYOUT_PATH);
    if (temp)
    {
        std::string Temp = FileHandler::ReadFile(DATA_MAINMENU_LAYOUT_PATH);
        m_MainMenuBackground = FileHandler::StringToTextWidget(Temp);
    }
    m_MainMenuBackground.SetWidgetPosition(0, 0);
    m_MenuTitleText.SetWidgetPosition(54, 15);
    m_NewGameText.SetWidgetPosition(52, 18);
    m_QuitGameText.SetWidgetPosition(52, 20);
}
