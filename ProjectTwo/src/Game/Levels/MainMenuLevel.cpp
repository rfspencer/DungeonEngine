﻿#include "MainMenuLevel.h"

#include "Core/Application.h"
#include "Core/Input.h"
#include "Game/Levels/DungeonLevel.h"
#include "Game/Widgets/MainMenuHUD.h"

MainMenuLevel::MainMenuLevel(Application* OwningApp)
    : World(OwningApp)
{
    m_MainMenuHUD = SpawnHUD<MainMenuHUD>();
}

void MainMenuLevel::BeginPlay()
{
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

void MainMenuLevel::StartGame()
{
    GetApplication()->GetRendererRef().ClearConsoleScreen();
    RemoveListenerForInput();
    GetApplication()->LoadWorld<DungeonLevel>();
}

void MainMenuLevel::QuitGame()
{
    GetApplication()->QuitApplication();
}
