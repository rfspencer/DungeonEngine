// Copyright (c) 2024 Rich Spencer. All rights reserved.

#include "World.h"

#include "Actor.h"
#include "Widgets/HUD.h"

World::World(Application* OwningApp)
    : m_OwningApp(OwningApp), m_bBeginPlay(false), m_Actors(), m_PendingActors()
{
}

void World::BeginPlayInternal()
{
    if (!m_bBeginPlay)
    {
        m_bBeginPlay = true;
        BeginPlay();
    }
}

void World::TickInternal(float DeltaTime)
{
    for(const SharedPtr<Actor>& Actor : m_PendingActors)
    {
        m_Actors.push_back(Actor);
        Actor->BeginPlayInternal();
    }
    m_PendingActors.clear();

    for (auto Iter = m_Actors.begin(); Iter != m_Actors.end();)
    {
        Iter->get()->TickInternal(DeltaTime);
        ++Iter;
    }
    
    Tick(DeltaTime);
}

void World::Render(Renderer& InRendererRef)
{
    for (const auto& Actor : m_Actors)
    {
        Actor->Render(InRendererRef);
    }
    RenderHUD(InRendererRef);
}

World::~World()
{
}

void World::BeginPlay()
{
}

void World::Tick(float DeltaTime)
{
}

void World::RenderHUD(Renderer& InRendererRef)
{
    if(m_HUD)
    {
        m_HUD->Render(InRendererRef);
    }
}
