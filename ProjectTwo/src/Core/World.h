#pragma once

#include "Core/Object.h"
#include "Core/Types.h"

class Actor;
class Application;
class HUD;
class Renderer;

class World : public Object
{
public:
    World(Application* OwningApp);
    
    void BeginPlayInternal();
    void TickInternal(float DeltaTime);
    void Render(Renderer& InRendererRef);

    virtual ~World();

    template<typename ActorType, typename... Args>
    WeakPtr<ActorType> SpawnActor(Args... InArgs);

    template<typename HUDType, typename... Args>
    WeakPtr<HUDType> SpawnHUD(Args... InArgs);
    
    Application* GetApplication() { return m_OwningApp; }
    const Application* GetApplication() const { return m_OwningApp; }

private:
    virtual void BeginPlay();
    virtual void Tick(float DeltaTime);

    void RenderHUD(Renderer& InRendererRef);
    
private:
    Application* m_OwningApp;
    bool m_bBeginPlay;

    List<SharedPtr<Actor>> m_Actors;
    List<SharedPtr<Actor>> m_PendingActors;

    SharedPtr<HUD> m_HUD;
    
};

template<typename ActorType, typename... Args>
WeakPtr<ActorType> World::SpawnActor(Args... InArgs)
{
    SharedPtr<ActorType> NewActor{ new ActorType(this, InArgs...) };
    m_PendingActors.push_back(NewActor);
    return NewActor;
}

template<typename HUDType, typename... Args>
WeakPtr<HUDType> World::SpawnHUD(Args... InArgs)
{
    SharedPtr<HUDType> NewHUD{ new HUDType(InArgs...) };
    m_HUD = NewHUD;
    return NewHUD;
}
