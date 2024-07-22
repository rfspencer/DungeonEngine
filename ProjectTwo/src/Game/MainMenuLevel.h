#pragma once

#include "World.h"

class MainMenuLevel : public World
{
public:
    MainMenuLevel(Application* OwningApp);
    void BeginPlay() override;
    void Tick(float DeltaTime) override;

private:
    void StartGame();
    void QuitGame();
    
};
