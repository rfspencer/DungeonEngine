#include "MainMenuLevel.h"

#include "Application.h"
#include "Input.h"
#include "Player.h"
#include "Widgets/MainMenuHUD.h"

MainMenuLevel::MainMenuLevel(Application* OwningApp)
    : World(OwningApp)
{
    m_MainMenuHUD = SpawnHUD<MainMenuHUD>();
}

void MainMenuLevel::BeginPlay()
{
    // UniquePtr<Player> NewPlayer = std::make_unique<Player>();
    m_InputEvent = std::bind(&MainMenuLevel::HandleInput, this, std::placeholders::_1);
    Input::AddListener(m_InputEvent);
}

void MainMenuLevel::Tick(float DeltaTime)
{
}

void MainMenuLevel::HandleInput(int InKeyPressed)
{
    if (tolower(InKeyPressed) == 'q')
    {
        QuitGame();
    }
    if (tolower(InKeyPressed) == 'n')
    {
        StartGame();
    }
}

void MainMenuLevel::RemoveListenerForInput() const
{
    Input::RemoveListener(m_InputEvent);
}

void MainMenuLevel::StartGame() const
{
    RemoveListenerForInput();
    GetApplication()
}

void MainMenuLevel::QuitGame()
{
    GetApplication()->QuitApplication();
}
