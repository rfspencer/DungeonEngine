﻿// Copyright (c) 2024 Rich Spencer. All rights reserved.

#include "Actor.h"

#include "Renderer.h"

Actor::Actor(World* InOwningWorld)
    : m_OwningWorld(InOwningWorld), m_HasBeganPlay(false), m_IsRenderable(true)
{
}

Actor::~Actor()
{
}

void Actor::BeginPlayInternal()
{
    if (!m_HasBeganPlay)
    {
        m_HasBeganPlay = true;
        BeginPlay();
    }
}

void Actor::TickInternal(float DeltaTime)
{
    if (!IsPendingDestroy())
    {
        Tick(DeltaTime);
    }
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
    // TODO: May need to check if we've moved before rendering. Do this in case of flickering.
    // if (m_Transform.HasMovedThisFrame()) { }
    InRendererRef.DrawActor(*this);
}

void Actor::SetActorLocation(const Vector2i InNewLocation)
{
    m_Transform.SetPosition(InNewLocation);
}

void Actor::SetActorSize(const Vector2i InSize)
{
    m_Transform.SetSize(InSize);
}

void Actor::Destroy()
{
    Object::Destroy();
}

void Actor::ApplyDamage(float InAmount)
{
}
