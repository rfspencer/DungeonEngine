#pragma once

#include <functional>
#include <vector>

#include "Types.h"

class Input
{
public:
    Input() = default;

    static void Update();
    static int GetKeyDown();
    static void AddListener(std::function<void(int Input)> Callback);
    static void RemoveListener(std::function<void(int Input)> Callback);
    static void CleanUp() { m_InputListeners.clear(); }

private:
    // The currently pressed key. 0 if no keys are pressed.
    static int m_KeyDown;

    static List<std::function<void(int)>> m_InputListeners;
};
