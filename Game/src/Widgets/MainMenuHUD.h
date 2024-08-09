// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

#include "Widgets/HUD.h"
#include "Widgets/TextWidget.h"

/**
 * @class MainMenuHUD
 * @brief A class that represents the main menu heads-up display (HUD).
 *
 * This class is a subclass of `HUD` and provides functionality for rendering
 * the main menu HUD on the screen and handling events.
 */
class MainMenuHUD : public HUD
{
public:
    MainMenuHUD();

    /**
     * @brief Renders the main menu heads-up display (HUD) on the screen.
     *
     * This method is called to render the main menu HUD using the provided `Renderer` object.
     * It internally renders the main menu background, menu title text, new game text, and quit game text.
     *
     * @param InRendererRef The reference to the `Renderer` object that will be used to render the HUD.
     */
    void Render(Renderer& InRendererRef) override;

    /**
     * @brief Handles events for the MainMenuHUD.
     *
     * This method handles events for the MainMenuHUD class. It is responsible
     * for processing user input and triggering appropriate actions based on
     * the input events. The method returns a boolean value indicating whether
     * the event was handled or not.
     *
     * @return True if the event was handled, false otherwise.
     */
    bool HandleEvent() override;

private:
    void Init() override;

    // Widgets to be displayed in HUD
    TextWidget m_MainMenuBackground;
    TextWidget m_MenuTitleText;
    TextWidget m_NewGameText;
    TextWidget m_QuitGameText;

};
