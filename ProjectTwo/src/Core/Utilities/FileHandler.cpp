/**
* @file FileHandler.cpp
 * @brief Implementation for the FileHandler class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

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

std::array<std::array<char, WINDOW_WIDTH>, WINDOW_HEIGHT> FileHandler::StringToMap(const std::string& InString, bool bLoadAllData)
{
    std::array<std::array<char, WINDOW_WIDTH>, WINDOW_HEIGHT> TempArray;
    if (bLoadAllData)
    {
        int Row = 0;
        int Column = 0;
        
        for (const char& Char : InString)
        {
            TempArray[Row][Column] = Char;
            Column++;
            
            if (Column % 120 == 0)
            {
                Column = 0;
                Row++;
            }
            if (Row > WINDOW_HEIGHT) break;
        }
        return TempArray;
    }
    return TempArray;
}

