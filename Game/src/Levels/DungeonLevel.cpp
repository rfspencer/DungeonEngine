// Copyright (c) 2024 Rich Spencer. All rights reserved.

#include "Levels/DungeonLevel.h"

#include <memory>

#include "Application.h"
#include "Input.h"
#include "Map.h"
#include "Actors/PickUp.h"
#include "Levels/MainMenuLevel.h"
#include "Player/Player.h"
#include "Player/PlayerManager.h"
#include "Widgets/GameplayHUD.h"

const char* DATA_DUNGEON_MAP_PATH = "res/Maps/DungeonOne.map";

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
    m_Map = SpawnActor<Map>(DATA_DUNGEON_MAP_PATH, 120, 30);
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
    
    WeakPtr<PickUp> GoldPickup2 = SpawnActor<PickUp>(Gold);
    GoldPickup2.lock()->SetActorLocation({36, 14});
    m_Map.lock()->AddActorToMap(GoldPickup2.lock().get());
    
    WeakPtr<PickUp> GoldPickUp3 = SpawnActor<PickUp>(Gold);
    GoldPickUp3.lock()->SetActorLocation({86, 10});
    m_Map.lock()->AddActorToMap(GoldPickUp3.lock().get());
    
    WeakPtr<PickUp> Potion1 = SpawnActor<PickUp>(Health);
    Potion1.lock()->SetActorLocation({20, 8});
    m_Map.lock()->AddActorToMap(Potion1.lock().get());
    
    WeakPtr<PickUp> Potion2 = SpawnActor<PickUp>(Health);
    Potion2.lock()->SetActorLocation({60, 15});
    m_Map.lock()->AddActorToMap(Potion2.lock().get());
    
    WeakPtr<PickUp> Potion3 = SpawnActor<PickUp>(MaxHealth);
    Potion3.lock()->SetActorLocation({80, 7});
    m_Map.lock()->AddActorToMap(Potion3.lock().get());
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
