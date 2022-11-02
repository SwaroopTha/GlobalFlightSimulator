#pragma once
#include <vector>
#include <map>
#include <string>

class Graph {
private:
    struct GraphNode {
        std::string name;
        double latitude, longitude;
        std::vector<GraphNode*> neighbors;
        GraphNode(std::string name_, double lat_, double long_) :
            name(name_), latitude(lat_), longitude(long_) {}
    };
public:
    Graph() : numConnections(0) {}
    void addNode(int id, std::string name, double latitude, double longitude);
    bool connect(int id1, int id2);
    int size() const { return nodes.size(); }
    int connections() const { return numConnections; }
    double distance(GraphNode * a, GraphNode * b) const;
private:
    int numConnections;
    std::map<int, GraphNode*> nodes;
};
