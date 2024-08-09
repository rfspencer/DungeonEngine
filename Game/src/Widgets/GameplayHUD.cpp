/**
* @file GameplayHUD.cpp
 * @brief Implementation for the GameplayHUD class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#include "GameplayHUD.h"

#include "World.h"
#include "Player/PlayerManager.h"
#include "Utilities/FileHandler.h"

const char* DATA_GAMEPLAY_LAYOUT_PATH = "res/UI/GameplayHUD.layout";

GameplayHUD::GameplayHUD()
    : m_PlayerStats_Str(""), m_PlayerStats_Dex(""), m_PlayerStats_Con(""),
      m_PlayerStats_Int(""), m_PlayerStats_Wis(""), m_PlayerStats_Cha(""),
      m_PlayerStats_Level(""), m_PlayerStats_Gold(""), m_PlayerStats_HP(""),
      m_PlayerStats_MaxHP(""), m_PlayerStats_XP(""), m_PlayerStats_NextLevelXP(""),
      m_PlayerStats_AC(""), m_PlayerStats_PosX(""), m_PlayerStats_PosY("")
{
    Init();
}

void GameplayHUD::Init()
{
    // TODO: Ideally this should be handled in an Asset Manager class and cached
    if (FileHandler::DoesFileExist(DATA_GAMEPLAY_LAYOUT_PATH))
    {
        std::string TempString = FileHandler::ReadFile(DATA_GAMEPLAY_LAYOUT_PATH);
        m_GameplayHUDBackground = FileHandler::StringToTextWidget(TempString);
    }
    m_GameplayHUDBackground.SetWidgetPosition(0, 0);
    
    m_PlayerStats_Level.SetWidgetPosition(7, 28);
    m_PlayerStats_Level.SetOverrideColor(3);
    
    m_PlayerStats_Gold.SetWidgetPosition(17, 28);
    m_PlayerStats_Gold.SetOverrideColor(6);
    
    m_PlayerStats_HP.SetWidgetPosition(25, 28);
    m_PlayerStats_HP.SetOverrideColor(4);
    
    m_PlayerStats_MaxHP.SetWidgetPosition(30, 28);
    m_PlayerStats_MaxHP.SetOverrideColor(4);
    
    m_PlayerStats_AC.SetWidgetPosition(39, 28);
    m_PlayerStats_AC.SetOverrideColor(3);
    
    m_PlayerStats_XP.SetWidgetPosition(50, 28);
    m_PlayerStats_XP.SetOverrideColor(2);
    
    m_PlayerStats_NextLevelXP.SetWidgetPosition(54, 28);
    m_PlayerStats_NextLevelXP.SetOverrideColor(2);
    
    m_PlayerStats_PosX.SetWidgetPosition(77, 28);
    m_PlayerStats_PosX.SetOverrideColor(2);
    
    m_PlayerStats_PosY.SetWidgetPosition(82, 28);
    m_PlayerStats_PosY.SetOverrideColor(2);
    
    m_PlayerStats_Str.SetWidgetPosition(40, 29);
    m_PlayerStats_Str.SetOverrideColor(3);
    
    m_PlayerStats_Dex.SetWidgetPosition(48, 29);
    m_PlayerStats_Dex.SetOverrideColor(3);
    
    m_PlayerStats_Con.SetWidgetPosition(56, 29);
    m_PlayerStats_Con.SetOverrideColor(3);
    
    m_PlayerStats_Int.SetWidgetPosition(64, 29);
    m_PlayerStats_Int.SetOverrideColor(3);
    
    m_PlayerStats_Wis.SetWidgetPosition(72, 29);
    m_PlayerStats_Wis.SetOverrideColor(3);
    
    m_PlayerStats_Cha.SetWidgetPosition(80, 29);
    m_PlayerStats_Cha.SetOverrideColor(3);
}

void GameplayHUD::Render(Renderer& InRendererRef)
{
    m_GameplayHUDBackground.RenderInternal(InRendererRef, true);
    
    m_PlayerStats_Level.RenderInternal(InRendererRef);
    m_PlayerStats_Gold.RenderInternal(InRendererRef);
    m_PlayerStats_MaxHP.RenderInternal(InRendererRef);
    m_PlayerStats_HP.RenderInternal(InRendererRef);
    m_PlayerStats_AC.RenderInternal(InRendererRef);
    m_PlayerStats_XP.RenderInternal(InRendererRef);
    m_PlayerStats_NextLevelXP.RenderInternal(InRendererRef);
    m_PlayerStats_PosX.RenderInternal(InRendererRef);
    m_PlayerStats_PosY.RenderInternal(InRendererRef);
    
    m_PlayerStats_Str.RenderInternal(InRendererRef);
    m_PlayerStats_Dex.RenderInternal(InRendererRef);
    m_PlayerStats_Con.RenderInternal(InRendererRef);
    m_PlayerStats_Int.RenderInternal(InRendererRef);
    m_PlayerStats_Wis.RenderInternal(InRendererRef);
    m_PlayerStats_Cha.RenderInternal(InRendererRef);
}

void GameplayHUD::BindDelegates()
{
    WeakPtr<Player> Player = PlayerManager::Get().GetPlayer();
    if (!Player.expired())
    {
        Player.lock()->OnPlayerStatsChanged.BindAction(GetWeakRef(), &GameplayHUD::PlayerStatsChanged);
        Player.lock()->OnLevelChanged.BindAction(GetWeakRef(), &GameplayHUD::PlayerLevelChanged);
        Player.lock()->OnGoldChanged.BindAction(GetWeakRef(), &GameplayHUD::PlayerGoldChanged);
        Player.lock()->OnXPChanged.BindAction(GetWeakRef(), &GameplayHUD::PlayerXPChanged);
        Player.lock()->OnPositionChanged.BindAction(GetWeakRef(), &GameplayHUD::PlayerPositionChanged);
        Player.lock()->OnMaxHealthChanged.BindAction(GetWeakRef(), &GameplayHUD::PlayerMaxHPChanged);
        Player.lock()->OnHealthChanged.BindAction(GetWeakRef(), &GameplayHUD::PlayerHPChanged);
    }
}

void GameplayHUD::PlayerStatsChanged(const Stats InStats)
{
    m_PlayerStats_AC.SetText(std::to_string(InStats.AC));
    m_PlayerStats_AC.SetDoesNeedUpdate(true);
    
    m_PlayerStats_Str.SetText(std::to_string(InStats.Str));
    m_PlayerStats_Str.SetDoesNeedUpdate(true);
    
    m_PlayerStats_Dex.SetText(std::to_string(InStats.Dex));
    m_PlayerStats_Dex.SetDoesNeedUpdate(true);
    
    m_PlayerStats_Con.SetText(std::to_string(InStats.Con));
    m_PlayerStats_Con.SetDoesNeedUpdate(true);
    
    m_PlayerStats_Int.SetText(std::to_string(InStats.Int));
    m_PlayerStats_Int.SetDoesNeedUpdate(true);
    
    m_PlayerStats_Wis.SetText(std::to_string(InStats.Wis));
    m_PlayerStats_Wis.SetDoesNeedUpdate(true);
    
    m_PlayerStats_Cha.SetText(std::to_string(InStats.Cha));
    m_PlayerStats_Cha.SetDoesNeedUpdate(true);
}

void GameplayHUD::PlayerLevelChanged(const int InLevel)
{
    m_PlayerStats_Level.SetText(std::to_string(InLevel));
    m_PlayerStats_Level.SetDoesNeedUpdate(true);
}

void GameplayHUD::PlayerGoldChanged(const int InGold)
{
    m_PlayerStats_Gold.SetText(std::to_string(InGold));
    m_PlayerStats_Gold.SetDoesNeedUpdate(true);
}

void GameplayHUD::PlayerXPChanged(const int InXP)
{
    m_PlayerStats_XP.SetText(std::to_string(InXP));
    m_PlayerStats_XP.SetDoesNeedUpdate(true);

    WeakPtr<Player> Player = PlayerManager::Get().GetPlayer();
    if (!Player.expired())
    {
        if (InXP < Player.lock()->GetLevelUpXP().Level_2)
        {
            m_PlayerStats_NextLevelXP.SetText(std::to_string(Player.lock()->GetLevelUpXP().Level_2));
        }
        else if (InXP >= Player.lock()->GetLevelUpXP().Level_2)
        {
            m_PlayerStats_NextLevelXP.SetText(std::to_string(Player.lock()->GetLevelUpXP().Level_3));
        }
        else if (InXP >= InXP >= Player.lock()->GetLevelUpXP().Level_3)
        {
            m_PlayerStats_NextLevelXP.SetText(std::to_string(Player.lock()->GetLevelUpXP().Level_4));            
        }
        else if (InXP >= Player.lock()->GetLevelUpXP().Level_4)
        {
            m_PlayerStats_NextLevelXP.SetText(std::to_string(Player.lock()->GetLevelUpXP().Level_5));            
        }
        m_PlayerStats_NextLevelXP.SetDoesNeedUpdate(true);
    }
}

void GameplayHUD::PlayerPositionChanged(const Vector2i InPosition)
{
    m_PlayerStats_PosX.SetText(std::to_string(InPosition.X));
    m_PlayerStats_PosX.SetDoesNeedUpdate(true);
    
    m_PlayerStats_PosY.SetText(std::to_string(InPosition.Y));
    m_PlayerStats_PosY.SetDoesNeedUpdate(true);
}

void GameplayHUD::PlayerMaxHPChanged(const int InMaxHP)
{
    m_PlayerStats_MaxHP.SetText(std::to_string(InMaxHP));
    m_PlayerStats_MaxHP.SetDoesNeedUpdate(true);
}

void GameplayHUD::PlayerHPChanged(const int InHP)
{
    m_PlayerStats_HP.SetText(std::to_string(InHP));
    m_PlayerStats_HP.SetDoesNeedUpdate(true);
}
