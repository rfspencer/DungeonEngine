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
    if (FileHandler::DoesFileExist(InPath.c_str()))
    {
        std::string TempString = FileHandler::ReadFile(InPath.c_str());
        m_MapLayout = FileHandler::StringToMap(TempString);
    }
}
