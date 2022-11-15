#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

/**
 * @brief Gets each field in a line separated by a delimiter
 * 
 * @param ss A stringstream with the line
 * @param delim The delimiter, comma by default
 * @return vector<string> A vector with each item being a field in the line
 */
std::vector<std::string> readline(std::stringstream & ss, char delim = ',');

/**
 * @brief Determines if an ID is valid (i.e. greater than 0)
 * 
 * @param id the ID
 * @return bool Whether the ID is valid
 */
bool validID(int id);
/**
 * @brief Determines if an International Air Transport Association code is valid
 * The IATA code is valid if it consists of three capital letters
 * 
 * @param iata the IATA code
 * @return bool Whether the IATA code is valid
 */
bool validIATA(std::string iata);
/**
 * @brief Determines if a latitude is valid (i.e. no more than 90 in absolute value)
 * 
 * @param latitude the latitude
 * @return bool Whether the latitude is valid
 */
bool validLatitude(double latitude);
/**
 * @brief Determines if a longitude is valid (i.e. no more than 180 in absolute value)
 * 
 * @param latitude the longitude
 * @return bool Whether the longitude is valid
 */
bool validLongitude(double longitude);
