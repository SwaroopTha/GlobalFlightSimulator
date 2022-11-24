#include "bet_cent.h"

using namespace std;

void BetweenessCentrality::calculateScores(const Graph& graph) {
    airport_ids_ = graph.getIDs();

}

map<int, int> BetweenessCentrality::getAllScores() {
    return airport_scores_;
}

vector<int> BetweenessCentrality::getAirportsWithMinFrequency(int frequency) {
    vector<int> score_vector;
    for (auto i : airport_scores_) {
        if (i.second >= frequency) {
            score_vector.push_back(i.first);
        }
    }
    return score_vector;
}