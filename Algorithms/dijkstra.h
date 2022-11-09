#pragma once
#include <Graph.h>
#include <vector>
#include <utility>

using namespace std;

class Dijkstras {
    public:
        vector<int> getPath(Graph g, int source, int target);
        double NearestAirport(int start, int airport);
        bool exists(int airport);
    private:
        vector<int> path_;
};