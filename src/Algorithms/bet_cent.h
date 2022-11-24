#pragma once

#include "../Graph.h"
#include <vector>
#include <map>

using namespace std;

class BetweenessCentrality {
    public:
        // BetweenessCentrality();
        void calculateScores();
        map<int, double> getAllScores();
        vector<int> getAirportsMinScore(int min_score);

    private:
        map<int, double> airport_scores_; // Maps all the airports (id - int) to their Betweeness Centrality Score

};

