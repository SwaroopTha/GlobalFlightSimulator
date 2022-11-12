#include "dijkstra.h"
#include <queue>
#include <iostream>
#include <set>

using namespace std;


vector<int> Dijkstras::getPath(const Graph& g, int source, int target) {
    vector<int> ports = g.getIDs();
    auto comp = [](DijNode a, DijNode b) {
        return a.distance > b.distance;
    };
    std::priority_queue<DijNode, vector<DijNode>, decltype(comp)> qu;
    map<int, double> nodes;
    map<int, int> prev;

    for (int id : ports) {
        if (source == id) {
            DijNode node(id, 0);
            qu.push(node);
            nodes[id] = 0;
        } else {
            DijNode node(id, std::numeric_limits<double>::infinity());
            qu.push(node);
            nodes[id] = std::numeric_limits<double>::infinity();
        }
        prev[id] = -1;
    }

    set<int> seen;

    while (!qu.empty()) {
        auto node = qu.top();
        qu.pop();
        while (seen.find(node.id) != seen.end() && !qu.empty()) {
            node = qu.top();
            qu.pop();
        }
        seen.insert(node.id);
        auto neighbors = g.getNode(node.id)->connections;
        for (auto adj : neighbors) {
            double alt = node.distance + adj.second;
            if (alt < nodes.at(adj.first->id)) {
                nodes[adj.first->id] = alt;
                prev[adj.first->id] = node.id;
                qu.push(DijNode(adj.first->id, alt));
            }
        }
    }

    // std::cout << nodes[target] << std::endl;
    // for (auto it : nodes) {
    //     if (it.second == std::numeric_limits<double>::infinity()) continue;
    //     std::cout << it.first << " ";
    //     std::cout << it.second << std::endl;
    // }
    // target++;
    int temp = target;
    std::vector<int> paths;
    while (temp != -1) {
        paths.push_back(prev[temp]);
        temp = prev.at(temp);
    }
    

    std::reverse(paths.begin(), paths.end());
    for (auto i : paths) {
        if (i == -1) continue;
        cout << g.getNode(i)->name << "-->" << std::endl;
    }
    std::cout << g.getNode(target)->name << std::endl;
    std::cout << nodes[target] << std::endl;

    // target++;
    return vector<int>();

}


// double Dijkstras::NearestAirport(int start, int airport) {

// }


// bool Dijkstras::exists(int airport) {

// }