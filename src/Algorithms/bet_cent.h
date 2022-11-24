#pragma once

#include "../Graph.h"
#include <vector>
#include <map>

using namespace std;

class BetweenessCentrality {
    public:
        // BetweenessCentrality();
        void calculateScores(const Graph& graph);
        map<int, int> getAllScores();
        vector<int> getAirportsWithMinFrequency(int frequency);

    private:
        vector<int> airport_ids_; // vector of all airport ids
        
        map<int, int> airport_scores_; // Maps all the airports (id - int) to their Betweeness Centrality Frequency

};

