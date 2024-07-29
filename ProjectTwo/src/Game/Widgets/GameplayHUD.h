#pragma once

#include "Widgets/HUD.h"
#include "Widgets/TextWidget.h"

struct Stats;

class GameplayHUD : public HUD
{
public:
    GameplayHUD();
    
    void Render(Renderer& InRendererRef) override;

    void BindDelegates();

private:
    void PlayerStatsChanged(const Stats InStats);
    void PlayerLevelChanged(const int InLevel);
    void PlayerGoldChanged(const int InGold);
    void PlayerXPChanged(const int InXP);
    void PlayerPositionChanged(const Vector2i InPosition);
    void PlayerMaxHPChanged(const int InMaxHP);
    void PlayerHPChanged(const int InHP);
    
    void Init() override;

    TextWidget m_GameplayHUDBackground;
    
    TextWidget m_PlayerStats_Str;
    TextWidget m_PlayerStats_Dex;
    TextWidget m_PlayerStats_Con;
    TextWidget m_PlayerStats_Int;
    TextWidget m_PlayerStats_Wis;
    TextWidget m_PlayerStats_Cha;
    
    TextWidget m_PlayerStats_Level;
    TextWidget m_PlayerStats_Gold;
    TextWidget m_PlayerStats_HP;
    TextWidget m_PlayerStats_MaxHP;
    TextWidget m_PlayerStats_XP;
    TextWidget m_PlayerStats_NextLevelXP;
    TextWidget m_PlayerStats_AC;
    TextWidget m_PlayerStats_PosX;
    TextWidget m_PlayerStats_PosY;
};
