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

    void RemoveListenerForInput() const;

    WeakPtr<Map> GetMap() const { return m_Map; }
    WeakPtr<Player> GetPlayer() override { return m_Player; }

    void QuitGame();
    
private:
    void HandleInput(int InKeyPressed);
    
    WeakPtr<Player> m_Player;    
    WeakPtr<GameplayHUD> m_GameplayHUD;
    WeakPtr<Map> m_Map;
    
    std::function<void(int)> m_InputEvent;
};
