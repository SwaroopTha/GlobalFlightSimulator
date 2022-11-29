#pragma once

#include "Graph.h"
#include "readdat.h"
#include "dijkstra.h"

#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

class BetweenessCentrality {
    public:
        // BetweenessCentrality();
        // O(|n|^2 log|n| + |n||m|) time 
        // O(n^2) space
        map<int, int> getAllScores(const Graph& graph);
        // map<int, int> getAllScores();
        vector<int> getAirportsWithMinFrequency(int frequency);

        map<int, int> getAllScoresDijkstras(const Graph& graph);
        vector<int> getAirportsWithMinFrequencyDijkstras(int frequency);

    private:
        vector<int> airport_ids_; // vector of all airport ids
        
        map<int, int> airport_scores_; // Maps all the airports (id - int) to their Betweeness Centrality Frequency

        map<int, int> airport_scores_dijkstras_;

};

