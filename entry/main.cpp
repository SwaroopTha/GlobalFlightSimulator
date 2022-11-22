#include "Graph.h"
#include "readdat.h"
#include "Algorithms/dijkstra.h"

using namespace std;

int main() {
    Graph g = readData();

    cout << g.size() << " airports and " << g.connections() << " connections" << endl;

    Dijkstras dij;
    //auto vec = dij.getPath(g, 1, 2);
    //auto vec1 = dij.getPath(g, 4049, 2997);

    // std::cout << vec.size() << std::endl;



}
