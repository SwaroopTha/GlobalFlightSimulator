#include "readdat.h"
#include <iostream>

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
        if (!isupper(c)) {
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

Graph readData() {
    Graph g;
    ifstream airports("../Data/airports.dat");
    ifstream routes("../Data/routes.dat");
    string line;
    //map from IATA to ID to fix issues later on
    map<string, int> iataToID;
    int skippedAirports = 0;
    int skippedRoutes = 0;
    int fixedRoutes = 0;

    //reads in the airports
    while (getline(airports, line)) {
        stringstream ss(line);
        vector<string> fields = readline(ss);
        //skip if there are not 14 fields
        if (fields.size() != 14) {
            skippedAirports++;
            continue;
        }
        //we only care about these fields
        int id = stoi(fields[0]);
        string name = fields[1];
        string iata = fields[4];
        double latitude = stod(fields[6]);
        double longitude = stod(fields[7]);
        if (validID(id) && validIATA(iata)) {
            iataToID[iata] = id;
        }

        if (validID(id) && validLatitude(latitude) && validLongitude(longitude)) {
            //add the airport to the graph
            g.addNode(id, name, latitude, longitude);
        } else {
            skippedAirports++;
        }
    }
    airports.close();

    //reads in the connections
    while (getline(routes, line)) {
        stringstream ss(line);
        vector<string> fields = readline(ss);
        //skip if there aren't 9 lines
        if (fields.size() != 9) {
            skippedRoutes++;
            continue;
        }
        int id1, id2;
        bool fixed = false;
        //the ID will be missing occassionally so we try to use the IATA to figure it out
        //this is for the first airport
        if (fields[3] == "\\N") {
            if (iataToID.find(fields[2]) != iataToID.end()) {
                //if the IATA is found use the corresponding ID
                id1 = iataToID[fields[2]];
                fixed = true;
            } else {
                //skip it otherwise
                skippedRoutes++;
                continue;
            }
        } else {
            id1 = stoi(fields[3]);
        }
        //same thing for the second airport
        if (fields[5] == "\\N") {
            if (iataToID.find(fields[4]) != iataToID.end()) {
                id2 = iataToID[fields[4]];
                fixed = true;
            } else {
                skippedRoutes++;
                continue;
            }
        } else {
            id2 = stoi(fields[5]);
        }
        if (!(validID(id1) && validID(id2))) {
            skippedRoutes++;
            continue;
        }
        //make the connection (or try to)
        if (!g.connect(id1, id2)) {
            skippedRoutes++;
        }
        //count the number of fixed routes (i.e. routes that use IATA to determine ID)
        if (fixed) {
            fixedRoutes++;
        }
    }
    routes.close();

    return g;
}
