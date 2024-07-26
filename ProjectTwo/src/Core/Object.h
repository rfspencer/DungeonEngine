#pragma once

#include <memory>

#include "Types.h"

/**
 * Object class for all game objects to derive from.
 * @ref <CPP> https://en.cppreference.com/w/cpp/memory/enable_shared_from_this
 */
class Object : public std::enable_shared_from_this<Object>
{
public:
    Object();
    virtual ~Object();

    virtual void Destroy();
    bool IsPendingDestroy() const { return m_IsPendingDestroy; }

    WeakPtr<Object> GetWeakRef();
    WeakPtr<const Object> GetWeakRef() const;

    unsigned int GetUniqueID() const { return m_UniqueID; }

private:
    // Game wide, every object has a unique identifier
    unsigned int m_UniqueID;

    bool m_IsPendingDestroy;

    static unsigned int UniqueIDCounter;
    // Increments UniqueIDCounter and returns the next Object ID in sequence
    static unsigned int GetNextAvailableID();
};
