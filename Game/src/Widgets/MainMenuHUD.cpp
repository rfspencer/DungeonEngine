/**
* @file MainMenuHUD.cpp
 * @brief Implementation for the MainMenuHUD class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#include "MainMenuHUD.h"

#include "Utilities/FileHandler.h"

#include <ostream>

const char* DATA_MAINMENU_LAYOUT_PATH = "res/UI/MainMenu.layout";

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
