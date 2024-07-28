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

void DungeonLevel::RemoveListenerForInput() const
{
}

void DungeonLevel::HandleInput(int InKeyPressed)
{
}

void DungeonLevel::QuitGame()
{
    GetApplication()->GetRendererRef().ClearConsoleScreen();
    RemoveListenerForInput();
    GetApplication()->LoadWorld<MainMenuLevel>();
}
