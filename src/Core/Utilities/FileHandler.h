/**
* @file FileHandler.h
 * @brief Header for the FileHandler class
 * @author Rich Spencer
 * @cs-class CSCI-120-70
 * @date July 29, 2024
 */

#pragma once

#include <array>
#include <string>

#include "Utilities/Constants.h"

class TextWidget;

class FileHandler
{
public:
    /**
     * @brief Checks to see if file exist on disk
     *
     * @param InPath The path of the file to check for existence
     * @return True if the file exists, false otherwise
     */
    static bool DoesFileExist(const char *InPath);
    
    /**
     * @brief Read the specified file from disk and return its contents as a string, each line as a vector element
     *
     * This static function reads the specified file from disk and returns its contents as a string.
     * Each line of the file is stored as an element in a vector of strings.
     *
     * @private @memberof FileHandler
     * @param InPath The file path of the file to be read
     *
     * @return A vector of strings, with each element representing a line from the file
     *
     * @note If the specified file cannot be opened or read, an empty vector will be returned
     */
    static std::string ReadFile(const char* InPath);

    /**
     * @brief Deserialize a string representation of a TextWidget object.
     *
     * This function takes a string and converts it into a Widget objects.
     *
     * @private @memberof FileHandler
     * @param InString The string to deserialize into a Book object.
     * @param bLoadAllData Whether to load all data including the checked out status of the book. Default: true
     *
     * @return TextWidget populated with string data.
     */
    static TextWidget StringToTextWidget(const std::string& InString, bool bLoadAllData = true);

    /**
     * @brief Convert a string to an array Map object.
     *
     * @private @memberof FileHandler
     * @param InString The string to convert to 2D map array.
     * @param bLoadAllData Whether to load all data including the checked out status of the map. Default: true
     * @note This function assumes the map data fills the render buffer space.
     *
     * @return Map populated with string data.
     */
    static std::array<std::array<char, WINDOW_WIDTH>, WINDOW_HEIGHT> StringToMap(const std::string& InString, bool bLoadAllData = true);
};
