/**
* @file Interact.h
 * @brief Header for the Interact interface class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

/**
 * @class Interact
 *
 * @brief Abstract base class for objects that can be interacted with.
 *
 * The Interact class provides a way to define objects that can be interacted with.
 * Derived classes need to implement the OnInteract() method that handles the interaction.
 */
class Interact
{
public:
    Interact() {}
    virtual ~Interact() {}
    
    virtual void OnInteract() = 0;
};
