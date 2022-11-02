#include "Graph.h"
#include "readdat.h"
#include <cmath>
#include <iostream>

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
    node2->neighbors.push_back(node1);
    numConnections++;
    return true;
}

int main() {
    Graph g;
    ifstream airports("airports.dat");
    string line;
    while (getline(airports, line)) {
        stringstream ss(line);
        vector<string> fields = readline(ss);
        int id = stoi(fields[0]);
        string name = fields[1];
        double latitude = stod(fields[6]);
        double longitude = stod(fields[7]);
        g.addNode(id, name, latitude, longitude);
    }
    airports.close();
    cout << g.size() << endl;
    ifstream routes("routes.dat");
    int count = 0;
    while (getline(routes, line)) {
        stringstream ss(line);
        vector<string> fields = readline(ss);
        if (fields[3] == "\\N" || fields[5] == "\\N") {
            cout << "skipping " << fields[2] << " to " << fields[4] << endl;
            continue;
        }
        int id1 = stoi(fields[3]);
        int id2 = stoi(fields[5]);
        g.connect(id1, id2);
        count++;
    }
    routes.close();
    cout << g.connections() << endl;
}
