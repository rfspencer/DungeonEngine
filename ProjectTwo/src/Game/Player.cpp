#include "Player.h"

#include <iostream>

#include "Input.h"
#include "Map.h"
#include "Levels/DungeonLevel.h"

Player::Player(World* InOwningWorld)
    : Actor(InOwningWorld), m_MoveSpeed(1)
{
    Init();
    SetOverrideColor(m_PlayerSettings.Color);
}

void Player::Init()
{
    SetSprite(m_PlayerSettings.Sprite);
    
    m_InputEvent = std::bind(&Player::HandleInput, this, std::placeholders::_1);
    Input::AddListener(m_InputEvent);
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
