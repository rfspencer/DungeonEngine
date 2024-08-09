/**
* @file PickUp.h
 * @brief Header for the PickUp class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include "Actor.h"
#include "Interface/Interact.h"

class Player;

enum PickUpType
{
    Health,
    MaxHealth,
    Gold
};

// using GiveFunction = std::function<void(WeakPtr<Player>)>;
typedef std::function<void(WeakPtr<Player>)> GiveFunction;

/**
 * @class PickUp
 * @brief Represents a pick-up object that can be interacted with by the player.
 *
 * The PickUp class is derived from both the Actor and Interact classes. It represents
 * a pick-up item in the game world that the player can interact with. The class provides
 * methods for setting and getting the interaction prompt, the pick-up amount, and for giving
 * gold, HP, and max HP to the player when interacted with.
 *
 * @note Class is incomplete. Currently on functionality is rendering Actor on Map
 */
class PickUp : public Actor, public Interact
{
public:
    PickUp(World* InOwningWorld, PickUpType InType);

    void OnInteract();

    std::string GetInteractionPrompt() { return m_InteractionPrompt; }
    void SetInteractionPrompt(const std::string& InString) { m_InteractionPrompt = InString; }

    int GetPickUpAmount() const { return m_PickUpAmount; }
    void SetPickUpAmount(const int InAmount) { m_PickUpAmount = InAmount; } // TODO: Should check if not negative before setting
    
    void GiveGold(WeakPtr<Player> InPlayer);
    void GiveHP(WeakPtr<Player> InPlayer);
    void GiveMaxHP(WeakPtr<Player> InPlayer);
private:

    GiveFunction m_GiveFunction;
    
    std::string m_InteractionPrompt;
    int m_PickUpAmount;
};
