#include "Graph.h"
#include "readdat.h"
#include <cmath>
#include <iostream>
#include <map>

using namespace std;

double Graph::distance(GraphNode * a, GraphNode * b) const {
    double deltax = a->longitude - b->longitude;
    double deltay = a->latitude - b->latitude;
    return sqrt(deltax * deltax + deltay * deltay);
}

void Graph::addNode(int id, string name, double latitude, double longitude) {
    GraphNode * node = new GraphNode(name, latitude, longitude);
    nodes[id] = node;
}

bool Graph::connect(int id1, int id2) {
    if (nodes.find(id1) == nodes.end() || nodes.find(id2) == nodes.end()) {
        return false;
    }
    GraphNode * node1 = nodes[id1];
    GraphNode * node2 = nodes[id2];
    node1->neighbors.push_back(node2);
    numConnections++;
    return true;
}

int main() {
    Graph g;
    ifstream airports("airports.dat");
    string line;
    map<string, int> iataToID;
    int skippedAirport;
    while (getline(airports, line)) {
        stringstream ss(line);
        vector<string> fields = readline(ss);
        if (fields.size() != 14) {
            cout << "row has " << fields.size() << " fields; skipping" << endl;
            skippedAirport++;
            continue;
        }
        int id = stoi(fields[0]);
        string name = fields[1];
        string iata = fields[4];
        double latitude = stod(fields[6]);
        double longitude = stod(fields[7]);
        iataToID[iata] = id;
        g.addNode(id, name, latitude, longitude);
    }
    airports.close();
    ifstream routes("routes.dat");
    int skippedRoute = 0;
    while (getline(routes, line)) {
        stringstream ss(line);
        vector<string> fields = readline(ss);
        if (fields.size() != 9) {
            cout << "row has " << fields.size() << " fields; skipping" << endl;
            skippedRoute++;
            continue;
        }
        int id1, id2;
        if (fields[3] == "\\N") {
            if (iataToID.find(fields[2]) != iataToID.end()) {
                id1 = iataToID[fields[2]];
            } else {
                //cout << "skipping route from " << fields[2] << " to " << fields[4] << endl;
                skippedRoute++;
                continue;
            }
        } else {
            id1 = stoi(fields[3]);
        }
        if (fields[5] == "\\N") {
            if (iataToID.find(fields[4]) != iataToID.end()) {
                id2 = iataToID[fields[4]];
            } else {
                //cout << "skipping route from " << fields[2] << " to " << fields[4] << endl;
                skippedRoute++;
                continue;
            }
        } else {
            id2 = stoi(fields[5]);
        }
        if (!g.connect(id1, id2)) {
            //cout << "couldn't connect " << fields[2] << " to " << fields[4] << endl;
            skippedRoute++;
        }
    }
    routes.close();
    cout << g.size() << " airports added" << endl;
    cout << skippedAirport << " airports skipped" << endl;
    cout << g.connections() << " routes added" << endl;
    cout << skippedRoute << " routes skipped" << endl;
}
