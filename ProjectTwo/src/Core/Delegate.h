#pragma once

#include <functional>
#include "Types.h"

class Object;

template<typename... Args>
class Delegate
{
public:
    template<typename ClassName>
    void BindAction(WeakPtr<Object> Obj, void(ClassName::*Callback)(Args...))
    {
        std::function<bool(Args...)> CallbackFunc = [Obj, Callback](Args... InArgs)->bool
        {
            if (!Obj.expired())
            {
                (static_cast<ClassName*>(Obj.lock().get())->*Callback)(InArgs...);
                return true;
            }
            return false;
        };
        m_Callbacks.push_back(CallbackFunc);
    }

    void Broadcast(Args... InArgs)
    {
        for (auto Iter = m_Callbacks.begin(); Iter != m_Callbacks.end();)
        {
            if ((*Iter)(InArgs...))
            {
                ++Iter;
            }
            else
            {
                Iter = m_Callbacks.erase(Iter);
            }
        }
    }

private:
    List<std::function<bool(Args...)>> m_Callbacks;
};
