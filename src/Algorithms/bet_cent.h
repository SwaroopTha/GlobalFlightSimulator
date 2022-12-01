#pragma once

#include "Graph.h"
#include "readdat.h"
#include "dijkstra.h"
#include "../ProgressBar.h"

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
        /**
        * @brief Applies the betweenness centrality algorithm with a probabilistic approach
        * Instead of considering all pairs of distinct points, uniformly samples a given
        * amount of pairs of distinct points
        *
        * @param graph The graph on which to apply betweenness centrality
        * @param sampleSize How many paths to sample from the graph
        * @param skipNonPaths Whether or not to skip pairs of points with no path
        * @param showProgress Whetehr to show a progress bar
        * @return map<int, int> A map of IDs to betweenness scores
        */
        map<int, int> getAllScoresDijkstrasProbabilistic(const Graph& graph, int sampleSize, bool skipNonPaths = true, bool showProgress = true);

    private:
        vector<int> airport_ids_; // vector of all airport ids
        
        map<int, int> airport_scores_; // Maps all the airports (id - int) to their Betweeness Centrality Frequency

        map<int, int> airport_scores_dijkstras_;

};

