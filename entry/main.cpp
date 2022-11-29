#include "Graph.h"
#include "readdat.h"
#include "Algorithms/dijkstra.h"
#include "Algorithms/bfs.h"
#include "makeimage.h"

using namespace std;

int main() {
    Graph g = readData();

    cout << g.size() << " airports and " << g.connections() << " connections" << endl;

    int source = 2;
    int target = 3995;
    cs225::PNG output = plotDijkstra(g, source, target);
    output.writeToFile("output.png");

    BFS bfs;
    vector<int> path = bfs.traversalOfBFS(g, 1);
    cout << path.size() << endl;
    for (int id : path) {
        cout << id << " -> ";
    }
}
