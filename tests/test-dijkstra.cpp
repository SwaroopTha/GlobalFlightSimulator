#include <catch2/catch_test_macros.hpp>

#include "Graph.h"

#include "/workspaces/WBLR-CS-225-Project-7/src/Algorithms/dijkstra.h"

using namespace std;


TEST_CASE("Dijkstra simple") {
    Graph g;

    cout << g.size() << " airports added" << endl;

    Dijkstras dij;
    // auto vec = dij.getPath(g, 1, 2);
    auto vec1 = dij.getPath(g, 4049, 2997);
}