/**
* @file GameplayHUD.h
 * @brief Header for the GameplayHUD class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include "Widgets/HUD.h"
#include "Widgets/TextWidget.h"

struct Stats;

/**
 * @class GameplayHUD
 * @brief The GameplayHUD class is a subclass of the HUD class that represents the in-game heads-up display.
 *
 * The GameplayHUD class provides methods and properties for rendering and updating the HUD on the screen.
 */
class GameplayHUD : public HUD
{
public:
    GameplayHUD();

    /**
     * @brief Renders the GameplayHUD on the screen.
     *
     * This method is called to render the GameplayHUD on the screen using the provided Renderer object.
     *
     * @param InRendererRef The reference to the Renderer object that will be used to render the GameplayHUD.
     */
    void Render(Renderer& InRendererRef) override;

    /**
     * Binds delegates for player events.
     */
    void BindDelegates();

private:
    // Delegate Function Callbacks
    void PlayerStatsChanged(const Stats InStats);
    void PlayerLevelChanged(const int InLevel);
    void PlayerGoldChanged(const int InGold);
    void PlayerXPChanged(const int InXP);
    void PlayerPositionChanged(const Vector2i InPosition);
    void PlayerMaxHPChanged(const int InMaxHP);
    void PlayerHPChanged(const int InHP);
    
    void Init() override;

    // TextWidgets displayed in the HUD
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
