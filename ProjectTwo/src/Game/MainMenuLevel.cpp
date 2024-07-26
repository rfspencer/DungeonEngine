#include "MainMenuLevel.h"

#include "Widgets/MainMenuHUD.h"

MainMenuLevel::MainMenuLevel(Application* OwningApp)
    : World(OwningApp)
{
    m_MainMenuHUD = SpawnHUD<MainMenuHUD>();
}

void MainMenuLevel::BeginPlay()
{
    
}

void MainMenuLevel::Tick(float DeltaTime)
{
    // Poll input for menu selection
}

void MainMenuLevel::StartGame()
{
}

void MainMenuLevel::QuitGame()
{
}
