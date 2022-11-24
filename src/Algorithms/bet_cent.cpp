#include "bet_cent.h"

using namespace std;

void BetweenessCentrality::calculateScores() {

}

map<int, double> BetweenessCentrality::getAllScores() {
    return airport_scores_;
}

vector<int> BetweenessCentrality::getAirportsMinScore(double min_score) {
    vector<int> score_vector;
    for (auto i : airport_scores_) {
        if (i.second >= min_score) {
            score_vector.push_back(i.first);
        }
    }
    return score_vector;
}