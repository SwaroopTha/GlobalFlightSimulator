#include "Graph.h"
#include "readdat.h"
#include <iostream>

using namespace std;

int main() {
    Graph g;
    ifstream airports("airports.dat");
    ifstream routes("routes.dat");
    string line;
    map<string, int> iataToID;
    int skippedAirports = 0;
    int skippedRoutes = 0;
    int fixedRoutes = 0;

    while (getline(airports, line)) {
        stringstream ss(line);
        vector<string> fields = readline(ss);
        if (fields.size() != 14) {
            skippedAirports++;
            continue;
        }
        int id = stoi(fields[0]);
        string name = fields[1];
        string iata = fields[4];
        double latitude = stod(fields[6]);
        double longitude = stod(fields[7]);
        if (validID(id) && validIATA(iata)) {
            iataToID[iata] = id;
        }
        if (validID(id) && validLatitude(latitude) && validLongitude(longitude)) {
            g.addNode(id, name, latitude, longitude);
        } else {
            skippedAirports++;
        }
    }
    airports.close();

    while (getline(routes, line)) {
        stringstream ss(line);
        vector<string> fields = readline(ss);
        if (fields.size() != 9) {
            skippedRoutes++;
            continue;
        }
        int id1, id2;
        bool fixed = false;
        if (fields[3] == "\\N") {
            if (iataToID.find(fields[2]) != iataToID.end()) {
                id1 = iataToID[fields[2]];
                fixed = true;
            } else {
                skippedRoutes++;
                continue;
            }
        } else {
            id1 = stoi(fields[3]);
        }
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
        if (!g.connect(id1, id2)) {
            skippedRoutes++;
        }
        if (fixed) {
            fixedRoutes++;
        }
    }
    routes.close();

    cout << g.size() << " airports added" << endl;
    cout << skippedAirports << " airports skipped" << endl;
    cout << g.connections() << " routes added, " << fixedRoutes << " of which were fixed" << endl;
    cout << skippedRoutes << " routes skipped" << endl;
}
