/**
* @file Renderer.h
 * @brief Header for the Renderer class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include <array>
#include <string>

#include "Windows.h"
#include "Core/World.h"
#include "Game/Utilities/Constants.h" // TODO: not great to include game stuff here. Find a way to keep this in Game
#include "Utilities/Vector2i.h"

class Map;
class Widget;

class Renderer
{
public:
    Renderer();

    /**
     * Initializes the renderer with the specified title.
     *
     * @param InTitle The title to set for the renderer.
     */
    void Init(std::wstring InTitle);

    /**
     * Clears the console screen by filling the entire buffer with spaces and resetting the cursor position.
     *
     * @return void
     */
    void ClearConsoleScreen();

    /**
     * @brief Adds an Actor to the Render buffer at its designated location.
     *
     * This method is called by an Actor to add itself to the Render buffer
     * at its current location. It also erases the sprite from the previous
     * position if the Actor has moved during the frame.
     *
     * @param InActor The Actor to be drawn.
     */
    void DrawActor(Actor& InActor);
    /**
     * @brief Draws an actor on the screen using the provided map.
     *
     * This method is called to draw an actor on the screen. It takes a pointer to a Map object as a paramter,
     * which contains the actor's location, size, sprite, and override color. The method loops through the sprite string,
     * ignoring spaces, and adds each non-space character as a CHAR_INFO element to the render buffer using the AddElementToRenderBuffer method.
     * The CHAR_INFO element's UnicodeChar is set to the sprite character, and its Attributes is set to the override color.
     * The position of each element in the render buffer is determined by the index of the character in the sprite string.
     *
     * @param InMap A pointer to the Map object containing the actor's location, size, sprite, and override color.
     *
     * @note This method assumes that InMap is not null and contains valid data.
     */
    void DrawActor(Map* InMap);

    /**
     * @brief Draws a UI widget on the screen.
     *
     * This method is used to draw a UI widget on the screen. It takes in a reference to the Widget object
     * to be drawn, the position where the widget should be drawn, and a flag indicating whether the widget
     * should be drawn as multi-line or not.
     *
     * If the widget is of type TextWidget, it iterates through each character in the text and converts it
     * into a CHAR_INFO structure with appropriate attributes. It then adds this element to the render
     * buffer array.
     *
     * Note: This method needs to be called within a rendering loop to update the UI on the screen.
     *
     * @param InWidget The widget object to be drawn.
     * @param InPosition The position where the widget should be drawn.
     * @param bIsMultiLine Flag indicating whether the widget should be drawn as multi-line or not.
     */
    void DrawUI(Widget& InWidget, Vector2i InPosition, bool bIsMultiLine = false);

    /**
     * Displays the render buffer array on the console screen.
     *
     * It uses the Windows API `WriteConsoleOutput` function to write the render buffer
     * onto the console screen.
     *
     * Note: This method assumes that the render buffer (`m_RenderBuffer`) is populated
     * correctly and the console window is properly set up.
     */
    void DisplayRenderBuffer();
    
private:
    /**
     * @brief Fixes the console window's properties to remove the maximize and resize buttons.
     *
     * This method fixes the console window's properties to remove the maximize and resize buttons.
     * It sets the style of the console window by calling GetConsoleWindow to get the handle of the console window,
     * then retrieves the current window style using GetWindowLong.
     * It removes the WS_MAXIMIZEBOX and WS_THICKFRAME flags from the style to hide the maximize and resize buttons.
     * Finally, it sets the modified style using SetWindowLong to update the console window's properties.
     *
     * @note This method assumes that the console is running on Windows platform.
     */
    void FixConsoleWindow();

    /**
     * @brief Hides the console cursor.
     *
     * This method hides the console cursor by setting its visibility to 0.
     * It uses the Windows API `GetStdHandle` and `SetConsoleCursorInfo` functions
     * to retrieve the console output handle and set the cursor visibility respectively.
     * The cursor size is set to 1.
     */
    void HideCursor();

    /**
     * Moves the cursor to the specified coordinates on the console screen.
     *
     * @param InX The X-coordinate to move the cursor to.
     * @param InY The Y-coordinate to move the cursor to.
     */
    void GoToXY(int InX, int InY);

    /**
     * @brief Adds an element to the render buffer at the specified position.
     *
     * This method is used to add an element to the render buffer at the specified position.
     * The element is represented by a CHAR_INFO structure containing the sprite and attributes.
     * The position is specified by a Vector2i structure containing X and Y coordinates.
     *
     * @param InSprite The CHAR_INFO structure representing the element to add to the render buffer.
     * @param InPosition The Vector2i structure representing the position at which to add the element.
     *
     * @note This method assumes that the render buffer is already initialized and is large enough to accommodate the element at the specified position.
     * @note This method modifies the render buffer by adding the element at the specified position.
     */
    void AddElementToRenderBuffer(CHAR_INFO InSprite, Vector2i InPosition);

    /**
     * @brief Sets the console color to the specified value.
     *
     * This method is used to set the console color to the specified value. It takes in an integer value
     * representing the color, which should be one of the values defined in the Constants.h file.
     * The method internally calls the Windows API function `SetConsoleTextAttribute` to set the console
     * color to the specified value.
     *
     * @param InColor The color value to set for the console.
     *
     * @note This method assumes that the console window is already opened and initialized.
     * @note The InColor parameter should be one of the color constants defined in the Constants.h file.
     * @note This method does not validate the InColor parameter, so ensure it is a valid color value.
     */
    void SetConsoleColor(int InColor);

    /**
     * @brief The render buffer used by the renderer.
     *
     * The render buffer is a std::array of CHAR_INFO structures with a size of WINDOW_WIDTH * WINDOW_HEIGHT.
     * It is used to store the character information for each position in the window.
     */
    std::array<CHAR_INFO, WINDOW_WIDTH * WINDOW_HEIGHT> m_RenderBuffer;
};

