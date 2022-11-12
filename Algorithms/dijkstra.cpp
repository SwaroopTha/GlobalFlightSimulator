#include "dijkstra.h"
#include <queue>
#include <iostream>

using namespace std;


vector<string> Dijkstras::getPath(const Graph& g, int source, int target) {
    vector<int> ports = g.getIDs();
    auto comp = [](DijNode a, DijNode b) {
        return a.distance < b.distance;
    };
    std::priority_queue<DijNode, vector<DijNode>, decltype(comp)> qu;

    for (int id : ports) {
        if (source == id) {
            DijNode node(g.getNode(id)->name, id, 0);
            qu.push(node);
            nodes[g.getNode(id)->name] = 0;
        } else {
            DijNode node(g.getNode(id)->name, id, std::numeric_limits<double>::infinity());
            qu.push(node);
            nodes[g.getNode(id)->name] = std::numeric_limits<double>::infinity();
        }
    }

    // while (!qu.empty()) {
    //     auto node = qu.top();
    //     qu.pop();
    //     auto neighbors = g.getNode(node.id)->connections;
    //     for (auto adj : neighbors) {
    //         double alt = node.distance + adj.second;
    //         if (alt < nodes[adj.first->name]) {
    //             // nodes[adj.first->] = alt;
    //             nodes[adj.first->name] = alt;
    //             // qu.push(DijNode(adj.first->name, nodes[adj.first->name].id));
    //         }
    //     }
    // }


    target++;
    return vector<string>();

}


// double Dijkstras::NearestAirport(int start, int airport) {

// }


// bool Dijkstras::exists(int airport) {

// }