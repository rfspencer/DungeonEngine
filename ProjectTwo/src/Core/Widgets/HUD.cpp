/**
* @file HUD.cpp
 * @brief Implementation for the HUD class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

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
