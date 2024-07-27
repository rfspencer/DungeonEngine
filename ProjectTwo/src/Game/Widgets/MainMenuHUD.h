#pragma once

#include "Widgets/HUD.h"
#include "Widgets/TextWidget.h"

class MainMenuHUD : public HUD
{
public:
    MainMenuHUD();

    void Render(Renderer& InRendererRef) override;
    bool HandleEvent() override;

private:
    void Init() override;

    TextWidget m_MainMenuBackground;
    TextWidget m_MenuTitleText;
    TextWidget m_NewGameText;
    TextWidget m_QuitGameText;

};
