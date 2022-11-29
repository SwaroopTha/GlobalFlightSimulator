#pragma once

#include "Graph.h"


#include <vector>
#include <utility>
#include <algorithm>
#include <string>

#include "readdat.h"

#include <fstream>

using namespace std;

class Dijkstras {
    public:
        vector<int> getPath(const Graph& g, int source, int target);
        double shortestDistance() {
            return shortestDistance_;
        }

    private:
        /*
        struct DijNode
        {
            int id;
            double distance;
            DijNode(int id, double distance) : id(id), distance(distance) { }
        };
        */

        vector<int> airports_; //list of all airports
        map<int, double> ports_; // maps source airport connections to its distances
        map<int, int> prev_; // maps airport's previous immediate source


        double shortestDistance_; // shorteset distance for intended algorithm
      
};
