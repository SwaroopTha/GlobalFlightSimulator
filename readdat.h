#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> readline(std::stringstream & ss, char delim = ',');

bool validID(int id);
bool validIATA(std::string iata);
bool validLatitude(double latitude);
bool validLongitude(double longitude);
