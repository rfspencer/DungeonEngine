#include "GameplayHUD.h"

#include "Utilities/FileHandler.h"

const char* DATA_GAMEPLAY_LAYOUT_PATH = "src/Game/Data/GameplayHUD.layout";

GameplayHUD::GameplayHUD()
{
    Init();
}

void GameplayHUD::Init()
{
    // TODO: Ideally this should be handled in an Asset Manager class and cached
    if (FileHandler::DoesFileExist(DATA_GAMEPLAY_LAYOUT_PATH))
    {
        std::string TempString = FileHandler::ReadFile(DATA_GAMEPLAY_LAYOUT_PATH);
        m_GameplayHUDBackground = FileHandler::StringToTextWidget(TempString);
    }
    m_GameplayHUDBackground.SetWidgetPosition(0, 0);
}

void GameplayHUD::Render(Renderer& InRendererRef)
{
    m_GameplayHUDBackground.RenderInternal(InRendererRef, true);
}

