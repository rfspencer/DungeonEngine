/**
* @file Input.h
 * @brief Header for the Input class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include <functional>
#include <vector>

#include "Types.h"

/** @class Input
 *  @brief The Input class provides an interface for handling user input.
 *
 *  The Input class provides static functions to update and retrieve user input,
 *  as well as a mechanism to notify listeners when input events occur.
 *
 *  @note This will eventually be folded into the Application event system
 */
class Input
{
public:
    Input() = default;

    /**
     * @brief Update the input state.
     *
     * This function updates the input state by checking if any key is pressed.
     * If a key is pressed, it stores the key code in `m_KeyDown` and notifies
     * all the listeners by calling their callback functions.
     * If no key is pressed, it assigns 0 to `m_KeyDown`.
     */
    static void Update();

    /**
     * @brief Retrieve the key code of the most recent key press event.
     *
     * This function retrieves the key code of the most recent key press event.
     * If no key is currently being pressed, it will return 0.
     *
     * @return The key code of the most recent key press event. 0 if no key is being pressed.
     */
    static int GetKeyDown();
    /**
     * @brief Adds a listener function to handle input events.
     *
     * This function adds a listener function to the list of input listeners. The listener function
     * will be called whenever an input event occurs. The listener function must take an integer input parameter.
     *
     * @param Callback The listener function to be added.
     */
    static void AddListener(std::function<void(int Input)> Callback);
    /**
     * @brief Remove a listener from the input event.
     *
     * This method removes a listener from the input event by comparing the target type of the listener with the callback passed as an argument.
     *
     * @param Callback The callback function to remove from the input event.
     *
     * @return void
     */
    static void RemoveListener(std::function<void(int Input)> Callback);
    /**
     * @brief Clean up the input listeners.
     *
     * This function removes all the registered input listeners, clearing the list
     * of callbacks for input events. After calling this function, there will be no
     * listeners to notify when an input event occurs.
     */
    static void CleanUp() { m_InputListeners.clear(); }

private:
    // The currently pressed key. 0 if no keys are pressed.
    static int m_KeyDown;
    // List of Listeners the requested Callbacks
    static List<std::function<void(int)>> m_InputListeners;
};
