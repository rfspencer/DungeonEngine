// Copyright (c) 2024 Rich Spencer. All rights reserved.

#include "Widgets/HUD.h"

HUD::HUD()
    : m_HasInit(false)
{
}

void HUD::InitInternal()
{
    if (!m_HasInit)
    {
        m_HasInit = true;
        Init();
    }
}

void HUD::Init()
{
}

bool HUD::HandleEvent()
{
    return false;
}

void HUD::Tick(float DeltaTime)
{
}
