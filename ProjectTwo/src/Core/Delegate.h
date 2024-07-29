/**
* @file Delegate.h
 * @brief Header for the Delegate class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include <functional>
#include "Types.h"

class Object;

/**
 * @class Delegate
*
 * @brief The Delegate class is responsible for managing a list of callback functions and broadcasting events to them.
 * @tparam Args The types of arguments that the callback functions accept.
 *
 * The Delegate class provides a mechanism for implementing event-driven programming
 * in C++. It allows you to register multiple event handlers, which are then called
 * when the event occurs. This is useful for situations where you need to notify multiple
 * objects when a specific event happens.
 *
 * The Delegate class is a template class, which means that it can be used with any
 * class type. You can specify the class type as a template argument when creating
 * an instance of the Delegate class.
 *
 * Example usage:
 *
 * ```
 * // Declare a delegate for the OnMapLoaded event
 * Delegate<> OnMapLoaded;
 *
 * // Register an event handler
 * OnMapLoaded.AddEventHandler(&MyClass::OnMapLoadedHandler, &myObject);
 *
 * // Call the event handlers
 * OnMapLoaded.Invoke();
 * ```
 */
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
