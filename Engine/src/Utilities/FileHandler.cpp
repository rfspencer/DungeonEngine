// Copyright (c) 2024 Rich Spencer. All rights reserved.

#include "FileHandler.h"

#include "Application.h"
#include "Widgets/TextWidget.h"

#include <fstream>
#include <iostream>

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

std::vector<std::vector<char>> FileHandler::StringToMap(const std::string& InString, int InMapWidth, int InMapHeight, bool bLoadAllData)
{
    std::vector TempVector(InMapHeight, std::vector<char>(InMapWidth));
    if (bLoadAllData)
    {
        int Row = 0;
        int Column = 0;
        
        for (const char& Char : InString)
        {
            //TempVector[Row][Column] = Char;
            TempVector.at(Row).at(Column) = Char;
            Column++;
            
            if (Column % InMapWidth == 0)
            {
                Column = 0;
                Row++;
            }
            if (Row > InMapHeight) break;
        }
        return TempVector;
    }
    return TempVector;
}
