#include "Object.h"

unsigned int Object::UniqueIDCounter = 0;
Object::Object()
    : m_UniqueID(GetNextAvailableID())
{
}

Object::~Object()
{
}

unsigned int Object::GetNextAvailableID()
{
    return UniqueIDCounter++;
}
