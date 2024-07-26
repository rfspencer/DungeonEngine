#include "Widget.h"

Widget::Widget()
    : m_WidgetTransform(), m_IsVisible(true), m_DoesNeedUpdate(true)
{
}

void Widget::RenderInternal(Renderer& InRendererRef)
{
    if(m_IsVisible && GetDoesNeedUpdate())
    {
        Render(InRendererRef);
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

void Widget::Render(Renderer& InRendererRef)
{
}

void Widget::LocationUpdated(const Vector2i InNewLocation)
{
}
