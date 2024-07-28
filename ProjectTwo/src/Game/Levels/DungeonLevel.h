#pragma once

#include "World.h"

class Player;
class GameplayHUD;

class DungeonLevel : public World
{
public:
    DungeonLevel(Application* InOwningApp);
    void BeginPlay() override;
    void Tick(float DeltaTime) override;

    void RemoveListenerForInput() const;
    
private:
    void HandleInput(int InKeyPressed);
    
    void QuitGame();

    WeakPtr<Player> m_Player;    
    WeakPtr<GameplayHUD> m_GameplayHUD;
    
    std::function<void(int)> m_InputEvent;
};
