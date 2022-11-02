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
    void addNode(int id, std::string name, double latitude, double longitude);
    bool connect(int id1, int id2);
    int getSize() const { return nodes.size(); }
    double distance(GraphNode * a, GraphNode * b) const;
private:
    std::map<int, GraphNode*> nodes;
};
