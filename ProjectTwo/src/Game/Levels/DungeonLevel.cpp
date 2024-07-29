#include "Game/Levels/DungeonLevel.h"

#include <memory>

#include "Core/Application.h"
#include "Core/Map.h"
#include "Game/Levels/MainMenuLevel.h"
#include "Game/Player/PlayerManager.h"
#include "Game/Player/Player.h"
#include "Game/Widgets/GameplayHUD.h"

const char* DATA_DUNGEON_MAP_PATH = "src/Game/Data/DungeonOne.map";

DungeonLevel::DungeonLevel(Application* InOwningApp)
    : World(InOwningApp)
{
}

void DungeonLevel::BeginPlay()
{
    m_Map = SpawnActor<Map>(DATA_DUNGEON_MAP_PATH);
    m_GameplayHUD = SpawnHUD<GameplayHUD>();

    m_Player = PlayerManager::Get().CreateNewPlayer(this);
    
    // Set player start location
    m_Player.lock()->SetActorLocation({14, 22});
}

void DungeonLevel::Tick(float DeltaTime)
{
}

void DungeonLevel::QuitGame()
{
    GetApplication()->GetRendererRef().ClearConsoleScreen();
    GetApplication()->LoadWorld<MainMenuLevel>();
}
