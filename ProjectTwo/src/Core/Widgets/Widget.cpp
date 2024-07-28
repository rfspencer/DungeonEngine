#include "Widget.h"

Widget::Widget()
    : m_WidgetTransform(0, 0), m_IsVisible(true), m_DoesNeedUpdate(true), m_OverrideColor(7)
{
}

void Widget::RenderInternal(Renderer& InRendererRef, bool bIsMultiLine)
{
    if(m_IsVisible && GetDoesNeedUpdate())
    {
        Render(InRendererRef, bIsMultiLine);
    }
}

void Widget::SetWidgetPosition(Vector2i InNewLocation)
{
    m_WidgetTransform.SetPosition(InNewLocation);
    LocationUpdated(InNewLocation);
    SetDoesNeedUpdate(true);
}

void Widget::SetWidgetPosition(int InX, int InY)
{
    m_WidgetTransform.SetPosition({InX, InY});
    LocationUpdated({InX, InY});
    SetDoesNeedUpdate(true);
}

void Widget::SetVisibility(bool InNewVisibility)
{
    m_IsVisible = InNewVisibility;
    SetDoesNeedUpdate(true);
}

void Widget::Render(Renderer& InRendererRef, bool bIsMultiLine)
{
}

void Widget::LocationUpdated(const Vector2i InNewLocation)
{
}
