#pragma once

#include "Utilities/Vector2i.h"

class Transform
{
public:
    Transform()
        :  m_Position(0, 0), m_PreviousPosition(0, 0), m_HasMovedThisFrame(false) { }
    Transform(Vector2i InNewPosition)
        : m_Position(InNewPosition), m_PreviousPosition(0,0), m_HasMovedThisFrame(false) { }
    Transform(int InX, int InY)
        : m_Position(InX, InY), m_PreviousPosition(0, 0), m_HasMovedThisFrame(false) { }

    Vector2i GetPosition() const { return m_Position; }
    Vector2i GetPreviousPosition() const { return m_PreviousPosition; }
    
    bool HasMovedThisFrame() const { return m_HasMovedThisFrame; }
    
    void SetPosition(int InX, int InY)
    {
        m_PreviousPosition = m_Position;
        m_Position = Vector2i(InX, InY);
        if (m_PreviousPosition != m_Position)
        {
            m_HasMovedThisFrame = true;
        }
        else
        {
            m_HasMovedThisFrame = false;
        }
    }
    void SetPosition(Vector2i InNewPosition)
    {
        m_PreviousPosition = m_Position;
        m_Position = Vector2i(InNewPosition.X, InNewPosition.Y);
        if (m_PreviousPosition != m_Position)
        {
            m_HasMovedThisFrame = true;
        }
        else
        {
            m_HasMovedThisFrame = false;
        }
    }

    
private:
    Vector2i m_Position;
    Vector2i m_PreviousPosition;

    bool m_HasMovedThisFrame;
};
