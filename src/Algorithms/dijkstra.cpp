#include "dijkstra.h"
#include <queue>
#include <iostream>
#include <set>
#include <limits>
#include <utility>

using namespace std;

typedef pair<int, double> DijNode;

vector<int> Dijkstras::getPath(const Graph& g, int source, int target) {
    vector<int> airports = g.getIDs();
    auto comp = [](DijNode a, DijNode b) {
        return a.second > b.second;
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
        while (seen.find(node.first) != seen.end() && !qu.empty()) {
            node = qu.top();
            qu.pop();
        }
        seen.insert(node.first);
        vector<int> neighbors = g.getConnections(node.first);
        for (int adj : neighbors) {
            double alt = node.second + g.getDistance(node.first, adj);
            if (alt < ports.at(adj)) {
                ports[adj] = alt;
                prev[adj] = node.first;
                qu.push(DijNode(adj, alt)); // removed a bunch of adj.first->id
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
    paths.push_back(target);
    // for (auto i : paths) {
    //     if (i == -1) continue;
    //     cout << g.getNode(i)->name << "-->" << std::endl;
    // }
    // std::cout << g.getNode(target)->name << std::endl;
    // std::cout << ports[target] << std::endl;

    // target++;
    // std::cout << ports[target] << std::endl;
    return paths;
}

double Dijkstras::shortestDistance(const Graph &g, int start, int airport) {
    vector<int> airports = g.getIDs();
    auto comp = [](DijNode a, DijNode b) {
        return a.second > b.second;
    };
    std::priority_queue<DijNode, vector<DijNode>, decltype(comp)> qu(comp);
    map<int, double> ports;
    map<int, int> prev;

    for (int id : airports) {
        if (start == id) {
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
        while (seen.find(node.first) != seen.end() && !qu.empty()) {
            node = qu.top();
            qu.pop();
        }
        seen.insert(node.first);
        vector<int> neighbors = g.getConnections(node.first);
        for (int adj : neighbors) {
            double alt = node.second + g.getDistance(node.first, adj);
            if (alt < ports.at(adj)) {
                ports[adj] = alt;
                prev[adj] = node.first;
                qu.push(DijNode(adj, alt)); // removed a bunch of adj.first->id
            }
        }
    }

    return ports[airport];

}

