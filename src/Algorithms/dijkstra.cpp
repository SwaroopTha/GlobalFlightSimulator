#include "dijkstra.h"
#include <queue>
#include <iostream>
#include <set>
#include <limits>

using namespace std;


vector<int> Dijkstras::getPath(const Graph& g, int source, int target) {
    vector<int> airports = g.getIDs();
    auto comp = [](DijNode a, DijNode b) {
        return a.distance > b.distance;
    };
    std::priority_queue<DijNode, vector<DijNode>, decltype(comp)> qu(comp);
    map<int, double> ports;
    map<int, int> prev;

    for (int id : airports) {
        if (source == id) {
            DijNode node(id, 0);
            qu.push(node);
            ports[id] = 0;
        } else {
            DijNode node(id, std::numeric_limits<double>::infinity());
            qu.push(node);
            ports[id] = std::numeric_limits<double>::infinity();
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
            if (alt < ports.at(adj.first)) {
                ports[adj.first] = alt;
                prev[adj.first] = node.id;
                qu.push(DijNode(adj.first, alt)); // removed a bunch of adj.first->id
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
    std::cout << ports[target] << std::endl;

    // target++;
    // std::cout << ports[target] << std::endl;
    return vector<int>();
}

// double Dijkstras::NearestAirport(int start, int airport) {

// }


// bool Dijkstras::exists(int airport) {

// }

