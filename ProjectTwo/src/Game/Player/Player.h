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

struct Stats
{
    int Str = 18;
    int Dex = 14;
    int Con = 12;
    int Int = 10;
    int Wis = 12;
    int Cha = 8;
};

struct LevelUpXP
{
    int Level_2 = 100;
    int Level_3 = 300;
    int Level_4 = 800;
    int Level_5 = 1500;
};

class Player : public Actor
{
public:
    Player(World* InOwningWorld);
    void Init();
    void BeginPlay() override;
    
    void RemoveListenerForInput();
    void SetMoveSpeed(int InSpeed) { m_MoveSpeed = InSpeed; }

    bool CanMove(const Vector2i InOffset);
    void Move(const Vector2i InOffset);

    Delegate<Stats> OnPlayerStatsChanged;
    Delegate<int> OnLevelChanged;
    Delegate<int> OnXPChanged;
    Delegate<int> OnGoldChanged;

private:
    void HandleInput(int InKeyPressed);

    PlayerSettings m_PlayerSettings;
    unsigned int m_MoveSpeed;
    unsigned int m_Level;
    unsigned int m_XP;
    unsigned int m_Gold;

    Stats m_PlayerStats;
    std::function<void(int)> m_InputEvent;
};
