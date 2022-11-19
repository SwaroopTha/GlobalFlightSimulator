#include <catch2/catch_test_macros.hpp>

#include "graph.h"

using namespace std;

TEST_CASE("graph constructor") {
    Graph g;
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 0);
    REQUIRE(g.getIDs() == vector<int>());
}


TEST_CASE("adding and getting nodes") {
    Graph g;
    g.addNode(12, "idk", 30, -30);
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 1);
    REQUIRE(g.getIDs() == vector<int>(1,12));

    g.addNode(24, "smth", 25, -35);
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 2);
    vector<int> expected = {12, 24};
    REQUIRE(g.getIDs() == expected);
}

TEST_CASE("connecting nodes") {
    Graph g;
    g.addNode(12, "idk", 30, -30);
    g.addNode(24, "smth", 25, -35);
    Graph::GraphNode * gn1 = g.getNode(12);
    Graph::GraphNode * gn2 = g.getNode(24);

    double dist = g.distance(12, 24);
}
