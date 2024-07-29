#pragma once

#include "Actor.h"
#include "Game/Interface/Interact.h"

class Player;

enum PickUpType
{
    Health,
    MaxHealth,
    Gold
};

// using GiveFunction = std::function<void(WeakPtr<Player>)>;
typedef std::function<void(WeakPtr<Player>)> GiveFunction;

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
