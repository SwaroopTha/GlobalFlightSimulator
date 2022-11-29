#include "bet_cent.h"

using namespace std;
/*
getIDs() -> returns vector (int) of All Airport IDs
vector<int> airport_ids_ = graph.getIDs(); 

getConnections() -> returns vector (int) of All Airport IDs that connect to current airport
vector<int> neighbors = graph.getConnections(id - int);

getDistance() -> returns double representing distance between 2 airport IDs (RETURNS INFINITY IF NOT CONNECTED)
*/

map<int, int> BetweenessCentrality::getAllScores(const Graph& graph) {
    airport_ids_ = graph.getIDs(); 

    for (int id : airport_ids_) {
        airport_scores_[id] = 0;
    }

    // int airport_score;

    for (int v : airport_ids_) {
        for (int s : airport_ids_) {
            for (int t : airport_ids_) {

                vector<int> neighbors = graph.getConnections(v);

                // airport_score = 0;

                vector<int> P;

                stack<int> S;

                map<int, int> sigma;
                sigma[t] = 0;
                sigma[s] = 1;

                map<int, int> D;
                D[t] = -1;
                D[s] = 0;

                queue<int> Q;
                Q.push(s);

                while (!Q.empty()) {
                    int v = Q.front();
                    Q.pop();
                    S.push(v);
                    
                    for (int w : neighbors) {
                        // w found first time?
                        if (D[w] < 0) {
                            Q.push(w);
                            D[w] = D[v] + 1;
                        }
                        // shortest path to w via v?
                        if (D[w] == D[v] + 1) {
                            sigma[w] += sigma[v];
                            P.push_back(v);
                        }
                    }
                }

                map<int, int> delta;
                delta[v] = 0;

                while (!S.empty()) {
                    int w = S.top();
                    S.pop();
                    for (int p : P) {
                        delta[v] += (sigma[v] / sigma[w]) * (1 + delta[w]);
                    }
                    if (w != s) {
                        airport_scores_[w] = airport_scores_[w] + delta[w];
                    }
                }

            }
        }
    }
    

    return airport_scores_;

}

map<int, int> BetweenessCentrality::getAllScoresDijkstras(const Graph& graph) {
    airport_ids_ = graph.getIDs(); 

    Dijkstras d;

    int total_paths = 0;

    for (int id1 : airport_ids_) {
        for (int id2 : airport_ids_) {
            // cout << "id1: " << id1 << " id2: " << id2 << endl;
            if (id1 != id2) {
                vector<int> shortest_path = d.getPath(graph, id1, id2);

                if (shortest_path.size() > 2) {
                    for (size_t i = 1; i < shortest_path.size() - 1; i++) {
                        int current_airport = shortest_path[i];
                        if (airport_scores_dijkstras_.find(current_airport) != airport_scores_dijkstras_.end())
                            airport_scores_dijkstras_[current_airport]++;
                        else
                            airport_scores_dijkstras_[current_airport] = 1;
                    }

                    
                }

                total_paths++;
            }
        }
    }

    cout << "Total Paths: " << total_paths << endl;

    return airport_scores_dijkstras_;
}

// map<int, int> BetweenessCentrality::getAllScores() {
//     return airport_scores_;
// }

vector<int> BetweenessCentrality::getAirportsWithMinFrequency(int frequency) {
    vector<int> score_vector;
    for (auto i : airport_scores_) {
        if (i.second >= frequency) {
            score_vector.push_back(i.first);
        }
    }
    return score_vector;
}