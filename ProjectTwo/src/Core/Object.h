/**
* @file Object.h
 * @brief Header for the Object class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include <memory>

#include "Core/Delegate.h"
#include "Core/Types.h"

/**
 * @class Object
 * @brief The Object class is the base class for all objects in the game.
 *
 * The Object class provides common functionality and properties that all objects can inherit from.
 * It also provides a unique identifier for each object and the ability to check if an object is pending destruction.
 *
 * https://en.cppreference.com/w/cpp/memory/enable_shared_from_this
 *
 * @see Actor
 * @see HUD
 */
class Object : public std::enable_shared_from_this<Object>
{
public:
    Object();
    virtual ~Object();

    virtual void BeginPlay() { }

    virtual void Destroy();
    bool IsPendingDestroy() const { return m_IsPendingDestroy; }

    /**
     * @brief Returns a weak reference to the object.
     *
     * A weak reference allows you to hold a non-owning reference to an object.
     * It does not contribute to the ownership of the object,
     * meaning that if all the strong references to the object are destroyed,
     * the object will be destroyed and the weak reference will become invalid.
     *
     * @return WeakPtr<Object> - A weak reference to the object.
     */
    WeakPtr<Object> GetWeakRef();
    /**
     * @brief Returns a weak, const reference to the object.
     *
     * GetWeakRef() returns a weak pointer to the object, allowing other parts of the code
     * to hold a non-owning reference to the object without preventing it from being destroyed.
     * This can be used to check if the object is still alive and perform certain operations
     * if it is.
     *
     * @return A WeakPtr<Object> to the object.
     */
    WeakPtr<const Object> GetWeakRef() const;

    /**
     * @brief Returns the unique identifier of the object.
     *
     * The unique identifier is a game-wide identifier that is assigned to each object.
     * It allows for efficient identification and lookup of objects within the game.
     *
     * @return unsigned int - The unique identifier of the object.
     */
    unsigned int GetUniqueID() const { return m_UniqueID; }

private:
    // Game wide, every object has a unique identifier
    unsigned int m_UniqueID;

    bool m_IsPendingDestroy;

    static unsigned int UniqueIDCounter;
    // Increments UniqueIDCounter and returns the next Object ID in sequence
    static unsigned int GetNextAvailableID();
};
