#include <catch2/catch_test_macros.hpp>

#include "Graph.h"

#include <iostream>

#include "Algorithms/dijkstra.h"

#include <ostream>

#include "/workspaces/WBLR-CS-225-Project-7/src/Algorithms/dijkstra.h"

using namespace std;

TEST_CASE("Simple Dijkstra") {
    Graph g;

    g.addNode(1, "one", 0, 1);
    g.addNode(2, "two", 0, 2);
    g.addNode(3, "three", 0, 3);
    g.addNode(4, "four", 1, 2);
    g.connect(1, 2);
    g.connect(2, 3);

    Dijkstras dij;
    vector<int> actual = dij.getPath(g, 1, 3);
    vector<int> expected = {-1, 1, 2, 3};

    REQUIRE(actual == expected);
}


TEST_CASE("Dijkstra Airport Simple") {

    Dijkstras canvas;

    Graph g = canvas.generator();

    cout << g.size() << " airports added" << endl;

    Dijkstras dij;
    // auto vec = dij.getPath(g, 1, 2);
    vector<int> vec1 = dij.getPath(g, 4049, 3830);

    double minDist = dij.shortestDistance(g, 4049, 3830);
    double expec1 = g.distance(4049, 3830);

    vector<int> expected = {-1, 4049, 3830};

    REQUIRE(vec1 == expected);

    REQUIRE(minDist == expec1);

}