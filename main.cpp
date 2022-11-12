#include "Graph.h"
#include "readdat.h"
#include <iostream>
#include "Algorithms/dijkstra.h"

using namespace std;

int main() {
    Graph g;
    ifstream airports("Data/airports.dat");
    ifstream routes("Data/routes.dat");
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

    //summarize the data reading
    cout << g.size() << " airports added" << endl;
    cout << skippedAirports << " airports skipped" << endl;
    cout << g.connections() << " routes added, " << fixedRoutes << " of which were fixed" << endl;
    cout << skippedRoutes << " routes skipped" << endl;

    Dijkstras dij;
    // auto vec = dij.getPath(g, 1, 2);
    auto vec1 = dij.getPath(g, 4049, 2997);

    // std::cout << vec.size() << std::endl;



}
