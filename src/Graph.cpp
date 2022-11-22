#include "Graph.h"
#include <cmath>
#include <map>

using namespace std;

double Graph::distance(int id1, int id2) const {
    GraphNode a = nodes.at(id1);
    GraphNode b = nodes.at(id2);
    //uses haversine formula
    double EARTH_RADIUS = 6378.1;
    double lat1 = a.latitude * 3.14/180;
    double lat2 = b.latitude * 3.14/180;
    double deltalat = lat1 - lat2;
    double deltalong = (b.longitude - a.longitude)* 3.14/180;
    double haversine1 = pow(sin(deltalat/2),2)+cos(lat1)*cos(lat2)*pow(sin(deltalong/2),2);
    double haversine2 = 2*atan2(sqrt(haversine1), sqrt(1-haversine1));
    return haversine2 * EARTH_RADIUS;
}

void Graph::addNode(int id, string name, double latitude, double longitude) {
    GraphNode node = GraphNode(id, name, latitude, longitude);
    nodes[id] = node;
}

bool Graph::connect(int id1, int id2) {
    if (nodes.find(id1) == nodes.end() || nodes.find(id2) == nodes.end()) {
        //if either node doesn't exist
        return false;
    }
    nodes[id1].connections[id2] = distance(id1, id2);
    numConnections++;
    return true;
}

vector<int> Graph::getIDs() const {
    vector<int> ids;
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        ids.push_back(it->first);
    }
    return ids;
}

vector<int> Graph::getConnections(int id) const {
    vector<int> ids;
    GraphNode gn = nodes.at(id);
    for (auto it = gn.connections.begin(); it != gn.connections.end(); it++) {
        ids.push_back(it->first);
    }
    return ids;
}
