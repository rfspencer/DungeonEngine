#include "Core/World.h"

#include "Core/Widgets/HUD.h"


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

void World::Render(Renderer& InRendererRef)
{
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
