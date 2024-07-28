#pragma once

#include "World.h"

class Player;
class GameplayHUD;
class Map;

class DungeonLevel : public World
{
public:
    DungeonLevel(Application* InOwningApp);
    void BeginPlay() override;
    void Tick(float DeltaTime) override;

    WeakPtr<Map> GetMap() const { return m_Map; }

    void QuitGame();
    
private:    

    WeakPtr<Player> m_Player;    
    WeakPtr<GameplayHUD> m_GameplayHUD;
    WeakPtr<Map> m_Map;
    
    std::function<void(int)> m_InputEvent;
};
