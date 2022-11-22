#pragma once

#include "../Graph.h"
#include <vector>

using namespace std;

class BetweenessCentrality {
    public:
        // BetweenessCentrality();
         

    private:
        vector<pair<Graph::GraphNode, double>> score_;
};

