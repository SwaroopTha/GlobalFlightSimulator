#include "Graph.h"
#include "readdat.h"
#include "Algorithms/dijkstra.h"
#include "Algorithms/bfs.h"
#include "makeimage.h"

using namespace std;

int main() {
    Graph g = readData("../Data/airports.dat",  "../Data/routes.dat");

    cout << g.size() << " airports and " << g.connections() << " connections" << endl;

    int source = 3319;
    int target = 5554;
    cs225::PNG output = plotDijkstra(g, source, target);
    output.writeToFile("output.png");
}
