#include "readdat.h"

using namespace std;

vector<string> readline(stringstream & ss, char delim) {
    vector<string> fields;
    string field = "";
    char c;
    bool inQuote = false;
    while (ss.get(c)) {
        if (c == '"') {
            inQuote = !inQuote;
        } else if (c == delim && !inQuote) {
            fields.push_back(field);
            field = "";
        } else {
            field += c;
        }
    }
    fields.push_back(field);
    return fields;
}

bool validID(int id) {
    return id > 0;
}

bool validIATA(std::string iata) {
    for (char c : iata) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return iata.length() == 3;
}

bool validLatitude(double latitude) {
    return latitude >= -90 && latitude <= 90;
}

bool validLongitude(double longitude) {
    return longitude >= -180 && longitude <= 180;
}
