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
        return a.distance > b.distance;
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

    return ports[airport];

}

Graph Dijkstras::generator() const {
    Graph g;
    ifstream airports("../Data/airports.dat");
    ifstream routes("../Data/routes.dat");
    string line;
    //map from IATA to ID to fix issues later on
    map<string, int> iataToID;
    int skippedAirports = 0;
    int skippedRoutes = 0;
    int fixedRoutes = 0;

    //reads in the airports
    while (getline(airports, line)) {
        stringstream ss(line);
        vector<string> fields = readline(ss);
        //skip if there are not 14 fields
        if (fields.size() != 14) {
            skippedAirports++;
            continue;
        }
        //we only care about these fields
        int id = stoi(fields[0]);
        string name = fields[1];
        string iata = fields[4];
        double latitude = stod(fields[6]);
        double longitude = stod(fields[7]);
        if (validID(id) && validIATA(iata)) {
            iataToID[iata] = id;
        }

        if (validID(id) && validLatitude(latitude) && validLongitude(longitude)) {
            //add the airport to the graph
            g.addNode(id, name, latitude, longitude);
        } else {
            skippedAirports++;
        }
    }
    airports.close();

    //reads in the connections
    while (getline(routes, line)) {
        stringstream ss(line);
        vector<string> fields = readline(ss);
        //skip if there aren't 9 lines
        if (fields.size() != 9) {
            skippedRoutes++;
            continue;
        }
        int id1, id2;
        bool fixed = false;
        //the ID will be missing occassionally so we try to use the IATA to figure it out
        //this is for the first airport
        if (fields[3] == "\\N") {
            if (iataToID.find(fields[2]) != iataToID.end()) {
                //if the IATA is found use the corresponding ID
                id1 = iataToID[fields[2]];
                fixed = true;
            } else {
                //skip it otherwise
                skippedRoutes++;
                continue;
            }
        } else {
            id1 = stoi(fields[3]);
        }
        //same thing for the second airport
        if (fields[5] == "\\N") {
            if (iataToID.find(fields[4]) != iataToID.end()) {
                id2 = iataToID[fields[4]];
                fixed = true;
            } else {
                skippedRoutes++;
                continue;
            }
        } else {
            id2 = stoi(fields[5]);
        }
        if (!(validID(id1) && validID(id2))) {
            skippedRoutes++;
            continue;
        }
        //make the connection (or try to)
        if (!g.connect(id1, id2)) {
            skippedRoutes++;
        }
        //count the number of fixed routes (i.e. routes that use IATA to determine ID)
        if (fixed) {
            fixedRoutes++;
        }
    }
    routes.close();

    return g;
}

