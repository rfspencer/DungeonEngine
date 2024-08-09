// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

#include "Object.h"

class Renderer;

/**
 * @class HUD
 * @brief The abstract base class for Heads-Up Display (HUD).
 *
 * This class represents the HUD in the game. It provides a way to render
 * the HUD on the screen, handle events, and update the HUD each frame.
 *
 * The HUD class inherits from Object.
 */
class HUD : public Object
{
public:
    /**
     * @brief This method is a pure virtual method that needs to be implemented by subclasses.
     *        It renders the HUD on the screen using the provided `Renderer` object.
     *
     * @param InRendererRef The reference to the `Renderer` object that will be used to render the HUD.
     *
     * @see World::RenderHUD(Renderer& InRendererRef)
     */
    virtual void Render(Renderer& InRendererRef) = 0;

    /**
     * @fn void HUD::InitInternal()
     * @brief Initializes the HUD.
     *
     * This method is called to initialize the HUD. It checks if the
     * HUD has already been initialized and if not, it sets the m_HasInit flag
     * to true and calls the Init() method.
     *
     * @see HUD::Init()
     * @see HUD::HasInit()
     */
    void InitInternal();

    /**
     * @brief Checks if the HUD has been initialized.
     *
     * This method returns a boolean value indicating whether the HUD has been initialized or not.
     *
     * @return True if the HUD has been initialized, false otherwise.
     *
     * @see HUD::InitInternal()
     * @see HUD::Init()
     */
    bool HasInit() const { return m_HasInit; }

    virtual bool HandleEvent();

    /**
     * @brief Updates the HUD each frame.
     *
     * This method is called each frame to update the HUD. Subclasses can override
     * this method to implement custom HUD update logic.
     *
     * @param DeltaTime The time elapsed since the last frame, in seconds.
     *
     * @see HUD::Render(Renderer& InRendererRef)
     */
    virtual void Tick(float DeltaTime);

protected:
    HUD();

private:
    virtual void Init();

    bool m_HasInit;
};
