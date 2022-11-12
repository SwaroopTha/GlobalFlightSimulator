#pragma once

#include "../Graph.h"


#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Dijkstras {
    public:
        
        // Dijkstras(Graph g, int source, int target);
        vector<string> getPath(const Graph& g, int source, int target);
        double NearestAirport(int start, int airport);
        bool exists(int airport);

    private:
        vector<string> path_;
        // map<int, double> dist_;
        map<int, int> prev_;

        struct DijNode
        {
            string name;
            int id;
            double distance;
            DijNode(string name, int id, double distance) : name(name), id(id), distance(distance) { }
        };
        map<std::string, double> nodes;
      
};
