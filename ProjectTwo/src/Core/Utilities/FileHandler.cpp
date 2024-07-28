#include "FileHandler.h"

#include "Core/Widgets/TextWidget.h"
#include "Game/Utilities/Constants.h"

#include <fstream>
#include <iostream>
#include <sstream>

bool FileHandler::DoesFileExist(const char* InPath)
{
    if (InPath)
    {
        std::ifstream File(InPath);
        return File.good();
    }
    return false;
}

std::string FileHandler::ReadFile(const char* InPath)
{
    std::string TempString;
    std::string Line;
    
    std::ifstream File(InPath);
    if (!File) {
        // Using std::cerr because standard output buffer is rendering application 
        std::cerr << "Unable to open " << InPath << std::endl;
        return TempString;
    }

    // Read the file
    while (std::getline(File, Line))
    {
        TempString += Line;
    }
    File.close();
    return TempString;
}

TextWidget FileHandler::StringToTextWidget(const std::string& InString, bool bLoadAllData)
{
    TextWidget TempWidget;
    if (bLoadAllData)
    {
        TempWidget.SetText(InString);
    }
    return TempWidget;
}

std::array<char, RENDER_BUFFER_SIZE> FileHandler::StringToMap(const std::string& InString, bool bLoadAllData)
{
    std::array<char, RENDER_BUFFER_SIZE> TempArray;
    if (bLoadAllData)
    {
        for (unsigned int i = 0; i < RENDER_BUFFER_SIZE; ++i)
        {
            TempArray[i] = InString.at(i);
        }
        return TempArray;
    }
    return TempArray;
}

