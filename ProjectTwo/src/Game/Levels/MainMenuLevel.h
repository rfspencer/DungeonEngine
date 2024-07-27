#pragma once

#include "World.h"

class MainMenuHUD;

class MainMenuLevel : public World
{
public:
    MainMenuLevel(Application* OwningApp);
    void BeginPlay() override;
    void Tick(float DeltaTime) override;

    void RemoveListenerForInput() const;
    
private:
    void HandleInput(int InKeyPressed);
    
    void StartGame();
    void QuitGame();

    WeakPtr<MainMenuHUD> m_MainMenuHUD;
    
    std::function<void(int)> m_InputEvent;
};
