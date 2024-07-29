#pragma once

#include "Player.h"

class PlayerManager
{
public:
    WeakPtr<Player> CreateNewPlayer(World* InOwningWorld);

    WeakPtr<Player> GetPlayer();
    WeakPtr<Player> GetPlayer() const;

    static PlayerManager& Get();

    void ResetPlayer();

protected:
    PlayerManager() = default;

private:
    // Making this a List to later extend to multiple players 
    List<SharedPtr<Player>> m_Players;

    static UniquePtr<PlayerManager> m_PlayerManager;
};
