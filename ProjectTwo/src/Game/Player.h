#pragma once

#include "Actor.h"

#include <functional>

struct PlayerSettings
{
    enum InputKey
    {
        Up = 'w',
        Down = 's',
        Left = 'a',
        Right = 'd',
        Interact = 'e',
        Endgame = 0
    };

    std::string Sprite = "@";
    unsigned int MovementSpeed = 1;
    int Color = 2;
};

class Player : public Actor
{
public:
    Player(World* InOwningWorld);
    void Init();
    void RemoveListenerForInput();
    void SetMoveSpeed(int InSpeed) { m_MoveSpeed = InSpeed; }

    bool CanMove();
    void Move(const Vector2i InOffset);

private:
    void HandleInput(int InKeyPressed);

    PlayerSettings m_PlayerSettings;
    unsigned int m_MoveSpeed;

    std::function<void(int)> m_InputEvent;
};
