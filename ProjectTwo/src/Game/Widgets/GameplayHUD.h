#pragma once

#include "Widgets/HUD.h"
#include "Widgets/TextWidget.h"

class GameplayHUD : public HUD
{
public:
    GameplayHUD();
    
    void Render(Renderer& InRendererRef) override;

private:
    void Init() override;

    TextWidget m_GameplayHUDBackground;
};
