#include "Map.h"

#include "Utilities/FileHandler.h"

Map::Map(World* InOwningWorld, const std::string& InPath)
    : Actor(InOwningWorld)
{
    Init(InPath);
}

void Map::Init(const std::string& InPath)
{
    // Initialize Map Widget
    SetActorSize({WINDOW_WIDTH, WINDOW_HEIGHT});

    std::string TempString;
    if (FileHandler::DoesFileExist(InPath.c_str()))
    {
        TempString = FileHandler::ReadFile(InPath.c_str());
        m_MapLayout = FileHandler::StringToMap(TempString);
    }
    SetSprite(TempString);
    // Broadcast Map is loaded
    OnMapLoaded.Broadcast();
}

void Map::Render(Renderer& InRendererRef)
{
    if (!IsPendingDestroy())
    {
        InRendererRef.DrawActor(this);
    }
}

bool Map::TileIsEmpty(Vector2i InPosition) const
{
    const char C = m_MapLayout[InPosition.Y][InPosition.X];
    if (C == ' ')
    {
        return true;
    }
    return false;    
}

void Map::AddActorToMap(Actor* InActor)
{
    if (InActor != nullptr)
    {
        Vector2i ActorPosition = InActor->GetActorLocation();
        m_MapLayout[ActorPosition.Y][ActorPosition.X] = InActor->GetSprite()[0];
    }
}

void Map::RemoveActorFromMap(Actor* InActor)
{
}
