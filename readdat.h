#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

/**
 * @brief readline
 * Gets each field in a line separated by a delimiter
 * @param ss A stringstream with the line
 * @param delim The delimiter, comma by default
 * @return vector<string> A vector with each item being a field in the line
 */
std::vector<std::string> readline(std::stringstream & ss, char delim = ',');

/**
 * @brief validID
 * Determines if an ID is valid (i.e. )
 * @param id 
 * @return bool
 */
bool validID(int id);
bool validIATA(std::string iata);
bool validLatitude(double latitude);
bool validLongitude(double longitude);
