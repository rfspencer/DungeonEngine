#include "PickUp.h"

#include "World.h"
#include "Player/Player.h"

PickUp::PickUp(World* InOwningWorld, PickUpType InType)
    : Actor(InOwningWorld)
{
    switch (InType)
    {
    case Gold:
        {
            // m_GiveFunction = std::bind(&PickUp::GiveGold, this, std::placeholders::_1);
            SetSprite("$");
            SetOverrideColor(6);
            m_InteractionPrompt = "You found some Gold!";
            break;    
        }
        
    }
}

void PickUp::OnInteract()
{
    m_GiveFunction(GetWorld()->GetPlayer());
}

void PickUp::GiveGold(WeakPtr<Player> InPlayer)
{
    InPlayer.lock()->AddToGold();
}

void PickUp::GiveHP(WeakPtr<Player> InPlayer)
{
}

void PickUp::GiveMaxHP(WeakPtr<Player> InPlayer)
{
}
