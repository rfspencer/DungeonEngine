#include "Game/Levels/DungeonLevel.h"

#include <memory>

#include "Application.h"
#include "MainMenuLevel.h"
#include "Player.h"
#include "Game/Widgets/GameplayHUD.h"

DungeonLevel::DungeonLevel(Application* InOwningApp)
    : World(InOwningApp)
{
}

void DungeonLevel::BeginPlay()
{
    m_GameplayHUD = SpawnHUD<GameplayHUD>();
    m_Player = SpawnActor<Player>();
}

void DungeonLevel::Tick(float DeltaTime)
{
}

void DungeonLevel::QuitGame()
{
    GetApplication()->GetRendererRef().ClearConsoleScreen();
    GetApplication()->LoadWorld<MainMenuLevel>();
}
