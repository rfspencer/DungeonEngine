#include "World.h"


World::World(Application* OwningApp)
    : m_OwningApp(OwningApp), m_bBeginPlay(false)
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
    Tick(DeltaTime);
}

void World::BeginPlay()
{
}

void World::Tick(float DeltaTime)
{
}
