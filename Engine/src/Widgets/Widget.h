// Copyright (c) 2024 Rich Spencer. All rights reserved.

#pragma once

#include "Object.h"

#include "Utilities/Transform.h"

class Renderer;

/**
 * @class Widget
 * @brief The base class for all widgets in the UI system.
 */
class Widget : Object
{
public:
    /**
     * @brief Renders the widget internally if it is visible and needs update.
     *
     * @param InRendererRef The reference to the renderer object.
     * @param bIsMultiLine Indicates whether the widget should be rendered in multi-line mode or not. Default is false.
     */
    void RenderInternal(Renderer& InRendererRef, bool bIsMultiLine = false);

    /**
     * @brief Sets the position of the widget.
     *
     * @param InNewLocation The new location of the widget.
     * @see Widget::SetWidgetPosition(int InX, int InY)
     */
    void SetWidgetPosition(Vector2i InNewLocation);
    /**
     * @brief Sets the position of the widget.
     *
     * @param InX The x-coordinate of the new position.
     * @param InY The y-coordinate of the new position.
     */
    void SetWidgetPosition(int InX, int InY);
    /**
     * @brief Retrieves the position of the widget.
     *
     * This method returns the position of the widget in the form of a Vector2i object.
     *
     * @return The position of the widget.
     */
    Vector2i GetWidgetPosition() const { return m_WidgetTransform.GetPosition(); }

    /**
     * @brief Sets the visibility of the widget.
     *
     * This method sets the visibility of the widget to the specified value. If the widget is visible,
     * it will be rendered internally if it needs an update.
     *
     * @param InNewVisibility The new visibility state of the widget. True indicates visible, false indicates hidden.
     */
    void SetVisibility(bool InNewVisibility);
    /**
     * @brief Gets the visibility of the widget.
     *
     * This method retrieves the visibility state of the widget. If the widget is visible, it will be rendered internally if it needs an update.
     *
     * @return The visibility state of the widget. True indicates visible, false indicates hidden.
     */
    bool GetVisibility() const { return m_IsVisible; }

    /**
     * @brief Sets the override color for the widget.
     *
     * @param InOverrideColor The new override color value to set.
     */
    void SetOverrideColor(int InOverrideColor) { m_OverrideColor = InOverrideColor; }
    /**
     * @brief Gets the override color for the widget.
     *
     * @return The override color value.
     */
    int GetOverrideColor() const { return m_OverrideColor; }

    /**
     * @brief Sets the value indicating whether the widget needs an update.
     *
     * This method sets the value of m_DoesNeedUpdate to the specified value. If the widget needs an update,
     * it will be rendered internally the next time RenderInternal() is called.
     *
     * @param InDoesNeedUpdate The new value for m_DoesNeedUpdate. True indicates that the widget needs an update, false otherwise.
     */
    void SetDoesNeedUpdate(bool InDoesNeedUpdate) { m_DoesNeedUpdate = InDoesNeedUpdate; }
    /**
     * @brief Gets the value indicating whether the widget needs an update.
     *
     * If the widget needs an update, it will be rendered internally the next time RenderInternal() is called.
     *
     * @return The value indicating whether the widget needs an update. True indicates that the widget needs an update, false otherwise.
     */
    bool GetDoesNeedUpdate() const { return m_DoesNeedUpdate; }

protected:
    Widget();
    
private:
    /**
     * @brief Renders the widget using the provided renderer.
     *
     * This method is responsible for rendering the widget if it is visible and needs an update.
     *
     * @param InRendererRef The reference to the renderer object used for rendering.
     * @param bIsMultiLine Indicates whether the widget should be rendered in multi-line mode or not. Default is false.
     */
    virtual void Render(Renderer& InRendererRef, bool bIsMultiLine = false);

    /**
     * @brief Called when the location of the widget is updated.
     *
     * This method is called whenever the location of the widget is updated using the SetWidgetPosition method.
     * It can be overridden in derived classes to perform custom logic when the location changes.
     *
     * @param InNewLocation The new location of the widget in the form of a Vector2i object.
     */
    virtual void LocationUpdated(const Vector2i InNewLocation);

    /**
     * @class Transform
     * @brief Represents the transformation of a widget in the UI system.
     *
     * This class is responsible for storing the position and other transform properties of a widget.
     * It is used by the Widget class to render and manipulate widgets in the UI system.
     */
    Transform m_WidgetTransform;
    
    bool m_IsVisible;
    bool m_DoesNeedUpdate;
    int m_OverrideColor;
};
