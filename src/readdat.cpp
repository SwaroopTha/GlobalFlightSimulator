#include "readdat.h"

using namespace std;

vector<string> readline(stringstream & ss, char delim) {
    vector<string> fields;
    string field = "";
    char c;
    //this is needed so commas in quotes aren't used
    bool inQuote = false;
    while (ss.get(c)) {
        if (c == '"') {
            //quote either starts or ends when a " is found
            inQuote = !inQuote;
        } else if (c == delim && !inQuote) {
            //adds the field to the list
            fields.push_back(field);
            //gets started on the new field
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
