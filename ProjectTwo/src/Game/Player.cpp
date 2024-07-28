#include "Player.h"

#include <iostream>

#include "Input.h"

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

void Player::Update(float DeltaTime)
{
}

void Player::RemoveListenerForInput()
{
    Input::RemoveListener(m_InputEvent);
}

bool Player::CanMove()
{
    return true;
}

void Player::Move(const Vector2i InOffset)
{
    if (CanMove())
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
