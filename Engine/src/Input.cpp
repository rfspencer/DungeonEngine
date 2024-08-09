// Copyright (c) 2024 Rich Spencer. All rights reserved.

#include "Input.h"

#include <conio.h>

int Input::m_KeyDown = 0;
List<std::function<void(int)>> Input::m_InputListeners;

void Input::Update()
{
    if (_kbhit())
    {
        m_KeyDown = _getch();

        for (auto& Listener : m_InputListeners)
        {
            Listener(m_KeyDown);
        }
    }
    else
    {
        m_KeyDown = 0;
    }
    
}

int Input::GetKeyDown()
{
    return m_KeyDown;
}

void Input::AddListener(std::function<void(int Input)> Callback)
{
    m_InputListeners.push_back(Callback);
}

void Input::RemoveListener(std::function<void(int Input)> Callback)
{
    auto It = std::remove_if(m_InputListeners.begin(), m_InputListeners.end(), [Callback](const auto& Listener)
    {
        return Listener.target_type() == Callback.target_type();
    });
    m_InputListeners.erase(It, m_InputListeners.end());
}


