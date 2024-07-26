#include "Core/Actor.h"

#include "Core/Renderer.h"

Actor::Actor(World* InOwningWorld)
    : m_OwningWorld(InOwningWorld), m_HasBeganPlay(false), m_IsRenderable(true)
{
}

Actor::~Actor()
{
}

void Actor::BeginPlayInternal()
{
}

void Actor::TickInternal(float DeltaTime)
{
}

void Actor::BeginPlay()
{
}

void Actor::Tick(float DeltaTime)
{
}

void Actor::Render(Renderer& InRendererRef)
{
    if (IsPendingDestroy())
    {
        return;
    }
    //InRendererRef.DrawObject();
}

void Actor::SetActorLocation(const Vector2i InNewLocation)
{
    m_Transform.SetPosition(InNewLocation);
}

void Actor::Destroy()
{
    Object::Destroy();
}

void Actor::ApplyDamage(float InAmount)
{
}
