#pragma once

#include "../Graph.h"


#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Dijkstras {
    public:
        
        // Dijkstras(Graph g, int source, int target);
        vector<int> getPath(const Graph& g, int source, int target);
        double NearestAirport(int start, int airport);
        bool exists(int airport);

    private:
        // vector<int> path_;
        // map<int, double> dist_;
        // map<int, int> prev_;

        struct DijNode
        {
            int id;
            double distance;
            DijNode(int id, double distance) : id(id), distance(distance) { }
        };

      
};
