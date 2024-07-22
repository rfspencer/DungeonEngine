#include "MainMenuLevel.h"
#include <iostream>

MainMenuLevel::MainMenuLevel(Application* OwningApp)
    : World(OwningApp)
{
}

void MainMenuLevel::BeginPlay()
{
    std::cout << "Dungeon Crawler" << std::endl << std:: endl;
    std::cout << "Main Menu" << std::endl;
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
