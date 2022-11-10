#include "Graph.h"
#include <cmath>
#include <map>

using namespace std;

double Graph::distance(GraphNode * a, GraphNode * b) const {
    //uses haversine formula
    double EARTH_RADIUS = 6378.1;
    double lat1 = a->latitude;
    double lat2 = b->latitude;
    double deltalat = b - a;
    double deltalong = b->longitude - a->longitude;
    double haversine1 = pow(sin(deltalat/2),2)+cos(lat1)*cos(lat2)*pow(sin(deltalong/2),2);
    double haversine2 = 2*atan2(sqrt(haversine1), sqrt(1-haversine1));
    return haversine2 * EARTH_RADIUS;
}

void Graph::addNode(int id, string name, double latitude, double longitude) {
    GraphNode * node = new GraphNode(name, latitude, longitude);
    nodes[id] = node;
}

bool Graph::connect(int id1, int id2) {
    if (nodes.find(id1) == nodes.end() || nodes.find(id2) == nodes.end()) {
        //if either node doesn't exist
        return false;
    }
    GraphNode * node1 = nodes[id1];
    GraphNode * node2 = nodes[id2];
    pair<GraphNode*, double> p = make_pair(node2, distance(node1, node2));
    node1->connections.push_back(p);
    numConnections++;
    return true;
}

vector<int> Graph::getIDs() {
    vector<int> ids;
    map<int, GraphNode*>::iterator it;
    for (it = nodes.begin(); it != nodes.end(); it++) {
        ids.push_back(it->first);
    }
    return ids;
}
