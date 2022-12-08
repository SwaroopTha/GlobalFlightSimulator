#include "Graph.h"
#include <cmath>
#include <map>

using namespace std;

double Graph::GraphNode::_connectionDistance(int id) const {
    if (_connectedTo(id)) {
        return connections_.at(id);
    }
    return std::numeric_limits<double>::infinity();
}

void Graph::addNode(int id, string name, double latitude, double longitude) {
    GraphNode node = GraphNode(id, name, latitude, longitude);
    nodes_[id] = node;
}

void Graph::removeNode(int id) {
    if (!inGraph(id)) {
        return;
    }
    GraphNode toRemove = nodes_[id];
    numConnections_ -= toRemove.connections_.size();
    nodes_.erase(id);
    for (auto it = nodes_.begin(); it != nodes_.end(); it++) {
        GraphNode node = it->second;
        if (node.connections_.find(id) != node.connections_.end()) {
            node.connections_.erase(id);
            numConnections_--;
        }
    }
}

bool Graph::connect(int id1, int id2) {
    if (nodes_.find(id1) == nodes_.end() || nodes_.find(id2) == nodes_.end()) {
        //if either node doesn't exist
        return false;
    }
    nodes_[id1].connections_[id2] = _distance(id1, id2);
    numConnections_++;
    return true;
}

bool Graph::disconnect(int id1, int id2) {
    if (nodes_.find(id1) == nodes_.end() || nodes_.find(id2) == nodes_.end()) {
        //if either node doesn't exist
        return false;
    }
    if (nodes_[id1].connections_.find(id2) != nodes_[id1].connections_.end()) {
        nodes_[id1].connections_.erase(id2);
        numConnections_--;
        return true;
    } else {
        return false;
    }
}

vector<int> Graph::getIDs() const {
    vector<int> ids;
    for (auto it = nodes_.begin(); it != nodes_.end(); it++) {
        ids.push_back(it->first);
    }
    return ids;
}

vector<int> Graph::getConnections(int id) const {
    if (!inGraph(id)) {
        return vector<int>();
    }
    vector<int> ids;
    GraphNode gn = nodes_.at(id);
    for (auto it = gn.connections_.begin(); it != gn.connections_.end(); it++) {
        ids.push_back(it->first);
    }
    return ids;
}

bool Graph::connectedTo(int id1, int id2) const {
    if (nodes_.find(id1) != nodes_.end() && nodes_.find(id2) != nodes_.end()) {
        return nodes_.at(id1)._connectedTo(id2);
    }
    return false;
}

double Graph::_distance(int id1, int id2) const {
    if (!inGraph(id1) || !inGraph(id2)) {
        return numeric_limits<double>::infinity();
    }
    GraphNode a = nodes_.at(id1);
    GraphNode b = nodes_.at(id2);
    if (spherical_) {
        double PI = 4*atan(1);
        //haversine formula
        double EARTH_RADIUS = 6378.1;
        double lat1 = a.latitude_ * PI/180;
        double lat2 = b.latitude_ * PI/180;
        double deltalat = lat1 - lat2;
        double deltalong = (b.longitude_ - a.longitude_) * PI/180;
        double haversine1 = pow(sin(deltalat/2),2)+cos(lat1)*cos(lat2)*pow(sin(deltalong/2),2);
        double haversine2 = 2*atan2(sqrt(haversine1), sqrt(1-haversine1));
        return haversine2 * EARTH_RADIUS;
    } else {
        double deltalat = a.latitude_ - b.latitude_;
        double deltalong = a.longitude_ - b.longitude_;
        return sqrt(pow(deltalat, 2) + pow(deltalong, 2));
    }
}
