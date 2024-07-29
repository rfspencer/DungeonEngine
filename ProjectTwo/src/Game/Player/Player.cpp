/**
* @file Player.cpp
 * @brief Implementation for the Player class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#include "Player.h"

#include "Input.h"
#include "Map.h"
#include "Actors/PickUp.h"
#include "Interface/Interact.h"
#include "Levels/DungeonLevel.h"

Player::Player(World* InOwningWorld)
    : Actor(InOwningWorld),
      m_MoveSpeed(1), m_Level(1), m_XP(0), m_Gold(0)
{
    Init();
    m_Health = m_PlayerStats.MaxHP;
    SetOverrideColor(m_PlayerSettings.Color);
}

void Player::Init()
{
    SetSprite(m_PlayerSettings.Sprite);

    // Binding to input events
    m_InputEvent = std::bind(&Player::HandleInput, this, std::placeholders::_1);
    Input::AddListener(m_InputEvent);
}

void Player::BeginPlay()
{
    // Initial broadcast of all Player delegates to update HUD
    OnPlayerStatsChanged.Broadcast(m_PlayerStats);
    OnLevelChanged.Broadcast(m_Level);
    OnXPChanged.Broadcast(m_XP);
    OnGoldChanged.Broadcast(m_Gold);
    OnPositionChanged.Broadcast(GetActorLocation());
    OnMaxHealthChanged.Broadcast(m_PlayerStats.MaxHP);
    OnHealthChanged.Broadcast(m_Health);
}

void Player::Tick(float DeltaTime)
{
    Actor::Tick(DeltaTime);

    CheckForInteractables();
}

void Player::RemoveListenerForInput()
{
    Input::RemoveListener(m_InputEvent);
}

bool Player::CanMove(const Vector2i InOffset)
{
    // Check the map to see if the player can move into that position
    DungeonLevel* Level = dynamic_cast<DungeonLevel*>(GetWorld());
    WeakPtr<Map> Map = Level->GetMap();
    if (!Map.expired())
    {
        Vector2i PlayerPosition = GetActorLocation();
        Vector2i NewPosition = PlayerPosition + InOffset;
        if(Map.lock()->TileIsEmpty(NewPosition))
        {
            return true;
        }
    }
    return false;
}

void Player::Move(const Vector2i InOffset)
{
    if (CanMove(InOffset))
    {
        const Vector2i CurrentLocation = GetActorLocation();
        SetActorLocation(CurrentLocation + InOffset);
    }
    OnPositionChanged.Broadcast(GetActorLocation());
}

void Player::HandleInput(int InKeyPressed)
{
    if (InKeyPressed == tolower(PlayerSettings::InputKey::Up))
    {
        const Vector2i Direction{0, -1};
        Move(Direction);
    }
    if (InKeyPressed == tolower(PlayerSettings::InputKey::Down))
    {
        const Vector2i Direction{0, 1};
        Move(Direction);
    }
    if (InKeyPressed == tolower(PlayerSettings::InputKey::Left))
    {
        const Vector2i Direction{-1, 0};
        Move(Direction);
    }
    if (InKeyPressed == tolower(PlayerSettings::InputKey::Right))
    {
        const Vector2i Direction{1, 0};
        Move(Direction);
    }
}

bool Player::CheckForInteractables()
{
    // Check the squares surrounding the player
    bool bFoundInteractable = false;
    Vector2i CheckDirection = {0, 0};
    Vector2i Self = {0,0};
    
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; i <= 1; ++i)
        {
            CheckDirection = {j, i};
            if (CheckDirection != Self) // We don't want to check ourselves
            {
                bool bIsInteractable = std::is_base_of_v<Interact, PickUp>;
                if (!CanMove(CheckDirection) && bIsInteractable)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
