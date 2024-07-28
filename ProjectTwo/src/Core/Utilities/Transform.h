#pragma once

#include "Utilities/Vector2i.h"

class Transform
{
public:
    Transform()
        :  m_Position(0, 0), m_PreviousPosition(0, 0), m_Size({1, 1}), m_HasMovedThisFrame(false) { }
    Transform(Vector2i InNewPosition, Vector2i InSize = {1, 1})
        : m_Position(InNewPosition), m_PreviousPosition(0,0), m_Size({1, 1}), m_HasMovedThisFrame(false) { }
    Transform(int InPosX, int InPosY, int InSizeX = 1, int InSizeY = 1)
        : m_Position(InPosX, InPosY), m_PreviousPosition(0, 0), m_Size({1, 1}), m_HasMovedThisFrame(false) { }
    
    
    Vector2i GetPosition() const { return m_Position; }
    Vector2i GetPreviousPosition() const { return m_PreviousPosition; }
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

    Vector2i GetSize() const { return m_Size; }
    void SetSize(Vector2i InSize) { m_Size = InSize; } 
    
    bool HasMovedThisFrame() const { return m_HasMovedThisFrame; }
    
private:
    Vector2i m_Position;
    Vector2i m_PreviousPosition;
    Vector2i m_Size;

    bool m_HasMovedThisFrame;
};
