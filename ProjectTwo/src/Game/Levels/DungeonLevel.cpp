#include "Game/Levels/DungeonLevel.h"

#include <memory>

#include "Input.h"
#include "Actors/PickUp.h"
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
    // Level listening for Quit game
    m_InputEvent = std::bind(&DungeonLevel::HandleInput, this, std::placeholders::_1);
    Input::AddListener(m_InputEvent);

    // Begin spawning actors and HUD
    m_Map = SpawnActor<Map>(DATA_DUNGEON_MAP_PATH);
    m_GameplayHUD = SpawnHUD<GameplayHUD>();

    // Spawn Player
    m_Player = PlayerManager::Get().CreateNewPlayer(this);
    // Set player start location
    m_Player.lock()->SetActorLocation({14, 22});

    m_GameplayHUD.lock()->BindDelegates();

    // Adding pickups to the level
    WeakPtr<PickUp> GoldPickup1 = SpawnActor<PickUp>(Gold);
    GoldPickup1.lock()->SetActorLocation({62, 7});
    m_Map.lock()->AddActorToMap(GoldPickup1.lock().get());
}

void DungeonLevel::Tick(float DeltaTime)
{
}

void DungeonLevel::RemoveListenerForInput() const
{
    Input::RemoveListener(m_InputEvent);
}

void DungeonLevel::QuitGame()
{
    PlayerManager::Get().ResetPlayer();
    GetApplication()->GetRendererRef().ClearConsoleScreen();
    GetApplication()->LoadWorld<MainMenuLevel>();
}

void DungeonLevel::HandleInput(int InKeyPressed)
{
    if (InKeyPressed == '0')
    {
        QuitGame();
    }
}
