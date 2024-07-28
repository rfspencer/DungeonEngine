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
        // m_MapLayout = FileHandler::StringToMap(TempString);
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
