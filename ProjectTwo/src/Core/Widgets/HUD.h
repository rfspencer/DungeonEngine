#pragma once

#include "Core/Object.h"

class Renderer;

class HUD : public Object
{
public:
    virtual void Render(Renderer& InRendererRef) = 0;
    void InitInternal();

    bool HasInit() const { return m_HasInit; }

    virtual bool HandleEvent();

    virtual void Tick(float DeltaTime);

protected:
    HUD();

private:
    virtual void Init();

    bool m_HasInit;
};
