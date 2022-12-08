#include "Graph.h"
#include "readdat.h"
#include "Algorithms/dijkstra.h"
#include "Algorithms/bfs.h"
#include "Algorithms/bet_cent.h"
#include "Algorithms/makeimage.h"

using namespace std;
using cs225::PNG;

int main() {
    // example usage
    Graph g = readData("../Data/airports.dat",  "../Data/routes.dat");

    cout << g.size() << " airports and " << g.connections() << " connections" << endl;

    int source = 3319;
    int target = 5554;
    PNG worldMap;
    worldMap.readFromFile("../Data/map.png");

    cs225::PNG output = plotDijkstra(worldMap, g, source, target);
    output.writeToFile("output.png");
}
