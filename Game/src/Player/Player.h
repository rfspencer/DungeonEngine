/**
* @file Player.h
 * @brief Header for the Player class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include "Actor.h"

#include <functional>

/**
 * @struct PlayerSettings
 *
 * @brief Contains settings for a player.
 *
 * The PlayerSettings struct defines the settings for a player in the game. It includes the input key mapping,
 * the sprite character, the movement speed, and the color.
 *
 * @var PlayerSettings::InputKey Up
 * @brief The input key for moving up.
 *
 * @var PlayerSettings::InputKey Down
 * @brief The input key for moving down.
 *
 * @var PlayerSettings::InputKey Left
 * @brief The input key for moving left.
 *
 * @var PlayerSettings::InputKey Right
 * @brief The input key for moving right.
 *
 * @var PlayerSettings::InputKey Interact
 * @brief The input key for interacting with objects.
 *
 * @var PlayerSettings::InputKey Endgame
 * @brief The input key for ending the game.
 *
 * @var PlayerSettings::Sprite
 * @brief The character representing the player's sprite.
 *
 * @var PlayerSettings::MovementSpeed
 * @brief The movement speed of the player.
 *
 * @var PlayerSettings::Color
 * @brief The color of the player's sprite.
 */
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

/**
 * @struct Stats
 *
 * @brief Represents the statistics of a character.
 *
 * The Stats struct defines the statistics of a character in the game. It includes attributes such as strength (Str),
 * dexterity (Dex), constitution (Con), intelligence (Int), wisdom (Wis), charisma (Cha), armor class (AC), and maximum
 * hit points (MaxHP).
 *
 * @var Stats::Str
 * @brief The strength attribute of the character.
 *
 * @var Stats::Dex
 * @brief The dexterity attribute of the character.
 *
 * @var Stats::Con
 * @brief The constitution attribute of the character.
 *
 * @var Stats::Int
 * @brief The intelligence attribute of the character.
 *
 * @var Stats::Wis
 * @brief The wisdom attribute of the character.
 *
 * @var Stats::Cha
 * @brief The charisma attribute of the character.
 *
 * @var Stats::AC
 * @brief The armor class of the character, calculated based on the dexterity attribute (+2).
 *
 * @var Stats::MaxHP
 * @brief The maximum hit points of the character, calculated as the average of the strength and constitution attributes.
 */
struct Stats
{
    int Str = 18;
    int Dex = 14;
    int Con = 12;
    int Int = 10;
    int Wis = 12;
    int Cha = 8;
    
    int AC = Dex + 2;
    int MaxHP = (Con + Str) / 2;
};

/**
 * @struct LevelUpXP
 *
 * @brief Contains the XP thresholds for leveling up.
 *
 * The LevelUpXP struct defines the XP thresholds required to level up. It includes the XP thresholds for each level,
 * starting from level 2 onwards.
 *
 * @var LevelUpXP::Level_2
 * @brief The XP threshold for reaching level 2.
 *
 * @var LevelUpXP::Level_3
 * @brief The XP threshold for reaching level 3.
 *
 * @var LevelUpXP::Level_4
 * @brief The XP threshold for reaching level 4.
 *
 * @var LevelUpXP::Level_5
 * @brief The XP threshold for reaching level 5.
 */
struct LevelUpXP
{
    int Level_2 = 100;
    int Level_3 = 300;
    int Level_4 = 800;
    int Level_5 = 1500;
};

/**
 * @class Player
 *
 * @brief Represents a player in the game.
 *
 * The Player class inherits from the Actor class and represents a player in the game world. Players
 * have various attributes such as health, level, experience points (XP), gold, and stats. They can
 * also move around the game world and interact with other objects.
 */
class Player : public Actor
{
public:
    Player(World* InOwningWorld);

    /**
     * @brief Initializes the Player object.
     *
     * This method is responsible for initializing the Player object. It sets the sprite,
     * adds an input event listener, and initializes various attributes such as move speed,
     * level, XP, gold, and health. This method is called during the construction of the Player object.
     */
    void Init();

    /**
     * @brief This function is called when the player begins playing the game.
     *
     * It broadcasts events to notify listeners of changes in player stats, level, experience points (XP),
     * gold, position, max health, and current health. This function is called at the start of the game to
     * initialize the player and set up any necessary initial values.
     */
    void BeginPlay() override;

    /**
     * @brief Updates the player's state every frame.
     *
     * The Tick method updates the player's state every frame based on the provided delta time. It calls
     * the base class's Tick method to ensure that any base functionality is executed as well. In addition
     * to the base Tick method, the Tick method also calls CheckForInteractables to check if the player
     * can interact with any objects in the game world.
     *
     * @param DeltaTime The time elapsed since the last frame.
     */
    void Tick(float DeltaTime) override;

    /**
     * @brief Remove a listener from the input event.
     *
     * This method removes a listener from the input event by comparing the target type of
     * the listener with the callback passed as an argument.
     *
     * @param Callback The callback function to remove from the input event.
     */
    void RemoveListenerForInput();

    /**
     * @brief Sets the move speed of the player.
     *
     * This method sets the move speed of the player to the specified value. The move speed determines
     * how fast the player can move around the game world.
     *
     * @param InSpeed The new move speed for the player.
     */
    void SetMoveSpeed(int InSpeed) { m_MoveSpeed = InSpeed; }

    /**
     * @brief Determines whether the player can move in a given direction.
     *
     * This method checks if the player can move in a specified direction by checking if the destination tile is empty.
     *
     * @param InOffset The offset representing the direction in which the player wants to move.
     *
     * @return True if the player can move in the specified direction, false otherwise.
     */
    bool CanMove(const Vector2i InOffset);

    /**
     * @brief Moves the player by the given offset vector.
     *
     * This method is responsible for moving the player by the given offset vector. It first checks if the
     * player can move in the desired direction by calling the CanMove method. If the player can move, it
     * updates the player's current location by adding the offset vector to the current location. Finally,
     * it broadcasts an OnPositionChanged event to notify other objects of the player's new location.
     *
     * @param InOffset The offset vector specifying the direction and distance to move the player.
     */
    void Move(const Vector2i InOffset);

    /**
     * @brief Retrieves the LevelUpXP object.
     *
     * This method returns a reference to the LevelUpXP object associated with the player. The LevelUpXP object
     * contains the XP thresholds required to level up the player. It is used to determine the next level of the player
     * based on their current XP.
     *
     * @return A reference to the LevelUpXP object.
     */
    LevelUpXP& GetLevelUpXP() { return m_LevelUpXp; }

    /**
     * @brief Returns the amount of gold the player currently has.
     *
     * This method returns the current amount of gold that the player has.
     *
     * @return The amount of gold the player has.
     */
    unsigned int GetGold() const { return m_Gold; }

    /**
     * @brief Adds a specified amount to the player's gold.
     *
     * This method increases the player's gold by the specified amount. By default, it adds 1 unit of gold
     * to the player's current gold amount.
     *
     * @param InAmountToAdd The amount of gold to be added to the player's current gold amount. Defaults to 1.
     *
     * @note The gold amount cannot be negative.
     */
    void AddToGold(unsigned int InAmountToAdd = 1) { m_Gold += InAmountToAdd; }

    // Player Delegates
    Delegate<Stats> OnPlayerStatsChanged;
    Delegate<int> OnLevelChanged;
    Delegate<int> OnXPChanged;
    Delegate<int> OnGoldChanged;
    Delegate<Vector2i> OnPositionChanged;
    Delegate<int> OnHealthChanged;
    Delegate<int> OnMaxHealthChanged;

private:
    void HandleInput(int InKeyPressed);

    /**
     * @brief Checks for interactable objects surrounding the player.
     *
     * This method checks the squares surrounding the player to see if there are any interactable objects.
     * It iterates over the adjacent squares using nested loops and checks each square for interactability.
     * If an interactable object is found, the method immediately returns true. Otherwise, it returns false
     * indicating that no interactable objects were found.
     *
     * @return True if there is an interactable object nearby, false otherwise.
     */
    bool CheckForInteractables();

    PlayerSettings m_PlayerSettings;
    unsigned int m_MoveSpeed;
    unsigned int m_Level;
    unsigned int m_XP;
    unsigned int m_Gold;
    unsigned int m_Health;

    Stats m_PlayerStats;
    LevelUpXP m_LevelUpXp;
    std::function<void(int)> m_InputEvent;
};
