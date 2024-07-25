#pragma once

#include <functional>
#include <vector>

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
    static int m_KeyDown;
    static std::vector<std::function<void(int)>> m_InputListeners;
};
