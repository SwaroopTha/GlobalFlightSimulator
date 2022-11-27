#include "Graph.h"
#include "readdat.h"
#include "Algorithms/dijkstra.h"
#include "makeimage.h"

using namespace std;

int main() {
    Graph g = readData();

    cout << g.size() << " airports and " << g.connections() << " connections" << endl;

    int source = 2;
    int target = 3995;
    cs225::PNG output = plotDijkstra(g, source, target);
    cout << g.getName(source) << " to " << g.getName(target) << endl;
    output.writeToFile("output.png");
}
