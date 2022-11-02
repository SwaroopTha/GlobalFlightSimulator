#include "Graph.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>

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
    return true;
}

int main() {
    Graph g;
    ifstream airports("airports.txt");
}
