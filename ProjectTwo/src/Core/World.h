#pragma once

#include "Core/Object.h"
#include "Core/Types.h"

class Application;
class HUD;
class Renderer;

class World : public Object
{
public:
    World(Application* OwningApp);
    
    void BeginPlayInternal();
    void TickInternal(float DeltaTime);

    virtual ~World();

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
    
};

    SharedPtr<HUD> m_HUD;
    
};

template<typename HUDType, typename... Args>
WeakPtr<HUDType> World::SpawnHUD(Args... InArgs)
{
    SharedPtr<HUDType> NewHUD{ new HUDType(InArgs...) };
    m_HUD = NewHUD;
    return NewHUD;
}
