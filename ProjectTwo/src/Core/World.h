#pragma once

#include "Object.h"
#include "Types.h"

class Application;

class World : public Object
{
public:
    World(Application* OwningApp);
    
    virtual void BeginPlayInternal();
    virtual void TickInternal(float DeltaTime);

    Application* GetApplication() { return m_OwningApp; }
    const Application* GetApplication() const { return m_OwningApp; }

private:
    virtual void BeginPlay();
    virtual void Tick(float DeltaTime);
    
private:
    Application* m_OwningApp;
    bool m_bBeginPlay;
    
};
