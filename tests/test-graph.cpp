#include <catch2/catch_test_macros.hpp>

#include "graph.h"

using namespace std;

TEST_CASE("graph constructor") {
    Graph g;
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 0);
    REQUIRE(g.getIDs() == vector<int>());
}


TEST_CASE("adding and accessing nodes") {
    Graph g;
    g.addNode(12, "idk", 30, -30);
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 1);
    REQUIRE(g.getIDs() == vector<int>(1,12));
    REQUIRE(g.getName(12) == "idk");
    REQUIRE(g.getLatitude(12) == 30);
    REQUIRE(g.getLongitude(12) == -30);

    g.addNode(24, "smth", 25, -35);
    REQUIRE(g.connections() == 0);
    REQUIRE(g.size() == 2);
    vector<int> expected = {12, 24};
    REQUIRE(g.getIDs() == expected);
    REQUIRE(g.getName(24) == "smth");
    REQUIRE(g.getLatitude(24) == 25);
    REQUIRE(g.getLongitude(24) == -35);
}

TEST_CASE("connecting nodes") {
    Graph g;
    g.addNode(12, "idk", 30, -30);
    g.addNode(24, "smth", 25, -35);

    REQUIRE(g.connections() == 0);
    REQUIRE(g.getConnections(12).size() == 0);
    REQUIRE(g.getConnections(24).size() == 0);
    
    g.connect(12, 24);
    REQUIRE(g.connections() == 1);
    REQUIRE(g.getConnections(12) == vector<int>(1,24));
    REQUIRE(g.getConnections(24).size() == 0);
    REQUIRE(g.getDistance(12, 24) == g.distance(12, 24));
    REQUIRE(g.getDistance(24, 12) == numeric_limits<double>::infinity());
}
