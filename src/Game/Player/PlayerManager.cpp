#include "PlayerManager.h"

#include "World.h"

UniquePtr<PlayerManager> PlayerManager::m_PlayerManager{nullptr};

WeakPtr<Player> PlayerManager::CreateNewPlayer(World* InOwningWorld)
{
    SharedPtr<Player> NewPlayer = std::make_shared<Player>(InOwningWorld);    
    m_Players.emplace(m_Players.begin(), NewPlayer);
    // TODO: See comments in World, line 34. Will need to fix this
    InOwningWorld->m_PendingActors.push_back(NewPlayer);
    return std::weak_ptr<Player>(m_Players.back());
}

WeakPtr<Player> PlayerManager::GetPlayer()
{
    return m_Players[0];
}

WeakPtr<Player> PlayerManager::GetPlayer() const
{
    return m_Players[0];
}

PlayerManager& PlayerManager::Get()
{
    if (!m_PlayerManager)
    {
        m_PlayerManager = std::move(UniquePtr<PlayerManager>(new PlayerManager()));
    }
    return *m_PlayerManager;
}

void PlayerManager::ResetPlayer()
{
    m_Players.clear();
}

