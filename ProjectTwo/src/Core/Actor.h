#pragma once

#include <string>

#include "Core/Object.h"
#include "Core/Utilities/Vector2i.h"
#include "Utilities/Transform.h"

class Renderer;
class World;

class Actor : public Object
{
public:
    Actor(World* InOwningWorld);
    virtual ~Actor();

    void BeginPlayInternal();
    void TickInternal(float DeltaTime);
    virtual void BeginPlay();
    virtual void Tick(float DeltaTime);

    virtual void Render(Renderer& InRendererRef);

    void SetActorLocation(const Vector2i InNewLocation);
    Vector2i GetActorLocation() const { return m_Transform.GetPosition(); }

    bool HasMovedThisFrame() const { return m_Transform.HasMovedThisFrame(); }
    Vector2i GetPreviousPosition() const { return m_Transform.GetPreviousPosition(); }

    const World* GetWorld() const { return m_OwningWorld; }
    World* GetWorld() { return m_OwningWorld; }

    virtual void Destroy() override;

    virtual void ApplyDamage(float InAmount);

    std::string& GetSprite() { return m_Sprite; }
    void SetSprite(const std::string& InString) { m_Sprite = InString; }

    int GetOverrideColor() const { return m_OverrideColor; }
    void SetOverrideColor(const int InColor) { m_OverrideColor = InColor; }

private:
    World* m_OwningWorld;
    bool m_HasBeganPlay;
    bool m_IsRenderable;

    std::string m_Sprite = "*";
    int m_OverrideColor = -1;

    Transform m_Transform = Transform();
};
