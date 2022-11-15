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

    Graph::GraphNode * gn1 = g.getNode(12);
    REQUIRE(gn1->id == 12);
    REQUIRE(gn1->name == "idk");
    REQUIRE(gn1->latitude == 30);
    REQUIRE(gn1->longitude == -30);
    REQUIRE(gn1->connections == vector<pair<Graph::GraphNode*, double>>());

    Graph::GraphNode * gn2 = g.getNode(24);
    REQUIRE(gn2->id == 24);
    REQUIRE(gn2->name == "smth");
    REQUIRE(gn2->latitude == 25);
    REQUIRE(gn2->longitude == -35);
    REQUIRE(gn2->connections == vector<pair<Graph::GraphNode*, double>>());
}

TEST_CASE("connecting nodes") {
    Graph g;
    g.addNode(12, "idk", 30, -30);
    g.addNode(24, "smth", 25, -35);
    Graph::GraphNode * gn1 = g.getNode(12);
    Graph::GraphNode * gn2 = g.getNode(24);

    double dist = g.distance(12, 24);

    vector<pair<Graph::GraphNode*, double>> gn1connections = {make_pair(gn2, dist)};
    vector<pair<Graph::GraphNode*, double>> gn2connections = {make_pair(gn1, dist)};
    
    REQUIRE(gn1->connections == vector<pair<Graph::GraphNode*, double>>());
    REQUIRE(gn2->connections == vector<pair<Graph::GraphNode*, double>>());

    g.connect(12, 24);

    REQUIRE(gn1->connections == gn1connections);
    REQUIRE(gn2->connections == vector<pair<Graph::GraphNode*, double>>());

    g.connect(24, 12);

    REQUIRE(gn1->connections == gn1connections);
    REQUIRE(gn2->connections == gn2connections);
}
