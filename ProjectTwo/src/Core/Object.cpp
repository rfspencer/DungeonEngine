#include "Object.h"

unsigned int Object::UniqueIDCounter = 0;
Object::Object()
    : m_UniqueID(GetNextAvailableID()), m_IsPendingDestroy(false)
{
}

Object::~Object()
{
}

void Object::Destroy()
{
    m_IsPendingDestroy = true;
}

WeakPtr<Object> Object::GetWeakRef()
{
    return weak_from_this();
}

WeakPtr<const Object> Object::GetWeakRef() const
{
    return weak_from_this();
}

unsigned int Object::GetNextAvailableID()
{
    return UniqueIDCounter++;
}
