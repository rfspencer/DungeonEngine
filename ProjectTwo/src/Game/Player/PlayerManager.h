#pragma once

#include "Player.h"

class PlayerManager
{
public:
    std::weak_ptr<Player> CreateNewPlayer(World* InOwningWorld);

    std::weak_ptr<Player> GetPlayer();
    std::weak_ptr<Player> GetPlayer() const;

    static PlayerManager& Get();

    void ResetPlayer();

protected:
    PlayerManager() = default;

private:
    // Making this a List to later extend to multiple players 
    List<SharedPtr<Player>> m_Players;

    static UniquePtr<PlayerManager> m_PlayerManager;
};
