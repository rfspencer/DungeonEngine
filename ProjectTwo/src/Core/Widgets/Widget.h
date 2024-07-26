#pragma once

#include "Object.h"

#include "Utilities/Transform.h"

class Renderer;

class Widget : Object
{
public:
    void RenderInternal(Renderer& InRendererRef);

    void SetWidgetPosition(Vector2i InNewLocation);
    void SetWidgetPosition(int InX, int InY);
    Vector2i GetWidgetPosition() const { return m_WidgetTransform.GetPosition(); }

    void SetVisibility(bool InNewVisibility);
    bool GetVisibility() const { return m_IsVisible; }

    void SetDoesNeedUpdate(bool InDoesNeedUpdate) { m_DoesNeedUpdate = InDoesNeedUpdate; }
    bool GetDoesNeedUpdate() const { return m_DoesNeedUpdate; }

protected:
    Widget();
    
private:
    virtual void Render(Renderer& InRendererRef);
    virtual void LocationUpdated(const Vector2i InNewLocation);

    Transform m_WidgetTransform;
    bool m_IsVisible;
    bool m_DoesNeedUpdate;
};
